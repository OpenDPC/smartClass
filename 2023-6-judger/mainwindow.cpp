#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_progressdialog.h"

#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QThread>
#include <QFont>


class ItemWindow : public QDialog {
public:
    ItemWindow(const QString& content, QWidget* parent = nullptr) : QDialog(parent) {
        //setWindowTitle("Item Content");

        QVBoxLayout* layout = new QVBoxLayout(this);
        QPlainTextEdit *plain = new QPlainTextEdit(content, this);
        layout->addWidget(plain);
        plain->setReadOnly(true);
        QFont font("consolas");
        plain->setFont(font);
        setLayout(layout);
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    timelimit = ui->spinBoxTimelimit->value();
    QObject::connect(ui->pushButtonStartCompile, SIGNAL(clicked()), this, SLOT(mainExecution()));
    QObject::connect(ui->radioButtonO1, SIGNAL(clicked()), this, SLOT(setCompilerOptimization()));
    QObject::connect(ui->radioButtonO2, SIGNAL(clicked()), this, SLOT(setCompilerOptimization()));
    QObject::connect(ui->radioButtonO3, SIGNAL(clicked()), this, SLOT(setCompilerOptimization()));
    //QObject::connect(this, SIGNAL(locChanged()), progressDialog, SLOT(changeLoc()));
}

MainWindow::~MainWindow()
{
    delete ui;
    term();
}

void MainWindow::init()
{
    compileProcess = new QProcess(this);
    programProcess = new QProcess(this);

    compile_src_loc = 0;

    optimizationState = O1; //default

    hasChosenSourceCode = false;
    isCompiled = false;

    progressDialog = new ProgressDialog(this);

    ui->pushButtonStartCompile->setDisabled(true);
    ui->tableResult->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::term()
{
    delete compileProcess;
    delete programProcess;
    delete progressDialog;
}

QStringList MainWindow::set_compile_command(QString path)
{
    QDir tempDir(path);
    QString exeDir(QDir::currentPath() + "/temp/" + tempDir.dirName());
#ifdef _DEBUG_COMPILE_
    qDebug() << exeDir;
#endif
    QString compileCommand("");
    compileCommand.append(compilerPath);
    compileCommand.append(" " + path + "/*.cpp");
    compileCommand.append(" -o " + exeDir);

    if(optimizationState == O1)
    {
        compileCommand.append(" -O1");
    }
    else if(optimizationState == O2)
    {
        compileCommand.append(" -O2");
    }
    else if(optimizationState == O3)
    {
        compileCommand.append(" -O3");
    }
    QStringList ret(compileCommand);
    ret.append(exeDir + ".exe");
    return ret;
}

QString MainWindow::start_compile(QString compileCommand)
{
    compileProcess->start(compileCommand);
    compileProcess->waitForFinished();
    compileProcess->waitForReadyRead();
    QString errOutput = compileProcess->readAllStandardError();
    return errOutput;
}

void MainWindow::mainExecution()
{
    ui->pushButtonStartCompile->setDisabled(true);
    ui->pushButtonChooseDir->setDisabled(true);
    compile_src_loc = 0;
    //progressDialog->setRange(srcDirs.length() - 1);
    QProgressDialog pd("Processing...", "Cancel", 0, srcDirs.length(), this);
    pd.setWindowModality(Qt::WindowModal);
    pd.setAutoClose(false);
    pd.show();
    qDebug() << "leng: " << srcDirs.length();
    qDebug() << "O: " << optimizationState;

    //创建存放exe的文件夹
    QDir currentDir(QDir::currentPath() + "/temp");
    if(!currentDir.exists())
    {
        currentDir.mkdir(QDir::currentPath() + "/temp");
    }

    //主循环
    //progressDialog->show();
    for(QString const &path: srcDirs)
    {
        //progressDialog->setCurrentState(path.split('/').last());
        pd.setValue(compile_src_loc);
        pd.setLabelText("当前学生: " + path.split('/').last());
        pd.setWindowTitle("处理中...");

        if(pd.wasCanceled())
        {
            break;
        }
        //compile
        QStringList l = set_compile_command(path);
        QString compileCommand = l[0];
        QString exeDir = l[1];
        QString errOutput = start_compile(compileCommand);
        compileResult.append(errOutput);
#ifdef _DEBUG_COMPILE_
        qDebug() << QString("Current Task: ") << compile_src_loc;
        qDebug() << exeDir;
#endif

        //judge
        if (errOutput == "")
        {
            QStringList score;
            score = run_single_file(exeDir, QDir::currentPath() + "/in", QDir::currentPath() + "/out");
            qDebug() << score;
            ui->tableResult->setItem(compile_src_loc, 0, new QTableWidgetItem(path.split('/').last())); //folder name (stu name)
            ui->tableResult->setItem(compile_src_loc, 1, new QTableWidgetItem(score[0]));   //score
            ui->tableResult->setItem(compile_src_loc, 2, new QTableWidgetItem(score[1]));   //AC or WA or CE
            scoreList.append(score[0]);
            judgeList.append(score[1]);
        }
        else {
            ui->tableResult->setItem(compile_src_loc, 0, new QTableWidgetItem(path.split('/').last()));
            ui->tableResult->setItem(compile_src_loc, 1, new QTableWidgetItem("0/0"));
            ui->tableResult->setItem(compile_src_loc, 2, new QTableWidgetItem("Compile Error"));
            scoreList.append("0/0");
            judgeList.append(errOutput);
        }

        compile_src_loc++;
        //emit locChanged(compile_src_loc);
        //progressDialog->setValue(compile_src_loc);

        qDebug() << compile_src_loc;
        QThread::msleep(200);
    }
    isCompiled = true;
    //progressDialog->close();
    pd.setValue(srcDirs.length());
    pd.close();
}

void MainWindow::setCompilerOptimization()
{
    if(ui->radioButtonO1->isChecked())
    {
        optimizationState = O1;
    }
    else if(ui->radioButtonO2->isChecked())
    {
        optimizationState = O2;
    }
    else if(ui->radioButtonO3->isChecked())
    {
        optimizationState = O3;
    }
}

void MainWindow::getDirs(QString fullPath)
{
    QDir const source(fullPath);
    QStringList folders = source.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);

    if(folders.isEmpty())
    {
        srcDirs.append(fullPath);
        return;
    }
    for(QString const& name: folders)
    {
        getDirs(fullPath + "/" + name);
    }
}

void MainWindow::on_pushButtonChooseDir_clicked()
{
    QFileDialog dirChooser;
    dirChooser.setFileMode(QFileDialog::Directory);
    dirChooser.setOption(QFileDialog::ShowDirsOnly);
    dirChooser.setOption(QFileDialog::ReadOnly);
    dirChooser.setOption(QFileDialog::DontUseNativeDialog);

    if(dirChooser.exec())
    {
        targetDir = dirChooser.selectedFiles()[0];
    }

    qDebug() << "selected files:" << dirChooser.selectedFiles();
    qDebug() << "target directory:" << targetDir;
    srcDirs.clear();
    getDirs(targetDir);

    int tableRowCount = 0;
    qDebug() << "source directories:";
    for(const QString& directory: srcDirs)
    {
        tableRowCount++;
        qDebug() << directory;
    }
    ui->tableResult->setRowCount(tableRowCount);
    ui->pushButtonStartCompile->setEnabled(true);
}

void MainWindow::on_spinBoxTimelimit_valueChanged(int arg1)
{
    timelimit = arg1;
}

void MainWindow::on_tableResult_cellDoubleClicked(int row, int column)
{
    qDebug() << row << ", " << column;
    if(!isCompiled) return;
    QString content;
    switch(column)
    {
    case 0:
        content = srcDirs[row];
        break;
    case 1:
        content = scoreList[row];
        break;
    case 2:
        content = judgeList[row];
        break;
    }
    qDebug() << content;
    ItemWindow itemWindow(content, this);
    itemWindow.setWindowTitle(ui->tableResult->item(row, 0)->text());
    itemWindow.exec();
}

void MainWindow::changeLoc(const int& loc)
{
    progressDialog->setValue(loc);
}




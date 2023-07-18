#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QStringList>
#include <QTextCodec>
#include <QDebug>
#include <QElapsedTimer>
#include <QTableWidget>
#include <QProgressDialog>

#include "progressdialog.h"

//#define _DEBUG_COMPILE_

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ProgressDialog *progressDialog; //开始编译和判题时show这个，结束时关闭  //改用QProgressDialog

private slots:
    void mainExecution();   //编译和判题主函数
    void setCompilerOptimization(); //用于radiobutton设置编译器优化选项
    void on_pushButtonChooseDir_clicked();
    void on_spinBoxTimelimit_valueChanged(int arg1);
    void on_tableResult_cellDoubleClicked(int row, int column);
    void changeLoc(const int& loc);

signals:
    void locChanged(const int& loc);

private:
    Ui::MainWindow *ui;

#ifdef _DEBUG_COMPILE_
    QString const compilerPath = "debug/TDM-GCC-64/bin/g++.exe";
#else
    QString const compilerPath = "TDM-GCC-64/bin/g++.exe";
#endif
    //利用QProcess分别进行编译和程序运行
    QProcess *compileProcess;
    QProcess *programProcess;
    QString targetDir;  //学生源代码文件夹路径的父路径，在选择路径时获取
    QString inputDir;   //输入样例路径
    QString outputDir;  //输出样例路径
    QStringList srcDirs;//每个学生源代码路径，list中是每个文件夹的fullpath
    QStringList compileResult;  //存放结果，共
    QStringList programOutput;
    QStringList scoreList;  //存放分数
    QStringList judgeList;  //存放评判结果

    int compile_src_loc;    //之后记得改成srcLoc

    int timelimit;  //判题运行时间限制

    bool hasChosenSourceCode;
    bool isCompiled;    //if not isCompiled,

    enum Optimization{
        O1, O2, O3
    }optimizationState;

    void init();    //mem allocation
    void term();    //mem deletion

    void getDirs(QString fullPath); //获取当前路径下所有无子文件夹的文件夹的路径，即用于获取学生源代码文件夹路径

    //以下函数将用在主函数中
    QStringList set_compile_command(QString path);  //设置编译命令并返回
    QString start_compile(QString cmd); //返回编译器输出
    QStringList run_single_file(QString, QString, QString);
    bool judge_single_data(QString, QFileInfo, QFileInfo);
    bool judge_single_data(QString, QFileInfo);
    QString struced_sample(QString, QString);
};
#endif // MAINWINDOW_H

#include "progressdialog.h"
#include "ui_progressdialog.h"

#include <QDebug>

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    ui->progressBarCompile->setRange(0,0);
    ui->progressBarCompile->setMinimum(0);
    ui->progressBarCompile->setMaximum(0);
    ui->progressBarCompile->reset();
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::setRange(int max)
{
    ui->progressBarCompile->setRange(0, max);
}

void ProgressDialog::init()
{
    ui->progressBarCompile->setRange(0,0);
    ui->progressBarCompile->setMinimum(0);
    ui->progressBarCompile->setMaximum(0);
    ui->progressBarCompile->reset();
}

void ProgressDialog::setValue(int loc)
{
    ui->progressBarCompile->setValue(loc);
}

void ProgressDialog::setCurrentState(QString stu)
{
    ui->labelState->setText("当前：" + stu);
    qDebug() << "label: " << ui->labelState->text();
}

void ProgressDialog::locToProgressBar(const int& loc)
{
    setValue(loc);
    qDebug() << "loc: " << loc;
}

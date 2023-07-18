#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = nullptr);
    ~ProgressDialog();
    void setRange(int max);
    void init();
    void setValue(int loc);
    void setCurrentState(QString stu);
private:
    Ui::ProgressDialog *ui;

public slots:
    void locToProgressBar(const int& loc);
};

#endif // PROGRESSDIALOG_H

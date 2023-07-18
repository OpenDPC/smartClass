#include "mainwindow.h"
#include "progressdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ProgressDialog p;
    w.progressDialog = &p;
    QObject::connect(&w, &MainWindow::locChanged, &p, &ProgressDialog::locToProgressBar);
    w.show();
    return a.exec();
}

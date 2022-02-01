#include "mainwindow.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile stylesheet_file(":/style/style.qss");
    stylesheet_file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylesheet_file.readAll());
    app.setStyleSheet(stylesheet);


    MainWindow window;
    window.show();
    return app.exec();
}

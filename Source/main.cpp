/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#include "QtWidgets/QApplication"
#include "QtCore/QCommandLineParser"
#include "QtCore/QCommandLineOption"

#include "MainWindow.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("weiyuyijin");
    QCoreApplication::setApplicationName("WOT Loot Crate Simulator");
    QCoreApplication::setApplicationVersion("1.10");

    MainWindow window;
    window.show();
    return app.exec();
}

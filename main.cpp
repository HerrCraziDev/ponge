#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.show();

    //std::cout << "Programme lancé";

    int retval = app.exec();

    std::cout << "\n\nExecution terminated with code " << retval << ".\n";
    return retval;
}
#ifndef DEF_PONGE_MAINW
#define DEF_PONGE_MAINW

#include <QMainWindow>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QWidget>

//#include <QGraphicsView>

#include "Ponge.hpp"

class MainWindow : public QMainWindow
{
    public:
    MainWindow();
    ~MainWindow();

    private:

    QWidget *main_container;
    Ponge *scene;
    QGraphicsView *view;
};


#endif
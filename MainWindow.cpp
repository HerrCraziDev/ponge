#include "MainWindow.hpp"

MainWindow::MainWindow() : QMainWindow()
{
    main_container = new QWidget();
    main_container->setMinimumSize(600,400);
    QLayout *main_layout = new QVBoxLayout();
    main_layout->setMargin(0);
    
    /*QPalette pal(Qt::black);
    pal.setBrush(QPalette::Window, QBrush(QImage("assets/textures/ponge_menubk.png")));

    main_container->setPalette(pal);*/
    main_container->setLayout(main_layout);

    this->setCentralWidget(main_container);
    this->setWindowTitle("SUBERPONGE 9000 Preumium Edition Reloaded Xtra Gold");

    scene = new Ponge(this);
    view = new QGraphicsView(scene, this);
    view->ensureVisible(0,0,610,410,0,0);
    view->show();
    //view->setRenderHints();

    main_layout->addWidget(view);
}

MainWindow::~MainWindow() {}

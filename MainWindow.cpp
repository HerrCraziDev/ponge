#include "MainWindow.hpp"

MainWindow::MainWindow() : QMainWindow()
{
    main_container = new QWidget();
    main_container->setMinimumSize(800,600);
    QLayout *main_layout = new QVBoxLayout();
    main_layout->setMargin(0);
    
    main_container->setPalette(QPalette(Qt::black));
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

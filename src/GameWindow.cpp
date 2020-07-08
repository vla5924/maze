#include "GameWindow.h"

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Maze");
    setFixedSize(500, 500);

    player = new Player("../textures/player.svg", this);
    player->resize(50, 50);

    scene = new QGraphicsScene(this);
    playerProxy = scene->addWidget(player);
    playerProxy->setPos(50, 50);
}

GameWindow::~GameWindow()
{
}

void GameWindow::keyPressEvent(QKeyEvent* e)
{
    quint32 key = e->nativeVirtualKey();
    if (key == Qt::Key_W)
    {
        
    }
}

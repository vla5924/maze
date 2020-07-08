#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QtWidgets/QGraphicsProxyWidget>
#include "Player.h"

namespace Ui
{
    class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);
    ~GameWindow();

    void keyPressEvent(QKeyEvent* e) override;

private:
    QGraphicsScene* scene;
    QGraphicsProxyWidget* playerProxy;
    Player* player;
};

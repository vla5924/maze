#pragma once

#include <QtGui/QImage>
#include <QtSvg/QSvgWidget>

class Player : public QSvgWidget
{
public:
    Player(const char* texturePath, QWidget* parent = nullptr);
};

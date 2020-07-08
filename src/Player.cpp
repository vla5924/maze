#include "Player.h"

Player::Player(const char* texturePath, QWidget* parent)
    : QSvgWidget(texturePath, parent)
{
    //load(texturePath);
}

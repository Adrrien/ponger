#include "entities/Cup.hpp"
#include "entities/Ball.hpp"
#include <cmath>

Cup::Cup(float x, float y, float radius, sf::Color color) : Entity(x, y, radius, color) {
    this->shape.setOutlineThickness(5.f);
    this->shape.setOutlineColor(sf::Color::White);
}

Cup::~Cup() {}

bool Cup::contains(const Ball* ball) const
{
    if (!ball)
        return false;

    const sf::Vector2f distance = ball->getPosition() - this->getPosition();
    const float radiusSum = ball->getRadius() + this->getRadius();
    return (distance.x * distance.x) + (distance.y * distance.y) <= radiusSum * radiusSum;
}
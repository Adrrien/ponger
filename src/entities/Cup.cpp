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

    const float ballRadius = ball->getRadius();
    const float cupRadius = this->getRadius();
    if (cupRadius <= ballRadius)
        return false;

    const sf::Vector2f ballCenter = ball->getPosition() + sf::Vector2f(ballRadius, ballRadius);
    const sf::Vector2f cupCenter = this->getPosition() + sf::Vector2f(cupRadius, cupRadius);
    const sf::Vector2f distance = ballCenter - cupCenter;
    const float allowedDistance = cupRadius - ballRadius;
    return (distance.x * distance.x) + (distance.y * distance.y) <=
        allowedDistance * allowedDistance;
}
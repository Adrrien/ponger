#include "Entity.hpp"

Entity::Entity(float x, float y, float radius, sf::Color color) : shape(radius)
{
    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(x, y));
}

void Entity::render(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Entity::setPosition(float x, float y)
{
    shape.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Entity::getPosition() const
{
    return shape.getPosition();
}

float Entity::getRadius() const
{
    return shape.getRadius();
}

Entity::~Entity() {}

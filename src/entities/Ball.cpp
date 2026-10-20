#include "entities/Ball.hpp"

Ball::Ball(float x, float y, float radius) : Entity(x, y, radius, sf::Color::White) 
{
    this->velocity = sf::Vector2f(0, 0);
    this->isLaunched = false;
    this->slowDownFactor = 0.99f;
}

void Ball::move(sf::Window* window)
{

    // bounce off the window edges
    sf::Vector2f position = this->shape.getPosition();
    sf::Vector2u windowSize = window->getSize();
    if (position.x <= 0 || position.x >= windowSize.x)
    {
        this->velocity.x = -this->velocity.x;
    }

    if (position.y <= 0 || position.y >= windowSize.y)
    {
        this->velocity.y = -this->velocity.y;
    }

    // slow down the ball if it has been launched
    if (this->isLaunched)
    {
        this->velocity *= this->slowDownFactor;
    }    

    // apply the velocity to the ball's position
    this->shape.move(this->velocity);
}

void Ball::resetXMove()
{
    if (!this->isLaunched)
        this->velocity = sf::Vector2f(0, 0);
}

void Ball::XMove(float speed)
{
    if (!this->isLaunched)
        this->velocity.x = -speed;
}

void Ball::launch(float speed)
{
    if (!this->isLaunched)
    {
        this->isLaunched = true;
        this->velocity.y = -speed;
    }
}

Ball::~Ball() = default;
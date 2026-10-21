#include "Player.hpp"


Player::Player(sf::Window* window)
{
    this->ball = new Ball(window->getSize().x / 2, window->getSize().y - 50, 50);
    this->movingSpeed = 2.0f;
    this->launchForce = 0.2f;
    this->lauchSpeed = 0.0f;
}

Ball* Player::getBall()
{
    return this->ball;
}

void Player::left()
{
    this->ball->XMove(this->movingSpeed);
}

void Player::right()
{
    this->ball->XMove(-this->movingSpeed);
}

void Player::launch()
{
    if (this->lauchSpeed > 0.0f)
    {
        this->ball->launch(this->lauchSpeed);
        this->lauchSpeed = 0.0f;
    }
}

void Player::playerEvent(const std::optional<sf::Event>* event)
{
    if (!event)
        return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        this->left();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        this->right();
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        this->ball->resetXMove();

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        this->lauchSpeed += this->launchForce;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        this->launch();
    }
    
}

Player::~Player()
{
    delete this->ball;
}
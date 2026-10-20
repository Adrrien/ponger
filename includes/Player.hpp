#if !defined(__BALL_HPP__)
#define __BALL_HPP__
#include "entities/Ball.hpp"
#endif

class Player
{
private:
    Ball* ball;
    float movingSpeed;
    float launchForce;
    float lauchSpeed;

    void left();
    void right();
    void launch();
public:
    Player(sf::Window* window);
    ~Player();

    Ball* getBall();
    

    void playerEvent(const std::optional<sf::Event>* event);
};

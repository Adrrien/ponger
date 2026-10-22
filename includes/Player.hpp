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
    void resetBall(sf::Window* window);
public:
    Player(sf::Window* window);
    ~Player();

    Ball* getBall();
    float getLaunchProgress() const;
    

    void playerEvent(const std::optional<sf::Event>* event, sf::Window* window);
};

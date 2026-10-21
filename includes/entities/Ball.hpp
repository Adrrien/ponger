#if !defined(__SFML_ENTITY_HPP__)
#define __SFML_ENTITY_HPP__
#include <SFML/Graphics.hpp>
#endif

#if !defined(__ENTITY_HPP__)
#define __ENTITY_HPP__
#include "Entity.hpp"
#endif


class Ball : public Entity
{
private:
    sf::Vector2f velocity;
    float slowDownFactor;
    bool isLaunched;

public:
    Ball(float x, float y, float radius);
    ~Ball();

    void move(sf::Window* window);
    void resetXMove();
    void XMove(float speed);
    void launch(float speed);
};

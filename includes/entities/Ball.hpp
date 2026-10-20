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
public:
    Ball(float x, float y, float radius, sf::Color color);
    ~Ball();
};

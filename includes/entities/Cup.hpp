#if !defined(__ENTITY_HPP__)
#define __ENTITY_HPP__
#include "Entity.hpp"
#endif

class Cup : public Entity
{
public:
    Cup(float x, float y, float radius, sf::Color color);
    ~Cup();
};

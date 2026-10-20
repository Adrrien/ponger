#if !defined(__SFML_GRAPHICS_HPP__)
#define __SFML_GRAPHICS_HPP__
#include <SFML/Graphics.hpp>
#endif


class Entity
{
protected:
    sf::CircleShape shape;
public:
    Entity(float x, float y, float radius, sf::Color color);
    ~Entity();

    void render(sf::RenderWindow& window);
    void setPosition(float x, float y);
};
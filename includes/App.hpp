#if !defined(__SFML_GRAPHICS_HPP__)
#define __SFML_GRAPHICS_HPP__
#include <SFML/Graphics.hpp>
#endif

#if !defined(__ENTITY_HPP__)
#define __ENTITY_HPP__
#include "Entity.hpp"
#endif

#if !defined(__VECTOR_HPP__)
#define __VECTOR_HPP__
#include <vector>
#endif

#if !defined(__STRING_HPP__)
#define __STRING_HPP__
#include <string>
#endif

#include "Player.hpp"
#include "entities/Cup.hpp"

class App
{
private:
    sf::RenderWindow window;
    Player* player;
    std::vector<Entity* > entities;

    void entitiesDeclaration();
    void renderEntities();
    void renderPowerGauge();
    void cleanUpEntities();
    void checkWin(Cup* cup, Ball* ball);
public:
    App(std::string title, unsigned int width, unsigned int height);
    ~App();
    void run();
    void addEntity(Entity* entity);
};
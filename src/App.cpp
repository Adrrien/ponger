#include "App.hpp"

App::App(std::string title, unsigned int width, unsigned int height) : window(sf::VideoMode({width, height}), title) {}

void App::run()
{
    Ball* ball = new Ball(100, 100, 50, sf::Color::White);
    this->addEntity(ball);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        this->renderEntities();
        window.display();
    }
}

void App::cleanUpEntities()
{
    for (Entity* entity : entities)
    {
        delete entity;
    }
}


void App::renderEntities()
{
    for (Entity* entity : entities)
    {
        entity->render(window);
    }
}

void App::addEntity(Entity* entity)
{
    entities.push_back(entity);
}


App::~App() {
    this->cleanUpEntities();
}
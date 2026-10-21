#include "App.hpp"

App::App(std::string title, unsigned int width, unsigned int height) : window(sf::VideoMode({width, height}), title)
{
    this->player = new Player(&window);
}

void App::run()
{
    Cup* cup = new Cup(200, 200, 50, sf::Color::Red);
    Ball* ball = this->player->getBall();
    this->addEntity(cup);
    this->addEntity(ball);

    while (this->window.isOpen())
    {
        while (const std::optional event = this->window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                this->window.close();
            
            this->player->playerEvent(&event);
        }

        this->window.clear();
        ball->move(&this->window);
        this->renderEntities();
        this->window.display();
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
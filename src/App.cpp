#include "App.hpp"
#include <algorithm>

App::App(std::string title, unsigned int width, unsigned int height) : window(sf::VideoMode({width, height}), title)
{
    this->player = new Player(&window);
}


void App::entitiesDeclaration()
{
    this->cleanUpEntities();
    Cup* cup = new Cup(200, 200, 50, sf::Color::Red);
    Ball* ball = this->player->getBall();
    this->addEntity(cup);
    this->addEntity(ball);
}

void App::run()
{
    Cup* cup = new Cup(200, 200, 100, sf::Color::Red);
    Ball* ball = this->player->getBall();
    this->addEntity(cup);

    while (this->window.isOpen())
    {
        while (const std::optional event = this->window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                this->window.close();
            
            this->player->playerEvent(&event, &this->window);
        }

        this->window.clear();
        ball->move(&this->window);
        this->checkWin(cup, ball);
        this->renderEntities();
        ball->render(this->window);
        this->renderPowerGauge();
        this->window.display();
    }
}

void App::cleanUpEntities()
{
    for (Entity* entity : entities)
    {
        if (entity != nullptr)
            delete entity;
    }
    entities.clear();
}


void App::renderEntities()
{
    for (Entity* entity : entities)
    {
        entity->render(window);
    }
}

void App::checkWin(Cup* cup, Ball* ball)
{
    if (!cup || !ball || !cup->contains(ball))
        return;

    this->window.setTitle("Ponger - WIN!");
    ball->reset();
}

void App::renderPowerGauge()
{
    const float progress = std::clamp(this->player->getLaunchProgress(), 0.0f, 1.0f);
    const sf::Vector2f gaugeSize(300.0f, 24.0f);

    sf::RectangleShape background(gaugeSize);
    background.setPosition(sf::Vector2f(30.0f, 30.0f));
    background.setFillColor(sf::Color(50, 50, 50));
    background.setOutlineThickness(2.0f);
    background.setOutlineColor(sf::Color::White);

    sf::RectangleShape power(sf::Vector2f(gaugeSize.x * progress, gaugeSize.y));
    power.setPosition(background.getPosition());
    power.setFillColor(sf::Color::Green);

    this->window.draw(background);
    this->window.draw(power);
}

void App::addEntity(Entity* entity)
{
    entities.push_back(entity);
}


App::~App() {
    this->cleanUpEntities();
}
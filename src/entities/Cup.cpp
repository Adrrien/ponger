#include "entities/Cup.hpp"

Cup::Cup(float x, float y, float radius, sf::Color color) : Entity(x, y, radius, color) {
    this->shape.setOutlineThickness(5.f);
    this->shape.setOutlineColor(sf::Color::White);
}

Cup::~Cup() {}
#include "Entity.hpp"

Entity::Entity(/* args */)
{
    this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
    this->shape.setFillColor(sf::Color::White);
    movement_speed = 100.0f;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
    this->shape.move(dir_x * this->movement_speed * dt, dir_y * this->movement_speed * dt);
}

void Entity::update(const float &dt)
{
    
}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}

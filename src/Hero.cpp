#include "Hero.h"

Hero::Hero()
{
}
Hero::~ Hero()
{
}
void Hero::init(std::string texture_name, sf::Vector2f position, float speed)
{
    m_position = position;
    m_speed = speed;
    // Load a Texture
    m_texture.loadFromFile(texture_name.c_str());
    // Create Sprite and Attach a Texture
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
    m_sprite.setScale(4, 4);
    m_rot = 'S';
    m_x = 0;
    m_y = 0;
}

void Hero::update(float dt) {
    walk(dt);
}

void Hero::walk(float _dt) {
    if(m_rot == 'S') {
        m_y = 0;
        m_x = 0;
    }

    if (m_rot == 'U')
        m_y = -1 * m_speed * _dt;
    if (m_rot == 'D')
        m_y = m_speed * _dt;
    if (m_rot == 'L')
        m_x = -1 * m_speed * _dt;
    if (m_rot == 'R')
        m_x = m_speed * _dt;

    
    m_sprite.move(m_x, m_y);
}
void Hero::move(char rot)
{
    
    m_rot = rot;
}

sf::Sprite Hero::getSprite()
{
    return m_sprite;
}
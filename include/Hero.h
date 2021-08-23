#include "SFML/Graphics.hpp"

class Hero
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    int jump_count; // will be deleted
    float m_force;
    float m_mass;
    float m_velocity;
    const float m_gravity = 9.80f; //will be deleted
    bool m_grounded; //will be deleted

    
public:
    Hero();
    ~Hero();
    void init(std::string textureName, sf::Vector2f position, float mass);
    void update(float dt);
    void jump(float velocity);
    sf::Sprite getSprite();
};

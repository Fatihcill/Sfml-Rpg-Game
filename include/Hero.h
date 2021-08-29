#include "SFML/Graphics.hpp"

class Hero
{
    public:
        Hero();
        ~Hero();
        void init(std::string texture_name, sf::Vector2f position, float _speed);
        void update(float dt);
        void move(char rot);
        sf::Sprite getSprite();
        float m_x, m_y;
        float m_speed;

    protected:
        void walk(float _dt);
    private:

        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Vector2f m_position;
        float m_velocity;
        char m_rot;
};

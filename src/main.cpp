#include "SFML/Graphics.hpp"
#include "Hero.h"
#include "config.h"

sf::Texture background_texture;
sf::Sprite background_sprite;
Hero hero;

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello Game SFML !!!", sf::Style::Default);

void init()
{
    // Load sky Texture
    background_texture.loadFromFile("../assets/background.jpg");
    // Set and Attacha Texture to Sprite
    background_sprite.setTexture(background_texture);

    hero.init("../assets/Archer/Archer_Idle_1.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
}

void draw() {
    window.draw(background_sprite);
    window.draw(hero.getSprite());
}

void updateInput() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                hero.jump(750.0f);
            }
        }
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
        window.close();
    }
}
void update(float dt) 
{
    hero.update(dt); 
}

int main()
{
    sf::Clock clock;
    init();
    while (window.isOpen())
    {
        updateInput();
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
        window.clear(sf::Color::Red);
        draw();
        window.display();
    }
    return 0;
}
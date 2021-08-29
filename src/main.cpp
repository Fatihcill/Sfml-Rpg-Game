#include "SFML/Graphics.hpp"
#include "Hero.h"
#include "config.h"
#include "Enemy.h"

sf::Texture background_texture;
sf::Sprite background_sprite;

Hero hero;
std::vector<Enemy*> enemies;

float current_time;
float prev_time = 0.0f;


sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello Game SFML !!!", sf::Style::Default);

void spawnEnemy(){
    int randLoc = rand() % 3;
    sf::Vector2f enemyPos;
    float speed;
    switch (randLoc)
    {
    case 0:
        enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75f);
        speed = -400;
        break;
    case 1:
        enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.60f);
        speed = -550;
        break;
    case 3:
        enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.40f);
        speed = -650;
        break;
    default:
        printf("incorrect y value \n");
        return;
    }
    Enemy* enemy = new Enemy();
    enemy->init("../assets/goblin/goblin_idle_anim_f0.png", enemyPos, speed);
    enemies.push_back(enemy);
}

void init()
{
    // Load sky Texture
    background_texture.loadFromFile("../assets/background.jpg");
    // Set and Attacha Texture to Sprite
    background_sprite.setTexture(background_texture);

    hero.init("../assets/Archer/Archer_Idle_1.png", sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 500);
    srand((int)time(0));
}

void draw() {
    window.draw(background_sprite);
    window.draw(hero.getSprite());
    for (Enemy *enemy : enemies)
    {
        window.draw(enemy -> getSprite());
    }
    
}

void updateInput() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up) hero.move('U');
            if (event.key.code == sf::Keyboard::Down) hero.move('D');
            if (event.key.code == sf::Keyboard::Left) hero.move('L');
            if (event.key.code == sf::Keyboard::Right) hero.move('R');
            
        }
        if (event.type == sf::Event::KeyReleased)
            {
                hero.move('S');
            }
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
        window.close();
    }
}
void update(float dt) 
{
    hero.update(dt); 
    current_time += dt;
    if (current_time >= prev_time + 1.125f) 
    {
        spawnEnemy();
        prev_time = current_time;
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        Enemy *enemy = enemies[i];
        enemy -> update(dt);
        
        if (enemy -> getSprite().getPosition().x < 0)
        {
            enemies.erase(enemies.begin() + i);
            delete(enemy);
        }
        
    }
    
    
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
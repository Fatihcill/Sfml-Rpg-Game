#include "GameState.hpp"

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys) 
    : State(window, supportedKeys)
{
    this->initKeybinds();
}

GameState::~GameState()
{
}

void GameState::update(const float &dt)
{
    this->updateInput(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget *target)
{
    if(!target)
        target = this->window;
    
    this->player.render(this->window);
}

void GameState::endState()
{
    std::cout << "END STATE" << std::endl;
}

void GameState::updateInput(const float &dt)
{
    this->checkForQuit();


    //Update player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.0f, -1.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.0f, 1.0f);
}

void GameState::initKeybinds()
{
    std::ifstream ifs("../../config/gamestate_keybinds.ini");
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    ifs.close();
}

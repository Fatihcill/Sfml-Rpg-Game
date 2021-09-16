#include "States/GameState.hpp"


GameState::GameState(sf::RenderWindow* window) : State(window)
{
}

GameState::~GameState()
{
}

void GameState::update(const float &dt)
{
    this->updateKeybinds(dt);
    this->player.update(dt);
    
}

void GameState::render(sf::RenderTarget *target)
{
    if(target)
    {
        
    }
    else
    {
        this->player.render(this->window);
    }
}

void GameState::endState()
{
    std::cout << "END STATE" << std::endl;
}

void GameState::updateKeybinds(const float &dt)
{
    this->checkForQuit();
}
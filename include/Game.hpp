#ifndef GAME_H
#define GAME_H
#include "stdafx.hpp"
#include "States/GameState.hpp"

class Game 
{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;
    //Initialization
    void initWindow();
    void initStates();

public:
    Game();
    virtual ~Game();

    //functions
    void endApplication();
    //update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //render 
    void render();

    //core
    void run();


};
#endif
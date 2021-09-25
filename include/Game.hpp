#ifndef GAME_H
#define GAME_H
#include "stdafx.hpp"
#include "GameState.hpp"

class Game 
{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    
    std::map<std::string, int> supportedKeys;

    //Initialization
    void initWindow();
    void initStates();
    void initKeys();

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
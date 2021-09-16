#ifndef ENTITY_H
#define ENTITY_H

//Core
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <thread>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

//SFML
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Entity
{
private:


protected:
    sf::RectangleShape shape;
    float movement_speed;

public:
    Entity();
    virtual ~Entity();

    //functions
    virtual void move(const float &dt, const float dir_x, const float dir_y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};



#endif
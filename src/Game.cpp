#include <Game.hpp>

Game::Game() 
{
    this->initWindow();
    this->initStates();
}

Game::~Game() 
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    
}

void Game::endApplication() 
{
    std::cout << "Ending Application" << std::endl;
}

void Game::updateDt()   
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() 
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() 
{
    this->updateSFMLEvents();
    //Update items
    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //App end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render() 
{
    this->window->clear();
     
    //Render items
    if (!this->states.empty())
    {
        this->states.top()->render();
    }
    

    this->window->display();
}

void Game::run() 
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
    
    
}

void Game::initWindow() 
{
    std::ifstream ifs("../config/window.ini");

    std::string title = "NONE";
    sf::VideoMode window_bounds(800, 600);
    unsigned frame_limit = 120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> frame_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(sf::VideoMode(window_bounds), title);
    this->window->setFramerateLimit(frame_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initStates() 
{
    this->states.push(new GameState(this->window)); 
}

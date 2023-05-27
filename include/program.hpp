#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "state_manager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Program
{
private:
    sf::RenderWindow m_window;
    sf::View m_camera;
    sf::Clock m_clock;
    sf::Time m_previous_time;
    // Time Step Between Frames in seconds
    float m_dt;

public:
    StateManager m_state_manager;

public:
    Program();
    Program(const int frame_rate);
    ~Program();
    /**
     * Runs the game, should only be called once.
     * Contains the game loop.
     */
    void run();
    sf::RenderWindow *getWindow();
    sf::Time getPreviousTime();


private:
    void updateDeltaTime();
    /**
     * Updates the common logic based on the current state of the game.
     */
    void updateCommonLogic(const float &dt);
    /**
     * Processes individual events and inputs AFTER it is polled.
     * This needs to be inside the while(pollevents()) loop.
     * Events handled here should contain only common events regardless of gamestate.
     */
    void handleCommonEvents(const sf::Event &event);

    void drawCommonElements();
};


#endif // PROGRAM_HPP

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Bar.h"
#include <vector>
#include "Constants.h"
#include <memory>
#include "CollisionManager.h"
#include "GameState.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow app(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong XI: Tokyo Drift");       // Create the main window

    GameState game("8-bit pusab.ttf");

    Ball ball("Sprites/ball.png",WIN_WIDTH/2,WIN_HEIGHT/2);             //Setting the ball
    ball.setDirectionX(BALL_SPEED_X);


    auto blu=make_shared<Bar>("Sprites/bluBar.png",WIN_WIDTH-BAR_FROM_BORDERS,WIN_HEIGHT/2);
    auto red=make_shared<Bar>("Sprites/redBar.png",BAR_FROM_BORDERS,WIN_HEIGHT/2);


    vector<shared_ptr<PSprite>> bars;
    bars.push_back(blu);
    bars.push_back(red);

    bool z=0;
    bool s=0;
    bool up=0;
    bool down=0;

    Texture background;
    background.loadFromFile("Sprites/background.png");        //Setting the background
    Sprite sp_bg;
    sp_bg.setTexture(background);

    app.setFramerateLimit(MAX_FPS);
    app.setVerticalSyncEnabled(1);

    while (app.isOpen())
    {
        Event event;        // Process events
        while (app.pollEvent(event))
        {
            switch (event.type)                  // Event's type
            {
                case Event::Closed :                // Close button on the window
                    app.close();
                break;

                case Event::KeyPressed :            // Event key pressed
                {
                    switch (event.key.code)             // The pressed key
                    {
                        case Keyboard::Escape :             // Escape
                            app.close();
                        break;

                        case Keyboard::Up:
                            if(!game.getPaused())
                            {
                                up=1;
                            }
                        break;

                        case Keyboard::Down:                //To manage simultaneous key pressing we set booleans
                            if(!game.getPaused())                     //linked to the pressed buttons and later make movements
                            {                               //based on their values
                                down=1;
                            }
                        break;

                        case Keyboard::Z:
                            if(!game.getPaused())
                            {
                                z=1;
                            }
                        break;

                        case Keyboard::S:
                            if(!game.getPaused())
                            {
                                s=1;
                            }
                        break;

                        case Keyboard::Space:
                            game.setPaused();
                        break;

                        default:
                        break;
                    }
                }
                break;

                case Event::KeyReleased:
                {
                    switch (event.key.code)             // The released key
                    {
                        case Keyboard::Up:
                            if(!game.getPaused())                 //Stopping the movement when the keys are released
                            {
                                up=0;
                            }
                        break;

                        case Keyboard::Down:
                            if(!game.getPaused())
                            {
                                down=0;
                            }
                        break;

                        case Keyboard::Z:
                            if(!game.getPaused())
                            {
                                z=0;
                            }
                        break;

                        case Keyboard::S:
                            if(!game.getPaused())
                            {
                                s=0;
                            }
                        break;

                        default:
                        break;
                    }
                }
                break;

                default :
                break;
            }
        }

        if(game.getPaused())
        {
            z=0;                    //Stopping the movements if the game is paused
            s=0;
            up=0;
            down=0;
        }

        if(z)                               //Verifying the booleans to make movements
        {
            red->setDirectionY(-BAR_SPEED);
            red->motion();
        }

        if(s)
        {
            red->setDirectionY(BAR_SPEED);
            red->motion();
        }

        if(up)
        {
            blu->setDirectionY(-BAR_SPEED);
            blu->motion();
        }

        if(down)
        {
            blu->setDirectionY(BAR_SPEED);
            blu->motion();
        }

        if(!game.getPaused())
        {
            ball.motion(bars,game);
        }

        app.clear();        // Clear screen

        app.draw(sp_bg);
        app.draw(game.getTXTScoreBlu());
        app.draw(game.getTXTScoreRed());
        app.draw(ball);     // Draw the sprite
        app.draw(*blu);
        app.draw(*red);


        app.display();      // Update the window

    }

    return EXIT_SUCCESS;
}

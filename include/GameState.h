#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class GameState
{
    public:
        GameState(const std::string&);

        bool getPaused() const;
        bool getStarted() const;
        int getScoreBlu() const;
        int getScoreRed() const;
        sf::Text getTXTScoreBlu() const;
        sf::Text getTXTScoreRed() const;

        void setPaused();
        void setStarted();
        void setScoreBlu(const int&);
        void setScoreRed(const int&);

    private:
        bool started;
        bool paused;
        int scoreBlu;
        int scoreRed;

        sf::Font font;
        sf::Text txt_scoreBlu;
        sf::Text txt_scoreRed;
};

#endif // GAMESTATE_H

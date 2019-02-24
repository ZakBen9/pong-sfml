#include "GameState.h"
#include "Constants.h"

using namespace sf;
using namespace std;

GameState::GameState(const string& fontFile):started(0),paused(1),scoreBlu(0),scoreRed(0)
{
    font.loadFromFile(fontFile);

    txt_scoreBlu.setFont(font);
    txt_scoreBlu.setString(to_string(scoreBlu));
    txt_scoreBlu.setPosition(WIN_WIDTH-SCORE_FROM_BORDERS,SCORE_Y);

    txt_scoreRed.setFont(font);
    txt_scoreRed.setString(to_string(scoreRed));
    txt_scoreRed.setPosition(SCORE_FROM_BORDERS,SCORE_Y);
}


bool GameState::getPaused() const
{
    return paused;
}

bool GameState::getStarted() const
{
    return started;
}

int GameState::getScoreBlu() const
{
    return scoreBlu;
}

int GameState::getScoreRed() const
{
    return scoreRed;
}

Text GameState::getTXTScoreBlu() const
{
    return txt_scoreBlu;
}

Text GameState::getTXTScoreRed() const
{
    return txt_scoreRed;
}


void GameState::setPaused()
{
    paused=!paused;
}

void GameState::setStarted()
{
    started=!started;
}

void GameState::setScoreBlu(const int& score)
{
    scoreBlu=score;
    txt_scoreBlu.setString(to_string(scoreBlu));
}

void GameState::setScoreRed(const int& score)
{
    scoreRed=score;
    txt_scoreRed.setString(to_string(scoreRed));
}

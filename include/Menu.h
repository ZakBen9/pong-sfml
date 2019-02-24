#ifndef MENU_H
#define MENU_H

#include <string>
#include <SFML/Graphics.hpp>

class Menu
{
    public:
        Menu(const std::string&,const std::string&,const std::string&);
        void display(sf::RenderWindow&);


    private:
        std::string title;
        std::string subTitle;

        unsigned int opacityTitle;
        unsigned int opacitySub;

        sf::Font font;
};

#endif // MENU_H

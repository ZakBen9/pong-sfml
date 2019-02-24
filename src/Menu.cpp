#include "Menu.h"
#include "Constants.h"

using namespace std;
using namespace sf;

Menu::Menu(const std::string& fontFile,const std::string& gameTitle,const std::string& sub):opacityTitle(0),opacitySub(0)
{
    font.loadFromFile(fontFile);

    title=gameTitle;
    subTitle=sub;
}

void Menu::display(RenderWindow& app)
{
    Font instFont;
    instFont.loadFromFile("8-bit pusab.ttf");

    Text txt_title(title,font,60),txt_sub(subTitle,font,20),txt_inst("Press space to start",instFont,15);

    txt_title.setPosition(WIN_WIDTH/2-100,60);

    txt_sub.setPosition(WIN_WIDTH/2-80,130);

    txt_inst.setPosition(WIN_WIDTH/2-125,WIN_HEIGHT/2+10);

    if(opacityTitle<=255)
    {
        txt_title.setColor(Color(255,255,255,opacityTitle));
        txt_sub.setColor(Color(255,255,255,0));
        opacityTitle++;
    }

    else if(opacitySub<=255)
    {
        txt_sub.setColor(Color(255,255,255,opacitySub));
        opacitySub++;
    }

    else
    {
        app.draw(txt_inst);
    }

    app.draw(txt_title);
    app.draw(txt_sub);
}



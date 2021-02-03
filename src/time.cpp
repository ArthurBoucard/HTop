/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** time
*/

#include "time.hpp"

Time::Time()
: _name("Time")
{
    
}

Time::~Time() 
{
    
}

std::string Time::getTime() const
{
   time_t now = time(0);
   std::string dt = ctime(&now);

    size_t i = 0;
    for (char &c: dt)
    {
        if (c == ' ')
            i++;
        if (i == 3) {
            c = '\n';
            break;
        }
    }
    dt = " " + dt;
   return dt;
}

char *Time::getRawTime() const
{
    time_t now = time(0);
    char *dt = ctime(&now);

    dt[strlen(dt) - 1] = '\0';
    return dt;
}

void Time::refreshData() 
{
    
}

void Time::drawSFML(sf::RenderWindow &win, int place) 
{
    sf::RectangleShape rect(sf::Vector2f(194, 194));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");
    
    sf::Text txt("Time", font, 40);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(50, 10);

    sf::Text time_to_disp(getTime(), font, 22);
    time_to_disp.setPosition((place / 4) * 200, (place % 4) * 200);
    time_to_disp.setFillColor(sf::Color::Green);
    time_to_disp.move(17, 90);

    win.draw(rect);
    win.draw(txt);
    win.draw(time_to_disp);
}

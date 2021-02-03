/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** DisplaySFML.cpp
*/

#include "DisplaySFML.hpp"


DisplaySFML::DisplaySFML()
{
    
}

DisplaySFML::~DisplaySFML() 
{
    
}

void DisplaySFML::init() 
{
    win.create(sf::VideoMode(800, 800, 32), "MyGKrellm", sf::Style::Default);
}

void DisplaySFML::draw(IMonitorModule &mod, int place)
{
    mod.drawSFML(this->win, place);
}

bool DisplaySFML::isWindowOpen() const
{
    return win.isOpen();
}

void DisplaySFML::eventToClose(sf::Event evt) 
{
    
    while (this->win.pollEvent(evt))
    {
        if (evt.type == sf::Event::Closed)
            win.close();
    }
    win.display();
    win.clear(sf::Color::Black);
}

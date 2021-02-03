/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** DisplaySFML.hpp
*/

#ifndef __DISPLAYSFML_H__
#define __DISPLAYSFML_H__

#include "IMonitorDisplay.hpp"
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class DisplaySFML : public IMonitorDisplay
{
    private:
        sf::RenderWindow win;

    public:
        DisplaySFML();
        virtual ~DisplaySFML();

        void init();
        void draw(IMonitorModule &mod, int place);
        bool isWindowOpen() const;
        void eventToClose(sf::Event evt);
};

#endif // __DISPLAYSFML_H__
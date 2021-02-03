/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** IMonitorModule.hpp
*/

#ifndef __IMONITORMODULE_H__
#define __IMONITORMODULE_H__

#include <string>
#include <SFML/Graphics.hpp>

class IMonitorModule
{
    protected:
        IMonitorModule() {};

    public:
        virtual ~IMonitorModule() {};

        virtual void refreshData() = 0;
        virtual void drawSFML(sf::RenderWindow &win, int place) = 0;
};


#endif // __IMONITORMODULE_H__
/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** temperature.hpp
*/

#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include "IMonitorModule.hpp"
#include <string>
#include <sstream>
#include <fstream>

class Temperature : public virtual IMonitorModule
{
    private:

    public:
        Temperature();
        ~Temperature();

        std::string cpu_temp();
        std::string board_temp();
        std::string remote_temp();

        void refreshData();
        void drawSFML(sf::RenderWindow &win, int place);
};

#endif // __TEMPERATURE_H__
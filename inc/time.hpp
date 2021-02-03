/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <iostream>
#include <ctime>
#include <cstring>

#include "IMonitorModule.hpp"
#include <SFML/Graphics.hpp>


class Time : virtual public IMonitorModule {
    private:
        std::string _name;

    public:
        Time();
        ~Time();

        std::string getTime() const;
        char *getRawTime() const;
        void refreshData();
        void drawSFML(sf::RenderWindow &win, int place);
};


#endif /* !TIME_HPP_ */

/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** Hostname.hpp
*/


#ifndef __HOSTNAME_H__
#define __HOSTNAME_H__
#include <stdlib.h>
#include "IMonitorModule.hpp"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>


class Hostname : virtual public IMonitorModule
{
    private:

    protected:
        std::string _HostName;
        std::string _UserName;

    public:
        Hostname();
        ~Hostname();

        std::string getHostName();
        std::string getUserName();
        void refreshData();
        void drawSFML(sf::RenderWindow &win, int place);
};

#endif // __HOSTNAME_H__
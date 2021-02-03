/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** ram.hpp
*/

#ifndef __RAM_H__
#define __RAM_H__

#include "IMonitorModule.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

class Ram : virtual public IMonitorModule
{
    private:
    std::string _name;
        std::string mem_total;
        std::string mem_used;
        std::string mem_cache;
        std::string mem_free;
        float ratio;

    public:
        Ram();
        ~Ram();

        void refreshData();
        std::string getTotal() const {return mem_total;};
        std::string getUsed() const {return mem_used;};
        std::string getCache() const {return mem_cache;};
        std::string getFree() const {return mem_free;};
        float getRatio() const {return ratio;};
        void drawSFML(sf::RenderWindow &win, int place);
};

#endif // __RAM_H__
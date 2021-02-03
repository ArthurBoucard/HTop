/*
** EPITECH PROJECT, 2021
** CPPrush3 [WSL: Ubuntu]
** File description:
** cpu
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <iostream>
#include <algorithm>
#include "IMonitorModule.hpp"

class Cpu : virtual public IMonitorModule
{
    public:
        Cpu();
        ~Cpu();
        std::string getModel();
        std::string getRawModel();
        std::string getCores();
        std::string getThreads();
        float getUsage();

        void refreshData();
        void drawSFML(sf::RenderWindow &win, int place);

    protected:
        std::string cpu_info;
        std::string cpu_stat;
        std::string cpu_model;
        std::string cpu_cores;
        std::string cpu_threads;
        std::string _name;

        float prec_usage;
};

#endif /* !CPU_HPP_ */

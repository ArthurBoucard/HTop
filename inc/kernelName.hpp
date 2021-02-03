/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** kernelName
*/

#ifndef KERNELNAME_HPP_
#define KERNELNAME_HPP_

#include "IMonitorModule.hpp"
#include <sys/utsname.h>
#include <iostream>
#include <fstream>
#include <string>

class Kernelname : virtual public IMonitorModule
{
    private:

    protected:
        std::string _name;
        std::string _opSysName;
        std::string _kernelName;

    public:
        Kernelname();
        ~Kernelname();

        std::string getOpSysName();
        std::string getKernelName();
        void refreshData();
        void drawSFML(sf::RenderWindow &win, int place);
};

#endif /* !KERNELNAME_HPP_ */

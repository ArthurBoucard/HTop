/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** sfml.cpp
*/

#include "DisplaySFML.hpp"
#include "Hostname.hpp"
#include "time.hpp"
#include "ram.hpp"
#include "cpu.hpp"
#include "kernelName.hpp"
#include "temperature.hpp"
#include "network.hpp"

void graphic_mode()
{
    DisplaySFML disp;
    sf::Event evt;

    Time ti;
    Hostname host;
    Ram ram;
    Cpu cpu;
    Kernelname kernel;
    Temperature temp;
    Network net;

    ram.refreshData();

    disp.init();

    while (disp.isWindowOpen())
    {
        disp.draw(ti, 0);
        disp.draw(host, 1);
        disp.draw(ram, 2);
        disp.draw(kernel, 4);
        disp.draw(net, 5);
        disp.draw(temp, 10);
        disp.draw(cpu, 8);
        disp.eventToClose(evt);
    }
    
}
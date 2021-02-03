/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** DisplayNcurse.hpp
*/

#ifndef __DISPLAYNCURSE_H__
#define __DISPLAYNCURSE_H__

#include "IMonitorDisplay.hpp"
#include "time.hpp"
#include "Hostname.hpp"
#include "kernelName.hpp"
#include "cpu.hpp"
#include "ram.hpp"
#include "temperature.hpp"
#include "network.hpp"
#include <ncurses.h>
#include <cstring>

class DisplayNcurse : public IMonitorDisplay
{
    private:
        // Window *_window;
    public:
        DisplayNcurse();
        ~DisplayNcurse();

        void init();
        void draw(IMonitorModule &mod);
};

#endif // __DISPLAYNCURSE_H__
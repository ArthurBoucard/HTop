/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** IMonitorDisplay.hpp
*/

#ifndef __IMONITORDISPLAY_H__
#define __IMONITORDISPLAY_H__

#include <SFML/Graphics.hpp>
#include "IMonitorModule.hpp"

class IMonitorDisplay
{
    protected:
        IMonitorDisplay() {};
    
    public:
        virtual ~IMonitorDisplay() {};

        virtual void init() = 0;
        virtual void draw(IMonitorModule &mod, int place) = 0;
};

#endif // __IMONITORDISPLAY_H__
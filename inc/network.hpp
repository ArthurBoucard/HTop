/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** network.hpp
*/

#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "IMonitorModule.hpp"
#include <string>
#include <sstream>
#include <fstream>

class Network : virtual public IMonitorModule
{
    private:

    public:
        Network();
        ~Network();

        std::string getDownload() const;
        std::string getUpload() const;

        void refreshData();
        void drawSFML(sf::RenderWindow &win, int place);
};

#endif // __NETWORK_H__
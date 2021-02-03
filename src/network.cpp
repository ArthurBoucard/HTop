/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** network.cpp
*/

#include "network.hpp"

Network::Network() 
{
    
}

Network::~Network() 
{
    
}

std::string Network::getDownload() const
{
    std::ifstream file;
    std::string str;

    file.open("/sys/class/net/lo/statistics/rx_bytes");

    std::getline(file, str);

    return str.substr(0, 2) + "." + str[2] + "Mb";
}

std::string Network::getUpload() const
{
    std::ifstream file;
    std::string str;

    file.open("/sys/class/net/lo/statistics/tx_bytes");

    std::getline(file, str);

    return str.substr(0, 2) + "." + str[2] + "Mb";
}

void Network::refreshData() 
{
    
}

void Network::drawSFML(sf::RenderWindow &win, int place) 
{
    sf::RectangleShape rect(sf::Vector2f(194, 194));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");
    
    sf::Text txt("Network", font, 25);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(35, 10);

    sf::Text host_user(getDownload() + "\n\n\n" + getUpload(), font, 25);
    host_user.setPosition((place / 4) * 200, (place % 4) * 200);
    host_user.setFillColor(sf::Color::Cyan);
    host_user.move(50, 80);

    sf::Text titles("Download\n\n\n  Upload\n", font, 22);
    titles.setPosition((place / 4) * 200, (place % 4) * 200);
    titles.setFillColor(sf::Color::Yellow);
    titles.move(40, 50);

    win.draw(rect);
    win.draw(txt);
    win.draw(host_user);
    win.draw(titles);
}

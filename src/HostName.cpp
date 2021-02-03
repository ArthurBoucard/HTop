/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** hostName
*/

#include "Hostname.hpp"

Hostname::Hostname()
{
    
}

Hostname::~Hostname() 
{
    
}

void Hostname::refreshData() 
{
    
}

std::string Hostname::getHostName()
{
    char hostname[HOST_NAME_MAX];

    gethostname(hostname, HOST_NAME_MAX);
    std::string tmp(hostname);
    return (tmp);
}

std::string Hostname::getUserName()
{
    char username[LOGIN_NAME_MAX];

    getlogin_r(username, LOGIN_NAME_MAX);
    std::string tmp(username);
    return (tmp);
}

void Hostname::drawSFML(sf::RenderWindow &win, int place) 
{
    sf::RectangleShape rect(sf::Vector2f(194, 194));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");
    
    sf::Text txt("Host / User", font, 25);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(7, 10);

    sf::Text host_user(getHostName() + "\n\n\n\n\n" + getUserName(), font, 15);
    host_user.setPosition((place / 4) * 200, (place % 4) * 200);
    host_user.setFillColor(sf::Color::Cyan);
    host_user.move(10, 80);

    sf::Text titles("Host\n\n\nUser\n", font, 22);
    titles.setPosition((place / 4) * 200, (place % 4) * 200);
    titles.setFillColor(sf::Color::Yellow);
    titles.move(55, 50);

    win.draw(rect);
    win.draw(txt);
    win.draw(host_user);
    win.draw(titles);
}
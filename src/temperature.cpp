/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** temperature.cpp
*/

#include "temperature.hpp"

Temperature::Temperature() 
{
    
}

Temperature::~Temperature() 
{
    
}

std::string Temperature::cpu_temp() 
{
    std::ifstream file;
    std::string str;

    file.open("/sys/class/thermal/thermal_zone0/temp");

    std::getline(file, str);

    return str.substr(0, 2) + "." + str[2];
}

std::string Temperature::board_temp() 
{
    std::ifstream file;
    std::string str;

    file.open("/sys/class/thermal/thermal_zone1/temp");

    std::getline(file, str);

    return str.substr(0, 2) + "." + str[2];
}

std::string Temperature::remote_temp() 
{
    std::ifstream file;
    std::string str;

    file.open("/sys/class/thermal/thermal_zone2/temp");

    std::getline(file, str);

    return str.substr(0, 2) + "." + str[2];
}

void Temperature::refreshData() 
{
    
}

void Temperature::drawSFML(sf::RenderWindow &win, int place) 
{
    
    sf::RectangleShape rect(sf::Vector2f(394, 194));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");
    
    sf::Text txt("Temperature", font, 30);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(90, 10);

    sf::Text titles("CPU\t\tBoard\t\tRemote", font, 22);
    titles.setPosition((place / 4) * 200, (place % 4) * 200);
    titles.setFillColor(sf::Color::Yellow);
    titles.move(20, 70);

    sf::Text Kernel(cpu_temp() + " C\t\t" + board_temp() + " C\t\t" + remote_temp() + " C", font, 25);
    Kernel.setPosition((place / 4) * 200, (place % 4) * 200);
    Kernel.setFillColor(sf::Color::Cyan);
    Kernel.move(5, 120);

    win.draw(rect);
    win.draw(txt);
    win.draw(titles);
    win.draw(Kernel);
}

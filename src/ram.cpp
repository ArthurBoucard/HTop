/*
** EPITECH PROJECT, 2020
** Rush3
** File description:
** ram.cpp
*/

#include "ram.hpp"

Ram::Ram() 
{
    
}

Ram::~Ram() 
{
    
}

void Ram::refreshData() 
{
    std::ifstream file;
    std::stringstream stream;
    std::string str;

    system("free -h > tt");
    file.open("tt");
    if (!file.is_open())
        return;
    stream << file.rdbuf();
    str = stream.str();

    str = str.substr(str.find("Mem:") + 4);
    str = str.substr(0, str.find("\n"));
    str.erase(std::unique(str.begin(), str.end()), str.end());
    str = str.substr(1);
    for (char &c : str)
    {
        if (c == ' ')
            c = ':';
        if (c == ',')
            c = '.';
    }

    this->mem_total = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);

    this->mem_used = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);
    str = str.substr(str.find(':') + 1);
    str = str.substr(str.find(':') + 1);

    this->mem_cache = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);

    this->mem_free = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);

    this->ratio = (std::stof(mem_total) - std::stof(mem_free)) / std::stof(mem_total);
}

void Ram::drawSFML(sf::RenderWindow &win, int place) 
{
    refreshData();

    sf::RectangleShape rect(sf::Vector2f(394, 394));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");

    sf::Text txt("RAM", font, 40);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(150, 10);


    sf::Text titles("Total\n\nUsed\n\nCache\n\nFree", font, 30);
    titles.setPosition((place / 4) * 200, (place % 4) * 200);
    titles.setFillColor(sf::Color::Magenta);
    titles.move(20, 80);


    sf::Text mem(mem_total + "\n\n\n" + mem_used + "\n\n\n" + mem_cache + "\n\n\n" + mem_free, font, 20);
    mem.setPosition((place / 4) * 200, (place % 4) * 200);
    mem.setFillColor(sf::Color::Red);
    mem.move(50, 120);

    sf::RectangleShape hover(sf::Vector2f(70, 200));
    hover.setPosition((place / 4) * 200, (place % 4) * 200);
    hover.move(250, 90);
    hover.setFillColor(sf::Color::Transparent);
    hover.setOutlineColor(sf::Color::White);
    hover.setOutlineThickness(2);

    sf::RectangleShape percet;
    percet.setOrigin(0, this->ratio * 200);
    percet.setSize(sf::Vector2f(70, this->ratio * 200));
    percet.setPosition((place / 4) * 200, (place % 4) * 200);
    percet.move(250, 290);
    percet.setFillColor(sf::Color((int)(ratio * 256), (int)((1 / ratio) * 256), 0, 255));


    sf::Text percet_num(std::to_string((int)(ratio * 100)), font, 35);
    percet_num.setPosition((place / 4) * 200, (place % 4) * 200);
    percet_num.setFillColor(sf::Color((int)(ratio * 256), (int)((1 / ratio) * 256), 0, 255));
    percet_num.move(260, 320);

    win.draw(rect);
    win.draw(titles);
    win.draw(txt);
    win.draw(mem);
    win.draw(hover);
    win.draw(percet);
    win.draw(percet_num);
}

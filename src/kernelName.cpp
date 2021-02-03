/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** kernelName
*/

#include "kernelName.hpp"

Kernelname::Kernelname()
{
}

Kernelname::~Kernelname()
{
}

std::string Kernelname::getOpSysName()
{
    struct utsname sysinfo;

    if (uname(&sysinfo) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    std::string opsysname(sysinfo.sysname);
    return (opsysname);
}

std::string Kernelname::getKernelName()
{
    std::ifstream file("/proc/version");
    std::string version;
    std::string tmp;

    if (file) {
        while (getline(file, tmp))
            version += tmp;
        return (version);
    } else {
        perror("cat /proc/version");
        return (NULL); 
    }
}

void Kernelname::refreshData() 
{
    
}

void Kernelname::drawSFML(sf::RenderWindow &win, int place) 
{
    sf::RectangleShape rect(sf::Vector2f(194, 194));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");
    
    sf::Text txt("Machine", font, 30);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(20, 10);

    sf::Text host_user(getKernelName(), font, 8);
    host_user.setPosition((place / 4) * 200, (place % 4) * 200);
    host_user.setFillColor(sf::Color::Cyan);
    host_user.move(5, 90);

    sf::Text titles("Kernel\n\n\nSystem\n", font, 22);
    titles.setPosition((place / 4) * 200, (place % 4) * 200);
    titles.setFillColor(sf::Color::Yellow);
    titles.move(55, 50);

    sf::Text Kernel(getOpSysName(), font, 20);
    Kernel.setPosition((place / 4) * 200, (place % 4) * 200);
    Kernel.setFillColor(sf::Color::Cyan);
    Kernel.move(70, 160);

    win.draw(rect);
    win.draw(txt);
    win.draw(host_user);
    win.draw(titles);
    win.draw(Kernel);
}
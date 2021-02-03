/*
** EPITECH PROJECT, 2021
** CPPrush3 [WSL: Ubuntu]
** File description:
** cpu
*/

#include "cpu.hpp"

Cpu::Cpu()
: prec_usage(1)
{
    std::ifstream cpu("/proc/cpuinfo");
    std::ifstream stat("/proc/stat");

    cpu_info.assign((std::istreambuf_iterator<char>(cpu)), (std::istreambuf_iterator<char>()));
    cpu_stat.assign((std::istreambuf_iterator<char>(stat)), (std::istreambuf_iterator<char>()));
}

Cpu::~Cpu()
{

}

std::string Cpu::getRawModel()
{
    cpu_model = cpu_info.substr(
        cpu_info.find("model name") + 13,
        cpu_info.find("\n", cpu_info.find("model name")) -
        cpu_info.find("model name") - 13
    );
    return cpu_model;
}

std::string Cpu::getModel()
{
    cpu_model = cpu_info.substr(
        cpu_info.find("model name") + 13,
        cpu_info.find("\n", cpu_info.find("model name")) -
        cpu_info.find("model name") - 13
    );
    
    cpu_model = cpu_model.substr(0, cpu_model.find("(TM)") + 4) + "\n" + cpu_model.substr(cpu_model.find("(TM)") + 6);

    return cpu_model;
}

std::string Cpu::getCores()
{
    cpu_cores = cpu_info.substr(
        cpu_info.find("cpu cores") + 12,
        cpu_info.find("\n", cpu_info.find("cpu cores")) -
        cpu_info.find("cpu cores") - 12);
    return cpu_cores;
}

std::string Cpu::getThreads()
{
    cpu_threads = cpu_info.substr(
        cpu_info.find("siblings") + 11,
        cpu_info.find("\n", cpu_info.find("siblings")) -
        cpu_info.find("siblings") - 11
    );
    return cpu_threads;
}

float Cpu::getUsage()
{
    float usage = 0.0f;

    std::ifstream file;
    std::string str;

    file.open("/proc/stat");

    std::getline(file, str);

    // for (int i = 1; i < std::stof(getThreads()); i++) {
    //     str = str.substr(5);
    //     usage += std::stof(str.substr(0, str.find(' ')));
    // }
    
    if (usage == prec_usage)
        return usage;
    usage = (usage / prec_usage) * 100;
    prec_usage = usage;
    return usage;
}

void Cpu::refreshData() 
{
    
}

void Cpu::drawSFML(sf::RenderWindow &win, int place) 
{
    
    sf::RectangleShape rect(sf::Vector2f(394, 394));
    rect.setPosition((place / 4) * 200, (place % 4) * 200);
    rect.move(3, 3);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);

    sf::Font font;
    font.loadFromFile("Gameplay.ttf");

    sf::Text txt("Monitor Core", font, 40);
    txt.setPosition((place / 4) * 200, (place % 4) * 200);
    txt.setFillColor(sf::Color::White);
    txt.move(40, 10);


    sf::Text titles("Cores\tThreads\tUsage", font, 22);
    titles.setPosition((place / 4) * 200, (place % 4) * 200);
    titles.setFillColor(sf::Color::Cyan);
    titles.move(25, 90);


    sf::Text mem(getCores() + "\t\t\t" + getThreads() + "\t\t\t" + std::to_string(getUsage()), font, 30);
    mem.setPosition((place / 4) * 200, (place % 4) * 200);
    mem.setFillColor(sf::Color::Green);
    mem.move(50, 140);


    sf::Text titles2("Model", font, 35);
    titles2.setPosition((place / 4) * 200, (place % 4) * 200);
    titles2.setFillColor(sf::Color::Yellow);
    titles2.move(140, 250);


    sf::Text model(getModel(), font, 20);
    model.setPosition((place / 4) * 200, (place % 4) * 200);
    model.setFillColor(sf::Color::Green);
    model.move(50, 320);

    win.draw(rect);
    win.draw(titles);
    win.draw(txt);
    win.draw(mem);
    win.draw(titles2);
    win.draw(model);
}

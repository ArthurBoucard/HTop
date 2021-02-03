/*
** EPITECH PROJECT, 2021
** CPPrush3 [WSL: Ubuntu]
** File description:
** main
*/

#include "lib.hpp"
#include <string>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        if (std::string(av[1]) == "terminal")
            terminal_mode();
        else if (std::string(av[1]) == "graphic")
            graphic_mode();
    }
    return 0;
}
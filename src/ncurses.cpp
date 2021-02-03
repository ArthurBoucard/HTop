/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ncurses
*/

#include "DisplayNcurse.hpp"

DisplayNcurse::DisplayNcurse()
{
}

DisplayNcurse::~DisplayNcurse()
{
}

void DisplayNcurse::init()
{
}

void net_window(Network &_net)
{
    //Net download
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(3, ((COLS / 5) * 4) + 1, "Download:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(4, ((COLS / 5) * 4) + 4, _net.getDownload().c_str());
    attroff(COLOR_PAIR(4));
    //Net upload
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(6, ((COLS / 5) * 4) + 1, "Upload:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(7, ((COLS / 5) * 4) + 4, _net.getUpload().c_str());
    attroff(COLOR_PAIR(4));
    //Net window
    attron(A_REVERSE);
    attron(COLOR_PAIR(1));
    mvprintw(1, ((COLS / 5) * 4) + ((COLS / 5) / 2) - strlen(" NET "), " NET ");
    attroff(COLOR_PAIR(1));
    attroff(A_REVERSE);
}

void temp_window(Temperature &_temp)
{
    //Temperature CPU
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(3, ((COLS / 5) * 3) + 1, "Cpu temperature:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(3));
    mvprintw(4, ((COLS / 5) * 3) + 4, (_temp.cpu_temp() + "°C").c_str());
    attroff(COLOR_PAIR(3));
    //Temperature board
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(6, ((COLS / 5) * 3) + 1, "Board temperature:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(3));
    mvprintw(7, ((COLS / 5) * 3) + 4, (_temp.board_temp() + "°C").c_str());
    attroff(COLOR_PAIR(3));
    //Temperature remote
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(9, ((COLS / 5) * 3) + 1, "Remote temperature:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(3));
    mvprintw(10, ((COLS / 5) * 3) + 4, (_temp.remote_temp() + "°C").c_str());
    attroff(COLOR_PAIR(3));
    //Temperature window
    WINDOW *net_win;
    net_win = subwin(stdscr, 0, (COLS / 5) * 4, 0, 0);
    wborder(net_win, '|', '|', '-', '-', '+', '+', '+', '+');
    attron(A_REVERSE);
    attron(COLOR_PAIR(1));
    mvprintw(1, ((COLS / 5) * 3) + ((COLS / 5) / 2) - (strlen(" TEMPERATURE ") / 2), " TEMPERATURE ");
    attroff(COLOR_PAIR(1));
    attroff(A_REVERSE);
}

void cpu_window(Cpu &_cpu)
{
    //Cpu Cores
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(3, (COLS / 5) + 1, "Cores:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(4, (COLS / 5) + 4, _cpu.getCores().c_str());
    attroff(COLOR_PAIR(4));
    //Cpu Model
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(6, (COLS / 5) + 1, "Model:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(7, (COLS / 5) + 4, _cpu.getRawModel().c_str());
    attroff(COLOR_PAIR(4));
    //Cpu Threads
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(9, (COLS / 5) + 1, "Threads:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(10, (COLS / 5) + 4, _cpu.getThreads().c_str());
    attroff(COLOR_PAIR(4));
    //Cpu Usage
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(12, (COLS / 5) + 1, "Usage:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(13, (COLS / 5) + 4, (std::to_string((int)(_cpu.getUsage() * 100)) + " %\n").c_str());
    attroff(COLOR_PAIR(4));
    //Cpu window
    WINDOW *cpu_win;
    cpu_win = subwin(stdscr, 0, (COLS / 5) + (COLS / 5), 0, 0);
    wborder(cpu_win, '|', '|', '-', '-', '+', '+', '+', '+');
    attron(A_REVERSE);
    attron(COLOR_PAIR(1));
    mvprintw(1, (COLS / 5) + ((COLS / 5) / 2) - (strlen(" MONITOR CORE ") / 2), " MONITOR CORE ");
    attroff(COLOR_PAIR(1));
    attroff(A_REVERSE);
}

void user_window(Hostname &_host, Kernelname &_kernel)
{
    //Hostname
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(3, 1, "Hostname:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(4, 4, _host.getHostName().c_str());
    attroff(COLOR_PAIR(4));
    //getUserName
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(6, 1, "User:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(7, 4, _host.getUserName().c_str());
    attroff(COLOR_PAIR(4));
    //Operating system
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(9, 1, "OS:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(4));
    mvprintw(10, 4, _kernel.getOpSysName().c_str());
    attroff(COLOR_PAIR(4));
    //Kernel
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(12, 1, "Kernel:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    // Parse Kernel name
    std::string temp = _kernel.getKernelName();
    size_t pos;
    for(int i = 0; i < 4; i++) {
        pos = temp.find(" (");
        temp.replace(pos, 1, "\n(");
    }
    attron(COLOR_PAIR(4));
    mvprintw(13, 4, temp.c_str());
    attroff(COLOR_PAIR(4));
    //User window
    WINDOW *user;
    user = subwin(stdscr, 0, COLS / 5, 0, 0);
    wborder(user, '|', '|', '-', '-', '+', '+', '+', '+');
}

void main_window(WINDOW *window)
{
    //Window Interface
    window = subwin(stdscr, 0, 0, 0, 0);
    wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
    //Title
    attron(A_REVERSE);
    attron(COLOR_PAIR(1));
    mvprintw(0, ((COLS / 5) * 2) + ((COLS / 5) / 2) - 8, " MyGKrellM ");
    attroff(COLOR_PAIR(1));
    attroff(A_REVERSE);
}

void live_update(Time &t, Ram &ram)
{
    //Time
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(1, 1, t.getRawTime());
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);
    //Ram Total
    ram.refreshData();
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(3, ((COLS / 5) * 2) + 1, "Mem total:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(5));
    mvprintw(4, ((COLS / 5) * 2) + 4, ram.getTotal().c_str());
    attroff(COLOR_PAIR(5));
    attron(A_UNDERLINE);
    //Ram Used
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(6, ((COLS / 5) * 2) + 1, "Mem used:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(5));
    mvprintw(7, ((COLS / 5) * 2) + 4, ram.getUsed().c_str());
    attroff(COLOR_PAIR(5));
    attron(A_UNDERLINE);
    //Ram Cache
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(9, ((COLS / 5) * 2) + 1, "Mem cache:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(5));
    mvprintw(10, ((COLS / 5) * 2) + 4, ram.getCache().c_str());
    attroff(COLOR_PAIR(5));
    attron(A_UNDERLINE);
    //Ram free
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(12, ((COLS / 5) * 2) + 1, "Mem free:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(5));
    mvprintw(13, ((COLS / 5) * 2) + 4, ram.getFree().c_str());
    attroff(COLOR_PAIR(5));
    //Ram ratio
    attron(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(15, ((COLS / 5) * 2) + 1, "Mem ratio:");
    attroff(COLOR_PAIR(2));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(5));
    mvprintw(16, ((COLS / 5) * 2) + 4, (std::to_string((int)(ram.getRatio() * 100)) + " %\n").c_str());
    attroff(COLOR_PAIR(5));
    attron(A_UNDERLINE);
    //Ram window
    WINDOW *cpu_win;
    cpu_win = subwin(stdscr, 0, (COLS / 5) * 3, 0, 0);
    wborder(cpu_win, '|', '|', '-', '-', '+', '+', '+', '+');
    attron(A_REVERSE);
    attron(COLOR_PAIR(1));
    mvprintw(1, ((COLS / 5) * 2) + ((COLS / 5) / 2) - strlen(" RAM "), " RAM ");
    attroff(COLOR_PAIR(1));
    attroff(A_REVERSE);
}

void DisplayNcurse::draw(IMonitorModule &mod)
{
    (void)mod;
    WINDOW *_window;
    Time _time;
    Hostname _host;
    Kernelname _kernel;
    Cpu _cpu;
    Ram _ram;
    Temperature _temp;
    Network _net;
    int pressed_key = 0;

    noecho();
    cbreak();
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    nodelay(stdscr, TRUE);
    do {
        user_window(_host, _kernel);
        cpu_window(_cpu);
        temp_window(_temp);
        net_window(_net);
        live_update(_time, _ram);
        main_window(_window);
        refresh();
    } while ((pressed_key = getch()) != 113);
    endwin();
}

void terminal_mode()
{
    IMonitorModule *i;
    DisplayNcurse *n;
    n->draw(*i);
}
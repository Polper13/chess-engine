#include <iostream>
#include <sstream>

#include "uci.h"
#include "engineInfo.h"

void UCI::run()
{
    while (true) // main bot loop
    {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if      (command == "uci")        { handleUCI(); }
        else if (command == "isready")    { handleIsReady(); }
        else if (command == "ucinewgame") { handleNewGame(); }
        else if (command == "position")   { handlePosition(); }
        else if (command == "go")         { handleGo(line); }
        else if (command == "quit")       { break; }
    }

}

void UCI::handleUCI()
{
    std::cout << "id name " << ENGINE_NAME << "\n";
    std::cout << "id author " << ENGINE_AUTHOR << "\n";
    std::cout << "uciok" << std::endl;
}

void UCI::handleIsReady()
{
    std::cout << "readyok" << std::endl;
}

void UCI::handleNewGame()
{
    // TODO: reset board state
}

void UCI::handlePosition()
{
    // TODO: play actually
}

void UCI::handleGo(std::string line)
{
    // TODO: run search, output result
    std::cout << "bestmove e7e5" << std::endl;
}
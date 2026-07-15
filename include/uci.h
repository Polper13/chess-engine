#pragma once

#include <string>

class UCI
{
public:
    void run();

private:
    void handleUCI();
    void handleIsReady();
    void handleNewGame();
    void handlePosition();
    void handleGo(std::string line);
};
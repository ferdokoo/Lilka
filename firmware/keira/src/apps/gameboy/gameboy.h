#pragma once
#include "app.h"

class GameBoyApp : public App {
public:
    explicit GameBoyApp(String path);
    ~GameBoyApp();

private:
    void run();

    char* argv[1];
};

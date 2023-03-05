#include "TTT/TTT.hpp"

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE  "Sandbox"

int main()
{
    TTT::Window::verbose                      = true;
    TTT::Window::toggleFPS                    = true;
    TTT::Window::shouldCreateDefaultEventLoop = true;

    TTT::Window ttt(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    return 0;
}

#include "TTT/TTT.hpp"

#include <string>

constexpr int WINDOW_WIDTH         = 1280;
constexpr int WINDOW_HEIGHT        = 720;
constexpr std::string WINDOW_TITLE = "TTT";

int main()
{
    TTT::Window::verbose                      = true;
    TTT::Window::toggleFPS                    = true;
    TTT::Window::shouldCreateDefaultEventLoop = true;

    TTT::Window::defaultEventLoopFontFilename = "sandbox/resources/fonts/04B_30__.TTF";

    TTT::Window ttt(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    return 0;
}

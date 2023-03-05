#include "include/TTT/TTT.hpp"

#include <iostream>
#include <fstream>

namespace TTT
{
    const module Log::TTT = "TTT";

    const module Log::WINDOW = "WINDOW";
    const module Log::UTILS  = "UTILS";
    const module Log::LOG    = "LOG";
    const module Log::SFML   = "SFML";

    const level Log::SUCCESS  = "SUCCESS";
    const level Log::INFO     = "INFO";
    const level Log::WARNING  = "WARNING";
    const level Log::ERROR    = "ERROR";
    const level Log::CRITICAL = "CRITICAL";

    const color Log::RESET    = "\033[0m";
    const color Log::RED      = "\033[31m";
    const color Log::GREEN    = "\033[32m";
    const color Log::WHITE    = "\033[37m";
    const color Log::L_RED    = "\033[91m";
    const color Log::L_YELLOW = "\033[93m";

    const std::string currentTime()
    {
        time_t now = time(0);
        struct tm    tstruct;
        char         buf[80];
        tstruct    = *localtime(&now);

        strftime(buf, sizeof(buf), "%X", &tstruct);

        return buf;
    }

    std::fstream logFile;

    void Log::log(module module, level level, std::string message)
    {
        logFile.open("TTT.log", logFile.app);

        logFile << "TTT - [" << module << " | " << level << "] (" << currentTime() << "): " << message << std::endl;

        if (Window::verbose)
        {
            if (level == Log::SUCCESS)
                std::cout << Log::GREEN    << "TTT - [" << module << " | " << level << "] (" << currentTime() << "): " << message << Log::RESET << std::endl;
            else if (level == Log::INFO)
                std::cout << Log::WHITE    << "TTT - [" << module << " | " << level << "] (" << currentTime() << "): " << message << Log::RESET << std::endl;
            else if (level == Log::WARNING)
                std::cout << Log::L_YELLOW << "TTT - [" << module << " | " << level << "] (" << currentTime() << "): " << message << Log::RESET << std::endl;
            else if (level == Log::ERROR)
                std::cout << Log::L_RED    << "TTT - [" << module << " | " << level << "] (" << currentTime() << "): " << message << Log::RESET << std::endl;
            else if (level == Log::CRITICAL)
                std::cout << Log::RED      << "TTT - [" << module << " | " << level << "] (" << currentTime() << "): " << message << Log::RESET << std::endl;
        }

        logFile.close();
    }
}

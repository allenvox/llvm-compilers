#include <iostream>
#include <string>

extern void loggerLog(const std::string& msg);

int main()
{
    loggerLog("Program started");
    return 0;
}

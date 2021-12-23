#include <game.hpp>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int main()
{
    gm::ReGame();
    return 0;
}
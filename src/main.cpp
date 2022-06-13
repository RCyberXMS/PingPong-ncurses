#include "kernel.h"

int main(void) {
    SCENE::Main_Menu * menu;
    SCENE::Game * game;
    SCENE::Manuals * manual;

    SCENE::windows.emplace_back(menu);
    SCENE::windows.emplace_back(manual);
    SCENE::windows.emplace_front(game);

    return EXIT_SUCCESS;
}
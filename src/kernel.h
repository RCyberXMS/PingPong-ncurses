#ifndef kernel_h
#define kernel_h
#include <deque>
#include <curses.h>
#include <ncurses.h>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

namespace SCENE {
    class Scene {
        virtual void load() = 0;
        virtual void exit() = 0;
        virtual ~Scene() = default;
    };

    class Game : public Scene {
        public:
            void load() override;
            void exit() override;
            ~Game() override = default;
    };

    class Main_Menu : public Scene {
        public:
            void load() override;
            void exit() override;
            ~Main_Menu() override = default;
            
    };

    class Manuals : public Scene {
        public:
            void load() override;
            void exit() override;
            ~Manuals() override = default;
    };

    extern std::deque<Scene *> windows;
}

#endif /* kernel_h */
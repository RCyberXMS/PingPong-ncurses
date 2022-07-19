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

typedef unsigned short int USI;
typedef unsigned long long ULLI;
typedef unsigned int UI;
typedef const unsigned short int CUSI; 

namespace SCENE {
    extern USI game_speed; 
    class Scene {
        protected:
            virtual void Load() = 0; 
            virtual void Exit() = 0;
            virtual ~Scene() = default;

            const std::string menu_selections[3] = {"❒ Singleplayer", "❒ Multiplayer", "❒ Exit"};
            
    };

    class Menu : public Scene {
        protected:
            void Load() override; 
            void Exit() override;
            virtual ~Menu() = default;
    };

    class Game : public Scene { 
        protected:
            void Load() override;
            void Exit() override;
            virtual ~Game() = default;
        
        public:
            bool is_multiplayer(USI & s) {
                switch (s) {
                    case 0: return false;
                    default: return true;
                }
            };
    };

    class PreGame : public Scene {
        protected:
            void Load() override;
            void Exit() override;
            virtual ~PreGame() = default;
    };
}


namespace PLAYER {
    class Player {
        protected:
            typedef struct State {
                std::pair<USI, CUSI> cordinate; 
                bool lost = false;
                bool is_player = true; 
                size_t score = 0;
            } State; 
            virtual void Move() =  0;
            virtual ~Player() = default;
    };

    class Player_1 : public Player {
        protected:
            void Move() override;
            virtual ~Player_1() = default;
    };

    class Player_2 : public Player {
        protected:
            void Move() override;
            virtual ~Player_2() = default;
    };
}


#endif /* kernel_h */
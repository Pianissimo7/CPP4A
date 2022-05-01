#include <string>
#include <vector>
#pragma once

namespace coup {
    class Game {
        public:
            Game();
            ~Game();
            std::string Turn = "";
            std::vector<std::string> Players;
            std::string turn();
            std::vector<std::string> players();
            void add_player(std::string name);
    };
}
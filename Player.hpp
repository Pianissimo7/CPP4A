#include <string>
#pragma once

namespace coup {
    class Player {
        public:
            Player(std::string role_name);
            ~Player();
            
            int balance = 0;
            std::string role_name = "";
            
            int coins();
            std::string role();
            void income();
            void foreign_aid();
            void coup(Player p);
    };
}
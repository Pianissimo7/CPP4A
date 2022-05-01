#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace coup {
    class Duke : public Player {
        public:
            Duke(Game game, std::string name);
            ~Duke();
            
            void tax();
            void block(Player p1);
    };
}
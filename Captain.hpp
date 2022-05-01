#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace coup {
    class Captain : public Player {
        public:
            Captain(Game game, std::string name);
            ~Captain();
            
            void steal(Player p1);
            void block(Player p1);

    };
}
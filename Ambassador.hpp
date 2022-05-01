#include <string>
#include "Player.hpp"

namespace coup {
    class Ambassador : public Player {
        public:
            Ambassador(Game game, std::string name);
            ~Ambassador();
            
            void transfer(Player p1, Player p2);
            void block(Player p1);
    };
}
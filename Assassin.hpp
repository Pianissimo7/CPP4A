#include <string>
#include "Player.hpp"

namespace coup {
    class Assassin : public Player {
        public:
            Assassin(Game game, std::string name);
            ~Assassin();
            
            void coup(Player p1);
    };
}
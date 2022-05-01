#include "Captain.cpp"

namespace coup {
    class Captain : public Player {
        public:
            Captain(Game game, std::string name);
            ~Captain();
            
            void steal(Player p1);
            void block(Player p1);

    };
}
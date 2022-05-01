#include "Duke.cpp"

namespace coup {
    class Duke : public Player {
        public:
            Duke(Game game, std::string name);
            ~Duke();
            
            void tax();
            void block(Player p1);
    };
}
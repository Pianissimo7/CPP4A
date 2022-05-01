#include "Contessa.cpp"

namespace coup {
    class Contessa : public Player {
        public:
            Contessa(Game game, std::string name);
            ~Contessa();
            
            void block(Player p1);
    };
}
#include "Game.cpp"

namespace coup {
    class Player {
        public:
            Game();
            ~Game();
            string turn = "";
            vector<string> players;
            string turn();
            vector<string> players();
            void add_player(string name);
    }
}
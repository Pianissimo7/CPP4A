#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace std;
using namespace zich;

TEST_CASE("players join the game")
{
    
    SUBCASE("players join as normal, should not throw")
    {
        Game game_1{};
        CHECK_NOTHROWS(Duke duke{game_1, "Moshe"});
	    CHECK_NOTHROWS(Assassin assassin{game_1, "Yossi"});
	    CHECK_NOTHROWS(Ambassador ambassador{game_1, "Meirav"});
	    CHECK_NOTHROWS(Captain captain{game_1, "Reut"});
	    CHECK_NOTHROWS(Contessa contessa{game_1, "Gilad"});
    }

    SUBCASE("multiple of the same class join")
    {
        Game game_1{};
        CHECK_NOTHROWS(Duke duke{game_1, "Moshe1"});
        CHECK_NOTHROWS(Duke duke{game_1, "Moshe2"});
	    CHECK_NOTHROWS(Assassin assassin{game_1, "Yossi1"});
        CHECK_NOTHROWS(Assassin assassin{game_1, "Yossi2"});
	    CHECK_NOTHROWS(Ambassador ambassador{game_1, "Meirav1"});
        CHECK_NOTHROWS(Ambassador ambassador{game_1, "Meirav2"});
	    CHECK_NOTHROWS(Captain captain{game_1, "Reut1"});
        CHECK_NOTHROWS(Captain captain{game_1, "Reut2"});
	    CHECK_NOTHROWS(Contessa contessa{game_1, "Gilad1"});
        CHECK_NOTHROWS(Contessa contessa{game_1, "Gilad2"});
    }
    SUBCASE("a player with no name joins")
    {
        Game game_1{};
        CHECK_NOTHROWS(Contessa contessa{game_1, ""});
    }
}

TEST_CASE("BAD INPUT")
{
    SUBCASE("")
    {   
        CHECK_THROWS();
        CHECK_NOTHROWS();
    }
}
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
        CHECK_NOTHROWS(Duke duke1{game_1, "Moshe1"});
        CHECK_NOTHROWS(Duke duke2{game_1, "Moshe2"});
	    CHECK_NOTHROWS(Assassin assassin1{game_1, "Yossi1"});
        CHECK_NOTHROWS(Assassin assassin2{game_1, "Yossi2"});
	    CHECK_NOTHROWS(Ambassador ambassador1{game_1, "Meirav1"});
        CHECK_NOTHROWS(Ambassador ambassador2{game_1, "Meirav2"});
	    CHECK_NOTHROWS(Captain captain1{game_1, "Reut1"});
        CHECK_NOTHROWS(Captain captain2{game_1, "Reut2"});
	    CHECK_NOTHROWS(Contessa contessa1{game_1, "Gilad1"});
        CHECK_NOTHROWS(Contessa contessa2{game_1, "Gilad2"});
    }
    SUBCASE("a player with no name joins")
    {
        Game game_1{};
        CHECK_NOTHROWS(Contessa contessa{game_1, ""});
    }
}
TEST_CASE("correct turn cycle") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());
    // now playing the actual turn
    CHECK_NOTHROWS(duke.income());
    // check the turn had passed
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(duke.income());
    // now playing the actual turn
    CHECK_NOTTHROWS(assassin.income());
    // check the turn had passed
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(duke.income());
    CHECK_THROWS(assassin.income());
    // now playing the actual turn
    CHECK_NOTHROWS(ambassador.income());
    // check the turn had passed
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(duke.income());
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    // now playing the actual turn
    CHECK_NOTHROWS(captain.income());
    // check the turn had passed
    CHECK_THROWS(duke.income());
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    // now playing the actual turn
    CHECK_NOTHROWS(contessa.income());
    // check the turn had passed
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());
    // now playing the actual turn
    CHECK_NOTHROWS(duke.income());
    //full cycle complete
}
TEST_CASE("turn legality") {
    SUBCASE("duke shall not be blocked from using 'tax'") {
        Game game_1{};
        Duke duke1{game_1, "Moshe1"};
        Duke duke2{game_1, "Moshe2"};
        Assassin assassin{game_1, "Yossi"};
        Ambassador ambassador{game_1, "Meirav"};
        Captain captain{game_1, "Reut"};
        Contessa contessa{game_1, "Gilad"};
        CHECK_NOTTHROWS(duke1.tax());
        CHECK_THROWS(duke2.block());
        CHECK_THROWS(assassin.block());
        CHECK_THROWS(captain.block());
        CHECK_THROWS(contessa.block());
        CHECK_THROWS(ambassador.block());
    }
    SUBCASE("Captain can steal unless he is being blocked by an Ambassador or another Captain") {
        Game game_1{};
        Captain captain1{game_1, "Reut1"};
        Captain captain2{game_1, "Reut2"};
        Duke duke{game_1, "Moshe"};
        Assassin assassin{game_1, "Yossi"};
        Ambassador ambassador{game_1, "Meirav"};
        Contessa contessa{game_1, "Gilad"};
        CHECK_NOTTHROWS(captain1.steal(captain2));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        CHECK_NOTTHROWS(captain1.steal(duke));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        CHECK_NOTTHROWS(captain1.steal(assasin));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        CHECK_NOTTHROWS(captain1.steal(ambassador));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        CHECK_NOTTHROWS(captain1.steal(contessa));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();

        captain1.steal(captain2);
        CHECK_NOTTHROWS(captain2.block(captain1));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        captain1.steal(duke);
        CHECK_THROWS(duke.block(captain1));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        captain1.steal(assasin);
        CHECK_THROWS(contessa.block(captain1));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        captain1.steal(ambassador);
        CHECK_NOTTHROWS(ambassador.block(captain1));
        captain2.income();
        duke.income();
        assassin.income();
        ambassador.income();
        contessa.income();
        captain1.steal(contessa);
        CHECK_THROWS(assassin.block(captain1));
    }
    SUBCASE("for the price of 3 coins the assasin can coup another player.\nthe contessa can stop an assassination") {
        Game game_1{};
        Assassin assassin{game_1, "Yossi"};
        Duke duke{game_1, "Moshe"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        assassin.income();
        duke.income();
        ambassador.income();
        captain.income();
        contessa.income();
        //
        assassin.income();
        duke.income();
        ambassador.income();
        captain.income();
        contessa.income();
        //
        assassin.income();
        duke.income();
        ambassador.income();
        captain.income();
        contessa.income();
        CHECK_NOTTHROWS(assassin.coup(duke));
        ASSERT_TRUE(assassin.coins() == 0);
        CHECK_NOTTHROWS(contessa.income());
    }
}
TEST_CASE("normal operation")
{
    SUBCASE("income action should increase the player's coin amount by 1")
    {   
        Game game_1{};
        Assassin assassin{game_1, "Yossi"};
        Duke duke{game_1, "Moshe"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        ASSERT_TRUE(assassin.coins() == 0);
        assassin.income();
        ASSERT_TRUE(assassin.coins() == 1);
        ASSERT_TRUE(duke.coins() == 0);
        duke.income();
        ASSERT_TRUE(duke.coins() == 1);
        ASSERT_TRUE(ambassador.coins() == 0);
        ambassador.income();
        ASSERT_TRUE(ambassador.coins() == 1);
        ASSERT_TRUE(captain.coins() == 0);
        captain.income();
        ASSERT_TRUE(captain.coins() == 1);
        ASSERT_TRUE(contessa.coins() == 0);
        contessa.income();
        ASSERT_TRUE(contessa.coins() == 1);
    }
    SUBCASE("foreign aid")
    {   
        Game game_1{};
        Assassin assassin{game_1, "Yossi"};
        Duke duke{game_1, "Moshe"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        ASSERT_TRUE(assassin.coins() == 0);
        assassin.foreign_aid();
        ASSERT_TRUE(assassin.coins() == 2);
        ASSERT_TRUE(duke.coins() == 0);
        duke.foreign_aid();
        ASSERT_TRUE(duke.coins() == 2);
        ASSERT_TRUE(ambassador.coins() == 0);
        ambassador.foreign_aid();
        ASSERT_TRUE(ambassador.coins() == 2);
        ASSERT_TRUE(captain.coins() == 0);
        captain.foreign_aid();
        ASSERT_TRUE(captain.coins() == 2);
        ASSERT_TRUE(contessa.coins() == 0);
        contessa.foreign_aid();
        ASSERT_TRUE(contessa.coins() == 2);
    }
    SUBCASE("coup is mandatory if the player has 10 coins at the start of the round") 
    {
        Game game_1{};
        Assassin assassin{game_1, "Yossi"};
        Duke duke{game_1, "Moshe"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();
        // now each player has 10 coins
        CHECK_THROWS(assassin.income(duke));
        CHECK_THROWS(duke.income(contessa));
        CHECK_THROWS(ambassador.income(duke));
        CHECK_THROWS(captain.income(duke));
        CHECK_THROWS(contessa.income(duke));
        CHECK_THROWS(assassin.foreign_aid(duke));
        CHECK_THROWS(duke.foreign_aid(contessa));
        CHECK_THROWS(ambassador.foreign_aid(duke));
        CHECK_THROWS(captain.foreign_aid(duke));
        CHECK_THROWS(contessa.foreign_aid(duke));
        CHECK_NOTTHROWS(assassin.coup(duke));
        contessa.block(assassin);
        CHECK_NOTTHROWS(duke.coup(assassin));
        contessa.block(duke);
        CHECK_NOTTHROWS(ambassador.coup(duke));
        contessa.block(ambassador);
        CHECK_NOTTHROWS(captain.coup(duke));
        contessa.block(captain);
        CHECK_NOTTHROWS(contessa.coup(duke));
    }
    SUBCASE("the winner should only be chosen when the game is over") 
    {
        Game game_1{};
        Assassin assassin{game_1, "Yossi"};
        Duke duke{game_1, "Moshe"};
	    Ambassador ambassador{game_1, "Meirav"};
	    Captain captain{game_1, "Reut"};
	    Contessa contessa{game_1, "Gilad"};
        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();

        assassin.foreign_aid();
        duke.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();
        
        CHECK_THROWS(game_1.winner());
        CHECK_NOTTHROWS(assassin.coup(duke));
        CHECK_THROWS(game_1.winner());
        CHECK_NOTTHROWS(ambassador.coup(captain));
        CHECK_THROWS(game_1.winner());
        CHECK_NOTTHROWS(contessa.coup(ambassador));
        CHECK_THROWS(game_1.winner());
        CHECK_NOTTHROWS(assassin.coup(contessa));
        // now only the assassin is left alive, hence he won the game.
        CHECK_NOTTHROWS(game_1.winner());

        Game game_2{};
        Assassin assassin2{game_2, "Yossi"};
        ASSERT_EQUALS(game_1.winner() == "Yossi");
        
        Game game_3{};
        Assassin assassin3{game_3, "Yossi"};
        Duke duke3{game_3, "Moshe"};
        CHECK_THROWS(game_3.winner());
    }
}
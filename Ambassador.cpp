#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Game.hpp"
#include "Ambassador.hpp"

using namespace std;
using namespace coup;

Ambassador::Ambassador(Game game, std::string name): Player(name) {
    
}
Ambassador::~Ambassador() {

}
void Ambassador::transfer(Player p1, Player p2) {

}
void Ambassador::block(Player p1) {

}
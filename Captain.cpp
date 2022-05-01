#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Game.hpp"
#include "Captain.hpp"

using namespace std;
using namespace coup;

Captain::Captain(Game game, std::string name): Player(name) {
    
}
Captain::~Captain() {

}
void Captain::steal(Player p1) {

}
void Captain::block(Player p1) {

}
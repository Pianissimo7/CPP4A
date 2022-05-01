#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Game.hpp"
#include "Assassin.hpp"

using namespace std;
using namespace coup;

Assassin::Assassin(Game game, std::string name): Player(name) {
    
}
Assassin::~Assassin() {

}
void Assassin::coup(Player p1) {

}
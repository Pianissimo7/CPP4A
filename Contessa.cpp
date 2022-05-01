#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Game.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;

Contessa::Contessa(Game game, std::string name): Player(name) {
    
}
Contessa::~Contessa() {

}
void Contessa::block(Player p1) {

}
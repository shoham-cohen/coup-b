#include "Contessa.hpp"
#include <stdexcept>

using namespace std;
using namespace coup;

Contessa::Contessa(Game &game, const string& name): Player(game, name){

        this-> my_role = "Contessa";
        this-> name = name;
}

void Contessa::block(Player &assassin){

    if(this-> get_is_alive() == 0){
        throw runtime_error("this player is not alive");
    }

    if(assassin.role() != "Assassin" || assassin.last_command != 3){
        throw runtime_error("nothing to block");
    }

    assassin.last_command_player-> set_is_alive(1);
}

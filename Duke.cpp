#include "Duke.hpp"
#include <stdexcept>

using namespace std;
using namespace coup;

Duke::Duke(Game &game, const std::string &name) : Player(game, name){
    this-> my_role = "Duke";
    this-> name = name;
}
    
void Duke::tax(){
    if(this-> is_alive == 0){
        throw runtime_error("this player is not alive");
    }
        
    if(this-> game -> turn() != this-> name){
        throw runtime_error("it is not your turn");
    }

    this-> add_coins(3);
    this-> last_command = 3;
    size_t size = this-> game-> _players.size();
    while(true){
        this-> game-> turn_var++;
        if(this-> game-> _players.at(this-> game-> turn_var % size)-> get_is_alive() == 1){
            break;
        }
    }
}

void Duke::block(Player &player){ //block the foreign aid
    if(this-> is_alive == 0){
        throw runtime_error("this player is not alive");
    }

    if(player.last_command != 1){
        throw runtime_error("nothing to block");
    }

    player.subtract_coins(2);
}

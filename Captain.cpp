#include "Captain.hpp"
#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace coup;

Captain::Captain(Game &game, const string& name): Player(game, name){

        this-> my_role = "Captain";
        this-> name = name;
}
    

void Captain::steal(Player &robbed){
    if(this-> get_is_alive() == 0){
        throw runtime_error("this player is not alive");
    }
        
    if(this-> game -> turn() != this-> get_name()){
        throw runtime_error("it is not your turn");
    }

    int to_steal = std::min(2, robbed.coins());
    this-> last_command_player = &robbed;
    this-> last_command = 3;
    this-> add_coins(to_steal);
    robbed.subtract_coins(to_steal);
    size_t size = this-> game-> _players.size();
    while(true){
        this-> game-> turn_var++;
        if(this-> game-> _players.at(this-> game-> turn_var % size)-> get_is_alive() == 1){
            break;
        }
    }
}
        
void Captain::block(Player &captain){
    
    if(this-> get_is_alive() == 0){
        throw runtime_error("this player is not alive");
    }

    if(captain.my_role != "Captain" || captain.last_command != 3){
        throw runtime_error("nothing to block");
    }

    captain.subtract_coins(2);
    captain.last_command_player-> add_coins(2);
    
}

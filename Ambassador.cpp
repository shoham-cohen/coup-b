#include "Ambassador.hpp"
#include <stdexcept>

using namespace std;

namespace coup{

    Ambassador::Ambassador(Game &game, const string& name): Player(game, name){

            this-> my_role = "Ambassador";
            this-> name = name;
    }

    void Ambassador::transfer(Player &robbed, Player &robber){

        if(this-> get_is_alive() == 0){
            throw runtime_error("this player is not alive");
        }
        
        if(this-> game -> turn() != this-> name){
            throw runtime_error("it is not your turn");
        }

        if(robbed.coins() == 0){
            throw runtime_error("cant tranfer 0 coins");
        }

        robber.add_coins(1);
        robbed.subtract_coins(1);
        this-> last_command = 3;
        size_t size = this-> game-> _players.size();
        while(true){
            this-> game-> turn_var++;
            if(this-> game-> _players.at(this-> game-> turn_var % size)-> get_is_alive() == 1){
                break;
            }
        }
    }

    void Ambassador::block(Player &captain){

        if(this-> get_is_alive() == 0){
            throw runtime_error("this player is not alive");
        }

        if(captain.my_role != "Captain" || captain.last_command != 3){
            throw runtime_error("nothing to block");
        }

        captain.subtract_coins(2);
        captain.last_command_player-> add_coins(2);
    }
}
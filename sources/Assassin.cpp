#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include <stdexcept>

using namespace std;
using namespace coup;

Assassin::Assassin(Game &game, const string& name): Player(game, name){

            this-> my_role = "Assassin";
            this-> name = name;
}

void Assassin::coup(Player &player){ //speacial coup: cost 3 coins 

    if(this-> get_is_alive() == 0){
        throw runtime_error("this player is not alive");
    }
        
    if(this-> game -> turn() != this-> get_name()){
        throw runtime_error("it is not your turn");
    }

    if(player.get_is_alive() == 0){
        throw runtime_error("the player that you want to kill is already dead");
    }
    
    const int three = 3;
    if(this-> coins() < three){
        throw runtime_error("you dont have enough coins");
    }

    const int seven = 7;
    if(this-> coins() >= seven){
        this-> subtract_coins(seven);
        this-> last_command = 2;
    }

    else{
        this-> subtract_coins(three);
        this-> last_command = 3;
    }
    
    player.set_is_alive(0);
    this-> last_command_player = &player;
    int remainning = this-> game-> remainning_alive();
    if(remainning == 1){
        this-> game-> is_ended = 1;
    }
    else{
        size_t size = this-> game-> _players.size();
        while(true){
            this-> game-> turn_var++;
            if(this-> game-> _players.at(this-> game-> turn_var % size)-> get_is_alive() == 1){
                break;
            } 
        }
    }
}     

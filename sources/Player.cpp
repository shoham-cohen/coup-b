#include <stdexcept>
#include "Player.hpp"

using namespace std;
using namespace coup;
const int six = 6;

Player::Player(Game &game, string name){
    
    this->game = &game;
     if(this->game->is_started == 1){
         throw runtime_error("cant join. the game has been started");
    }
    if(this->game->_players.size() == six){
         throw runtime_error("cant join. the game has already 6 players playing");
    }
    this-> game->add(this);
    this-> name = move(name);
    this-> num_of_coins = 0;
    this-> is_alive = 1;
    this-> last_command = -1;
    this-> last_command_player = NULL;
}


void Player::income(){

    if(this-> game-> _players.size() == 1){
        throw runtime_error("cant start the game with less than 2 players");
    }
    const int ten = 10;
    if(this-> is_alive == 0){
        throw runtime_error("this player is not alive");
    }
    if(this-> game -> turn() != this-> name){
        throw runtime_error("it is not your turn");
    }

    if(this-> num_of_coins >= ten){
        throw runtime_error("must coup with more than 10 coins");
    }

    this-> game-> is_started = 1;
    this-> add_coins(1);
    this-> last_command = 0;
    size_t size = this-> game-> _players.size();
    while(true){
        this-> game-> turn_var++;
        if(this-> game-> _players.at(this-> game-> turn_var % size)-> get_is_alive() == 1){
            break;
        }
    }  
}

void Player::foreign_aid(){

    if(this-> game-> _players.size() == 1){
        throw runtime_error("cant start the game with less than 2 players");
    }
    const int ten = 10;
    if(this-> is_alive == 0){
        throw runtime_error("this player is not alive");
    }
    if(this-> game -> turn() != this-> name){
        throw runtime_error("it is not your turn");
    }

    if(this-> num_of_coins >= ten){
        throw runtime_error("must coup with more than 10 coins");
    }

    this-> game-> is_started = 1;
    this-> add_coins(2);
    this-> last_command = 1;
    size_t size = this-> game-> _players.size();
    while(true){
        this-> game-> turn_var++;
        if(this-> game-> _players.at(this-> game-> turn_var % size)-> get_is_alive() == 1){
            break;
        }
    }
}

void Player::coup(Player &player){

    if(this-> is_alive == 0){
        throw runtime_error("this player is not alive");
    }
    if(this-> game -> turn() != this-> name){
        throw runtime_error("it is not your turn");
    }
    if(player.get_is_alive() == 0){
        throw runtime_error("the player that you want to kill is already dead");
    }
    const int seven = 7;
    if(this-> num_of_coins < seven){
        throw runtime_error("you cant coup with less than 7 coins");
    }
    this-> subtract_coins(seven);
    this-> last_command = 2;
    player.set_is_alive(0);
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

string Player::role() const{

    return this->my_role;
}

int Player::coins() const{

    return this->num_of_coins;
}

void Player::add_coins(int to_add){

    this->num_of_coins += to_add;
}

void Player::subtract_coins(int to_subtract){

    this->num_of_coins -= to_subtract;
}

int Player::get_is_alive() const{

    return this-> is_alive;
}

void Player::set_is_alive(int value){

    this-> is_alive = value;
}

string Player::get_name() const{

    return this-> name;
}

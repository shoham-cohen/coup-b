#include "Game.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace coup;

Game::Game(){
    this-> is_started = 0;
    this-> is_ended = 0;
    this-> turn_var = 0;
}

vector<string> Game::players(){
    vector<string> res;
    for(size_t i = 0; i < this->_players.size(); i++){
        if(this->_players.at(i)-> get_is_alive() == 1){
            res.push_back(this->_players.at(i)->get_name());
        }
    }
    return res;
}

string Game::turn(){

    size_t size = this->_players.size();
    size_t pos = this->turn_var % size;
    return this->_players.at(pos)->get_name();
}

string Game::winner(){
    int num_of_alives = this-> remainning_alive();
    if(num_of_alives == 1){
        if(this-> is_ended == 1){
            for(size_t i = 0; i < this->_players.size(); i++){
                if(this->_players.at(i)-> get_is_alive() == 1){
                    return this->_players.at(i)-> get_name();
                }
            }
        }
    }
    throw runtime_error("Game is not ended yet");
}

int Game::remainning_alive(){

    int res = 0;
    for(size_t i = 0; i < this->_players.size(); i++){
        if(this-> _players.at(i)->get_is_alive() == 1){
            res++;
        }
    }
    return res;
}

void Game::add(Player *player){

    this->_players.push_back(player);
}

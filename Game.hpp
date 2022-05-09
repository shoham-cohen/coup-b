#pragma once
#include "Player.hpp"
#include <vector>
#include <string>

namespace coup{
    class Player;
    class Game{
        
        public:
            Game();
            int is_started;
            int is_ended;
            std::vector<Player*> _players; //list of the players
            size_t turn_var; //holds the position of the current player in the list

            std::vector<std::string> players(); //returns the list of players
            std::string turn(); //returns the name of the current player
            std::string winner(); //returns the winners name if there is one
            void add(Player *player);
            int remainning_alive();
    };
}
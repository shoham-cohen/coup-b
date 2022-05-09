#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace coup{

    class Captain:public Player{

        public:
            Captain(Game &game, const std::string& name); //constructor
            void steal(Player &robbed); //steal from other player 1 coin
            void block(Player &captain); //block the steal
            
    };
}
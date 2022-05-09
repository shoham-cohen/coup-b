#include <string>
#include "Player.hpp"
#include "Game.hpp"


namespace coup{

    class Duke:public Player{

        public:
            Duke(Game &game, const std::string &name); //constructor
            void tax(); //take 3 coins
            void block(Player &player); //block the foreign aid
    };
}
#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace coup{

    class Contessa:public Player{

        public:
            Contessa(Game &game, const std::string& name); //constructors
            void block(Player &assassin); //block the coup of the assassin
    };
}

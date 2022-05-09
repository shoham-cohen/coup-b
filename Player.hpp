#pragma once
#include "Game.hpp"
#include <string>


namespace coup{
    class Game;
    class Player{

        public:
            Player(Game &game, std::string name);
            std::string name;
            int num_of_coins;
            Game *game;
            std::string my_role;
            int last_command; //-1 == just joined, 0 == income, 1 == foreign_aid, 2 == coup, 3 == speacial command (tax/steal...)
            int is_alive; //0 if dead, 1 if alive
            Player *last_command_player;
            void income(); //take one coin
            void foreign_aid(); //take two coins
            virtual void coup(Player &player); //eliminate a player //virtual means that it will be override
            std::string role() const; //returns the player's role
            int coins() const; // returns the amount of coins the player has
            void add_coins(int to_add);
            void subtract_coins(int to_subtract);
            int get_is_alive() const;
            void set_is_alive(int value);
            std::string get_name() const;
    };
}
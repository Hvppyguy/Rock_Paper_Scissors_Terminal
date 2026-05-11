#include <iostream>
#include <string>
#include <random>

class Opponent {
    private:
        int chances[3] = {10, 10, 10};
    public:
        std::string random_output(){
            std::string words[3] = {"rock", "paper", "scissors"};
            std::random_device rd;
            std::mt19937 gen(rd());
            std::discrete_distribution<> dist(chances, chances + 3);
            int result = dist(gen);
            return words[result];
        }
};
class Game_Logic {
    public:
        void lose(std::string opp){
            std::cout << opp << "\n";
            std::cout << "You Lost" << "\n";

        }
        void win(std::string opp) {
            std::cout << opp << "\n";
            std::cout << "You Won" << "\n";
            }
        int compare(std::string player, std::string opp) {
            if(!(player == "rock" || "paper" || "scissors")){
                std::cout << "ERROR" << "\n";
                return 0;
            }
            else if(player == opp){
                std::cout << "Tie" << "\n";
                return 0;
            }
            else if(player == "rock"){
                if(opp == "paper"){
                    lose(opp);
                }
                else {
                    win(opp);
                }
                return 0;
            }
            else if(player == "paper"){
                if(opp == "scissors"){
                    lose(opp);
                }
                else{
                    win(opp);
                }
                return 0;
            }
            else if(player == "scissors"){
                if(opp == "rock"){
                    lose(opp);
                }
                else{
                    win(opp);
                }
                return 0;
            }
            return 0;
        }
};
int main(){
    Opponent opp;
    Game_Logic logic;
    while(true){
        std::string input;
        std::cin >> input;
        logic.compare(input, opp.random_output());
    }
    return 0;
}
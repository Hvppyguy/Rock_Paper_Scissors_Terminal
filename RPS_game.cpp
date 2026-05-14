#include <iostream>
#include <string>
#include <random>

class Opponent {
    private:
        int chances[3] = {3, 3, 3};
        int history[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        int called = 0;
    public:
        std::string random_output(){
            std::string words[3] = {"rock", "paper", "scissors"};
            std::random_device rd;
            std::mt19937 gen(rd());
            std::discrete_distribution<> dist(chances, chances + 3);
            int result = dist(gen);
            return words[result];
        }
        void change_chance(int value, int call){
            if(history[call] != -1){
                chances[history[call]]--;
            }
            chances[value]++;
            history[call] = value;
            called = (called + 1) % 10;
        }
        void adapt(std::string player){
            if(player == "rock"){
                change_chance(1,called);
            }
            else if(player == "paper"){
                change_chance(2,called);
            }
            else if(player == "scissors"){
                change_chance(0,called);
            }
        }
};
class Game_Logic {
    public:
        int wins = 0;
        int loses = 0;
        int ties = 0;
        void lose(std::string opp){
            std::cout << opp << "\n";
            std::cout << "You Lost" << "\n";
            loses++;
        }
        void win(std::string opp){
            std::cout << opp << "\n";
            std::cout << "You Won" << "\n";
            wins++;
        }
        int compare(std::string player, std::string opp) {
            if(!(player == "rock" || "paper" || "scissors")){
                std::cout << "ERROR" << "\n";
                return 0;
            }
            else if(player == opp){
                std::cout << "Tie" << "\n";
                ties++;
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
        std::string input = "rock";
        std::cin >> input;
        logic.compare(input, opp.random_output());
        opp.adapt(input);
        std::cout << "Wins: " << logic.wins << " Loses: " << logic.loses << " Ties: " << logic.ties << "\n";
    }
    return 0;
}
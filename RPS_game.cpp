#include <iostream>
#include <string>
#include <random>

class Opponent {
    private:
        int chances[3] = {10, 10, 10};
    public:
        char random_output(){
            char Output[3] = {'r', 'p', 's'};
            std::string words[3] = {"Rock", "Paper", "Scissor"};
            std::random_device rd;
            std::mt19937 gen(rd());
            std::discrete_distribution<> dist(chances, chances + 3);
            int result = dist(gen);
            std::cout << words[result] << "\n";
            return Output[result];
        }
};
class Game_Logic {
    public:
        void lose(){
            std::cout << "You Lost" << "\n";
        }
        void win() {
            std::cout << "You Won" << "\n";
        }
        void compare(char player[], char opp) {
            int player_int = player[0] % 10;
            int opp_int = opp % 10;
            if(player_int == opp_int){
                std::cout << "Tie" << "\n";
            }
            else{
                switch(player_int){
                    case 4: // Rock(r)
                        if (opp_int == 5){
                            win();
                        }
                        else{
                            lose();
                        }
                        break;
                    case 2: //Paper(p)
                        if (opp == 4){
                            win();
                        }
                        else{
                            lose();
                        }
                        break;
                    case 5: //Sicssors(s)
                        if (opp == 2){
                            win();
                        }
                        else{
                            lose();
                        }
                        break;
                }
            }
        }
};
int main(){
    Opponent opp;
    Game_Logic logic;
    while(true){
        char *input[] = new char;
        std::cin >> *input[];
        logic.compare(*input[], opp.random_output());
        delete input[];
    }
    return 0;
}
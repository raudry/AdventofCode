/*
    Determine the highest score of rock paper scissors
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    //Variables
    ifstream guide;
    char opponentElf;
    char playerElf;
    int totalScore = 0;

    guide.open("strategyGuide.txt");

    while( guide >> opponentElf >> playerElf)
    {
        /*Opponent Guide:       Player Guide:
            A = Rock                X = Rock        +1
            B = Paper               Y = Paper       +2
            C = Scissors            Z = Scissors    +3
        */
        switch(opponentElf)
        {
            case 'A':
                    //draw
                    if(playerElf == 'X') //+1
                    {
                        totalScore += 4;    
                    }
                    //win
                    else if(playerElf == 'Y') //+2
                    {
                        totalScore += 8;
                    }
                    //loss
                    else if(playerElf == 'Z') //+3
                    {
                        totalScore += 3;
                    }
                    break;
            case 'B':
                    //loss
                    if(playerElf == 'X') //+1
                    {
                        totalScore += 1;
                    }
                    //draw
                    else if(playerElf == 'Y') //+2
                    {
                        totalScore += 5;
                    }
                    //win
                    else if(playerElf == 'Z') //+3
                    {
                        totalScore += 9;
                    }
                    break;
            case 'C':
                    //win
                    if(playerElf == 'X') //+1
                    {
                        totalScore += 7;
                    }
                    //loss
                    else if(playerElf == 'Y') //+2
                    {
                        totalScore += 2;
                    }
                    //draw
                    else if(playerElf == 'Z') //+3
                    {
                        totalScore += 6;
                    }
                    break;
            default:
                break;
        }
    }
    guide.close();
    cout << "Total points: " << totalScore << endl;
}
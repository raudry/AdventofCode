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
            A = Rock                X = Lose      
            B = Paper               Y = Draw    
            C = Scissors            Z = Win     
        */
        switch(opponentElf)
        {
            //Rock
            case 'A': 
                    //Scissors +3
                    if(playerElf == 'X') //Lose
                    {
                        totalScore += 3;    
                    }
                    //Rock +1
                    else if(playerElf == 'Y') //Draw +3
                    {
                        totalScore += 4;
                    }
                    //Paper +2
                    else if(playerElf == 'Z') //Win +6
                    {
                        totalScore += 8;
                    }
                    break;
            //Paper
            case 'B':
                    //Rock +1
                    if(playerElf == 'X') //Lose
                    {
                        totalScore += 1;
                    }
                    //Paper +2
                    else if(playerElf == 'Y') //Draw +3
                    {
                        totalScore += 5;
                    }
                    //Scissors +3
                    else if(playerElf == 'Z') //Win +6
                    {
                        totalScore += 9;
                    }
                    break;
            //Scissors
            case 'C':
                    //Paper +2
                    if(playerElf == 'X') //Lose
                    {
                        totalScore += 2;
                    }
                    //Scissors +3
                    else if(playerElf == 'Y') //Draw +3
                    {
                        totalScore += 6;
                    }
                    //Rock +1
                    else if(playerElf == 'Z') //Win +6
                    {
                        totalScore += 7;
                    }
                    break;
            default:
                break;
        }
    }
    guide.close();
    cout << "Total points: " << totalScore << endl;
}
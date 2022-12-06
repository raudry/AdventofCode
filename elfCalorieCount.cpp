/*
Calculate which elf has the most calories. Takes data input from a file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function prototypes

int main() {
    
	//variables
	ifstream calorieList;
    string calories;
    int mostElfCalories = 0;
    int currentElfCalories = 0;

	//read in file for data
	calorieList.open("elfCalories.txt");

	//read in calories
	while (getline(calorieList, calories))
	{
        //Blank lines means next elf
        if (calories == "" ){
            //if next elf has more calories packed than previous elf
		    if(currentElfCalories > mostElfCalories)
            {
                //set current elf calories to most elf calories
                mostElfCalories = currentElfCalories;
            }
            //reset current elf calories after each blank line
            currentElfCalories = 0;
        }
        //otherwise, keep adding calies to current elf
        else{
            currentElfCalories += stoi(calories);
        }
	}
    //print out most calories carried by an elf
    cout << "most elf calories: "<< mostElfCalories << endl;
    calorieList.close();
}
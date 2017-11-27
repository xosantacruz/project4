#include <iostream> 
#include <cmath>
#include <string>
#include <ctype.h>
#include<stdlib.h>
using namespace std;

// code was copied from stackoverflow to help with the input stream
void FlushInstream(istream &inStream = cin) {
    char inChar;

    inStream.clear();
    while (false == inStream.eof()) {
        inStream.get(inChar);
        if ('\n' == inChar) {
            break;
        }
    }
}

//functions 
int getMaleCalorieCount(int userAge, int userWeight, int userHeight){
	// TO DO: Use userAge, Weight, and Height to calculate # of calories
	int maleCalorieIntake =0;
	maleCalorieIntake = (userHeight * 6.25) + (userWeight * 9.99) - (userAge * 4.92) + 5;

	return maleCalorieIntake;
} 

int getFemaleCalorieCount(int userAge, int userWeight, int userHeight){
	int womenCalorieIntake = 0;
	womenCalorieIntake = (userHeight * 6.25) + (userWeight * 9.99) - (userAge * 4.92) - 161;

	return womenCalorieIntake;
}

void printGoals(){
	cout << "\n1.) Lose weight." << endl;
	cout << "2.) Maintain weight." << endl;
	cout << "3.) Gain muscle." << endl;
}

void printActivityLevels(){
	cout << "\n1.) Not very active. ";
	cout << "(Example: student, receptionist, programmer)";
	cout << "\n2.) Lightly active. ";
	cout << "(Example: teacher, salesman, optometrist)";
	cout << "\n3.) Active. ";
	cout << "(Example: UPS,)" << endl; // add to list...fix
	cout << "\n4.) Very Active. ";
	cout << "(Example: labor, bike messenger)";
}

void printErrorMsg() {
	cout << "\n\nYour input is invalid, please enter a valid input...";

	FlushInstream();
}

int main (){
	// Declarations 
	string userChar;
	int userAge = -1;
	int userWeight = -1;
	int userHeight = -1;
	int weightGoal = 0;
	int calorieCount = 0;
	string userGoal;
	string activityLevel;

	//user inputs

	while(userGoal.length() != 1){
		cout << "What is your goal? ";
		printGoals();
		cin >> userGoal;

		if(userGoal.length() > 1){
			printErrorMsg();
			continue;
		}

		int i = atoi(userGoal.c_str());
		if (i == 1 || i == 2 || i == 3) {
			break;
		}
		
	}

	while (activityLevel.length() != 1){ 
		cout << "\nWhat is your activity level outside of your fitness life? ";
		printActivityLevels();
		cin >> activityLevel;

		if (activityLevel.length() > 1){
			printErrorMsg();
			continue;
		}
		int i = atoi(activityLevel.c_str());
		if (i == 1 || i == 2 || i == 3 || i ==4){
			break;
		}
	}

	while (userChar.length() != 1) {
		FlushInstream();
		cout << "\nEnter your gender: (F/M)";
		cin >> userChar;

		if(userChar.length() >1){
			printErrorMsg();
			continue;
		}

		if (isdigit(userChar.at(0)) == true) {
			userChar.clear();
			printErrorMsg();
			continue;
	 	}

	 	if(tolower(userChar.at(0)) == 'f' || tolower(userChar.at(0)) == 'm'){
	 		break;
	 	}
		else{
	 		userChar.clear();
	 		printErrorMsg();
	 	}
	 }

	while (userAge.length() < 0 || userAge.length() > 110){
		FlushInstream();
		cout << "\nEnter your age: ";
		cin >> userAge;

		if (userAge.length() < 0 || userAge.length() > 110){
			
			printErrorMsg();
		}
	}
	while (userWeight < 0 || userWeight > 600){
		cout << "\nEnter your weight(in lbs): ";
		cin >> userWeight;

		if(userWeight < 0 || userWeight > 600){
			printErrorMsg();
		}
	}	

	while (userHeight < 0 || userHeight >300){
		cout << "\nEnter your height(in inches): ";
		cin >> userHeight;

		if( userHeight < 0 || userHeight > 300){
			printErrorMsg();
		}
	}	


	// if (userChar == 'F')
	// {
	// 	calorieCount = getFemaleCalorieCount(userAge, userWeight, userHeight);
	// } else {
	// 	calorieCount = getMaleCalorieCount(userAge, userWeight, userHeight);
	// }

	cout << "You should eat " << calorieCount << " calories each day to reach your goal." << endl;
	

	return 0;
}	

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

void printUserOptions(){
	cout << "\n1.) View my information." << endl;
	cout << "2.) Update my information." << endl;
	cout << "3.) Calculate my calories" << endl;
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
	string userName;
	int calorieCount = 0;
	string userChoice;
	string activityLevel;
	FILE * myDataFile;
	char userInfo[256]; 
	bool userFound = false;

	cout << "Enter name: ";
	cin >> userName;

	// Open data.txt
	myDataFile = fopen("data.txt", "r");

	if(myDataFile == NULL){
		cout << "Could not find data.txt" << endl;
		return 0;
	}

	while(feof(myDataFile) == false){
		fgets(userInfo, 256, myDataFile);

		string temp;
		temp.reserve(30);
		for (int i = 0; userInfo[i] != ','; ++i)
		{
			temp.push_back(userInfo[i]);
		}

		if (temp == userName)
		{
			cout << "We found your name in our file." << endl;
			userFound = true;
			break;
		}
	}

	if (userFound == false)
	{
		cout << "I'm sorry, your name was not found." << endl;
		return 0;
	}
	
	//get user choice
	while(userChoice.length() != 1){
		printUserOptions();
		cin >> userChoice;

		if(userChoice.length() > 1){
			printErrorMsg();
			continue;
		}

		int i = atoi(userChoice.c_str());
		if (i == 1 || i == 2 || i == 3) {
			break;
		}
		else{
			printErrorMsg();
			userChoice.clear();
		}	
	}

	//display user information
	if (userChoice.at(0) == '1')
	{ 
		for (int i = 0, j = 0; i < strlen(userInfo); ++i)
		{
			cout << "Name: " << userInfo[i];

			if (userInfo[i] == ',')
			{
				if (j == 1)
				{
					cout << "Weight: ";
				}
				else if(j == 2){
					cout << "Height: ";
				}
				else if(j ==3){
					cout << "Age: ";
				}
				else{
					cout << "Gender: ";
				}
			

				cout << endl;
			}
		}
		
	}

	

	
	

	// if (userChar == 'F')
	// {
	// 	calorieCount = getFemaleCalorieCount(userAge, userWeight, userHeight);
	// } else {
	// 	calorieCount = getMaleCalorieCount(userAge, userWeight, userHeight);
	// }

	//cout << "You should eat " << calorieCount << " calories each day to reach your goal." << endl;
	

	return 0;
}	

#include <iostream> 
#include <cmath>
#include <string>
#include <ctype.h>
#include <stdlib.h>

using namespace std;
// ========================================================================
// This code was copied from stackoverflow to help with the input stream
// This function helps with flushing the input stream of new line characters
// or carriage returns in Windows.
// ========================================================================
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

// Function declarations

// getMaleCalorieCount =====================================================
// This function calculates the calorie count for a male using the following
// equation.
//
// Input:
//		- userAge: The user's age.
//		- userWeight: The user's weight.
//		- userHeight: The user's height.
//
// Output:
//		- Returns the calorie count for a male (int)
// =========================================================================
int getMaleCalorieCount(int userAge, int userWeight, int userHeight) {
	// TO DO: Use userAge, Weight, and Height to calculate # of calories
	int maleCalorieIntake = 0;
	maleCalorieIntake = (userHeight * 6.25) + (userWeight * 9.99) - (userAge * 4.92) + 5;

	return maleCalorieIntake;
}


// getFemaleCalorieCount =====================================================
// This function calculates the calorie count for a female using the following
// equation.
//
// Input:
//		- userAge: The user's age.
//		- userWeight: The user's weight.
//		- userHeight: The user's height.
//
// Output:
//		- Returns the calorie count for a female (int)
// =========================================================================
int getFemaleCalorieCount(int userAge, int userWeight, int userHeight) {
	int womenCalorieIntake = 0;
	womenCalorieIntake = (userHeight * 6.25) + (userWeight * 9.99) - (userAge * 4.92) - 161;

	return womenCalorieIntake;
}

// printUserOptions ===========================================================
// This function prints out the options menu for the user after they have been
// located in the external data file.
//
// Input: nothing.
//
// Output: nothing.
// ============================================================================
void printUserOptions() {
	cout << "\nPlease choose from the following options:" << endl;
	cout << "1.) View my information." << endl;
	cout << "2.) Update my information." << endl;
	cout << "3.) Calculate my calories" << endl;
}


// printActivityLevels =========================================================
// This function prints out the activity level options that the user can choose
// from when calculating their calorie count.
//
// Input: Nothing.
//
// Output: Nothing.
// =============================================================================
void printActivityLevels() {
	cout << "\n1.) Not very active. ";
	cout << "(Example: student, receptionist, programmer)";
	cout << "\n2.) Lightly active. ";
	cout << "(Example: teacher, salesman, optometrist)";
	cout << "\n3.) Active. ";
	cout << "(Example: UPS,)" << endl; // add to list...fix
	cout << "\n4.) Very Active. ";
	cout << "(Example: labor, bike messenger)";
}

// printErrorMsg ==============================================================
// This function prints out the standard error message to the output when the
// user has encountered an error in the program. It also flushes the input
// stream.
//
// Input: nothing.
//
// Output: nothing.
// ============================================================================
void printErrorMsg() {
	cout << "\n\nYour input is invalid, please enter a valid input...";

	FlushInstream();
}

// main ========================================================================
//
// =============================================================================
int main() {
	// Variable declarations
	string userChar;
	string userAge;
	string userWeight;
	string userHeight;
	string userName;
	string userGender;
	int calorieCount = 0;
	string userChoice;
	string activityLevel;
	FILE * myDataFile;
	char userInfo[256];
	char tempUserInfo[256];
	bool userFound = false;
	errno_t err;
	errno_t err2;

	// Prompt the user for their name.
	cout << "Enter name: ";
	cin >> userName;

	// Open "data.txt" for "r"eading using the fopen_s function, and then check
	// the return value for a non-zero value. Non zero values mean that the file
	// could not be open or does not exist.
	err = fopen_s(&myDataFile, "data.txt", "r");
	if (err != 0) {
		cout << "Could not find data.txt" << endl;
		return 0;
	}

	// This while loop will loop through the data.txt file until EOF (end of file) is reached.
	while (feof(myDataFile) == false) {
		// gets a line of characters and stores it in userInfo, up to 256 bytes.
		// i.e. userInfo will look like the following array
		// ['C', 'a', 'r', 'l', 'o', 's', ',' '1', '5', '0', ',' '6', '5', ',' '3', '0', ',' 'M']
		fgets(userInfo, 256, myDataFile);

		string temp;
		temp.reserve(30);
		// Loop through the character array while userInfo[i] does not equal a comma.
		// Temp should hold just the user's name, i.e. ['C', 'a', 'r', 'l', 'o', 's']
		for (int i = 0; userInfo[i] != ','; ++i)
		{
			// Save the characters in a string.
			temp.push_back(userInfo[i]);
		}

		// If temp is equal to the userName, break.
		if (temp == userName)
		{
			cout << "We found your name in our file." << endl;
			userFound = true;
			break;
		}
	} // end of while loop

	// If you loop through the entire contents of data.txt and userFound still equals
	// false, then the user was never found. Exit the program.
	if (userFound == false)
	{
		cout << "I'm sorry, your name was not found." << endl;
		return 0;
	}

	// Close the pointer to the data.txt
	fclose(myDataFile);

	// This loop will print the user's options and read the value that they typed in.
	while (userChoice.length() != 1) {
		// Print user options and get user's choice.
		printUserOptions();
		cin >> userChoice;

		// If the user enters a string containing more than 1 character.
		if (userChoice.length() > 1) {
			printErrorMsg();
			continue;
		}

		// Check if the user entered a 1, 2, or 3.
		// If they didn't, print an error and clear the string.
		int i = atoi(userChoice.c_str());
		if (i == 1 || i == 2 || i == 3) {
			break;
		}
		else {
			printErrorMsg();
			userChoice.clear();
		}
	} // end of while loop.

	// If the user chooses option 1: "View my information"
	// Print the user's information to the output.
	if (userChoice.at(0) == '1')
	{
		string name;
		string weight;
		string height;
		string age;
		string gender;

		// Lengths of each category
		name.reserve(20);
		weight.reserve(3);
		height.reserve(3);
		age.reserve(3);
		gender.reserve(1);

		// This loop will save each category into its own variable
		for (int i = 0, numberOfCommas = 0; i < strlen(userInfo); i++)
		{
			// Every time you encounter a comma, increment the number of commas.
			if (userInfo[i] == ',')
			{
				numberOfCommas++;
				continue;
			}

			// Fill out the name
			if (numberOfCommas == 0) name.push_back(userInfo[i]);

			// Fill out the weight
			if (numberOfCommas == 1) weight.push_back(userInfo[i]);

			// Fill out the height
			if (numberOfCommas == 2) height.push_back(userInfo[i]);

			// Fill out the age
			if (numberOfCommas == 3) age.push_back(userInfo[i]);

			// Fill out the gender
			if (numberOfCommas == 4) gender.push_back(userInfo[i]);
		}

		// Print the user's info to the output
		cout << "========== Your information ==========" << endl;
		cout << "\nName: " << name << endl;
		cout << "Weight: " << weight << endl;
		cout << "Height: " << height << endl;
		cout << "Age: " << age << endl;
		cout << "Gender: " << gender << endl;
		cout << "======================================" << endl;
	}

	// If the user chooses option 2: "Update my information"
	if (userChoice.at(0) == '2')
	{
		// To output the new datafile.
		FILE * newDataFile;

		err = fopen_s(&newDataFile, "temp.txt", "w");
		err2 = fopen_s(&myDataFile, "data.txt", "r");
		if (err != 0) {
			cout << "Could not open temp.txt" << endl;
			return 0;
		}

		if (err2 != 0)
		{
			cout << "Could not open data.txt for reading." << endl;
			return 0;
		}

		// Loop through the data.txt file until you reach end of file
		while (fgets(tempUserInfo, 256, myDataFile)) {
			// Skip this record
			if (strcmp(userInfo, tempUserInfo) == false)
			{
				cout << "\nRemoving old information for " << userName << endl;
				continue;
			}

			// Write to file
			fputs(tempUserInfo, newDataFile);
		}

		// Delete data.txt
		fclose(myDataFile);
		fclose(newDataFile);
		if (remove("data.txt") != 0) cout << "Error deleting data.txt" << endl;

		// Rename temp.txt to data.txt
		rename("temp.txt", "data.txt");

		// Ask the user to enter their new information
		string updatedUserInfo;
		updatedUserInfo.reserve(strlen(userInfo));

		updatedUserInfo.append(userName);
		updatedUserInfo.push_back(',');
		
		// Get new user weight.
		while (userWeight.length() < 1 || userWeight.length() > 3)
		{
			cout << "\n\nEnter weight (lbs): ";
			cin >> userWeight;

			// Check weight is not greater than 999 or less than 1
			if (userWeight.length() > 3 || userWeight.length() < 1)
			{
				printErrorMsg();
				userWeight.clear();
				continue;
			}

			// Append the weight to the user's info.
			updatedUserInfo.append(userWeight);
			updatedUserInfo.push_back(',');
		}

		// Get new user height
		while (userHeight.length() < 1 || userHeight.length() > 3)
		{
			cout << "\n\nEnter Height (inches): ";
			cin >> userHeight;

			// Check it's not over 999 or less than 1
			if (userHeight.length() > 3 || userHeight.length() < 1)
			{
				printErrorMsg();
				userHeight.clear();
				continue;
			}

			// Append the height to the user's info.
			updatedUserInfo.append(userHeight);
			updatedUserInfo.push_back(',');
		}

		while (userAge.length() < 1 || userAge.length() > 3)
		{
			cout << "\n\nEnter age: ";
			cin >> userAge;

			// Check it's not over 999 or less than 1
			if (userAge.length() > 3 || userAge.length() < 1)
			{
				printErrorMsg();
				userAge.clear();
				continue;
			}

			// Append the age to the user's info.
			updatedUserInfo.append(userAge);
			updatedUserInfo.push_back(',');
		}

		while (userGender.length() != 1)
		{
			cout << "\n\nEnter gender: ";
			cin >> userGender;

			// Check it's not more than 1 character
			if (userGender.length() > 1)
			{
				printErrorMsg();
				userGender.clear();
				continue;
			}

			// Append the user's gender.
			updatedUserInfo.append(userGender);
		}

		// Open data.txt for "a"ppending
		err = fopen_s(&myDataFile, "data.txt", "a");
		if (err != 0)
		{
			cout << "Could not open data.txt for writing" << endl;
			return 0;
		}

		fputs(updatedUserInfo.c_str(), myDataFile);
		fclose(myDataFile);

		cout << "\nYour data has been updated successfully." << endl;
	}

	// If the user chooses option 3: "Calculate calorie count"
	if (userChoice.at(0) == '3')
	{

	}

	// If the user chooses option 3: "Calculate calories"
	// Then we calculate the user's calories and display them.
	// TO DO:
	return 0;
}


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Header.h"


void DisplayClocks(string userHour12, string userHour24, string userMinutes, string userSeconds, string ampm) {
	string displayBorder = "**************************";
	string clock24 = "24-Hour Clock";
	string clock12 = "12-Hour Clock";

	//Clock display
	cout << displayBorder << "            ";
	cout << displayBorder << endl;

	cout << "*      " << clock12 << "     *" << "            ";
	cout << "*      " << clock24 << "     *" << endl;

	cout << "*" << setw(9) << setfill(' ') << userHour12 << ":" << userMinutes << ":" << userSeconds << " " << ampm << setw(7) << setfill(' ') << "*" << setw(13) << setfill(' ');
	cout << "*" << setw(10) << setfill(' ') << userHour24 << ":" << userMinutes << ":" << userSeconds << setw(9) << setfill(' ') << "*" << endl;

	cout << displayBorder << "            ";
	cout << displayBorder << endl;

}


void  DisplayMenu() {
	string displayBorder = "*************************";

	cout << displayBorder << endl;
	cout << "* 1 - Add one hour      *" << endl;
	cout << "* 2 - Add one minute    *" << endl;
	cout << "* 3 - Add one second    *" << endl;
	cout << "* 4 - Quit program      *" << endl;
	cout << displayBorder << endl;
}


int AddHour12(int userHour) {
	userHour += 1;

	if (userHour > 12) {
		userHour = 01;
	}

	return userHour;
}

int AddHour24(int userHour) {
	userHour += 1;

	if (userHour > 23) {
		userHour = 00;
	}

	return userHour;
}

int AddMinute(int userMinute) {
	userMinute += 1;
	if (userMinute > 59) {
		userMinute = 00;
	}

	return userMinute;
}

int AddSecond(int userSecond) {
	userSecond += 1;
	if (userSecond > 59) {
		userSecond = 00;
	}

	return userSecond;
}


string AppendTime(int time) {
	string newTime;

	if (time >= 0 && time < 10) {
		newTime = to_string(time);
		newTime.insert(0, "0");
	}
	else {
		newTime = to_string(time);
	}

	return newTime;
}

string AppendAmPm(int ampm) {
	string newAmPm;

	if (ampm == 1) {
		newAmPm = "AM";
	}
	else {
		newAmPm = "PM";
	}

	return newAmPm;
}
 

int Format12HourClock(int userHour12) {

	if (userHour12 > 12 && userHour12 <= 23) {
		userHour12 -= 12;
	}

	if (userHour12 == 00){
		userHour12 += 12;
	}

	return userHour12;
}

int Format24HourClock(int userHour24, int ampm) {

	if (userHour24 > 12 && userHour24 <= 23 && ampm == 1) {
		userHour24 -= 12;
	} 
	else if (userHour24 >=0 && userHour24 < 12 && ampm == 2){
		userHour24 += 12;
	}
	else {
		userHour24 = userHour24;
	}

	return userHour24;
}


int main() {
	int clockHour;
	int clockMin;
	int clockSec;
	int amPm;

	int addHour12;
	int addHour24;
	int addMin;
	int addSec;

	int menuChoice = 0;


	//Obtain user input for current hour with input validation
	cout << "Welcome! Please enter the current hour in HH- format: ";
	cin >> clockHour;
	if (clockHour < 0 || clockHour > 23) {
		cout << "Invalid entry, please input a new number between 00 and 23: ";
		cin >> clockHour;
	}
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> clockHour;
		if (clockHour < 0 || clockHour > 23) {
			cout << "Invalid entry, please input a new number between 00 and 23: ";
			cin >> clockHour;
		}
	}

	//Obtain user input for minutes with input validation
	cout << "Please enter the current minute(s) in -MM- format: ";
	cin >> clockMin;
	if (clockMin < 0 || clockMin > 60) {
		cout << "Invalid entry, please input a new number between 00 and 59: ";
		cin >> clockMin;
	}
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> clockMin;
		if (clockMin < 0 || clockMin > 60) {
			cout << "Invalid entry, please input a new number between 00 and 59:";
			cin >> clockMin;
		}
	}

	//Obtain user input for seconds with input validation
	cout << "Please enter current second(s) in -SS format: ";
	cin >> clockSec;
	if (clockSec < 0 || clockSec > 60) {
		cout << "Invalid entry, please input a new number between 00 and 59: ";
		cin >> clockSec;
	}
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> clockSec;
		if (clockSec < 0 || clockSec > 60) {
			cout << "Invalid entry, please input a new number between 00 and 59:";
			cin >> clockSec;
		}
	}

	//obtain user input for AM/PM with input validation
	cout << "Is it AM or PM? " << endl;
	cout << " Type '1' for am, or '2' for pm: ";
	cin >> amPm;
	if (amPm < 1 || amPm > 2) {
		cout << "Invalid entry, please input '1' or '2': ";
		cin >> amPm;
	}
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> amPm;
		if (amPm < 1 || amPm > 2) {
			cout << "Invalid entry, please input '1' or '2': ";
			cin >> amPm;
		}
	}

	//format 12 hour standard clock and append leading 0s to hour
	int clockHour12 = Format12HourClock(clockHour);
	string editedHour12 = AppendTime(clockHour12);

	//format 24 hour standard clock and append leading 0s to hour, along with dynamic AM/PM formatting
	int clockHour24 = Format24HourClock(clockHour, amPm);
	string editedHour24 = AppendTime(clockHour24);

	//Append time to show leading 0s for min and sec
	string editedMin = AppendTime(clockMin);
	string editedSec = AppendTime(clockSec);

	//allow for dynamic AM/PM rendering in the display clock function depending on user input
	string editedAmPm = AppendAmPm(amPm);

	//Menu with dynamic AM/PM formatting to both clocks, AM/PM will change 24 clock and standard clock AM/PM display
	DisplayClocks(editedHour12, editedHour24, editedMin, editedSec, editedAmPm);
	cout << endl;

	//Stay in while loop while user decides to add time until 4 is input to exit program
	while (menuChoice != 4) {

		DisplayMenu();
		cout << endl;

		cout << "Please choose an option 1, 2, 3, or 4 to quit: ";
		cin >> menuChoice;

		//input validation for user menu
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid number\n";
			cin >> menuChoice;
		}
		cout << endl;

		if (menuChoice == 1) {
			addHour12 = AddHour12(clockHour12);
			editedHour12 = AppendTime(addHour12);

			addHour24 = AddHour24(clockHour24);
			editedHour24 = AppendTime(addHour24);

			clockHour12 = addHour12;
			clockHour24 = addHour24;
		}


		else if (menuChoice == 2) {
			addMin = AddMinute(clockMin);
			editedMin = AppendTime(addMin);
			clockMin = addMin;
		}

		else if (menuChoice == 3) {
			addSec = AddSecond(clockSec);
			editedSec = AppendTime(addSec);
			clockSec = addSec;
		}

		else if (menuChoice == 4) {
			break;
		}

		else {
			cout << "Invalid entry: please try again.." << endl;
			continue;
		}
		
		DisplayClocks(editedHour12, editedHour24, editedMin, editedSec, editedAmPm);
		cout << endl;
	}

	cout << "Thank you.." << endl;

	return 0;
}
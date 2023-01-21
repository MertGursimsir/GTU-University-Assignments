#include <iostream>
#include "header.h"
using namespace std;
using namespace Gursimsir;

int main(){
	cout << "This program tests the awesome DayOfYearSet.\n";

	string answer = "y";
	do{
		//Making test consecutively
		if (answer == "y") test();
		cout << "\n\n\nDo you want to test one more time? (y/n): ";
		cin >> answer;
		if(answer != "n" && answer != "y") cout << "Please enter valid input.\n";
		DayOfYearSet::reset();
	}while (answer != "n");

	cout << "\nGoodbye <3\n";
	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
using namespace std;

namespace Gursimsir{
	//static int for number of DayOfYear objects alive
	int DayOfYearSet::objectCount = 0;

	//DayOfYearSet Constructors
	DayOfYearSet::DayOfYearSet() : DayOfYearSet(50){ }

	DayOfYearSet::DayOfYearSet(int size) : capacity(size), used(0){
		doyp = new DayOfYear[capacity];
	}

	DayOfYearSet::DayOfYearSet(const DayOfYearSet& other) : capacity(other.getCapacity()), used(other.size()){
		doyp = new DayOfYear[capacity];
		for (int i = 0; i < used; ++i) doyp[i] = other[i];
	}
	
	DayOfYearSet::DayOfYearSet(vector <DayOfYear> dates) : capacity(dates.size()*2), used(0){
		doyp = new DayOfYear[capacity];
		for (int i = 0; i < dates.size(); ++i)
			this->add(dates[i]);
	}

	//DayOfYear Constructors
	DayOfYearSet::DayOfYear::DayOfYear() : day(1), month(1){ }
	DayOfYearSet::DayOfYear::DayOfYear(int dayValue) : month(1){ 
		if (dayValue < 1 || dayValue > 31){
			cout << "Invalid day value. \"1\" will be used as the day.\n";
			day = 1;
		}
		else day = dayValue;
	}
	DayOfYearSet::DayOfYear::DayOfYear(int dayValue,int monthValue){
		if (monthValue < 1 || monthValue > 12){
			cout << "Invalid value for date. \"1.1\" is going to be used for date.\n";
			day = 1;
			month = 1;
		}
		else{
			month = monthValue;
			switch(monthValue){
				case 1: if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 2: if(dayValue < 1 || dayValue > 29){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 3: if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 4: if(dayValue < 1 || dayValue > 30){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 5: if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 6: if(dayValue < 1 || dayValue > 30){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 7: if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 8: if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 9: if(dayValue < 1 || dayValue > 30){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 10:if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 11:if(dayValue < 1 || dayValue > 30){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
				case 12:if(dayValue < 1 || dayValue > 31){
							cout << "Invalid day value. \"1\" will be used as the day.\n";
							day = 1;
						}
						else day = dayValue;
						break;
			}
		}
	}

	//Overloaded assignment operator
	DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& rightSide){
		if (getCapacity() != rightSide.getCapacity()){
			delete [] doyp;
			doyp = new DayOfYear[rightSide.getCapacity()];
			//assigning equal place
		}

		capacity = rightSide.getCapacity();
		used = rightSide.size();

		for(int i = 0; i < size(); ++i) doyp[i] = rightSide[i];	//assigning values
		objectCount+=used;	//increment number of objectCount

		return *this;
	}

	//Printing details of the set
	ostream& operator<<(ostream& outputStream, const DayOfYearSet& printClass){
		outputStream << "\nThis set of DayOfYear objects has " << printClass.size() << " dates.\n"
			 		 << "Its capacity is " << printClass.getCapacity() << " now.\n"
			 		 << "Dates in this set are: \n";
		for (int i = 0; i < printClass.size(); ++i){
			outputStream << i+1 << ". DATE ----> ";
			switch(printClass[i].getMonth()){
				case 1: outputStream << printClass[i].getDay() << " January\n\n"; break;
				case 2: outputStream << printClass[i].getDay() << " February\n\n"; break;
				case 3: outputStream << printClass[i].getDay() << " March\n\n"; break;
				case 4: outputStream << printClass[i].getDay() << " April\n\n"; break;
				case 5: outputStream << printClass[i].getDay() << " May\n\n"; break;
				case 6: outputStream << printClass[i].getDay() << " June\n\n"; break;
				case 7: outputStream << printClass[i].getDay() << " July\n\n"; break;
				case 8: outputStream << printClass[i].getDay() << " August\n\n"; break;
				case 9: outputStream << printClass[i].getDay() << " September\n\n"; break;
				case 10:outputStream << printClass[i].getDay() << " October\n\n"; break;
				case 11:outputStream << printClass[i].getDay() << " November\n\n"; break;
				case 12:outputStream << printClass[i].getDay() << " December\n\n"; break;
			}
		}
		return outputStream;
	}

	//Comparison
	bool DayOfYearSet::operator==(const DayOfYearSet& rightSide)const{
		decltype(true) flag = true;
		int j;
		if (size() != rightSide.size()) flag = false; //They are not equal if their size are not equal.
		else{
			for (int i = 0; i < size(); ++i){
				for (j = 0 ; j < size(); ++j){
					if(doyp[i].getDay() == rightSide[j].getDay() && doyp[i].getMonth() == rightSide[j].getMonth()) break;
					//Comparing if the element in left-hand-side set exists in the right-hand-side set
				}
				if (j == size()){
					flag = false;
					break;
				}
			}
		}
		return flag;
	}
		
	bool DayOfYearSet::operator!=(const DayOfYearSet& rightSide)const{
		return !(*this == rightSide);
	}

	//Adding new element 
	void DayOfYearSet::add(DayOfYear date){
		for (int i = 0; i < size(); ++i){
			if (date.getDay() == doyp[i].getDay() && date.getMonth() == doyp[i].getMonth()){
				//cout << "This date already exists.\n\n";
				return;
			}
			//The element which already exists in set shouldn't be included
		}

		//check if we have enough space, if not allocate new memory
		if (used >= capacity){
			capacity *= 2; //incrementing the capacity
			DayOfYear* temp = new DayOfYear[capacity];	//allocate more memory
			for(int i = 0; i < used; ++i) temp[i] = doyp[i]; //assign every values 
			delete [] doyp;
			doyp = temp;
		}
		doyp[used] = date;
		used++;
		objectCount++;
	}

	//Remove an element
	void DayOfYearSet::remove(int index){
		if (index >= used || index < 0){
			//checking if index value proper
			cout << "Illegal index!\n";
			exit(1);
		}
		for(int i = index; i < size()-1; ++i){
			//slide every value by one
			doyp[i] = doyp[i+1];
		}
		used--;
		objectCount--;
	}

	//Union set
	DayOfYearSet DayOfYearSet::operator+(const DayOfYearSet& rightSide)const{
		DayOfYearSet temp;
		auto flag = true;
		
		for (int i = 0; i < size(); ++i) temp.add(doyp[i]); //add all elements in our set
		for (int i = 0; i < rightSide.size(); ++i){
			flag = true;
			for(int j = 0; j < temp.size(); ++j){
				if (rightSide[i].getDay() == temp[j].getDay() && rightSide[i].getMonth() == temp[j].getMonth()){ 
					flag = false; break; 
					//skipping same elements
				}
			}
			if (flag == true) temp.add(rightSide.doyp[i]);
			//adding different elements
		}
		objectCount -= temp.size();
		return DayOfYearSet(temp);
	}

	//Difference set
	DayOfYearSet DayOfYearSet::operator-(const DayOfYearSet& rightSide)const{
		DayOfYearSet temp;
		auto flag = true;

		for (int i = 0; i < size(); ++i){
			flag = true;
			for (int j = 0; j < rightSide.size(); ++j){
				if (doyp[i].getDay() == rightSide[j].getDay() && doyp[i].getMonth() == rightSide[j].getMonth()){
					flag = false; break;
					//skipping same elements
				}
			}
			if (flag == true) temp.add(doyp[i]);
			//adding different elements
		}
		objectCount -= temp.size();
		return DayOfYearSet(temp);
	}

	//Intersection set
	DayOfYearSet DayOfYearSet::operator^(const DayOfYearSet& rightSide)const{
		DayOfYearSet temp;

		for (int i = 0; i < size(); ++i){
			for (int j = 0; j < rightSide.size(); ++j){
				if (doyp[i].getDay() == rightSide[j].getDay() && doyp[i].getMonth() == rightSide[j].getMonth())
					temp.add(doyp[i]);
				//adding same elements
			}
		}
		objectCount -= temp.size();
		return DayOfYearSet(temp);
	}

	DayOfYearSet DayOfYearSet::operator!()const{
		DayOfYearSet temp;
		auto flag = true;

		for (int i = 1; i < 13; ++i){
			switch(i){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:for (int j = 1; j < 32; ++j){
							flag = true;
							for (int k = 0; k < size(); ++k){
								if (doyp[k].getDay() == j && doyp[k].getMonth() == i){
									flag = false;
									break;
								}
							}
							if (flag == true) {
								DayOfYear temp2(j, i);
								temp.add(temp2);
							}
						}
						break;
						//Checking if date exists in the set for January, March, May, July, August, October, December. If not --> add
				case 2:	for (int j = 1; j < 30; ++j){
							flag = true;
							for (int k = 0; k < size(); ++k){
								if (doyp[k].getDay() == j && doyp[k].getMonth() == 2){
									flag = false;
									break;
								}
							}
							if (flag == true) {
								DayOfYear temp2(j, i);
								temp.add(temp2);
							}
						}
						break;
						//Checking if date exists in the set for February. If not --> add
				case 4: 
				case 6:
				case 9:
				case 11:for (int j = 1; j < 31; ++j){
							flag = true;
							for (int k = 0; k < size(); ++k){
								if (doyp[k].getDay() == j && doyp[k].getMonth() == i){
									flag = false;
									break;
								}
							}
							if (flag == true) {
								DayOfYear temp2(j, i);
								temp.add(temp2);
							}
						}
						break;
						//Checking if date exists in the set for April, June, September, November. If not --> add
			}
		}
		objectCount -= temp.size();
		return DayOfYearSet(temp);
	}


	const DayOfYearSet::DayOfYear& DayOfYearSet::operator[](const int index)const{
		if (index >= used || index < 0)
	    {
	        cout << "Illegal index in DayOfYearSet.\n";
	        exit(1);
	    }
	    return doyp[index];
	    //returning the specified DayOfYear object if it is in the range
	}


	DayOfYearSet::DayOfYear& DayOfYearSet::operator[](const int index){
		if (index >= used || index < 0)
	    {
	        cout << "Illegal index in DayOfYearSet.\n";
	        exit(1);
	    }
	    return doyp[index];
	    //returning the specified DayOfYear object if it is in the range
	}

	//DESTRUCTOR
	DayOfYearSet::~DayOfYearSet(){
		delete [] doyp;
	}

	bool checkInput(){
		//Checking if we get the correct type
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			return false;
		}
		return true;
	}

	void test(){
		int capacity;

		//clear the saved file
		fstream clearSaved;
		clearSaved.open("saved.txt", std::fstream::out | std::fstream::trunc);
		clearSaved.close();

		//Get the capacity from user for our first set
		cout << "Your first set's constructor will take the capacity.\n"
			 << "Enter capacity for your very first, beautiful set: ";
		cin >> capacity;
		while(!checkInput()){
			cout << "Please enter valid number: ";
			cin >> capacity;
		}

		//Creating our first set with the one parameter constructor
		DayOfYearSet set1(capacity);
		//FILLING THE SET
		cout << "\nEnter up to " << capacity << " dates to add your set.\n"
			 << "Place negative number or zero to quit.\n";
		int day = 1, month = 1, i=0;
		while ((day > 0) && (month > 0) && i < capacity){
			cout << "Enter day: ";
			cin >> day;
			if (!checkInput()){
				cout << "Invalid input. Try again.\n";
				day = 1;
				continue;
			}
			if (day <= 0) break;
			cout << "Enter month: ";
			cin >> month;
			if (!checkInput()){
				cout << "Invalid input. Try again.\n";
				month = 1;
				continue;
			}
			if(month <= 0) break;
			set1.add(DayOfYearSet::DayOfYear(day, month));
			cout << endl;
			i++;
		}
		cout << "YOUR FIRST SET:\n";
		cout << set1;
		//Saving set1 to a file
		fstream saveSet1;
		saveSet1.open("set1.txt", fstream::out);
		saveSet1 << set1;
		saveSet1.close();
		cout << "This set has been saved to \"set1.txt\".\n\n";



		//Creating our first set with the constructor that takes vector as parameter
		cout << "\n\nYour second set's constructor will take a vector.\n"
			 << "So let's create the vector first. Enter the dates please.\n";
		vector <DayOfYearSet::DayOfYear> dates;
		//FILLING THE SET
		cout << "(Place negative number or zero to quit.)\n";
		day = 1; month = 1;
		while ((day > 0) && (month > 0)){
			cout << "Enter day: ";
			cin >> day;
			if (!checkInput()){
				cout << "Invalid input. Try again.\n";
				day = 1;
				continue;
			}
			if (day <= 0) break;
			cout << "Enter month: ";
			cin >> month;
			if (!checkInput()){
				cout << "Invalid input. Try again.\n";
				month = 1;
				continue;
			}
			if(month <= 0) break;
			dates.push_back(DayOfYearSet::DayOfYear(day, month));
			cout << endl;
		}
		DayOfYearSet set2(dates);
		cout << "YOUR SECOND SET:\n";
		cout << set2;
		//Saving set1 to a file
		fstream saveSet2;
		saveSet2.open("set2.txt", fstream::out);
		saveSet2 << set2;
		saveSet2.close();
		cout << "This set has been saved to \"set2.txt\".\n\n";

		//TOTAL NUMBER OF OBJECTS THANKS TO STATIC FUNCTION IN THE CLASS
		cout << "Total number of DayOfYear objects alive in all sets: "
			 << DayOfYearSet::getCount() << endl << endl;

		cout << "Now we have best 2 sets in the world.\n";
		cout << "Let's try our functions.\n\n";
		functionTests(set1, set2);
	}

	void functionTests(DayOfYearSet& set1, DayOfYearSet set2){
		//Checking the operators == and !=
		cout << "Firstly, let's look are these 2 sets equal\n--> ";
		if (set1 == set2) cout << "Yes, they are equal regardless of the keeping order.";
		else if (set1 != set2) cout << "No, they are not equal.";

		int index;
		//Checking the remove function twice --> for set1 and set2
		if (set1.size() != 0){
			cout << "\n\nNow, let's try to remove an element from the set1." << endl
				 << "Please enter index of the element which you want to remove: ";
			cin >> index;
			while(!checkInput()){
				cout << "Please enter valid number: ";
				cin >> index;
			}
			set1.remove(index);
			cout << "\nYOUR NEW SET:\n";
			cout << set1;
		}
		if (set2.size() != 0){
			cout << "\n\nNow, let's try to remove an element from the set2." << endl
				 << "Please enter index of the element which you want to remove: ";
			cin >> index;
			while(!checkInput()){
				cout << "Please enter valid number: ";
				cin >> index;
			}
			set2.remove(index);
			cout << "\nYOUR NEW SET:\n";
			cout << set2;
		}

		cout << "Size of set1: " << set1.size() << endl;
		cout << "Size of set2: " << set2.size() << endl;
		//TOTAL NUMBER OF OBJECTS THANKS TO STATIC FUNCTION IN THE CLASS
		cout << "Total number of DayOfYear objects alive in all sets: "
			 << DayOfYearSet::getCount() << endl << endl;


		cout << "Now, let's try operators for our sets.\n\n";
		operatorTests(set1, set2);
	}

	void operatorTests(DayOfYearSet set1, DayOfYearSet set2){
		DayOfYearSet set3, set4, set5, set6;

		set3 = set1 + set2;	//set3 is union set of set1 and set2
		set4 = set1 - set2;	//Set4 is difference set of set1 and set2
		set5 = set1 ^ set2;	//set5 is intersection set of set1 and set2
		set6 = !set2;		//set6 is complement set of set2

		cout << "\n\nUNION SET OF SET1 AND SET2\n"
			 << "--------------------------\n";
		cout << set3;

		cout << "\n\nDIFFERENCE SET (SET1 - SET2)\n"
			 << "----------------------------\n";
		cout << set4;

		cout << "\n\nINTERSECTION SET OF SET1 AND SET2\n"
			 << "---------------------------------\n";
		cout << set5;

		cout << "\n\nCOMPLEMENT SET OF SET2\n"
			 << "----------------------\n";
		cout << set6;


		//Checking [] operator for set6
		int index;
		cout << "\n\nNow let's get any element you want from the complement set.\n"
			 << "Please enter the date order (starting from 1): ";
		cin >> index;
		while(!checkInput()){
			cout << "Please enter valid number: ";
			cin >> index;
		}
		cout << index << ". date of the complement set is: " << set6[index-1].getDay() << "." << set6[index-1].getMonth() <<endl<<endl;


		cout << "Size of set1: " << set1.size() << endl
			 << "Size of set2: " << set2.size() << endl
			 << "Size of set3: " << set3.size() << endl
			 << "Size of set4: " << set4.size() << endl
			 << "Size of set5: " << set5.size() << endl
			 << "Size of set6: " << set6.size() << endl;
		cout << "Total number of DayOfYear objects alive in all sets: "
			 << DayOfYearSet::getCount() << endl << endl;


		//Checking De Morgan Rule  and save results to "saved.txt"
		cout << "Now let's look if 5 different set pairs satisfy De Morgan rule.\n";
		cout << "---------------------------------------------------------------\n";
		if (testDeMorgan(set1,set2) &&
			testDeMorgan(set2,set3) &&
			testDeMorgan(set3,set4) &&
			testDeMorgan(set4,set5) &&
			testDeMorgan(set5,set6)){
			cout << "All pairs satisfied De Morgan rule.\n"
				 << "You can check \"saved.txt\" to see subsequent 2 sets are same."
				 << endl << "( First set: !(s1 + s2)\n  Second set: (!s1 ^ !s2) )\n\n";
		}
	}

	bool testDeMorgan(const DayOfYearSet& set1, const DayOfYearSet& set2){
		fstream save;
		save.open("saved.txt", std::ios_base::app);

		save << !(set1+set2);
		save << (!set1 ^ !set2);
		save << "-----------------------------------------------------------------------------------\n"
		     << "===================================================================================\n"
		     << "-----------------------------------------------------------------------------------\n";
		save.close();
		return (!(set1 + set2) == (!set1 ^ !set2));
	}
}
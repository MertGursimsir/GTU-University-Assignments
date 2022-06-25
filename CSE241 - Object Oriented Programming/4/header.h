//This is header file for DayOfYearSet

#ifndef DTIME_H
#define DTIME_H
#include <vector>
using namespace std;

namespace Gursimsir{

	class DayOfYearSet{
	public:
		//Inner class of DayOfYearSet
		class DayOfYear{
		public:
			//There is no need for big three
			DayOfYear();
			DayOfYear(int dayValue);
			DayOfYear(int dayValue, int monthValue);

			//Getters
			int getDay()const {return day;};
			int getMonth()const {return month;}

			//Setters
			void setDay(int dayValue){day = dayValue;};
			void setMonth(int monthValue){month = monthValue;};
		private:
			int day;
			int month;
		};

		//BIG THREE
		DayOfYearSet(const DayOfYearSet& other);	//copy constructor 
		DayOfYearSet& operator=(const DayOfYearSet& rightSide);	//assignment operator
		~DayOfYearSet();	//destructor

		DayOfYearSet();							//no parameter constructor (assign capacity to 50)
		explicit DayOfYearSet(int size);		//constructor with size that determine the capacity
		DayOfYearSet(vector <DayOfYear> dates);	//constructor that takes DayOfYear vector

		friend ostream& operator<<(ostream& outputStream, const DayOfYearSet& printClass); //overloaded stream insertion operator
		bool operator==(const DayOfYearSet& rightSide)const;	//overloaded compare operator ==
		bool operator!=(const DayOfYearSet& rightSide)const;	//overloaded compare operator !=
		DayOfYearSet operator+(const DayOfYearSet& rightSide)const;	//overloaded + operator for union set
		DayOfYearSet operator-(const DayOfYearSet& rightSide)const;	//overloaded - operator for difference set
		DayOfYearSet operator^(const DayOfYearSet& rightSide)const;	//overloaded ^ operator for intersection set
		DayOfYearSet operator!()const;	//overloaded ! operator for complement set
		const DayOfYear& operator[](const int index)const;	//overloaded const index [] operator
		DayOfYear& operator[](const int index);				//overloaded index [] operator

		void add(DayOfYear date);	//adds element to set
		void remove(int index);		//removes element from set
		bool isFull()const {return capacity == used;} //checks if set is full
		int size()const {return used;};	//returns number of elements in the set
		int getCapacity()const{return capacity;};	//returns the capacity of the set

		//Functions to know the total number of DayOfYear objects alive
		static int getCount(){return objectCount;};
		static void reset(){objectCount = 0;}
	private:
		DayOfYear* doyp;//for array of DayOfYear objects
		int capacity;	//for the size of the array
		int used;		//for the number of elements in the array
		static int objectCount;
	};


	void test();		//function that starts the test
	bool checkInput();	//function to check input
	void functionTests(DayOfYearSet& set1, DayOfYearSet set2);				//function to test functions of the DayOfYearSet
	void operatorTests(DayOfYearSet set1, DayOfYearSet set2);				//function to test operators of the DayOfYearSet
	bool testDeMorgan(const DayOfYearSet& set1, const DayOfYearSet& set2);	//function to test De Morgan rule

}

#endif
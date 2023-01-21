/**
To compile: g++ 1901042646.cpp -o hw2
To run:		./hw2 {FILE_NAME}.txt
**/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

int numOfSets(string const str){
	//Function to learn how many sets in the given file.
	fstream file;
	string text;
	int setNumber = 0;
	file.open(str);
	while(!file.eof()){
		file >> text;
		if (text.length() == 1 && text[0] == static_cast<char>('A' + setNumber)) setNumber++;
		//Incrementing the number everytime we see a new upper case letter
	}
	file.close();
	return setNumber;
}

bool isOneToOne(vector<string> set){
	//Function to specify if given function is one-to-one
	for(int i = 0; i < set.size(); ++i)
		for(int j = 0; j < set.size() && i != j; ++j)
			if(set[i] == set[j]) return false;
	//We are examining the range set, 
	//if there are 2 elements which are same, then this means that 2 elements in our domain goes to the same element
	//and we know this break the one-to-one rule
	return true;
}

bool isFunc(vector<string> A, vector<string> B){
	//Function to learn if given function is really a function
	if (!isOneToOne(A)) return false; 		//Checking if one element match more than once in domain
	if (A.size() > B.size()) return false;	//Checking if there is unmatched element in A
	return true;
}

bool isOnto(vector<string> A, vector<string> B){
	//Function to specify if given function is onto
	bool flag;
	if (B.size() > A.size()){
		for (int i = A.size(); i < B.size(); ++i){
			flag = false;
			for (int j = 0; j < A.size() && !flag; ++j){
				if (B[j] == B[i]) flag = true;
			}
		}
		//We are checking the second set's elements
		//If there is different element which is not matched by the any element in the first set, then this function is not onto
		//Otherwise we can say function is onto
	}
	else flag = true;
	return flag;
}

void problem1(string const str){
	//Function to observe of a given function's specialities (onto, one-to-one, and validity)

	//SOME FILE STUFFS
	fstream file;
	string text;
	vector<string> A, B;
	file.open(str);
	file >> text;
	while (text != "B"){
		file >> text;
		if (text != "B") A.push_back(text);
	}
	while (getline(file, text)){
		if(text != "\t" && text != "\n" && !text.empty() ) B.push_back(text);
	}
	//Up to know, we have read 2 sets to our variables A and B in order.

	//Now it is time to determine the function's specialities
	cout << "Problem 1: ";
	if (!isFunc(A, B)) cout << "Not a function.\n";
	else if (isOnto(A, B) && !isOneToOne(B)) cout << "Onto but not one-to-one.\n";
	else if (!isOnto(A, B) && isOneToOne(B)) cout << "One-to-one but not onto.\n";
	else if (isOnto(A, B) && isOneToOne(B)) cout << "Bijective.\n";
	else if (!isOnto(A, B) && !isOneToOne(B)) cout << "Neither onto nor one-to-one.\n";

	file.close();
}

void problem2(string const str){
	//Function to observe of a inverse of a given function' specialities
	//Exactly the same function as problem1 but this time we change the order of reading sets from file

	//SOME FILE STUFFS AGAIN
	fstream file;
	string text;
	vector<string> A, B;
	file.open(str);
	file >> text;
	while (text != "B"){
		file >> text;
		if (text != "B") B.push_back(text);
	}
	while (getline(file, text)){
		if(text != "\t" && text != "\n" && !text.empty() ) A.push_back(text);
	}
	//Up to know, we have read 2 sets to our variables B and A in order.

	//Now it is time to determine the function's specialities
	cout << "Problem 2: ";
	if (!isFunc(A, B)) cout << "Not a function.\n";
	else if (isOnto(A, B) && !isOneToOne(B)) cout << "Onto but not one-to-one.\n";
	else if (!isOnto(A, B) && isOneToOne(B)) cout << "One-to-one but not onto.\n";
	else if (isOnto(A, B) && isOneToOne(B)) cout << "Bijective.\n";
	else if (!isOnto(A, B) && !isOneToOne(B)) cout << "Neither onto nor one-to-one.\n";

	file.close();
}

void problem3(string const str, int setNumber){
	//Function to observe specialities of function composition

	//SOME FILE STUFFS AGAIN
	fstream file;
	string text;
	vector<string> combinedSets;
	file.open(str);
	while (getline(file, text)){
		if(text != "\t" && text != "\n" && !text.empty() ) combinedSets.push_back(text);
	}
	//We get all the lines as 1 element to our combinedSets object.
	
	//setNo is for the number of sets, to identify upper case letter
	//temp is temporary value to hold former setNo value.
	int setNo = 0, temp, j;
	bool functionality=true, onto=true, oneToOne=false; //true-false values for functionality, onto, and one-to-one specialities of the function
	vector<string> set1, set2, firstSet;	//2 sets for each iteration and 1 set for hold the first set
	for (int i = 1; i < setNumber; ++i){
		set1.clear();
		set2.clear();
		j = 0;
		if (setNo != 0) setNo-=2;
		temp = setNo;

		//Reading sets from the file, 2 of them at each iteration
		while(combinedSets[j].length() != 1 || combinedSets[j][0] != static_cast<char>('A' + setNo)) j++;	
		//passing through the elements, until we get where we left at last iteration
		
		for(; j < combinedSets.size() && setNo-3!=temp; ++j){
			if (combinedSets[j].length() == 1 && combinedSets[j][0] == static_cast<char>('A' + setNo)) setNo++;
			else{
				//filling the sets
				if (temp==setNo-1) set1.push_back(combinedSets[j]);
				else set2.push_back(combinedSets[j]);
			}
		}

		if (i==1) firstSet = set1;	//assigning first set
		if (!isFunc(set1, set2)) {functionality = false; break;}	//checking functionality of each function in the composition
		if(i==setNumber-1) if (!isOnto(set1, set2)) onto = false;	//last function must be onto for our function composition to be onto
	}


	set<string> newSet;
	for(int i = 0; i < firstSet.size(); ++i) newSet.insert(set2[i]);
	//Here we assigned our last set's first x number to a set object (which all elements are different, x = number of elements in firstSet)
	if (newSet.size() == firstSet.size()) oneToOne = true;
	//We know that every element in our first set must go to the different element in the last set for our function composition to be one-to-one
	//According to our way of represent functions in files, first x number of last set must be different (x = number of elements in firstSet)
	//so that we can say our function composition is one-to-one

	if (!isOnto(firstSet, set2)) onto = false;
	//We are checking first set and last set to determine if our function composition is onto


	//Now it is time to determine the function's specialities
	cout << "Problem 3: ";
	if (!functionality) cout << "Not a function.\n";
	else if (onto && !oneToOne) cout << "Onto but not one-to-one.\n";
	else if (!onto && oneToOne) cout << "One-to-one but not onto.\n";
	else if (onto && oneToOne) cout << "Bijective.\n";
	else if (!onto && !oneToOne) cout << "Neither onto nor one-to-one.\n";

	file.close();
}

int main(int argc, char const *argv[]){
	//Checking if the program has been started correctly
	if (argc != 2){
		cerr << "Invalid number of arguments, exiting.\n";
		exit(1);
	}

	//Getting the number of sets and calling the proper functions.
	int setNumber = numOfSets(argv[1]);
	if (setNumber < 2){
		cerr << "Invalid number of sets, exiting.\n";
		exit(1);
	}
	else if (setNumber == 2){
		problem1(argv[1]);
		problem2(argv[1]);
	}
	else problem3(argv[1], setNumber);
	return 0;
}
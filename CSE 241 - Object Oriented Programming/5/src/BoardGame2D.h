#ifndef _GUARD1
#define _GUARD1

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std;

namespace Gursimsir{
	class BoardGame2D{
	public:
		//BIG THREE NOT NEEDED

		//Constructors
		BoardGame2D();
		BoardGame2D(int scoreValue, BoardGame2D* gamePtrValue);

		//Pure virtual functions
		virtual bool playUser(string movement) = 0;		
		virtual void playAuto() = 0;
		virtual bool endGame() = 0;	
		virtual void initialize() = 0;
		virtual void print() const = 0;

		//Overloaded << operator
		friend ostream& operator<<(ostream& outputStream, const BoardGame2D& game);

		//Final functions
		virtual void playAutoAll() final;
		virtual void playUser() final;

		//Static function
		static void playVector(vector <BoardGame2D*> games);

		//Other helpful functions
		int boardScore() const {return score;}
		void increaseScore() {score++;}
		void decreaseScore() {score--;}
		int randomGenerator(int min, int max);

	//Protected because we need to access them in derived classes
	protected:
		vector< vector<char> > board;
		int score;
		BoardGame2D* gamePtr;
	};	
}
	

#endif
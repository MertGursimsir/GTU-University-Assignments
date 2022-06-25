#ifndef _GUARD3
#define _GUARD3

#include "BoardGame2D.h"
using namespace std;

namespace Gursimsir{
	//Derived class from BoardGame2D
	class EightPuzzle : public BoardGame2D{
	public:
		//Constructor
		EightPuzzle();

		//Inherited functions
		virtual bool playUser(string movement);
		virtual void playAuto();
		virtual void print() const;
		virtual bool endGame();
		virtual void initialize();

		//Other helpful functions
		void calcScore();
		bool isSolvable();
		bool playUp(int row, int col);
		bool playDown(int row, int col);
		bool playLeft(int row, int col);
		bool playRight(int row, int col);
	};
}
	
#endif
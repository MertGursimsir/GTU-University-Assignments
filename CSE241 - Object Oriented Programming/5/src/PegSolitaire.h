#ifndef _GUARD2
#define _GUARD2

#include "BoardGame2D.h"
using namespace std;

namespace Gursimsir{
	//Derived class from BoardGame2D
	class PegSolitaire : public BoardGame2D{
	public:
		//Constructor
		PegSolitaire();

		//Inherited functions
		virtual bool playUser(string movement);
		virtual void playAuto();
		virtual void print() const;
		virtual bool endGame();
		virtual void initialize();

		//Helpful functions
		bool playUp(int row, int col);
		bool playDown(int row, int col);
		bool playLeft(int row, int col);
		bool playRight(int row, int col);
	};
}
	

#endif
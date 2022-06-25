#ifndef _GUARD4
#define _GUARD4

#include "BoardGame2D.h"
using namespace std;

namespace Gursimsir{
	//Derived class from BoardGame2D
	class Klotski : public BoardGame2D{
	public:
		//Constructor
		Klotski();

		//Inherited functions
		virtual bool playUser(string movement);
		virtual void playAuto();
		virtual void print() const;
		virtual bool endGame();
		virtual void initialize();

		//Other helpful functions
		void calcScore();
		bool playUp(int row, int col);
		bool playDown(int row, int col);
		bool playLeft(int row, int col);
		bool playRight(int row, int col);
	};
}
	
#endif
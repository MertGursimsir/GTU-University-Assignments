#ifndef _GUARD1
#define _GUARD1

#include <iostream>
#include <memory>
using namespace std;

namespace Gursimsir{
	template<class T>
	class Iterable{
	public:
		virtual bool empty() const = 0;
		virtual int size() const = 0;
		virtual void erase(T* itr) = 0;
		virtual void clear() = 0;
		virtual T* begin() const = 0;
		virtual T* end() const = 0;
		virtual const T* cbegin() const = 0;
		virtual const T* cend() const = 0;
	};
}
//_it=make_shared<T[]>(10)

#endif
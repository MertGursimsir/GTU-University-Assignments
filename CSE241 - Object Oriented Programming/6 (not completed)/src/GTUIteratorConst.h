#ifndef _GUARD3
#define _GUARD3

#include "Iterable.h"

namespace Gursimsir{
	template<class T>
	class GTUIteratorConst : public Iterable<T>{
	public:
		GTUIteratorConst();
		GTUIteratorConst(T* ptr);

		GTUIteratorConst& operator++();

		GTUIteratorConst operator++(int);

		GTUIteratorConst& operator--();

		GTUIteratorConst operator--(int);

		T* operator->(){ return _itc; }
		T& operator*(){ return *_itc; }

		bool operator==(const GTUIteratorConst& other) const { return _itc == other._itc; }

		const GTUIteratorConst& operator=(const GTUIteratorConst& other) { _itc = other._itc; return other; }

		virtual bool empty() const {return true;}
		virtual int size() const {return 0;}
		virtual void erase(T* itr) {}
		virtual void clear() {}
		virtual T* begin() const {T* garbage; return garbage;}
		virtual T* end() const {T* garbage; return garbage;}
		virtual const T* cbegin() const {T* garbage; return garbage;}
		virtual const T* cend() const {T* garbage; return garbage;}

		const shared_ptr<T> _itc;
	};
}

#endif
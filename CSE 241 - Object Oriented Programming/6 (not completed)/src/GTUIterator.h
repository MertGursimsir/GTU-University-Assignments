#ifndef _GUARD2
#define _GUARD2

#include "Iterable.h"

namespace Gursimsir{
	template<class T>
	class GTUIterator : public Iterable<T>{
	public:
		GTUIterator();
		GTUIterator(T* ptr);

		GTUIterator& operator++();

		GTUIterator operator++(int);

		GTUIterator& operator--();

		GTUIterator operator--(int);

		T* operator->(){ return _it; }
		T& operator*(){ return *_it; }

		void setter(shared_ptr<T> temp) {_it = temp;}

		bool operator==(const GTUIterator& other) const { return _it == other._it; }

		const GTUIterator& operator=(const GTUIterator& other) { _it = other._it; return other; }

		virtual bool empty() const {return true;}
		virtual int size() const {return 0;}
		virtual void erase(T* itr) {}
		virtual void clear() {}
		virtual T* begin() const {T* garbage; return garbage;}
		virtual T* end() const {T* garbage; return garbage;}
		virtual const T* cbegin() const {T* garbage; return garbage;}
		virtual const T*cend() const {T* garbage; return garbage;}

		shared_ptr<T> _it;
	};
}

#endif
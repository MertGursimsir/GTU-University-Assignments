#ifndef _GUARD4
#define _GUARD4

#include "GTUIterator.h"
#include "GTUIteratorConst.h"

namespace Gursimsir{
	template<class T>
	class GTUVector : public Iterable<T>{
	public:
		GTUVector();
		explicit GTUVector(int capacityValue);
		GTUVector(const GTUVector& other);

		T* begin() const { return iterator._it.get(); }
		T* end() const { return iterator._it.get() + _size; }
		const T* cbegin() const { return constIterator._itc.get(); }
		const T* cend() const { return constIterator._itc.get() + _size; }
		bool empty() const {return _size == 0;}
		int size() const {return _size; }
		void clear() {_size = 0; }

		void erase (T* itr);
		void add (const T& value);
		T& operator[](int index);

	private:
		GTUIterator<T> iterator;
		GTUIteratorConst<T> constIterator;

		shared_ptr<T> _data;
		int _size;
		int _capacity;


	};
}

#endif
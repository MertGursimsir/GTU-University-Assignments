#include "GTUIterator.h"

namespace Gursimsir{
	template<class T>
	GTUIterator<T>::GTUIterator() : _it(nullptr) { }

	template<class T>
	GTUIterator<T>::GTUIterator(T* ptr) : _it(ptr) { }

	template<class T>
	GTUIterator<T>& GTUIterator<T>::operator++(){	//pre-increment
		_it = _it.get()++;
		return *this;
	}

	template<class T>
	GTUIterator<T> GTUIterator<T>::operator++(int){
		GTUIterator<T> iterator = *this;
		++(*this);
		return iterator;
	}

	template<class T>
	GTUIterator<T>& GTUIterator<T>::operator--(){	//pre-decrement
		_it = _it.get()--;
		return *this;
	}

	template<class T>
	GTUIterator<T> GTUIterator<T>::operator--(int){
		GTUIterator<T> iterator = *this;
		--(*this);
		return iterator;
	}
}
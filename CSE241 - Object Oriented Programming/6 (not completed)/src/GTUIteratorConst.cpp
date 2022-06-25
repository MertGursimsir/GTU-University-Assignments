#include "GTUIteratorConst.h"

namespace Gursimsir{
	template<class T>
	GTUIteratorConst<T>::GTUIteratorConst() : _itc(nullptr) { }

	template<class T>
	GTUIteratorConst<T>::GTUIteratorConst(T* ptr) : _itc(ptr) { }

	template<class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator++(){	//pre-increment
		_itc = _itc.get()++;
		return *this;
	}

	template<class T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator++(int){
		GTUIteratorConst<T> iterator = *this;
		++(*this);
		return iterator;
	}

	template<class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator--(){	//pre-decrement
		_itc = _itc.get()--;
		return *this;
	}

	template<class T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator--(int){
		GTUIteratorConst<T> iterator = *this;
		--(*this);
		return iterator;
	}
}
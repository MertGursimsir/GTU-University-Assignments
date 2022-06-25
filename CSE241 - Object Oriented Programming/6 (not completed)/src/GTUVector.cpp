#include "GTUVector.h"

namespace Gursimsir{
	template<class T>
	GTUVector<T>::GTUVector(){
		size = 0;
		_capacity = 10;
		_data = new T[_capacity];
		iterator.setter(_data);
		constIterator.setter(_data);
	}

	template<class T>
	GTUVector<T>::GTUVector(int capacityValue){
		size = 0;
		_capacity = capacityValue;
		_data = new T[_capacity];
		iterator.setter(_data);
		constIterator.setter(_data);
	}

	template<class T>
	void GTUVector<T>::add(const T& value){
		if(_size >= _capacity){
			_capacity *= 2;
			_size++;
			shared_ptr<T> temp = _data;
			for(int i = 0; i < size()-1; ++i){
				*(temp.get()+i) = *(_data.get()+i);
			}
			*(temp.get()+size()-1) = value;
			_data = temp;
		}
		else{
			_size++;
			*(_data.get()+size()-1) = value;
		}
	}

	template<class T>
	T& GTUVector<T>::operator[](int index){
		if (index >= _size){
			cerr << "INVALID INDEX.\n";
		}
		else return *(_data.get()+index);
	}
}
#pragma once
#include <cassert> 

template <class Type> 

class Array {
private: 
	int array_size; 
	int *array_data; 

public: 
	Array() :
		array_size(0), array_data(nullptr)
	{
		cout << "Конструктор создания пустого массива" << endl; 
	}
	Array(int size) : array_size(size)
	{
		cout << "Конструктор создания массива заданного размера (с проверкой)" << endl;
		assert(size >= 0);
		if (size > 0)
			array_data = new int[size];
		else
			array_data = nullptr;
	}
	~Array()
	{
		cout << "Деструктор" << endl;
		delete[] array_data; 
	}

	void erase()
	{
		cout << "Функция для очистки массива" << endl;
		delete[] array_data; 
		array_data = nullptr; 
		array_size = 0;
	}

	int& operator [] (int index)
	{
		cout << "Перегрузка []" << endl;
		assert(index >= 0 && index < array_size);
		return array_data[index];
	}
	int getSize() {
		cout << "Длина массива (функция)" << endl; 
		return array_size; 
	}

	void reallocate(int new_size) // будет удалять элементы массива 
	{
		erase();
		if (new_size <= 0)
			return; 
		array_data = new int[new_size];
		array_size = new_size;
	}

	void resize(int new_size) // не будет удалять элементы массива 
	{
		if (new_size == array_size)
			return;
		if (new_size <= 0)
		{
			erase();
			return;
		}
		int* data = new int[new_size];
		if (array_size > 0)
		{
			int Elements_to_be_copied = (new_size > array_size) ? array_size : new_size;
			for (int index = 0; index < Elements_to_be_copied; index++)
				data[index] = array_data[index];
		}
		delete[] array_data;
		array_data = data; 
		array_size = new_size; 
	}

	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= array_size);
		int* data = new int[array_size + 1];
		for (int before = 0; before < index; before++)
			data[before] = array_data[before];
		data[index] = value;
		for (int after = index; after < array_size; after++)
			data[after + 1] = array_data[after];
		delete[] array_data;
		array_data = data;
		array_size++;
	}

	void remove(int index)
	{
		assert(index >= 0 && index < array_size);
		if (array_size == 1)
		{
			erase();
			return;
		}
		int* data = new int[array_size - 1];
		for (int before = 0; before < index; ++before)
			data[before] = array_data[before];
		for (int after = index + 1; after < array_size; ++after)
			data[after - 1] = array_data[after];
		delete[] array_data;
		array_data = data;
		array_size--;
	}
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, array_size); }

	int getLength() { 
		cout << "Длина массива" << endl; 
		return array_size; }
};
#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// сюда не смотрим, не удалась попытка 


using namespace std; 


class Films {
	int newDuration; 
	string newTitle; 
	string newGenre; 
	int* A;
	size_t FilmsSize; 
	size_t MaxSize = 5; 

public: 
	Films() noexcept {
		cout << "Создание пустого вектора!" << endl;
		vector<string> films_1 = {};
	};
	Films(const size_t MaxSize) noexcept {
		cout << "Создание нового вектра с добавлением фильмов!" << endl;
		vector<Films> films_2(5);
		films_2.push_back(Films(170, "IT: 2", "Horror"));
		films_2.push_back(Films(178, "The Lord of the Rings: The Fellowship of the Ring", "Fantasy"));
		films_2.push_back(Films(179, "The Lord of the Rings: The Two Towers", "Fantasy"));
		films_2.push_back(Films(201, "The Lord of the Rings: The Return of the King", "Fantasy"));
		films_2.push_back(Films(116, "Passengers", "Science Fiction"));
	};
	~Films() noexcept {
		delete[] A;
	}

	void push_front(const string& elem);
	void push_back(const string& elem);
	void resize(const size_t FilmsSize) noexcept;
	void insert(const unsigned position, const string& elem);
	void erase(const unsigned firstPosition, const unsigned secondPosition);
	void clear() noexcept; 

	constexpr size_t getSize() const noexcept {
		return FilmsSize;
	}
	constexpr size_t getCapacity() const noexcept {
		return MaxSize;
	}
	int& operator[](const int index) const noexcept {
		return A[index];
	}
	//======================== работа внутри вектора с данными =================================

	Films(int Duration = 0, const string& Title = "", const string& Genre = "");

	void Set_Title(const string& Title) { newTitle = Title; }
	string Get_Title() const {
		return newTitle;
	}

	void Set_Duration(int minutes) { newDuration = minutes; }
	int Duration() const { return newDuration; }

	void Set_Genre(const string& Genre) { newGenre = Genre; }
	string Get_Genre() const { return newGenre; }

	void Films<string>::erase(int firstPosition, int secondPosition) {
		int difference = secondPosition - firstPosition;
		if (difference >= 0 && difference < FilmsSize) {
			int* tempArr = new int[MaxSize];
			unsigned i = 0;
			for (; i < firstPosition; ++i) {
				tempArr[i] = A[i];
			}
			for (; i < FilmsSize - difference; ++i) {
				tempArr[i] = A[i + difference + 1];
			}
			FilmsSize -= difference + 1;

			delete[] A;
			A = tempArr;
		};
};
// =========================операторы ========================================================
int operator==(const Films& film1, const Films& film2);
int operator<(const Films& film1, const Films& film2);


Films::Films(int Duration, const string& Title, const string& Genre) {
	newDuration = Duration;
	newTitle = Title; 
	newGenre = Genre;
}

int operator==(const Films& film1, const Films& film2)
{
	return film1.Duration() == film2.Duration();
}

int operator<(const Films& film1, const Films& film2)
{
	return film1.Duration() < film2.Duration();
}


#pragma once
#include <iostream>

using namespace std;

class QueueRing {
	int* Wait; // очередь
	int MaxQueueLenght; // максимальный размер
	int QueueLenght; // текущий размер

public:
	QueueRing(int m); // конструктор
	~QueueRing(); // деструктор
	void add(int c); // добавление элемента
	int extract(); // извлечение элемента
	void clear(); // очистка
	bool isEmpty(); // проверка на пустоту
	bool isFull(); // проверка на изобилие (переполнение)
	int getCount(); // количество элементов
	void show(); // показ моды
};



void QueueRing::show() {
	for (int i = 0; i < QueueLenght; i++) {
		cout << Wait[i] << " ";
	}
	cout << endl;
}

QueueRing::~QueueRing() {
	delete[] Wait;
}

QueueRing::QueueRing(int m) {
	MaxQueueLenght = m;
	Wait = new int[MaxQueueLenght];
}

bool QueueRing::isEmpty() {
	return QueueLenght == 0;
}

bool QueueRing::isFull() {
	return QueueLenght == MaxQueueLenght;
}

int QueueRing::getCount() {
	return QueueLenght;
}

void QueueRing::add(int c) {
	if (!isFull()) Wait[QueueLenght++] = c;
}

int QueueRing::extract() {
	if (!isEmpty()) {
		int temp = Wait[0];
		for (int i = 1; i < QueueLenght; i++) {
			Wait[i - 1] = Wait[i];
		}
		Wait[QueueLenght - 1] = temp;

		return 1;
	}
	else return -1;
}

void QueueRing::clear() {
	QueueLenght = 0;
}


#pragma once
#include <iostream>
using namespace std;

class Queue {
	int* Wait; // очередь
	int MaxQueueLenght; // максимальный размер
	int QueueLenght; // текущий размер

public:
	Queue(int m); // конструктор
	~Queue(); // деструктор
	void add(int c); // добавление элемента
	int extract(); // извлечение элемента
	void clear(); // очистка
	bool isEmpty(); // проверка на пустоту
	bool isFull(); // проверка на изобилие (переполнение)
	int getCount(); // количество элементов
	void show(); // показ моды
};



void Queue::show() {
	for (int i = 0; i < QueueLenght; i++) {
		cout << Wait[i] << " ";
	}
	cout << endl;
}

Queue::~Queue() {
	delete[] Wait;
}

Queue::Queue(int m) {
	MaxQueueLenght = m;
	Wait = new int[MaxQueueLenght];
}

bool Queue::isEmpty() {
	return QueueLenght == 0;
}

bool Queue::isFull() {
	return QueueLenght == MaxQueueLenght;
}

int Queue::getCount() {
	return QueueLenght;
}

void Queue::add(int c) {
	if (!isFull()) Wait[QueueLenght++] = c;
}

int Queue::extract() {
	if (!isEmpty()) {
		int temp = Wait[0];
		for (int i = 1; i < QueueLenght; i++) {
			Wait[i - 1] = Wait[i];
		}
		QueueLenght--;
		return temp;
	}
	else return -1;
}

void Queue::clear() {
	QueueLenght = 0;
}
#pragma once
#include <iostream>

using namespace std;

class QueuePriority {
	int* Wait; // �������
	int* Pri;
	int MaxQueueLenght; // ������������ ������
	int QueueLenght; // ������� ������

public:
	QueuePriority(int m); // �����������
	~QueuePriority(); // ����������
	void add(int c, int p); // ���������� ��������
	int extract(); // ���������� ��������
	void clear(); // �������
	bool isEmpty(); // �������� �� �������
	bool isFull(); // �������� �� �������� (������������)
	int getCount(); // ���������� ���������
	void show(); // ����� ����
};



void QueuePriority::show() {
	for (int i = 0; i < QueueLenght; i++) {
		cout << Wait[i] << " - " << Pri[i] << endl;
	}
	cout << endl;
}

QueuePriority::~QueuePriority() {
	delete[] Wait;
	delete[] Pri;
}

QueuePriority::QueuePriority(int m) {
	MaxQueueLenght = m;
	Wait = new int[MaxQueueLenght];
	Pri = new int[MaxQueueLenght];
}

bool QueuePriority::isEmpty() {
	return QueueLenght == 0;
}

bool QueuePriority::isFull() {
	return QueueLenght == MaxQueueLenght;
}

int QueuePriority::getCount() {
	return QueueLenght;
}

void QueuePriority::add(int c, int p) {
	if (!isFull()) {
		Wait[QueueLenght] = c;
		Pri[QueueLenght] = p;
		QueueLenght++;
	}
}

int QueuePriority::extract() {
	if (!isEmpty()) {
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLenght; i++) {
			if (Pri[i] < max_pri) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		}

		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		for (int i = pos_max_pri; i < QueueLenght - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}

		QueueLenght--;
		return temp1;
	}
	else return -1;
}

void QueuePriority::clear() {
	QueueLenght = 0;
}
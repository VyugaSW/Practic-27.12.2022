
#include <Windows.h>
#include <iostream>
#include <string>
#include "Queue.h"
#include "QueuePriority.h"
#include "QueueRing.h"

using namespace std;

int main()
{
	srand(time(NULL));

	QueuePriority qu(25);
	for (int i = 0; i < 5; i++) {
		qu.add(rand() % 56, rand()%10);
	}
	qu.show();
	cout << qu.extract() << endl;
	qu.show();




}


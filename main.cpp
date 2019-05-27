#include<iostream>
#include"SeqList.h"
using namespace std;
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;
//½øÖÆ×ª»»£¨2~16£©
int exchange(int left, int right, int N) {
	if (left >= N) {
		left = exchange(left / N, left%N, N);
	}
	return 10 * left + right;
}
void Exchange(int num, int N) {
	int a = num % N;
	if (num/N != 0) {
		Exchange(num / N, N);
	}
	switch (a)
	{
	case 1:
		cout << a;
		break;
	case 2:
		cout << a;
		break;
	case 3:
		cout << a;
		break;
	case 4:
		cout << a;
		break;
	case 5:
		cout << a;
		break;
	case 6:
		cout << a;
		break;
	case 7:
		cout << a;
		break;
	case 8:
		cout << a;
		break;
	case 9:
		cout << a;
		break;
	case 10:
		cout << 'A';
		break;
	case 11:
		cout << 'B';
		break;
	case 12:
		cout << 'C';
		break;
	case 13:
		cout << 'D';
		break;
	case 14:
		cout << 'E';
		break;
	case 15:
		cout << 'F';
		break;
	default:
		break;
	}
}
int main() {
	while (true)
	{
		int thenum = 0;
		int N = 0;
		cin >> thenum;
		cin >> N;
		if (N < 10) {
			cout << exchange(thenum / N, thenum%N, N) << endl;
		}
		else {
			Exchange(thenum, N);
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
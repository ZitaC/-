#include<vector>
#include<iostream>
using namespace std;
int main() {//输入四个数字代表(a-b,b-c,a+b,b+c)求出abc
	vector<int> arr(4);
	for (int i = 0; i < 4; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; ++i) {
		if ((arr[i] < -30) || (arr[i] > 30)) {
			cout << "No" << endl;
		}
	}
	int _A = 0, _B = 0, _C = 0;
	if ((arr[0] + arr[2]) % 2 == 0) {
		_A = (arr[0] + arr[2]) / 2;
		_B = _A - arr[0];
		_C = _B - arr[1];
		if (_A < 0 || _B < 0 || _C < 0) {
			cout << "No" << endl;
		}
		else {
			cout << _A << ' ' << _B << ' ' << _C << endl;
		}
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
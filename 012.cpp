#include<iostream>
using namespace std;
int main() {//�õ�һ��byte���Ķ������������1�ĸ���
	int a = 0;
	cin >> a;
	int num = 0;
	int maxnum = 0;
	for (int i = 0; i < 8; ++i) {
		if (((1 << i) & a) == 0) {
			if (num > maxnum) {
				maxnum = num;
			}
			num = 0;
		}
		else {
			++num;
		}
	}
	if (num > maxnum) {
		maxnum = num;
	}
	cout << maxnum << endl;
	system("pause");
	return 0;
}
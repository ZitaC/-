//��a��b����С������
#include<iostream>
using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);
int main() {
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;
	cout << lcm(a, b) << endl;
	system("pause");
	return 0;
}
int gcd(int a, int b) {//greatest common divisor  ���Լ��
	int num = 0;
	if (a > b)
		num = b;
	else
		num = a;
	for (int i = num; i > 1; --i) {
		if (a%i == 0 && b%i == 0) {
			return i;
		}
	}
	return 1;
}
int lcm(int a, int b) {//��С������
	return (a*b) / gcd(a, b);
}
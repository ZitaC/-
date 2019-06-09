#include<iostream>
using namespace std;
//输出两个组成一个偶数差最小的素数
bool isprime(int a){
	if (a <= 1)
	{
		return false;
	}
	for (int i = 2; i < a; i++)
	{
		if (a == 2) {
			return true;
		}
		if (a%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main() {
	int n = 0;
	while (cin >> n) {
		for (int i = n / 2; i < n; ++i) {
			if (isprime(i)) {
				if (isprime(n - i)) {
					cout << n - i << endl;
					cout << i << endl;
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}
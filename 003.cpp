#include <iostream>
#include<vector>
using namespace std;
int main() {//��Ԫ�ظ���ΪN���������м�������������
	unsigned int n = 0;
	cin >> n;
	vector<int> s1(n);
	for (unsigned int i = 0; i < n; i++) {
		cin >> s1[i];
	}

	int sum = 1;
	for (unsigned int i = 0; i + 2 < n; i++) {
		if ((s1[i + 1] > s1[i] && s1[i + 1] > s1[i + 2]) ||
			(s1[i + 1] < s1[i] && s1[i + 1] < s1[i + 2])
			) {
			++sum;
			i += 1;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
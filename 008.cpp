#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {//��һ������쳲����������������һ�����Ĳ�
	int n = 0;
	cin >> n;
	vector<int> arr(2);
	arr[0] = 0;
	arr[1] = 1;
	while (1) {
		if (arr[1] >= n) {
			if (arr[1] - n < n - arr[0]) {
				cout << arr[1] - n << endl;
				break;
			}
			else {
				cout << n - arr[0] << endl;
				break;
			}
		}
		int temp = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	system("pause");
	return 0;
}


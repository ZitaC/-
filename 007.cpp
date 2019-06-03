#include<iostream>
#include<string>
#include<vector>
using namespace std;



//重做！！！
//求一个数组中连续子数组的和的最大值

int main() {
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (int j = 0; j < n; ++j) {
		cin >> arr[j];
	}
	int i = 0;
	int num = 0;
	int maxnum = 0;
	int count = 0;
	for (i; i < n; ++i) {

		if (arr[i] < 0) {
			if (num == 0) {
				count = 0;
				continue;
			}
			int sum = 0;
			int _count = 0;
			for (int j = i; j < n; ++j) {
				sum += arr[j];
				_count++;
				if (sum >= 0) {
					if (j == n - 1 && sum < arr[0]) {
						if (maxnum < num)
							maxnum = num;
						num = 0;
						break;
					}
					num += sum;
					count += _count;
					if (maxnum < num)
						maxnum = num;
					i = j;
					break;
					
				}
				if (j == n - 1) {
					if (maxnum < num)
						maxnum = num;
					num = 0;
					count = 0;
					++i;
				}
			}
			continue;
		}
		num += arr[i];
		count++;
		if (maxnum < num)
			maxnum = num;
	}
	if (count == n) {
		if (arr[0] > arr[n - 1]) {
			maxnum = maxnum - arr[n - 1];
		}
		else {
			maxnum = maxnum - arr[0];
		}
	}
	//
	reverse(arr.begin(), arr.end());

	int i1 = 0;
	int num1 = 0;
	int maxnum1 = 0;
	int count1 = 0;
	for (i1; i1 < n; ++i1) {
		if (num1 == 0 && arr[i1] < 0) {
			count1 = 0;
			continue;
		}
		if (arr[i1] < 0) {
			int sum1 = 0;
			int _count1 = 0;
			for (int j1 = i1; j1 < n; ++j1) {
				sum1 += arr[j1];
				_count1++;
				if (sum1 >= 0) {
					if (j1 == n - 1 && sum1 < arr[0]) {
						break;
					}
					num1 += sum1;
					count1 += _count1;
					if (maxnum1 < num1)
						maxnum1 = num1;
					i1 = j1;
					break;

				}
				if (j1 == n - 1) {
					if (maxnum1 < num1)
						maxnum1 = num1;
					num1 = 0;
					count1 = 0;
					++i1;
				}
			}
			continue;
		}
		num1 += arr[i1];
		count1++;
		if (maxnum1< num1)
			maxnum1 = num1;
	}
	if (count1 == n) {
		if (arr[0] > arr[n - 1]) {
			maxnum1 = maxnum1 - arr[n - 1];
		}
		else {
			maxnum1 = maxnum1 - arr[0];
		}
	}
	if (maxnum < maxnum1)
		maxnum = maxnum1;
	cout << maxnum << endl;
	system("pause");
	return 0;
}

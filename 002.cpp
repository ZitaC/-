#include<iostream>
#include<vector>
using namespace std;

//在一个数组中找到出现大于一半的元素
void quicksort(vector<int>& arr, int low, int high) {
	if (high <= low) return;
	int i = low;
	int j = high;
	int key = arr[low];
	while (true)
	{
		while (j > low)
		{
			if (arr[j] < key) {
				break;
			}
			--j;
		}
		while (i < high)
		{
			if (arr[i] > key) {
				break;
			}
			++i;
		}
		if (i >= j)
			break;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	quicksort(arr, low, j - 1);
	quicksort(arr, j + 1, high);
}
int text2() {
	vector<int> arr(100);
	int n = 0;
	while (n <= 100)
	{
		cin >> arr[n];
		++n;
		if (cin.get() == '\n') {
			break;
		}
	}
	arr.resize(n);
	quicksort(arr, 0, n - 1);
	int num = arr[0];
	for (int i = 0, len = 0; i < n; ++i, ++len) {
		if (n % 2 == 1) {
			if (arr[i] != num) {
				if (len > n / 2) {
					cout << num << endl;
					break;
				}
				len = 0;
				num = arr[i];
			}
		}
		else {
			if (arr[i] != num) {
				if (len >= n / 2) {
					cout << num << endl;
					break;
				}
				len = 0;
				num = arr[i];
			}
		}
	}
}

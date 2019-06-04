//根据判断N个字符串是否根据字典序或长度排序
#include<string>
#include<iostream>
#include<vector>
using namespace std;
bool islengths(vector<string> s,int n);
bool islexicographically(vector<string> s, int n);
int main() {
	int n = 0;
	cin >> n;
	cin.get();
	vector<string> arr(n);
	for (int i = 0; i < n ; ++i) {
		getline(cin, arr[i]);
	}
	bool a = islengths(arr, n);
	bool b = islexicographically(arr, n);
	if (a&&b) {
		cout << "both" << endl;
	}
	else if (a) {
		cout << "lengths" << endl;
	}
	else if (b) {
		cout << "lexicographically" << endl;
	}
	else {
		cout << "none" << endl;
	}
	system("pause");
	return 0;
}
bool islengths(vector<string> s, int n) {
	if (n == 1)
		return true;
	for (int i = 1; i < n; ++i) {
		if (s[i].size() < s[i - 1].size()) {
			return false;
		}
	}
	return true;
}
bool islexicographically(vector<string> s, int n) {
	if (n == 1)
		return true;
	for (int i = 1; i < n; ++i) {
		unsigned int size = 0;
		if (s[i].size() > s[i - 1].size()) {
			size = s[i - 1].size();
		}
		else{
			size = s[i].size();
		}
		for (unsigned int j=0,k=0; j<size; ++j) {
			if (s[i - 1][j] > s[i][j]) {
				return false;
			}
			else if (s[i - 1][j] == s[i][j]) {
				++k;
			}
			if (k == size && s[i - 1].size() > s[i].size()) {
				return false;
			}
		}
	}
	return true;
}
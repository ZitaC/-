#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {//以单词为单位逆转字符串
	string s1;
	getline(cin, s1);
	string s2;
	int i = s1.size() - 1;
	int j = s1.size();
	for (int cur; i >= 0; --i) {
		if (s1[i] == ' ') {
			for (cur = i + 1; cur < j; ++cur) {
				s2 = s2 + s1[cur];
			}
			j = i;
			s2 += s1[i];
		}
		if (i == 0) {
			for (cur = i; cur < j; ++cur) {
				s2 = s2 + s1[cur];
			}
		}
	}
	cout << s2 << endl;
	system("pause");
	return 0;
#include<string>
#include<iostream>
using namespace std;
int text1() {//在一个字符串中找到最长的连续数字
	string s1;
	getline(cin, s1);
	string s2;
	int sum = s1.size();
	int len = 0;
	int key = 0;
	for (int i = 0; i < sum; i++) {
		if (s1[i] == '0' || s1[i] == '1' || s1[i] == '2' || s1[i] == '3' || s1[i] == '4' || s1[i] == '5'
			|| s1[i] == '6' || s1[i] == '7' || s1[i] == '8' || s1[i] == '9') {

			for (int j = i; j < sum; j++) {

				if ((s1[j] != '0' && s1[j] != '1' && s1[j] != '2' && s1[j] != '3' && s1[j] != '4' && s1[j] != '5'
					&& s1[j] != '6' && s1[j] != '7' && s1[j] != '8' && s1[j] != '9') || j == sum - 1) {

					if ((j - i) >= len) {
						len = j - i;
						key = i;
					}
					i = j;
					break;

				}
			}
		}
	}
	for (int i = 0; i < len; i++) {
		s2 += s1[key + i];
	}
	if (len > 0) {
		cout << s2 << endl;
	}
}
#include <iostream>
#include<string>
#include<vector>
using namespace std;
#if 0
int main() {
	unsigned int n = 0;
	cin >> n;
	vector<int> s1(n);
	for (unsigned int i = 0; i < n; i++) {
		cin >> s1[i];
	}

	int sum = 1;
	for (unsigned int i = 0; i + 2 < n ; i++) {
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
#endif

#if 0
int main() {
	string s1;
	getline(cin, s1);
	string s2;
	int i = s1.size()-1;
	int j = s1.size();
	for ( int cur; i>=0; --i) {
		if (s1[i] == ' ') {
			for (cur = i+1; cur < j; ++cur) {
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
}
#endif
int main() {
	int n = 0;
	cin >> n;
	string s1;
	cin.get();
	getline(cin, s1);
	cout << n << endl;
	cout << s1 << endl;
	system("pause");
	return 0;
}
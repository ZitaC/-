#include<iostream>
using namespace std;
	int getLCA(int a, int b) {//二叉树找公共祖先节点
		if (a > b) {
			while (a > b) {
				if (a % 2 == 0) {
					a = a / 2;
				}
				else {
					a = (a - 1) / 2;
				}
			}
		}
		else if (b > a) {
			while (b > a) {
				if (b % 2 == 0) {
					b = b / 2;
				}
				else {
					b = (b - 1) / 2;
				}
			}
		}
		else {
			return a;
		}
		if (a == b) {
			return a;
		}
		while (a > 1 && a != b) {
			if (a > b) {
				if (a % 2 == 0) {
					a = a / 2;
				}
				else {
					a = (a - 1) / 2;
				}

				if (a == b) {
					break;
				}
				if (b % 2 == 0) {
					b = b / 2;
				}
				else {
					b = (b - 1) / 2;
				}
			}
			if (b > a) {
				if (b % 2 == 0) {
					b = b / 2;
				}
				else {
					b = (b - 1) / 2;
				}

				if (a == b) {
					break;
				}
				if (a % 2 == 0) {
					a = a / 2;
				}
				else {
					a = (a - 1) / 2;
				}
			}
		}
		if (a == b) {
			return a;
		}
		
		return 1;
	}
	int main() {
		int a = 0;
		int b = 0;
		cin >> a;
		cin >> b;
		cout << getLCA(a, b) << endl;
		system("pause");
		return 0;
	}


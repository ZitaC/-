//输入年月日计算这是这一年的第几天
#include<iostream>
using namespace std;
bool Year(int a);
int whichday(int year, int month, int day) {
	if(Year(year)){
		switch (month)
		{
		case 1:
			if (day>0 && day<32)
			{
				return day;
			}
			break;
		case 2:
			if (day > 0 && day < 30) 
			{
				return 31 + day;
			}
			break;
		case 3:
			if (day > 0 && day < 32)
			{
				return 60 + day;
			}
			break;
		case 4:
			if (day > 0 && day < 31)
			{
				return 91 + day;
			}
			break;
		case 5:
			if (day > 0 && day < 32)
			{
				return 121 + day;
			}
			break;
		case 6:
			if (day > 0 && day < 31)
			{
				return 152 + day;
			}
			break;
		case 7:
			if (day > 0 && day < 32)
			{
				return 182 + day;
			}
			break;
		case 8:
			if (day > 0 && day < 32)
			{
				return 213 + day;
			}
			break;
		case 9:
			if (day > 0 && day < 31)
			{
				return 244 + day;
			}
			break;
		case 10:
			if (day > 0 && day < 32)
			{
				return 274 + day;
			}
			break;
		case 11:
			if (day > 0 && day < 31)
			{
				return 305 + day;
			}
			break;
		case 12:
			if (day > 0 && day < 32)
			{
				return 335 + day;
			}
			break;
		default:
			return -1;
			break;
		}
		return -1;
	}
	else {
		switch (month)
		{
		case 1:
			if (day > 0 && day < 32)
			{
				return day;
			}
			break;
		case 2:
			if (day > 0 && day < 29)
			{
				return 31 + day;
			}
			break;
		case 3:
			if (day > 0 && day < 32)
			{
				return 59 + day;
			}
			break;
		case 4:
			if (day > 0 && day < 31)
			{
				return 90 + day;
			}
			break;
		case 5:
			if (day > 0 && day < 32)
			{
				return 120 + day;
			}
			break;
		case 6:
			if (day > 0 && day < 31)
			{
				return 151 + day;
			}
			break;
		case 7:
			if (day > 0 && day < 32)
			{
				return 181 + day;
			}
			break;
		case 8:
			if (day > 0 && day < 32)
			{
				return 212 + day;
			}
			break;
		case 9:
			if (day > 0 && day < 31)
			{
				return 243 + day;
			}
			break;
		case 10:
			if (day > 0 && day < 32)
			{
				return 273 + day;
			}
			break;
		case 11:
			if (day > 0 && day < 31)
			{
				return 304 + day;
			}
			break;
		case 12:
			if (day > 0 && day < 32)
			{
				return 334 + day;
			}
			break;
		default:
			return -1;
			break;
		}
		return -1;
	}
}
bool Year(int a){
	if (a % 400 == 0)
	{
		return true;
	}
	if (a % 4 == 0 && a % 100 != 0)
	{
		return true;
	}
	else
		return false;
}
int main() {
	int year = 0;
	int month = 0;
	int day = 0;
	while (1) {
		cin >> year;
		cin >> month;
		cin >> day;
		cout << whichday(year, month, day) << endl;
	}
	system("pause");
	return 0;
}
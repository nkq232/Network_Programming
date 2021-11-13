// Nguyễn Khánh Quân 19020400 
// Bài 1
// Viết chương trình nhập chuỗi ký tự từ bàn phím và xuất ra số ký tự là chữ cái, số ký tự là số và số ký tự là các ký hiệu.
#include<iostream>
using namespace std;
int main()
{
	string a;
	int letter = 0, number = 0, symbol = 0;
	cin >> a;
	for (int i = 0; i < a.size(); ++i)
	{
		if ( (65 <= a[i] && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122) )
		{
			/* code */
			letter++;

		} else if (a[i] <= 57 && a[i] >= 48)
		{
			/* code */
			number ++;
		} else {
			symbol ++;
		}
	}
	cout << "Chữ cái: " << letter << "   Số: " << number << "   Kí hiệu:  " << symbol;
	return 0;
}
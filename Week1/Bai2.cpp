// Nguyễn Khánh Quân 19020400 
// Bài 2
// Viết chương trình nhập tên file cần tạo mới và các chuỗi ký tự từ bàn phím cho đến khi nhập ký tự kết thúc (tự định nghĩa). 
// Lưu các chuỗi ký tự đã nhập vào file được tạo mới và xuất kích thước file ra màn hình.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	cout << "Nhập tên file (Nhập đuôi): ";
	string fileOut;
	cin >> fileOut;
	cout << "Nhập chuỗi kí tự: ";
	char input;
	string inputx;
	while(1) {
		input = getchar();
		if (input != '`')
		{
			/* code */
			inputx += input;
		} else {
			break;
		}
	}
	ofstream fileOutput(fileOut);
	for (int i = 0; i < inputx.size(); ++i)
	 {
	 	/* code */
	 	fileOutput << inputx[i];
	 } 
	cout << "Size of file:   " << fileOutput.tellp();
	fileOutput.close();
	return 0;
}
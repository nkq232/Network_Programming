// Nguyễn Khánh Quân 19020400 
// Bài 4
// Viết chương trình đọc dữ liệu từ một file ảnh và lưu dữ liệu đó sang một file khác.
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
	string filename;
	cout << "Nhập tên inputfile(Nhập đuôi): ";
	cin >> filename;
	ifstream fileInput(filename, std::ios::binary);
	if (fileInput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	ofstream fileOutput("result.jpg", std::ios::binary);
    if (fileOutput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	fileOutput<< fileInput.rdbuf();
	fileInput.close();
	fileOutput.close();
	return 0;
}

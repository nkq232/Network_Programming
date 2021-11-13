// Nguyễn Khánh Quân 19020400 
// Bài 3
// Viết chương trình đọc dữ liệu từ một file text và lưu các ký tự là chữ cái sang một file khác.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string filename;
	cout << "Nhập tên inputfile(Nhập đuôi): ";
	cin >> filename;
	string letter = "";
	ifstream fileInput(filename);
	if (fileInput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	while (!fileInput.eof()) {
		char a;
		fileInput >> a;
        if ((65 <= a && a <=90) || (a >= 97 && a <= 122))
        {
        	/* code */
        	letter+=a;
        }
	}
	fileInput.close();
	ofstream fileOutput("result.txt");
	for (int i = 0; i < letter.size(); ++i)
	 {
	 	/* code */
	 	fileOutput << letter[i];
	 } 
	fileOutput.close();
	return 0;
}

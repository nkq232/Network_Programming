// Nguyễn Khánh Quân 19020400 
// Bài 3.3.
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX_NAME_LENGTH 100
int main(){
	unsigned short fSize;           		// file size 
  	unsigned char fType;          		// file type
  	char fName[MAX_NAME_LENGTH];           //file name
    cout << "Nhập fSize: ";
    cin >> fSize;
    cout << "Nhập fileType: ";
    cin >> fType;
    cout << "Nhập fileName: ";
    cin >> fName;
    
    
	ofstream fileOutput("pkt_hdr_json.txt");
    if (fileOutput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	fileOutput << "{\n\tfileSize: " << fSize << ",\n\tfileType: " << fType << ",\n\tfileName: " << fName << "\n}";
	fileOutput.close();

}
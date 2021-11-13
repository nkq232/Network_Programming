// Nguyễn Khánh Quân 19020400 
// Bài 3.1
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#define MAX_NAME_LENGTH 100
struct udphdr {
  		unsigned short fileSize;           		// file size 
  		unsigned char fileType;          		// file type
  		unsigned char fileNameLength ;  	// file name length
  		char fileName[MAX_NAME_LENGTH];           //file name
	};
int main(){
	unsigned short fileSize;           		// file size 
  		unsigned char fileType;          		// file type
  		unsigned char fileNameLength ;  	// file name length
  		char fileName[MAX_NAME_LENGTH];           //file name
    cout << "Nhập fileSize: ";
    cin >> fileSize;
    cout << "Nhập fileType: ";
    cin >> fileType;
    cout << "Nhập fileNameLength: ";
    cin >> fileNameLength;
    cout << "Nhập fileName: ";
    cin >> fileName;
    
    udphdr *newText = new udphdr{fileSize, fileType, fileNameLength};
    strcpy(newText->fileName, fileName);
	fstream fileOutput("pkt_hdr.bin",ios::out|ios::binary);
    if (fileOutput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	fileOutput.write(( char *) newText , sizeof (newText) ) ;
	cout << "Size of file:   " << fileOutput.tellp();
	fileOutput.close();

}
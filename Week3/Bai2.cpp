// Nguyễn Khánh Quân 19020400 
// Bài 3.2
#include<iostream>
#include<fstream>
using namespace std;

#define MAX_NAME_LENGTH 100
struct udphdr {
  		unsigned short fileSize;           		// file size 
  		unsigned char fileType;          		// file type
  		unsigned char fileNameLength ;  	// file name length
  		char fileName[MAX_NAME_LENGTH];           //file name
	};
int main(){
	fstream fileInput("pkt_hdr.bin",ios::in|ios::binary);
    if (fileInput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	udphdr *newText = new udphdr;
	fileInput.read(( char *) newText , sizeof (newText) ) ;      
	cout << "fileSize là: " << newText->fileSize << endl ;
	cout << "fileType là: " << newText->fileType << endl;
	cout << "fileNameLength là: " << newText->fileNameLength << endl;
	cout << "fileName là: ";
	
	for (int i = 0; i < sizeof(newText->fileName); ++i)
	{
		/* code */
		cout << newText->fileName[i];
	}
	cout << endl;
	cout << sizeof(newText->fileName) << endl;
	fileInput.close();

}
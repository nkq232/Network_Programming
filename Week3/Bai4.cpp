// Nguyễn Khánh Quân 19020400 
// Bài 3.4.

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;


string getData(string check){
	string result = "";
	int checkpoint = 0;
	for (int i = 0; i < check.size(); ++i)
	{
		if (check[i] == ':')
		{
			/* code */
			checkpoint = i + 2;
		}
	}
	for (int i = checkpoint; i < check.size(); ++i)
	{
		/* code */
		result+= check[i];
	}
	return result;
}
int main(){
	
	ifstream fileInput("pkt_hdr_json.txt");
    if (fileInput.fail())
	{
		/* code */
		cout << "Fail to open !" << endl;
	}
	string check;
	getline(fileInput, check);
	getline(fileInput, check);
	check = getData(check);
	check.pop_back();
	cout << "fileSize: " << check ;
	getline(fileInput, check);
	check = getData(check);
	check.pop_back();
	cout << "\nfileType: ";
	if (check == "1")
	{
		cout << "Binary File\n";
	} else {
		cout << "Text File\n";
	}
	getline(fileInput, check);
	check = getData(check);
	cout << "fileName: " << check;
	fileInput.close();

}
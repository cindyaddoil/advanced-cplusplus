//============================================================================
// Name        : Binary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
};
#pragma pack(pop)

int main() {
	Person baobao = {"baobao" , 5};
	fstream outFile;
	outFile.open("text.bin", ios::binary | ios::out);
	if (outFile.is_open()) {
		outFile.write((char*)&baobao, sizeof(Person));
		outFile.close();
	} else {
		cout << "can't open the file to write" << endl;
	}

	Person other = {};
	fstream inFile;
	inFile.open("text.bin", ios::binary | ios::in);

	if (inFile.is_open()) {
		string line;
		inFile.read((char*)&other, sizeof(Person));
		inFile.close();
	} else {
		cout << "can't open the file to read" << endl;
	}
	cout << other.name;
	cout << " " << other.age << endl;

	return 0;
}

//20230101 build sample file

#include<iostream>
#include<fstream>
using namespace std;


int main(){

	ofstream Ofile("Final_Sample_File.txt", ios::out);
	string equation;

	if(!Ofile){
		cerr << "Wrong open file"<< endl;
		exit(1);
	}
	cout << "Start input Boolean functions." << endl;
	while(cin >> equation){
		Ofile << equation << endl;
	}
	cout << "End input Boolean functions." << endl;

	return 0;
}

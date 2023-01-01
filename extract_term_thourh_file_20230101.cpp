#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

string find_operator(const string, const char, vector<string> &);

int main()
{
	string input, boolean_name;
	vector<string> term;
	ifstream Ifile("Final_Sample_File.txt", ios::in);

	if(!Ifile){
		cerr << "Wrong open file"<< endl;
		exit(1);
	}
	while(Ifile >> input){
		term.clear();
		boolean_name = find_operator(input, '=', term);

		cout << "Boolean function name:" << endl << boolean_name << endl;
		cout << "term: " << endl;
		for(int i = 0; i < term.size(); i++) cout << term[i] << ' ';
		cout << endl << endl;
	}
	return 0;
}


string find_operator(const string eqa, const char get, vector<string> &term)
{
	string fname, terms, oneterm;
	size_t pos = 0;
	switch(get)
	{
	case '=':
		pos = eqa.find('=');
		terms = eqa.substr(pos+1);
		fname= eqa.substr(0, pos);
		find_operator(terms, '+', term);
		break;
	case '+':
		int start = 0, finish;
		for(int i = start; i < eqa.size(); i++)
		{
			if(eqa[i] == '+')
			{
				oneterm = eqa.substr(start, i - start);
				term.push_back(oneterm);
				oneterm.clear();
				start = i + 1;
			}
			if(i == eqa.size() - 1)
			{
				oneterm = eqa.substr(start);
				term.push_back(oneterm);
				oneterm.clear();
			}
		}
		break;
	}
	return fname;
}

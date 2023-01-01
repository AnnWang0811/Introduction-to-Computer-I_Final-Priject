//20221217 start
//only input one Boolean functions in SOP expression
//to make sure the function is correct

#include <iostream>
#include<vector>
#include<string>
using namespace std;

string find_operator(const string, const char, vector<string> &);

int main()
{
	string input, boolname;
	vector<string> term;

	cin >> input;
	boolname = find_operator(input, '=', term);

	//output the name of the Boolean function
	cout << "\nBoolean function's name:" << endl << boolname << endl;
	//output all catched terms
	cout << "\nterm: " << endl;
	for(int i = 0; i < term.size(); i++) cout << term[i] << ' ';
	cout << endl;

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

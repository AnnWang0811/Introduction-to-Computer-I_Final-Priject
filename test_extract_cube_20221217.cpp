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
	vector<string> cube;

	cin >> input;
	boolname = find_operator(input, '=', cube);

	//output the name of the Boolean function
	cout << "\nBoolean function's name:" << endl << boolname << endl;
	//output all catched cubes
	cout << "\ncube: " << endl;
	for(int i = 0; i < cube.size(); i++) cout << cube[i] << ' ';
	cout << endl;

	return 0;
}


string find_operator(const string eqa, const char get, vector<string> &cube)
{
	string fname, cubes, onecube;
	size_t pos = 0;
	switch(get)
	{
	case '=':
		pos = eqa.find('=');
		cubes = eqa.substr(pos+1);
		fname= eqa.substr(0, pos);
		find_operator(cubes, '+', cube);
		break;
	case '+':
		int start = 0, finish;
		for(int i = start; i < eqa.size(); i++)
		{
			if(eqa[i] == '+')
			{
				onecube = eqa.substr(start, i - start);
				cube.push_back(onecube);
				onecube.clear();
				start = i + 1;
			}
			if(i == eqa.size() - 1)
			{
				onecube = eqa.substr(start);
				cube.push_back(onecube);
				onecube.clear();
			}
		}
		break;
	}
	return fname;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class English
{
public:
	vector<string> numbers; //vector to store number's text representation

	string s = ""; //output string

	//use blank string "" if not needed
	string _space = " ";
	string _comma = ",";
	string _dash = "-";
	string _and = "and";
	string _ten = "ty";
	string _hundred = "hundred";
	string _thousand = "thousand";
	string _million = "million";
	string _billion = "billion";

	void insert_numbers(); //method for inserting number's text representation to vector
	void replace_text(string& source, string const& find, string const& replace); //method for replacing substring
	void replace_change(); //method for replacing a few change in language
	string convert(int input); //function to convert input to output

	void method_billion(int input); //method for billion input
	void method_million(int input); //method for million input
	void method_thousand(int input); //method for thousand input
	void method_hundred(int input); //method for hundred input
	void method_ten(int input); //method for les than a hundred input
};
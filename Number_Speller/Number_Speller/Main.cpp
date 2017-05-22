#include "Speller.h"

void main()
{
	bool b = false; //boolean to check number input
	int _input = 0; //input integer
	string _output = ""; //output string
	string _language = ""; //language

	//input language
	cout << "(For testing purpose, this program will loop infinitely until closed manually) \n";
	cout << "Enter a language, English is default for unknown input [english, bahasa] : ";
	cin >> _language; //input a language
	do
	{
		do
		{
			cout << "Enter an integer number (-2.147.483.647 to 2.147.483.647) : ";
			cin >> _input;
			if (!(b = cin.good()))
			{
				cout << "Incorrect Input !" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (!b); //check if whether the input is a valid integer number

		if (_input < 0) //minus input
		{
			_input = _input * -1;
			_output = method_spell(_language, _input);
			cout << "The number you entered is : minus " << _output << endl;
		}
		else //normal input
		{
			_output = method_spell(_language, _input);
			cout << "The number you entered is : " << _output << endl;
		}
	} while (0 == 0); //loop
}
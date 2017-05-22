#include "Speller.h"

string method_spell(string _language, int _input) //spell by language
{
	if (_language == "bahasa") //bahasa indonesia
	{
		Bahasa lang;
		return lang.convert(_input);
	}
	else //default to english
	{
		English lang;
		return lang.convert(_input);
	}
}
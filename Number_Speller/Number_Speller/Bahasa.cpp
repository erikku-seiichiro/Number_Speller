#include "Bahasa.h"

void Bahasa::insert_numbers() //method for inserting number's text representation to vector
{
	numbers.push_back("nol");	// 0
	numbers.push_back("satu");	// 1
	numbers.push_back("dua");	// 2
	numbers.push_back("tiga");	// 3
	numbers.push_back("empat");	// 4
	numbers.push_back("lima");	// 5
	numbers.push_back("enam");	// 6
	numbers.push_back("tujuh");	// 7
	numbers.push_back("delapan");	// 8
	numbers.push_back("sembilan");	// 9
}

void Bahasa::replace_text(string& source, string const& find, string const& replace) //method for replacing substring
{
	for (string::size_type i = 0; (i = source.find(find, i)) != string::npos;) //find all the substring and replace with another substring
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}

void Bahasa::replace_change() //method for replacing a few change in language
{
	replace_text(s, "satu puluh satu", "sebelas");
	replace_text(s, "satu puluh dua", "dua belas");
	replace_text(s, "satu puluh tiga", "tiga belas");
	replace_text(s, "satu puluh empat", "empat belas");
	replace_text(s, "satu puluh lima", "lima belas");
	replace_text(s, "satu puluh enam", "enam belas");
	replace_text(s, "satu puluh tujuh", "tujuh belas");
	replace_text(s, "satu puluh delapan", "delapan belas");
	replace_text(s, "satu puluh sembilan", "sembilan belas");

	replace_text(s, "satu puluh", "sepuluh");
	replace_text(s, "satu ratus", "seratus");
	replace_text(s, "satu ribu", "seribu");
}

string Bahasa::convert(int input) //function to convert input to output
{
	insert_numbers();
	method_billion(input);
	replace_change();
	return s;
}

void Bahasa::method_billion(int input)
{
	if (input < 1000000000) //less than a billion
	{
		if (input == 0) //zero input
		{
			s += numbers[0]; //write zero
		}
		else //numbers input
		{
			method_million(input); //pass to method_million
		}
	}
	else
	{
		method_hundred(input / 1000000000);
		s += _space + _billion; //write number + billion
		if (input % 1000000000 == 0) //zero after billion
		{
			s = s; //stay
		}
		else if (input % 1000000000 < 100) //2 digits after billion
		{
			s += _space + _and;
			method_ten(input % 1000000000); //write and + pass to method_ten
		}
		else //numbers after billion
		{
			s += _comma + _space;
			method_million(input % 1000000000); //write , + pass to method_million
		}
	}
}

void Bahasa::method_million(int input)
{
	if (input < 1000000) //less than a million
	{
		method_thousand(input); //pass to method_thousand
	}
	else
	{
		method_hundred(input / 1000000);
		s += _space + _million; //write number + million
		if (input % 1000000 == 0) //zero after million
		{
			s = s; //stay
		}
		else if (input % 1000000 < 100) //2 digit after million
		{
			s += _space + _and;
			method_ten(input % 1000000); //write and + pass to method_ten
		}
		else //numbers after million
		{
			s += _comma + _space;
			method_thousand(input % 1000000); //write , + pass to method_thousand
		}
	}
}

void Bahasa::method_thousand(int input)
{
	if (input < 1000) //less than a thousand
	{
		method_hundred(input); //pass to method_hundred
	}
	else
	{
		method_hundred(input / 1000);
		s += _space + _thousand; //write number + thousand
		if (input % 1000 == 0) //zero after thousand
		{
			s = s; //stay
		}
		else if (input % 1000 < 100) //2 digit after thousand
		{
			s += _space + _and;
			method_ten(input % 1000); //write _and + pass to method_ten
		}
		else //numbers after thousand
		{
			s += _comma + _space;
			method_hundred(input % 1000); //write , + pass to method_hundred
		}
	}
}

void Bahasa::method_hundred(int input)
{
	if (input < 100) //less than a hundred
	{
		method_ten(input); //pass to method_ten
	}
	else
	{
		method_ten(input / 100);
		s += _space + _hundred; //write number + hundred
		if (input % 100 == 0) //zero after hundred
		{
			s = s; //stay
		}
		else //numbers after hundred
		{
			s += _space + _and;
			method_ten(input % 100); //write and + pass to method_ten
		}
	}
}

void Bahasa::method_ten(int input)
{
	if (input < 10) //less than ten
	{
		if (input == 0) //zero input
		{
			s = s; //stay
		}
		else //numbers input
		{
			s += numbers[input]; //write number
		}
	}
	else //more than ten
	{
		s += numbers[input / 10] + _space + _ten; //write number + space + ty
		if (input % 10 == 0) //zero after ten
		{
			s = s; //stay
		}
		else //numbers after ten
		{
			s += _dash + numbers[input % 10]; //write - + number
		}
	}
}
#ifndef __ROMAN_NUMERAL_H__
#define __ROMAN_NUMERAL_H__
#include<string>
#include<stdexcept>


//convert integer within 0~9999
//for 5000 just stack M's
std::string toRoman(int i)
{
	if(i<0 || i>9999)	throw (std::out_of_range("Unable to convert to Roman Numeral"));

	//Roman sometimes uses N (stands for 'nihil') for 0
	if(i==0) return std::string("N");

	//simply convert based on each digits
	char* HUND[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	char* TENS[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	char* ONES[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	
	return std::string('m', i/1000) + HUND[(i/100) %10] + TENS[(i/10)%10] + ONES[i%10];
}

std::string toRoman(double d)
{
	if (i < 0)
		throw std::invalid_argument("Negative numbers are not allowed");
	std::string answer = toRoman(static_cast<int>(d));
	d %= 1;
	//TODO: Representation of Fractions
}

void operator "" _(const char* str) {}



#endif//__ROMAN_NUMERAL_H__

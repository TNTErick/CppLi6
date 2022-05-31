#pragma once 

#include<string>
#include<iostream>
#include<vector>


class _Int {
private:
	bool neg;
	std::string digits;
public:

	//constructor
	_Int();
	_Int(int i);
	_Int(long long int i);
	_Int(unsigned long long i);
	_Int(const std::string&);
	_Int(const std::string&, bool);
	_Int(const char*);
	
	//copy
	_Int(const _Int&);
	const _Int& operator=(const _Int&);

	//destructor
	virtual ~_Int();

	//helper
	void half();
	bool empty()const;
	size_t length()const;
	char operator[](const int)const;
	std::string str() const;
	_Int abs()const;
	bool isNeg() const;

	//faster method to scale up and down
	void operator<<=(int i);
	void operator>>=(int i);
	//void operator<<(int i);
	//void operator>>(int i);
	
	//unary
	_Int& operator++();
	_Int operator++(int);
	_Int& operator--();
	_Int operator--(int);
	const _Int& operator+();
	_Int operator-();

	//Addition and Subtraction
	friend _Int& operator+=(_Int&, const _Int&);
	friend _Int operator+(const _Int&, const _Int&);
	friend _Int operator-(const _Int&, const _Int&);
	friend _Int& operator-=(_Int&, const _Int&);

	//Comparison operators
	friend bool operator==(const _Int&, const _Int&);
	friend bool operator!=(const _Int&, const _Int&);

	friend bool operator>(const _Int&, const _Int&);
	friend bool operator>=(const _Int&, const _Int&);
	friend bool operator<(const _Int&, const _Int&);
	friend bool operator<=(const _Int&, const _Int&);

	//Multiplication and Division
	friend _Int& operator*=(_Int&, const _Int&);
	friend _Int operator*(const _Int&, const _Int&);
	friend _Int& operator/=(_Int&, const _Int&);
	friend _Int operator/(const _Int&, const _Int&);

	//Modulo
	friend _Int operator%(const _Int&, const _Int&);
	friend _Int& operator%=(_Int&, const _Int&);

	//Power Function
	friend _Int& operator^=(_Int&, const _Int&);
	friend _Int operator^(const _Int&, const _Int&);

	//Square Root Function
	friend _Int sqrt(const _Int&);
	friend _Int Factorial(_Int);

	//compatibility with stl datastream
	friend std::ostream& operator<<(std::ostream&, const _Int&);
	friend std::istream& operator>>(std::istream&, _Int&);
};

inline _Int::_Int() :digits("0"), neg(false) {}
inline _Int::_Int(int i):neg(false),digits("")
{
	if (i < 0)
	{
		neg = true;
		i = -i;
	}
	do 
	{
		digits.push_back(i % 10+'0');
		i /= 10;
	} while (i);
}
inline _Int::_Int(long long int i)
	:neg(false),digits("")
{
	if (i < 0)
	{
		neg = true;
		i = -i;
	}

	do
	{
		digits.push_back(i % 10);
		i /= 10;
	} while (i);
}

inline _Int::_Int(unsigned long long i)
	:neg(false),digits("")
{
	do
	{
		digits.push_back(i % 10);
		i /= 10;
	} while (i);
}

inline _Int::_Int(const std::string& str)
	:digits(),neg(false)
{	
	std::string::size_type x=0;
	if (str[0] == '-')
		x = neg = 1;
	else
		x = neg = false;

	for (char ch : str.substr(x))
	{
		if (!isdigit(ch))
			throw("Error: nondigit has been passed into _Int::_Int(std::string,bool).");
		digits.push_back(ch);
	}
	if(digits.length()>1)
	std::reverse(digits.begin(), digits.end());

	if (this->empty()) neg = false;
}

//no reverse to the string, while _Int(string) has.
inline _Int::_Int(const std::string& str, bool negt)
	:digits(),neg(negt)
{
	for (char ch : str)
	{
		if (!isdigit(ch))
			throw("Error: nondigit has been passed into _Int::_Int(std::string,bool).");
		digits.push_back(ch);
	}
}

inline _Int::_Int(const char*cstr) :digits(), neg(false)
{
	std::string str(cstr);
	std::string::size_type x = 0;
	if (str[0] == '-')
		x = neg = 1;
	else if (str[0] == '+')
		x = neg = false;

	for (char ch : str.substr(x))
	{
		if (!isdigit(ch))
			throw("Error: nondigit has been passed into _Int::_Int(std::string).");
		digits.push_back(ch);
	}
	std::reverse(digits.begin(), digits.end());
}

inline _Int::_Int(const _Int&that)
{
	neg = that.neg;
	this->digits = that.digits;
}

inline const _Int& _Int::operator=(const _Int&that)
{
	neg = that.neg;
	this->digits = that.digits;
	return *this;
}

inline _Int::~_Int()
{
	digits.~basic_string();
}

inline void _Int::half()
{
	bool hf = false;
	for (int idx = digits.length();--idx>=0; )
	{
		int tmp = ((digits[idx] - '0' )>>1)+ (hf ? 5 : 0);
		hf = (digits[idx] & 1);
		digits[idx] =tmp+'0';
	}
	while (digits.size() > 1 && digits.back()=='0')
		digits.pop_back();
}

inline bool _Int::empty()const
{
	if (this->digits == "0")
		return true;
	return false;
}

inline size_t _Int::length()const
{
	return this->digits.length();
}

inline char _Int::operator[](const int idx) const
{
	if (idx < 0)
		throw("Index must be a natural number.");
	size_t i = idx;
	if (digits.length()<=i)
		throw("Error: _Int::operator[] has index bigger than length.");
	return digits[i];
}

inline std::string _Int::str()const
{
	if (empty())
		return std::string("0");
	std::string str = digits;
	std::reverse(str.begin(), str.end());
	if (neg)
		str.insert(str.begin(),'-');
	return (str);
}

inline _Int _Int::abs() const
{
	_Int tmp(*this);
	tmp.neg = false;
	return tmp;
}

inline bool _Int::isNeg() const
{
	return this->neg;
}

inline void _Int::operator<<=(int i)
{
	digits.insert(0, i, '0');
}

inline void _Int::operator>>=(int i)
{
	digits.erase(0, i);
}

inline _Int& _Int::operator++()
{
	if (neg)
	{
		if (digits == std::string("1")) {
			digits = std::string("0");
			neg = false;
		}
		std::string::size_type i=0, n = digits.length();
		while(digits[i] == 0 && i < n)
			digits[i++] = 9;
		digits[i]--;
		if (n > 1 && digits[n - 1] == 0)
			digits.pop_back();
		return *this;
	}
	
	std::string::size_type i=0, end = digits.length();
	while (i < end && digits[i] == '9')
		digits[i++] = '0';
	if (i == end)
		digits.push_back('1');
	else
		digits[i]++;
	return *this;
}

inline _Int _Int::operator++(int)
{
	_Int nx = *this;
	this->operator++();
	return nx;
}

inline _Int& _Int::operator--()
{

	if (neg)
	{
		std::string::size_type i = 0, end = digits.length();
		while (i < end && digits[i] == '9')
			digits[i++] = '0';
		if (i == end)
			digits.push_back('1');
		else
			digits[i]++;
		return *this;
	}

	if (empty()) {
		digits = std::string("1");
		neg = true;
		return *this;
	}
	std::string::size_type i = 0, n = digits.length();
	while (digits[i] == 0 && i < n)
		digits[i++] = 9;
	digits[i]--;
	if (n > 1 && digits[n - 1] == 0)
		digits.pop_back();
	return *this;
}

inline _Int _Int::operator--(int)
{
	_Int pv = *this;
	this->operator--();
	return pv;
}

inline const _Int& _Int::operator+()
{
	return *this;
}

inline _Int _Int::operator-()
{
	if (digits == std::string("0"))
		return *this;
	return _Int(this->digits,!(this->neg));
}

//bugless. addition and subtraction.
_Int& operator+=(_Int& l, const _Int& rc)
{
	_Int r(rc), tmp(std::string("0"));
	if (l.neg xor r.isNeg())
	{
		if (l == -r)
		{
			l = _Int(0);
			return l;
		}
		bool neg = false;
		bool swap = false;

		//l>0>r
		if (l.neg)	swap = !swap;

		// implement l = -(|r| - |l|) if (|r| > l);
		// implement l = +(|l| - |r|) if (|r| < l);
		if (-r > l) swap = !swap;

		if (swap) tmp=l, l = r, r = tmp;

		//idk why but it fixes it.
		//std::reverse(r.digits.begin(), r.digits.end());
		
		// implement l = |l|-|r| and keep the symbol of l 
		std::string::size_type idx=0,
			n = l.digits.length(), m = r.digits.length();
		if (n < m) {
			throw("Why would this happen?");
		}
		int carry = 0,tmp=0;

		for(;idx < n;idx++)
		{
			tmp = l.digits[idx]- carry - ((idx < m) ? (r.digits[idx]) : '0');
			if (tmp < 0)
				tmp += 10,
				carry = 1;
			else carry = 0;
			l.digits[idx] = '0' + tmp;
		}
		while (l.digits.length()>1 && l.digits.back()=='0')
			l.digits.pop_back();
		return l;
	}
	//if ((l.neg && r.neg) || !(l.neg || r.neg))
	{
		//l(+) && r(+) => neg = l.neg, digits = |l|+|r|;
		//l(-) && r(-) => neg = l.neg, digits = |l|+|r|;
		char carry = 0;
		std::string::size_type idx = 0,
			n = l.digits.length(), m = r.digits.length();
		if (n < m) l.digits.append(m - n, '0');
		n = l.digits.length();
		while (idx < n)
		{
			l.digits[idx] += carry + (idx < m ? r.digits[idx] - '0' : 0);
			if (l.digits[idx] > '9')
			{
				l.digits[idx] -= 10;
				carry = 1;
			}
			else carry = 0;
			idx++;
		}
		if (carry) l.digits.push_back('1');
		return l;
	}
}

//calls += for addition.
inline _Int operator+(const _Int&l, const _Int&r)
{
	_Int t(l);
	t += r;
	return t;
}

//calls -= which ultimately calls += -(rhs) to subtract it. 
inline _Int operator-(const _Int&l, const _Int&r)
{
	_Int tmp(l);
	tmp -= r;
	return tmp;
}

//calls += for subtraction.
inline _Int& operator-=(_Int&l, const _Int& r)
{
	_Int t(r);
	l += (-t);
	return l;
}

inline bool operator==(const _Int&l, const _Int&r)
{
	if (l.digits == std::string("0") && r.digits == std::string("0"))
		return true;
	return (l.digits == r.digits && l.neg == r.neg);
}

inline bool operator!=(const _Int&l, const _Int&r)
{
	return !(l == r);
}

inline bool operator>(const _Int&l, const _Int&r)
{
	if (!(l.neg) && r.neg)
		return true;
	if (!(r.neg) && l.neg)
		return false;
	if (r.neg && l.neg)
	{
		auto n = l.digits.length();
		auto m = r.digits.length();
		if (n != m) return n < m;
		while (n--)
			if (l.digits[n] != r.digits[n])
				return l.digits[n] < r.digits[n];
		return false;
	}
	else
	{
		auto n = l.digits.length();
		auto m = r.digits.length();
		if (n != m) return n > m;
		while (n--)
			if (l.digits[n] != r.digits[n])
				return l.digits[n] > r.digits[n];
		return false;
	}
}

inline bool operator>=(const _Int&l, const _Int&r)
{
	return l > r || l == r;
}

inline bool operator<(const _Int&l, const _Int&r)
{
	return r > l;
}

inline bool operator<=(const _Int&l, const _Int&r)
{
	return !(l>r);
}

//bugless, multiplication.
inline _Int& operator*=(_Int&l, const _Int&r)
{
	if (l.empty() || r.empty())
	{
		l = _Int();
		return l;
	}
	l.neg = l.neg xor r.neg;

	std::string::size_type n = l.digits.length(), m = r.digits.length();
	std::vector<int> prod(n + m, 0);
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			prod[i + j] += (l.digits[i]-'0') * (r.digits[j]-'0');

	int carry = 0;
	for (int &i : prod)
	{
		i += carry;
		carry = i / 10;
		i %= 10;
	}

	int ir = n + m;
	while (ir>0 && !prod[--ir])
		prod.pop_back();

	l.digits = std::string(prod.size(), '0');
	for (size_t i = 0; i < l.digits.length(); i++)
		l.digits[i] += prod[i];
	return l;
}

inline _Int operator*(const _Int&l, const _Int&r)
{
	_Int t= l;
	t *= r;
	return t;
}

inline _Int& operator/=(_Int&nom , const _Int&denom)
{
	nom = (nom / denom);
	return nom;
}

//not checked.
inline _Int operator/(const _Int&nom, const _Int&denom)
{
	if (denom.empty())
		throw(std::string("Error: Division By Zero"));
	if (nom.empty())
		return _Int(0);

	std::string::size_type n = nom.digits.length(), m = denom.digits.length(), idx = m-1;
	if (n < m)
		return _Int(std::string(nom.neg ? "1":"0"), !denom.neg);
	if (nom.abs() == denom.abs())
		return _Int(std::string("1"), nom.neg xor denom.neg);

	std::string digNom = nom.digits;
	if (digNom.length() > 1)
		std::reverse(digNom.begin(), digNom.end());
	//checked until here.

	_Int tmDnm[10];
	for (int i = 0; i < 10; i++)
		tmDnm[i] = denom * _Int(i);
	//set such that digNom.sutstr[0, idx+1) is the minimal substr that is larger than denom.
	
	_Int tmp(digNom.substr(0, idx));
	_Int quot(std::string("0"), false);

	for (; idx < n ;)
	{
		if (tmp.empty())
			tmp.digits = std::string(1, digNom[idx++]);
		else
			tmp.digits.insert(0,1,digNom[idx++]);
		int i = 9;
		for (; tmDnm[i] > tmp && i >= 0; i--);
		tmp -= tmDnm[i];
		quot.digits.push_back(i + '0');
	}
	if (quot.digits.length() == 0)
		quot.digits.push_back('0');


	if (quot.digits.length() > 1)
		std::reverse(quot.digits.begin(), quot.digits.end());

	while ((quot.digits.length() > 1) && (quot.digits.back() == '0'))
		quot.digits.pop_back();
	if (nom.neg)
			quot++;
	quot.neg = (nom.neg xor denom.neg);
	return quot;
}

inline _Int operator%(const _Int&nom, const _Int&denom)
{
	if (denom.empty())
		throw(std::string("Error: Division By Zero"));
	if (nom.empty())
		return _Int(0);

	std::string::size_type n = nom.digits.length(), m = denom.digits.length(), idx = m - 1;
	if (n < m)
		return _Int(std::string(nom.neg ? "1" : "0"), !denom.neg);
	if (nom.abs() == denom.abs())
		return _Int(std::string("1"), nom.neg xor denom.neg);

	std::string digNom = nom.digits;
	if (digNom.length() > 1)
		std::reverse(digNom.begin(), digNom.end());
	//checked until here.

	_Int tmDnm[10];
	for (int i = 0; i < 10; i++)
		tmDnm[i] = denom * _Int(i);
	//set such that digNom.sutstr[0, idx+1) is the minimal substr that is larger than denom.

	_Int tmp(digNom.substr(0, idx));
	_Int quot(std::string("0"), false);

	for (; idx < n;)
	{
		if (tmp.empty())
			tmp.digits = std::string(1, digNom[idx++]);
		else
			tmp.digits.insert(0, 1, digNom[idx++]);
		int i = 9;
		for (; tmDnm[i] > tmp && i >= 0; i--);
		tmp -= tmDnm[i];
		quot.digits.push_back(i + '0');
	}

	if (tmp.empty())
		return tmp;
	if (nom.neg)
		return (denom - tmp);
	else
		return tmp;
}

inline _Int& operator%=(_Int&l, const _Int&r)
{
	l = (l % r);
	return l;
}

inline _Int& operator^=(_Int&l, const _Int&r)
{
	_Int bas(l), exp(r);
	for (l = 1; !exp.empty(); exp.half())
	{
		if (exp[0] & 1) // exp is odd
			l *= bas;
		bas *= bas;
	}
	return l;
}


inline _Int operator^(const _Int&l, const _Int&r)
{
	_Int tmp = l;
	tmp ^= r;
	return tmp;
}

inline _Int Factorial(_Int i)
{
	_Int tmp(1);
	for (_Int j(2); j <= i; j++)
		tmp *= j;
	return tmp;
}

inline std::ostream& operator<<(std::ostream&os, const _Int&i)
{
	if (i.empty())
		return (os << "0");
	if (i.neg)
		os << '-';
	std::string str = i.digits;
	std::reverse(str.begin(), str.end());
	return (os << str);
}

inline std::istream& operator>>(std::istream&is, _Int&i)
{
	std::string str;
	is >> str;
	i.neg = (str[0] == '-' ? true : false);
	if (i.neg)
		str.erase(str.begin());
	std::string kr = str.substr(0, str.find('.'));
	std::reverse(kr.begin(), kr.end());
	for (char ch : kr)
		if (!isdigit(ch))
			throw("Error: Invalid Number Input.");
		else i.digits.push_back(ch);
	return is;
}

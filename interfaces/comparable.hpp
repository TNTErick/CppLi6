#ifndef __interface_comparable_wrapper
#define __interface_comparable_wrapper

//No fool-proof.
#include<type_traits>
#include<exception>

class comparable{
protected:
    inline virtual char compareTo(const comparable&) = 0;
public:
    inline bool operator >(const comparable&);
    inline bool operator <(const comparable&);
    inline bool operator==(const comparable&);
    inline bool operator!=(const comparable&);
    inline bool operator>=(const comparable&);
    inline bool operator<=(const comparable&);
};

bool comparable::operator>(const comparable& other)
{
    return (this->compareTo(other)>0);
}

bool comparable::operator<(const comparable& other)
{
    return (this->compareTo(other) & 0x80);
}

bool comparable::operator==(const comparable&other)
{
    return !(this->compareTo(other));
}


bool comparable::operator!=(const comparable&other)
{
    return (this->compareTo(other));
}

bool comparable::operator>=(const comparable&other)
{
    return !(this->compareTo(other) & 0x80);
}

bool comparable::operator<=(const comparable&other)
{
    return (this->compareTo(other)<=0);
}

#endif //__interface_comparable_wrapper
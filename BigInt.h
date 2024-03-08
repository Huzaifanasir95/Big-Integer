// Huzaifa Nasir
// Assignment 3
#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>

using namespace std;
class BigInt {
private:
    char* digits; 
    int numDigits; 

public:
    BigInt(int val = 0);
    BigInt(const std::string& text);
    BigInt(const BigInt& copy); 

   BigInt operator+(const BigInt& val) const;
    BigInt operator+(int val) const;
    BigInt operator-(const BigInt& val) const;
    BigInt operator-(int val) const;
    BigInt operator*(const BigInt& val) const;

    BigInt& operator+=(const BigInt& rhs);
    BigInt& operator-=(const BigInt& rhs);
    BigInt& operator*=(const BigInt& rhs);

    bool operator==(const BigInt& val) const;
    bool operator==(const char* val) const;
    bool operator!=(const BigInt& val) const;
    bool operator<(const BigInt& val) const;
    bool operator<=(const BigInt& val) const;
    bool operator>(const BigInt& val) const;
    bool operator>=(const BigInt& val) const;

    BigInt& operator++(); 
    BigInt operator++(int); 
    BigInt& operator--(); 
    BigInt operator--(int); 

    operator string(); 
    operator int(); 
    ~BigInt(); 
    int getNumDigits() const;
	char* getDigits() const;
	void setDigits(char *digits);
    void setNumDigits(int numDigits);

};

 ostream& operator<<(ostream& output, const BigInt& val); 
 istream& operator>>(istream& input, BigInt& val); 

#endif // BIGINT_H

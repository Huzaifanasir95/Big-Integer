// Huzaifa Nasir
// Assignment 3
#include "BigInt.h"


BigInt::BigInt(int val)
{
    if (val == 0) {
        this->digits = new char[2]; 
        this->numDigits = 1;
        this->digits[1] = '\0';
        this->digits[0] = '0';
        
    }
    else {
       
        int temp = val;
        int numDigits = 0;
        
        if (temp < 0) {
            temp = -temp;
            numDigits++; 
            
        }

        for (;temp != 0;) {
            numDigits++;
            temp /= 10;
            
        }

        this->numDigits = numDigits;
        digits = new char[this->numDigits + 1]; 

        
        temp = val;
        int i = this->numDigits - 1;
        
        if (temp < 0) {
           
            temp = -temp;
            this->digits[0] = '-'; 
        }

        while (temp != 0) {
            this->digits[i--] = (temp % 10) + '0';
            temp /= 10;
        }

        digits[this->numDigits] = '\0'; 
    }
}

BigInt::BigInt(const std::string& text) {
        int temp = 0;
    for (;text[temp] != '\0';temp++) {
        
    }
    this->numDigits = temp;
    this->digits = new char[numDigits];
    for (int j = 0; j < numDigits; j++) {
        this->digits[j] = text[j];
    }
}

BigInt::BigInt(const BigInt& copy) {
    this->numDigits = copy.numDigits;
    this->digits = new char[numDigits];
    int i=0;
    while ( i < numDigits) {
        digits[i] = copy.digits[i];
        i++;
    }
}

BigInt::operator string()
{
    return string(digits);
}

BigInt::operator int(){
    int temp = 0;
    int multemp = 1;
    int i = numDigits - 1;
    while ( i >= 0 ) {
        temp += (digits[i] - '0') * multemp;
        multemp *= 10;
        i--;
    }
    return temp;
}

BigInt BigInt::operator+(const BigInt& val) const{
   
    int* res1 = new int[numDigits];
    int a = 0;
    while ( a < numDigits ) {
        res1[a] = digits[a] - '0';
        a++;
    }

    int* res2 = new int[val.numDigits];
    int b=0;
    while ( b < val.numDigits) {
        res2[b] = val.digits[b] - '0';
        b++;
    }

    int maxtemp = (numDigits > val.numDigits) ? numDigits : val.numDigits;
    maxtemp += 1;
    int* total = new int[maxtemp + 1]; 

    int temp = 0;
    
    int k = maxtemp - 1;
    int j = val.numDigits - 1;
    int i = numDigits - 1;

    
    for (;i >= 0 || j >= 0 || temp > 0;) {
        int sum = temp;
        if (i >= 0) {
            sum += res1[i--];
        }
        if (j >= 0) {
            sum += res2[j--];
        }
        temp = sum / 10;
        total[k--] = sum % 10;
    }

    total[maxtemp] = '\0'; 

   
    int lzero = 0;
    for (;lzero < maxtemp - 1 && total[lzero] == 0;) {
        lzero++;
    }

 
    if (lzero == maxtemp - 1) {
        lzero = 1;
    }

    char* result = new char[maxtemp - lzero + 1];
    int c=0;
    while ( c < maxtemp - lzero) {
        result[c] = total[lzero + c] + '0';
        c++;
    }
    result[maxtemp - lzero] = '\0';

    BigInt finalres(result);
    delete[] res1;
    delete[] res2;
    delete[] total;
    delete[] result;

    return finalres;
}

BigInt BigInt::operator+(int val) const {
    BigInt temp(val); 
    return *this + temp; 
}

BigInt& BigInt::operator+=(const BigInt& val)
{
    *this = *this + val;
    return *this;
}

BigInt BigInt::operator-(const BigInt& val) const
{
 return *this;
}

BigInt BigInt::operator-(int val) const
{
    BigInt temp(val); 
    return *this -temp; 
}

BigInt& BigInt::operator-=(const BigInt& rhs)
{
    *this = *this - rhs; 
    return *this;
}

BigInt BigInt::operator*(const BigInt& val) const
{
return *this;
}

BigInt& BigInt::operator*=(const BigInt& rhs)
{
return *this;
}

bool BigInt::operator==(const BigInt& val) const {

    int i = 0;
    while ( i < numDigits) {
        if (digits[i] != val.digits[i]) {
            return false;
        }
        i++;
    }

    if (numDigits != val.numDigits) {
    return false;
    }

    return true;
}

bool BigInt::operator==(const char* val) const {

    BigInt temp(val);

    return *this == temp;
}

bool BigInt::operator!=(const BigInt& val) const {
    
    bool flag=!(*this == val);
    return flag;
}

bool BigInt::operator<(const BigInt& val) const {
    
    if (this->numDigits > val.numDigits) {
         return false;
    }
    else if (this->numDigits < val.numDigits) {
        return true;
    }

    int i=0;
    while ( i < numDigits) {
        if ( this->digits[i] > val.digits[i]) {
            return false;
        } 
        else if (this->digits[i] < val.digits[i]) {
            return true;
        }
        i++;
    }

    return false;
}

bool BigInt::operator<=(const BigInt& val) const {

    bool flag;
    flag=(*this < val) || (*this == val);
    return flag;
}

bool BigInt::operator>(const BigInt& val) const {
    // Use the less than or equal to operator and negate the result
    return !(*this <= val);
}

bool BigInt::operator>=(const BigInt& val) const {

    bool flag;
    flag=(*this > val) || (*this == val);
    return flag;
}

BigInt& BigInt::operator++() {

    *this +=BigInt(1);
    return *this;
}

BigInt BigInt::operator++(int)
{
BigInt temp(*this);
operator++();
return temp;
}

BigInt& BigInt::operator--() {
    *this -= BigInt(1);
    return *this;
}

BigInt BigInt::operator--(int) {

    BigInt temp(*this);

    --(*this);

    return temp;
}

istream& operator>>(istream& input, BigInt& val) {
    string temp;;
    input >> temp;

    val = BigInt(temp);

    return input;
}

ostream& operator<<(ostream& output, const BigInt& val) {
    int i=0;
    while ( i < val.getNumDigits()) {
        output << val.getDigits()[i];
        i++;
    }
    return output;
}

BigInt::~BigInt(){
   
}

int BigInt::getNumDigits() const {
    return numDigits;
}

char* BigInt::getDigits() const {
		return digits;
	}

void BigInt::setDigits(char *digits) {
		this->digits = digits;
	}

void BigInt::setNumDigits(int numDigits) {
    this->numDigits = numDigits;
}

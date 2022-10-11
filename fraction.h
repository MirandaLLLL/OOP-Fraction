#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

class fraction {
	friend ostream& operator<<(ostream&, const fraction&);
	friend istream& operator>>(istream&, fraction&);
	friend	fraction operator+(fraction a, fraction b);
	friend	fraction operator-(fraction a, fraction b);
	friend	fraction operator*(fraction a, fraction b);
	friend	fraction operator/(fraction a, fraction b);
	friend bool operator==(fraction a, fraction b);
	friend bool operator<(fraction a,fraction b);
	friend bool operator<=(fraction a, fraction b);
	friend bool operator>=(fraction a, fraction b);
	friend bool operator>(fraction a, fraction b);
	friend bool operator!=(fraction a, fraction b);
	
private:
	int Numerator;
	int Denominator;

};



ostream& operator<<(ostream& output, const fraction& frac) //overload cout;
{
	if (frac.Denominator != 1)
		output << frac.Numerator << "/" << frac.Denominator; //output the result in string type;
	else
		output << frac.Numerator;
	return output;
}
istream& operator>>(istream& input, fraction& frac)  //overload cin;
{
	input >> frac.Numerator;    // read the fraction's numerator;
	input.ignore(1);                    //ignore "/"
	input >> frac.Denominator;  // read the fraction's denominator;
	return input;
}

fraction operator+(fraction a,fraction b) {  //overload "+"
	fraction c;
	int n;
	if (a.Denominator % b.Denominator == 0) { //if  a's denominator mod b's denominator = 0
		c.Denominator = a.Denominator;     //c's denominator=a's denominator;
		n = a.Denominator / b.Denominator;
		c.Numerator = a.Numerator + n * b.Numerator; //calculate c's numerator;
	}
	else {
		if (b.Denominator % a.Denominator == 0) {//if  b's denominator mod a's denominator = 0
			c.Denominator = b.Denominator;       //c's denominator=b's denominator;
			n = b.Denominator / a.Denominator;
			c.Numerator = b.Numerator + n * a.Numerator; //calculate c's numerator;
		}
		else {
			c.Denominator = a.Denominator * b.Denominator; //calculate c's denominator;
			c.Numerator = a.Denominator * b.Numerator + a.Numerator * b.Denominator; ////calculate c's numerator;
			
		}
	}
	int min = c.Denominator;
	int i;
	for (i = min; i >= 2; i--) {    //synthesize the fraction
		if ((c.Denominator % i == 0) && (c.Numerator % i == 0)) {
			c.Denominator = c.Denominator / i;
			c.Numerator = c.Numerator / i;
		}
	}

	return c;

}

fraction operator-(fraction a, fraction b) {  //overload the "-"
	fraction c;
	int n;
	if (a.Denominator % b.Denominator == 0) { //if  a's denominator mod b's denominator = 0
		c.Denominator = a.Denominator;  //c's denominator=a's denominator;
		n = a.Denominator / b.Denominator;
		c.Numerator = a.Numerator - n * b.Numerator;  //calculate c's numerator;
	}
	else {
		if (b.Denominator % a.Denominator == 0) {//if  b's denominator mod a's denominator = 0
			c.Denominator = b.Denominator; //c's denominator=b's denominator;
			n = b.Denominator / a.Denominator;
			c.Numerator = n * a.Numerator-b.Numerator; //calculate c's numerator;
		}
		else {
			c.Denominator = a.Denominator * b.Denominator;//calculate c's denominator;
			c.Numerator =  a.Numerator * b.Denominator - a.Denominator * b.Numerator ; //calculate c's numerator;
			
		}
	}
	int min = c.Denominator;
	int i;
	for (i = min; i >= 2; i--) {    //synthesize the fraction
		if ((c.Denominator % i == 0) && (c.Numerator % i == 0)) {
			c.Denominator = c.Denominator / i;
			c.Numerator = c.Numerator / i;
		}
	}

	return c;

}

fraction operator*(fraction a, fraction b) {  //overload the "*"
	fraction c;
	c.Denominator = a.Denominator * b.Denominator; //calculate c's denominator;
	c.Numerator = a.Numerator * b.Numerator;  //calculate c's numerator;
	int min = c.Denominator;
	if (c.Denominator > c.Numerator)
		min = c.Numerator;
	int i;
	for (i = min; i >= 2; i--) {  //synthesize the fraction;
		if ((c.Denominator % i == 0) && (c.Numerator % i == 0)) {
			c.Denominator = c.Denominator / i;
			c.Numerator = c.Numerator / i;
		}

		
	}
	return c;
}

		fraction operator/(fraction a, fraction b) { //overload the "/"
			fraction c;
			c.Denominator = a.Denominator * b.Numerator;  //calculate c's denominator;
			c.Numerator = a.Numerator * b.Denominator; //calculate c's numerator;
			int min = c.Denominator;
			if (c.Denominator > c.Numerator)
				min = c.Numerator;
			int i;
			for (i = 2; i <= min; i++) {  //synthesize the fraction;
				if ((c.Denominator % i == 0) && (c.Numerator % i == 0)) {
					c.Denominator = c.Denominator / i;
					c.Numerator = c.Numerator / i;
				}

				
			}
			return c;
		}
		
		bool operator==(fraction a, fraction b) {   //overload"=="
			if (a.Denominator * b.Numerator == a.Numerator * b.Denominator) //compare if a==b;
				return true;
			else
				return false;

		}
		bool operator!=(fraction a, fraction b) {  //overload "!="
			if (a.Denominator * b.Numerator != a.Numerator * b.Denominator)//compare if a!=b;
				return true;
			else
				return false;

		}
		bool operator>=(fraction a, fraction b) {  //overload  ">="
			if (a.Denominator * b.Numerator <= a.Numerator * b.Denominator)//compare if a>=b;
				return true;
			else
				return false;

		}
		bool operator<=(fraction a, fraction b) { //overload "<="
			if (a.Denominator * b.Numerator>= a.Numerator * b.Denominator) //compare if a<=b;
				return true;
			else
				return false;

		}
		bool operator>(fraction a, fraction b) {  //overload ">"
			if (a.Denominator * b.Numerator < a.Numerator * b.Denominator) //compare if a>b;
				return true;
			else
				return false;

		} 
		bool operator<(fraction a, fraction b) { //overload "<"
			if (a.Denominator * b.Numerator > a.Numerator * b.Denominator)//compare if a<b;
				return true;
			else
				return false;

		}
		
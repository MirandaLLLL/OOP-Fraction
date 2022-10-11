#include"fraction.h"

int main() {
	string ope; 
	cin>> ope;   //input the operation 
	while (ope != "end") {   //if the operation is "end"  ,then the process is over;
		fraction a, b;  
		cin >> a;    //input the first fraction;
		cin >> b;    //input the second fraction;
		if (ope == "+") {   //if the operation is "+" ,output the a+b in fraction type;
			cout << a + b << endl;
		}
		if (ope == "-") {   //if the operation is "-" ,output the a-b in fraction type;
			cout << a - b << endl;
		}
		if (ope == "*") {   //if the operation is "*" ,output the a*b in fraction type;
			cout << a * b << endl;
		}
		if (ope == "/") {   //if the operation is "/" ,output the a/b in fraction type;
			cout << a / b << endl;
		}
		if (ope == "==") {  //if the operation is "==" ,judge if a=b;
			cout << (a==b) << endl;
		}
		if (ope == "!=") {  //if the operation is "!=" ,judge if a!=b;
			cout << (a != b) << endl;
		}
		if (ope == "<=") {  //if the operation is "<=" ,judge if a<=b;
			cout << (a <= b) << endl;
		}
		if (ope == ">=") {  //if the operation is "<=" ,judge if a<=b;
			cout << (a >= b) << endl;
		}
		if (ope == "<") {   //if the operation is "<" ,judge if a<b;
			cout << (a < b) << endl;
		}
		if (ope == ">") {   //if the operation is ">" ,judge if a>b;
			cout << (a > b) << endl;
		}
		cin >> ope;
	}
	system("pause");
	return 0;
}
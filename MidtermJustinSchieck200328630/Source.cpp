#include <iostream>
#include <string>
using namespace std;


//Justin Schieck
//200328630

//function declarations
int RomanToBase10(string);
string Base10ToRoman(int);
string RomanAddition(string);
string RemoveSubtractives(string);
string addSubtractives(string);


//public variables
enum romans {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000};
int returnNumber;
string RomanNumber = "";
string RomanNumberFinal;



//Functions 
int RomanToBase10(string Number) {

	//takes the length and loops for length of roman number
	for (int i = 0; i < Number.length(); i++)
	{
		switch (Number[i])
		{
			//accesses enum to add number into the current amount.
		case 'M': returnNumber += M;
			break;
		case 'D': returnNumber += D;
			break;
		case 'C': returnNumber += C;
			break;
		case 'L': returnNumber += L;
			break;
		case 'X': returnNumber += X;
			break;
		case 'V': returnNumber += V;
			break;
		case 'I':
			//If there is an I after the current number and it is not the end of the number
			if (Number[i + 1] != 'I' && i + 1 != Number.length()){

				//subtract 1
				returnNumber -= 1;
			}
			else {
				//add 1
				returnNumber += 1;
			}
			
			break;
		}
	}
	return returnNumber;
	
}

string Base10ToRoman(int Base10) {


	do {
		if (Base10 >= 1000) {
		
			RomanNumber += 'M';
			Base10 -= 1000;

		}
		if (Base10 >= 500) {
			
			RomanNumber += 'D';
			Base10 -= 500;

		}
		if (Base10 >= 100) {
			
			RomanNumber += 'C';
			Base10 -= 100;

		}
		if (Base10 >= 50) {
			
			RomanNumber += 'L';
			Base10 -= 50;

		}
		if (Base10 >= 10) {
			
			RomanNumber += 'X';
			Base10 -= 10;

		}
		if (Base10 >= 5) {

			RomanNumber += 'V';
			Base10 -= 5;

		}
		if (Base10 >= 1) {
			
			RomanNumber += 'I';
			Base10 -= 1;

		}

	} while (Base10 != 0);

	RomanNumberFinal = RemoveSubtractives(RomanNumber);

	return RomanNumberFinal;
}

string RomanAddition(string num1, string num2) {

	//theres something wrong here and Id like to know what i did wrong so I can have a working version of this.


	int BaseNum1, BaseNum2, totalAdd;
	string TotalString;
	//set the variables to int
	BaseNum1 = RomanToBase10(num1);
	BaseNum2 = RomanToBase10(num2);
	TotalString = BaseNum1 + BaseNum2;


	//do the addition
	totalAdd = BaseNum1 + BaseNum2;
	
	//reconvert to string roman
	RomanNumber = Base10ToRoman(totalAdd);

	//condence the code 
	RomanNumberFinal = RemoveSubtractives(RomanNumber);

	return RomanNumberFinal;
}

string RemoveSubtractives(string RomanNum) {
	string ReturnString;

	ReturnString = RomanNum;
		
		//IV instead of IIII
		if (ReturnString.find("IIII") == true) {
			ReturnString.replace(ReturnString.find("IIII"), 0, "IV");
		}
		//IX instead of VIIII
		if (ReturnString.find("VIIII") == true) {
			ReturnString.replace(ReturnString.find("VIIII"), 0, "IX");
		}
		//XL instead of XXXX
		if (ReturnString.find("XXXX") == true) {
			ReturnString.replace(ReturnString.find("XXXX"), 0, "XL");
		}
		//XC instead of LXXXX
		if (ReturnString.find("LXXXX") == true) {
			ReturnString.replace(ReturnString.find("LXXXX"), 0, "XC");
		}
		//CD instead of  CCCC
		if (ReturnString.find("CCCC") == true) {
			ReturnString.replace(ReturnString.find("CCCC"), 0, "CD");
		}
		//CM instead of DCCCC
		if (ReturnString.find("DCCCC") == true) {
			ReturnString.replace(ReturnString.find("DCCCC"), 0, "CM");
		}
	
	return ReturnString;
}

void AddSubtractives() {

}


//Main Program
int main() {
	string fName, lName, SN, romanNum1, romanNum2, totalRoman;
	int menuChoice, base10, total;

	//NameTag
	fName = "Justin";
	lName = "Schieck";
	SN = "200328630";

	cout << fName << " " << lName << " (" << SN << ")"<< endl << endl ;
	cout << "";

	do {
		//Opening Dialog
		cout << "***Available Operations***" << endl;
		cout << "1. Roman to Base 10 " << endl;
		cout << "2. Base10 to Roman " << endl;
		cout << "3. Add 2 Roman Numbers " << endl;
		cout << "4. Exit " << endl;
		cout << "Please indicate your selection : " ;
		cout << endl;
		cin >> menuChoice;


		//Validation on MenuChoice
		if (menuChoice >= 5 || menuChoice <= 0) {
			cout << "Please indicate a valid option" << endl << endl;
		} 
		else {
		
			switch (menuChoice) {
				//convert roman number to base10
			case(1): {

				cout << "Please Input the Roman Number: " << endl;
				cin >> romanNum1;
				total = RomanToBase10(romanNum1);
				returnNumber = 0;
				cout << "The Base10 number is: " << total << endl << endl;
								
				break;
			}
					//convert base10 to roman numeral
			case(2): {

				cout << "Please Input the Base10 Number: " << endl;
				cin >> base10;
				totalRoman = Base10ToRoman(base10);
				RomanNumber = "";
				cout << "The Roman number is: " << totalRoman << endl << endl;

				break;
			}
					//add two roman numbers together
			case(3): {

				cout << "Please Input the first Roman Number: " << endl;
				cin >> romanNum1;
				cout << "Please Input the Second Roman Number: " << endl;
				cin >> romanNum2;
				RomanNumber = "";
				totalRoman = RomanAddition(romanNum1, romanNum2);

				cout << "The Sum of " << romanNum1 << " + " << romanNum2 << " = " << totalRoman << endl << endl;
				
				break;
			}
				//Exit 
			case(4): {
				cout << "Thank you for running this Program..." << endl << endl;
				cout << "Gratias tibi!!" << endl << endl;
				}
			}
		}
	} while (menuChoice != 4);
	system("pause");
	return(0);


}

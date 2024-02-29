//TASK NUMBER 2
//A SIMPLE CALCULATOR
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main() {
	double num1, num2;
	double result;
	int choice;
	
		cout << "WELCOME TO YOUR OWN CALCULATOR" << endl;
		cout << "PLEASE ENTER YOUR CHOICE" << endl;
		do {
		cout << "[1] ADDITION " << endl;
		cout << "[2] SUBTRACTION" << endl;
		cout << "[3] MULTIPLICATION" << endl;
		cout << "[4] DIVISION" << endl;
		cout << "[0] EXIT PROGRAM" << endl;
		cin >> choice;
		system("cls");
		if (choice == 0) { goto end; }
		else
		switch (choice) {
		case 1:
		{
			cout << "Enter 1st Number: " << endl;
			cin >> num1;
			cout << "Enter 2nd Number: " << endl;
			cin >> num2;
			result = num1 + num2;
			system("cls");
			cout << "Result of " << num1 << " + " << num2 << " = " << result<<endl;
			break;
		}
		case 2:
		{
			cout << "Enter 1st Number: " << endl;
			cin >> num1;
			cout << "Enter 2nd Number: " << endl;
			cin >> num2;
			result = num1 - num2;
			system("cls");
			cout << "Result of " << num1 << " - " << num2 << " = " << result<<endl;
			break;
		}
		case 3:
		{
			cout << "Enter 1st Number: " << endl;
			cin >> num1;
			cout << "Enter 2nd Number: " << endl;
			cin >> num2;
			result = num1 * num2;
			system("cls");
			cout << "Result of " << num1 << " * " << num2 << " = " << result<<endl;
			break;
		}
		case 4:
		{
		a:
			cout << "Enter 1st Number: " << endl;
			cin >> num1;
			cout << "Enter 2nd Number: " << endl;
			cin >> num2;
			if (num2 != 0) {
				result = num1 / num2;
				system("cls");
				cout << "Result of " << num1 << " / " << num2 << " = " << result<<endl;
			}
			else
			{
				system("cls");
				cout << "Please enter number greater than 0" << endl;
				goto a;
			}
			break;
		}
		default:
			cout << "Invalid option" << endl;
		}
	} while (true);
end:
	cout << "---------THE END!!!!--------" << endl;


}
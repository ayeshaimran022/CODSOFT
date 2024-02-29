//NUMBER GUESSING GAME 
//TASK NUMBER 1
#include <iostream>
#include<ctime>
	using namespace std;
	int main() {

		int a, b, c, d, e;
		srand(time(NULL));
		int x;
		x = rand() % 100;
		cout << "WELCOME TO HI LOW GAME" << endl;
		cout << "----------------------" << endl;
		cout << "DEAR PLAYER!!! PLEASE ENTER THE NUMBER BETWEEN 0 - 100	 AND I'LL HELP YOU IN GUESSTING IT RIGHT!" << endl;
		cout << "YOU HAVE 5 CHANCES TO GUESS IT RIGHT!! GOOD LUCK!!!" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "Enter you guess no. " << i + 1 << endl;
			cin >> a;
			if (a == x) {
				break;
			}
			else if (a > x) {
				cout << "TOO HIGH!!! TRY AGAIN" << endl;

			}
			else if (a < x) {
				cout << "TOO LOW!!! TRY AGAIN" << endl;
			}
		
		}
		cout << "YOU GUESSED IT RIGHT" << endl << "CONGRATULATIONS!!! YOU WON." << endl;
		return 0;
	}

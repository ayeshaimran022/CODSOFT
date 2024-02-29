#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include<conio.h>
using namespace std;
string name, tasks;
int id;
static int count;

void createMenu() {
    string name, tasks;
    int id;

    ofstream ofile("ToDoList.csv", ios::app);

    if (!ofile) {
        cout << "ERRORRRRR!!!!! File cannot be created" << endl;
        return;
    }

    cout << "INPUT YOUR TASKS. Press '0' to exit." << endl;
   

    do {
        cout << "Add your task number: " << endl;
        cin >> id;
        cin.ignore();
        if (id == 0) {
            break;
        }

        cout << "Enter your Tasks: ";
        getline(cin, name);

        cout << "Is the task Completed or Pending? ";
        getline(cin, tasks);

      //  count++;
        ofile << setw(20) << left << name << setw(10) << right << tasks << setw(10) << endl;

    } while (true);

    ofile.close();
}

void displayMenu() {
    ifstream ifile("ToDoList.csv");

    if (!ifile) {
        cerr << "ERROR: File cannot be opened" << endl;
        return;
    }

    cout << "WELCOME TO OUR CAFE!!!" << endl;
    cout << "OUR MENU IS DISPLAYED BELOW:" << endl;
    cout << setw(20) << left << "Tasks" << setw(10) << right << "Status" << endl;
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;

    string name, tasks;

    while (ifile >> quoted(name) >> ws >> quoted(tasks)) {
        cout << setw(20) << left << name << setw(10) << right << tasks << endl;
    }

    ifile.close();
}


void addItemToMenu() {

    string name;
    double price;

    ofstream addfile("ToDoList.csv", ios::app);

    if (!addfile) {
        cerr << "ERRORRRRRR!!!! File cannot be opened!" << endl;
        return;
    }

    cout << "Please enter the item to be added in the menu!!" << endl;
    cout << "ID of item: ";
    cin >> id;
    cin.ignore();

    cout << "Enter your Tasks: ";
    getline(cin, name);

    cout << "Is the task Completed or Pending? ";
    getline(cin, tasks);

    addfile << setw(20) << left << name << setw(10) << right << tasks << setw(10) << endl;
    addfile.close();
}

void removeItemFromMenu(const string& itemName) {
    ifstream ifile("ToDolist.csv");
    ofstream ofile("new.csv");

    if (!ifile || !ofile) {
        cout << "ERRORRRRR!!!! file cannot be opened." << endl;
        return;
    }
    while (ifile >> ws >> id >> name >> tasks) {
        if (name != itemName) {
            // Copy items other than the one to be removed to the new file.
            ofile << setw(20) << left << id << setw(10) << name << setw(10) << right << tasks << setw(10) << endl;

        }
    }

    ifile.close();
    ofile.close();

    // Remove the old file and rename the new file.
    remove("ToDolist.csv");
    rename("new.csv", "ToDoist.csv");
}

int main() {
    createMenu();

    cout << "Your To Do List has been created and saved!!" << endl;
    displayMenu();
    addItemToMenu();
    cout << "Your To Do List has been updated" << endl;
    displayMenu();

    cout << "Do you want to remove anything from the list?(y/n)" << endl;
    char choice;      //check again to remove the tasks
    cin >> choice;
    if (choice == 'y') {
        string itemToRemove;
        cout << "Please input your task to update your lists: ";
        getline(cin, itemToRemove);

        removeItemFromMenu(itemToRemove);

        cout << "Item has been removed from the menu.\n";
    }
    else {
        cout << "Nothing to Remove" << endl;
    }
    displayMenu();
    return 0;
}
#include "UserInterface.h"
#include <iostream>
#include <numeric>
using namespace std;

int startUI() {
    int option;
    cout << "\n\n-------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create New Account" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option > ";
    while (!(cin >> option)) {  // Verifica se a entrada não é um inteiro
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input! Please enter a valid option > ";
    }
    return option;
}

int menuUI() {
    int option;
    cout << "\n\n-------------------" << endl;
    cout << "1. View Balance" << endl;
    cout << "2. Cash Withdraw" << endl;
    cout << "3. Cash Deposit" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option > ";

    while (!(cin >> option)) {  // Verifica se a entrada não é um inteiro
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input! Please enter a valid option > ";
    }
    return option;
}

int startInputValidation() {
    int option;

    while (true) {
        option = startUI();
        if (option >= 1 && option <= 3) {
            return option;
        }
        cout << "\nInvalid input! Please insert a valid option!\n" << endl;
    }
}

int menuInputValidation() {
    int option;

    while (true) {
        option = menuUI();
        if (option >= 1 && option <= 4) {
            return option;
        }
        cout << "\nInvalid input! Please insert a valid option!\n" << endl;
    }
}

int endOperation() {
    int option;

    while (true) {
        cout << "\nPress 1 to make more operations\nPress 0 to return to the main menu > ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter 0 or 1." << endl;
        } else if (option == 0 || option == 1) {
            return option;
        } else {
            cout << "\nInvalid input. Please enter 0 or 1." << endl;
        }
    }
}

#include <iostream>
#include <numeric>
#include "Account.h"
#include "UserInterface.h"

using namespace std;

int main() {
    Account account(1000.00);
    int option;
    int system = 1;

    while (system != 0) {
        option = inputValidation();

        switch (option) {
            case 1:
                cout << "\nYour current balance is " << account.getBalance() << " EUR." << endl;
            system = endOperation();
            break;

            case 2:
                cout << "\nHow much money would you like to withdraw? > ";
            float amount;

            while (!(cin >> amount)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input! Please insert a valid number > ";
            }

            account.withdraw(amount);
            break;

            case 3:
                // Add deposit functionality here if needed
                    break;

            case 4:
                system = 0;  // Exit option
            break;

            default:
                cout << "\nInvalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}

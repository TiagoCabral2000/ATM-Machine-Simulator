#include "UserInterface.h"
#include <iostream>
#include <numeric>
using namespace std;

int UI() {
   int option;
   cout << "\n\n1. View Balance" << endl;
   cout << "2. Cash Withdraw" << endl;
   cout << "3. Cash Deposit" << endl;
   cout << "4. Exit" << endl;
   cout << "Enter your choice > ";

   while (!(cin >> option)) {  // Check if input is not an integer
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input! Please enter a valid option > ";
   }
   return option;
}

int inputValidation() {
   int option;

   while (true) {
      option = UI();
      if (option >= 1 && option <= 4) {
         return option;
      }
      cout << "\nInvalid input! Please insert a valid option!\n" << endl;
   }
}

int endOperation() {
   int option;

   while (true) {
      cout << "\nPress 1 to make more operations\nPress 0 to close the app > ";
      cin >> option;

      if (cin.fail()) {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "\nInvalid input. Please enter 0 or 1." << endl;
      } else if (option == 0 || option == 1) {
         return option;
      } else {
         cout << "\nInvalid option. Please enter 0 or 1." << endl;
      }
   }
}

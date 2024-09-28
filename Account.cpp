#include "Account.h"
#include <iostream>
#include <limits>

Account::Account() { // Constructor without arguments
   std::cout << "Please define an initial balance: ";
   while (!(std::cin >> balance)) {  // Check for valid float input
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input! Please enter a valid balance: ";
   }
}

Account::Account(float amount) : balance(amount) {}

float Account::getBalance() const {
   return balance;  // Changed to float
}

int Account::withdraw(float amount) {
   if (amount > balance)
      return 0;
   balance -= amount;
   return 1;
}

void Account::deposit(float amount) {
   balance += amount;
}

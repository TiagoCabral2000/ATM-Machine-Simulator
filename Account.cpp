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

void Account::withdraw(float amount) {
   if (amount > balance) {
      std::cout << "\nInsufficient balance! You only have " << balance << " left!" << std::endl;
      return;
   }
   balance -= amount;
}

void Account::deposit(float amount) {
   balance += amount;
}

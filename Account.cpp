#include "Account.h"
#include <iostream>
#include <limits>
#include <vector>

Account::Account() { // Constructor without arguments
   std::cout << "Please define an initial balance: ";
   while (!(std::cin >> balance)) {  // Check for valid float input
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input! Please enter a valid balance: ";
   }
}

Account::Account(float amount) : balance(amount) {}

void Account::checkAcc() {
   if (accounts.empty()) {
      std::cout << "No accounts available." << std::endl;
   } else {
      std::cout << "Accounts available:" << std::endl;
      for (const auto& account : accounts) {
         std::cout << account << std::endl;
      }
   }
}
void Account::checkPass() {

}

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

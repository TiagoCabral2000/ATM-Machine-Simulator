//
// Created by tiago on 28/09/2024.
//
#include <iostream>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
private:
   float balance;
public:
   //Constructors
   Account();
   Account(float amount);
   //Methods
   float getBalance() const;
   int withdraw(float amount);
   void deposit(float amount);
};

#endif //ACCOUNT_H

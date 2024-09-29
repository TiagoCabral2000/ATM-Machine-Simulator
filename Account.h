//
// Created by tiago on 28/09/2024.
//
#include <iostream>
#include <vector>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
private:
   float balance;
   vector<string> accounts;
   vector<string> passwords;
public:
   //Constructors
   Account();
   Account(float amount); //change to string username?
   //Methods
   void checkAcc();
   void checkPass();
   float getBalance() const;
   int withdraw(float amount);
   void deposit(float amount);
};

#endif //ACCOUNT_H

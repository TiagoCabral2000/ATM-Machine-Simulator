//
// Created by tiago on 28/09/2024.
//
#include <iostream>
#include <vector>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    vector<float> balances; // Vetor para armazenar saldos de cada conta
    vector<string> accounts;
    vector<string> passwords;

public:
    // Construtores
    Account();

    // Métodos
    void newAccount(const string& username, const string& password); // Cria nova conta
    bool login(const string& username, const string& password);       // Verifica login

    float getBalance(const string& username) const; // Obtém saldo de uma conta específica
    int withdraw(const string& username, float amount); // Retira dinheiro de uma conta
    void deposit(const string& username, float amount); // Deposita dinheiro em uma conta
};

#endif //ACCOUNT_H

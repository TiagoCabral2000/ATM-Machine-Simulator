#include "Account.h"
#include <iostream>
#include <limits>
#include <vector>

Account::Account() { // Construtor sem argumentos
    // Não é necessário inicializar o saldo aqui
}

void Account::newAccount(const string& username, const string& password) {
    // Verifica se o nome de usuário já existe
    for (const auto& acc : accounts) {
        if (acc == username) {
            cout << "\nAccount already exists with this username!" << endl;
            return;
        }
    }
    // Se o nome de usuário for único, cria a conta
    accounts.push_back(username);
    passwords.push_back(password);
    balances.push_back(0.0f); // Inicializa o saldo para a nova conta
    cout << "\nAccount created successfully!" << endl;
}

bool Account::login(const string& username, const string& password) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i] == username) {
            if (passwords[i] == password) {
                cout << "\nLogin successful!" << endl;
                return true;
            } else {
                cout << "\nIncorrect password!" << endl;
                return false;
            }
        }
    }
    cout << "\nUsername not found!" << endl;
    return false;
}

float Account::getBalance(const string& username) const {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i] == username) {
            return balances[i]; // Retorna o saldo da conta correspondente
        }
    }
    return 0.0f; // Retorna 0 se a conta não for encontrada
}

int Account::withdraw(const string& username, float amount) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i] == username) {
            if (amount > balances[i]) {
                return 0; // Saldo insuficiente
            }
            balances[i] -= amount; // Atualiza o saldo
            return 1; // Operação bem-sucedida
        }
    }
    return 0; // Conta não encontrada
}

void Account::deposit(const string& username, float amount) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i] == username) {
            balances[i] += amount; // Atualiza o saldo
            return; // Saída do método
        }
    }
}

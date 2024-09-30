#include <iostream>
#include <numeric>
#include <vector>
#include "Account.h"
#include "UserInterface.h"

using namespace std;

int main() {
    Account newAcc; // Construtor padrão inicializa saldo
    int startOption, menuOption;
    int menu = 0;
    int system = 1;
    float amount;
    string username, password;

    while (system != 0) {
        startOption = startInputValidation();

        switch (startOption) {
            case 1: // Login
                cout << "\nUsername > ";
                cin >> username;
                cout << "\nPassword > ";
                cin >> password;

                // Verifica se o login é bem-sucedido
                if (newAcc.login(username, password)) {
                    menu = 1; // Ativa o menu de operações
                }
                break;

            case 2: // Create Account
                cout << "\nCreate your Username > ";
                cin >> username;
                cout << "\nCreate your Password > ";
                cin >> password;

                newAcc.newAccount(username, password); // Cria nova conta
                break;

            case 3: // Exit
                system = 0;
                menu = 0;
                break;
        }

        // Menu de operações (caso o login seja bem-sucedido)
        while (menu != 0) {
            menuOption = menuInputValidation();
            switch (menuOption) {
                case 1: // Ver saldo
                    cout << "\nYour current balance is " << newAcc.getBalance(username) << " EUR." << endl;
                    menu = endOperation();
                    break;

                case 2: // Saque
                    cout << "\nHow much money would you like to withdraw? > ";

                    while (!(cin >> amount)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nInvalid input! Please insert a valid number > ";
                    }
                    if (newAcc.withdraw(username, amount)) {
                        cout << "\nOPERATION SUCCESSFUL!\nThe updated balance is " << newAcc.getBalance(username) << " EUR" << endl;
                    } else {
                        std::cout << "\nInsufficient balance! You only have " << newAcc.getBalance(username) << " EUR." << std::endl;
                    }
                    menu = endOperation();
                    break;

                case 3: // Depósito
                    cout << "\nHow much money would you like to deposit? > ";

                    while (!(cin >> amount)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nInvalid input! Please insert a valid number > ";
                    }
                    newAcc.deposit(username, amount); // Depósito
                    cout << "\nOPERATION SUCCESSFUL!\nThe updated balance is " << newAcc.getBalance(username) << " EUR" << endl;
                    menu = endOperation();
                    break;

                case 4: // Sair
                    menu = 0;
                    break;
            }
        }
    }

    return 0; // Encerra o programa
}

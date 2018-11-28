#include <iostream>
#include <vector>
#include "UserCredentials.h"
#include "SickLeave.h"
#include <algorithm>
#include "Worker.h"

using namespace std;

int mainMenu(Worker *worker);
void usersMenu(Worker *worker);

class Authentification {
public:

    void registration(Worker *worker) {
        UserCredentials *user = new UserCredentials();

        cin.ignore();
        cout << "Введите логин" << endl;

        string login;
        getline(cin, login);
        user->setLogin(login);

        cout << "Введите пароль" << endl;

        string password;
        getline(cin, password);
        user->setPassword(password);

        users.push_back(user);

        mainMenu(worker);
    }

    void login(Worker *worker) {
        cin.ignore();
        string login;
        cout << "Введите логин" << endl;
        getline(cin, login);

        cout << "Введите пароль" << endl;
        string password;
        getline(cin, password);

        for (int i = 0; i < users.size(); i++) {
            if (login == users[i]->getLogin() && password == users[i]->getPassword()) {
                usersMenu(worker);
            }
        }
        cout << "Неверный логин или пароль" << endl;
        mainMenu(worker);
    }

};

void usersMenu(Worker *worker) {
    cout << "---------------Меню пользователя------------------" << endl;
    cout << "1. Ввод информации" << endl;
    cout << "2. Просмотр данных" << endl;
    cout << "3. Поиск и фильтрация" << endl;
    cout << "4. Сортировка" << endl;
    cout << "5. Удаление" << endl;
    cout << "0. Выход в главное меню" << endl;

    int value;
    cin >> value;

    switch (value) {
        case 1: {
            worker->addInfo();
            usersMenu(worker);
            break;
        }
        case 2: {
            worker->showInfo();
            usersMenu(worker);
            break;
        }
        case 3: {
            worker->searchAndFilter();
            usersMenu(worker);
            break;
        }
        case 4: {
            worker->sortPersons();
            worker->showInfo();
            usersMenu(worker);
            break;
        }
        case 5: {
            worker->deleteBySurname();
            worker->showInfo();
            usersMenu(worker);
            break;
        }
        case 0: {
            mainMenu(worker);
            break;
        }
    }
}

int mainMenu(Worker *worker) {

    Authentification *authentification = new Authentification();

    cout << "-------------Выберите действие-------------------" << endl;
    cout << "1. Регистрация пользователя" << endl;
    cout << "2. Вход пользователя" << endl;
    cout << "0. Выход из программы" << endl;

    int value;
    cin >> value;

    switch (value) {
        case 1:
            authentification->registration(worker);
            break;
        case 2: {
            if (!users.empty()) {
                authentification->login(worker);
            } else {
                cout << "Нет зарегистрированных пользователей" << endl;
                mainMenu(worker);
            }

            break;
        }
        case 0:
            return 0;
    }
}

int main() {

    Worker *worker = new Worker();

    mainMenu(worker);

    return 0;
}
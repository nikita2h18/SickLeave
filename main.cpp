#include <iostream>
#include <vector>
#include <algorithm>
#include "Employee.h"
#include "Date.h"
#include "SickLeave.h"
#include "UserCredentials.h"

using namespace std;

vector<UserCredentials*> users;
vector<SickLeave*> sickLeaves;

int mainMenu();

void usersMenu();

void setDate(Date *date) {
    date->setDay();
    date->setMonth();
    date->setYear();

    if(!date->isValid()) {
        cout << "Ошибка при вводе даты, попробуйте снова: " << endl;
        setDate(date);
    }
}

void searchAndFilter() {
    string word;
    cin.ignore();

    cout << "Введите фамилию" << endl;
    getline(cin, word);

    for (int i = 0; i < sickLeaves.size(); i++) {
        int count = 0;
        for (int j = 0; j < word.size(); j++) {
            if (word[j] == sickLeaves[i]->getSurname()[j]) {
                count++;
            }
            if (count == word.size()) {
                sickLeaves[i]->getPerson();
                sickLeaves[i]->getStart();
                sickLeaves[i]->getEnd();
            }
        }
    }
}

void sortPersons() {
    sort(sickLeaves.begin(), sickLeaves.end(),
         [](SickLeave *x, SickLeave *y) { return (x->getSurname() < y->getSurname()); });
}

void addInfo() {
    auto *employee = new Employee();
    string name;
    string surname;
    string patronymic;
    string sex;

    auto *start = new Date();
    auto *end = new Date();

    cin.ignore();

    cout << "Введите имя" << endl;
    getline(cin, name);

    cout << "Введите фамилию" << endl;
    getline(cin, surname);

    cout << "Введите отчество" << endl;
    getline(cin, patronymic);

    cout << "Введите пол" << endl;
    getline(cin, sex);

    cout << "Введите дату начала больничного" << endl;

    setDate(start);

    cout << "Введите дату окончания больничного" << endl;
    setDate(end);

    employee->setName(name);
    employee->setPatronymic(patronymic);
    employee->setSurname(surname);
    employee->setSex(sex);

    SickLeave *sickLeave = new SickLeave();
    sickLeave->setEmployee(*employee);
    sickLeave->setStart(*start);
    sickLeave->setEnd(*end);

    sickLeaves.push_back(sickLeave);
}

void showInfo() {
    for (int i = 0; i < sickLeaves.size(); i++) {
        sickLeaves[i]->getPerson();
        cout << "Начало больничного" << endl;
        sickLeaves[i]->getStart();
        cout << "Окончание больничного" << endl;
        sickLeaves[i]->getEnd();
        cout << endl;
    }

}

void registration() {
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

    mainMenu();
}

void login() {
    cin.ignore();
    string login;
    cout << "Введите логин" << endl;
    getline(cin, login);

    cout << "Введите пароль" << endl;
    string password;
    getline(cin, password);

    for (int i = 0; i < users.size(); i++) {
        if (login == users[i]->getLogin() && password == users[i]->getPassword()) {
            usersMenu();
        }
    }
    cout << "Неверный логин или пароль" << endl;
    mainMenu();
}

void usersMenu() {
    cout << "---------------Меню пользователя------------------" << endl;
    cout << "1. Ввод информации" << endl;
    cout << "2. Просмотр данных" << endl;
    cout << "3. Поиск и фильтрация" << endl;
    cout << "4. Сортировка" << endl;
    cout << "0. Выход в главное меню" << endl;

    int value;
    cin >> value;

    switch (value) {
        case 1: {
            addInfo();
            usersMenu();
            break;
        }
        case 2: {
            showInfo();
            usersMenu();
            break;
        }
        case 3: {
            searchAndFilter();
            usersMenu();
            break;
        }
        case 4: {
            sortPersons();
            showInfo();
            usersMenu();
            break;
        }
        case 0: {
            mainMenu();
            break;
        }
    }
}

int mainMenu() {

    cout << "-------------Выберите действие-------------------" << endl;
    cout << "1. Регистрация пользователя" << endl;
    cout << "2. Вход пользователя" << endl;
    cout << "0. Выход из программы" << endl;

    int value;
    cin >> value;


    switch (value) {
        case 1:
            registration();
            break;
        case 2: {
            if (!users.empty()) {
                login();
            } else {
                cout << "Нет зарегистрированных пользователей" << endl;
                mainMenu();
            }

            break;
        }
        case 0:
            return 0;
    }

}

int main() {

    mainMenu();

    return 0;
}
#ifndef SICKLEAVES_WORKER_H
#define SICKLEAVES_WORKER_H


#include <iostream>
#include <vector>

using namespace std;

vector<SickLeave *> sickLeaves;
vector<UserCredentials *> users;

class Worker {
public:

    Worker() {}

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
                }
            }
        }
    }

    void deleteBySurname() {
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
                    sickLeaves.erase(sickLeaves.begin() + i);
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
        int salaryPerDay;

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

        cout << "Введите зарплату за день" << endl;
        cin >> salaryPerDay;

        cout << "Введите дату начала больничного" << endl;

        start->setDate(start);

        cout << "Введите дату окончания больничного" << endl;
        end->setDate(end);

        employee->setName(name);
        employee->setPatronymic(patronymic);
        employee->setSurname(surname);
        employee->setSex(sex);
        employee->setSalaryPerDay(salaryPerDay);

        SickLeave *sickLeave = new SickLeave();
        sickLeave->setEmployee(*employee);
        sickLeave->setStart(*start);
        sickLeave->setEnd(*end);

        sickLeaves.push_back(sickLeave);
    }

    void showInfo() {
        for (int i = 0; i < sickLeaves.size(); i++) {
            sickLeaves[i]->getPerson();
        }

    }

};


#endif //SICKLEAVES_WORKER_H

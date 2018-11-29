#ifndef SICKLEAVES_WORKER_H
#define SICKLEAVES_WORKER_H


#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

vector<SickLeave *> sickLeaves;
vector<UserCredentials *> users;

class Worker {
public:

    Worker() {}

    void searchAndFilterByPeriod() {
        int beginDay;
        int beginMonth;
        int beginYear;
        int endDay;
        int endMonth;
        int endYear;

        cout << "Введите дату 1" << endl;
        cin >> beginDay;
        cin >> beginMonth;
        cin >> beginYear;

        cout << "Введите дату 2" << endl;
        cin >> endDay;
        cin >> endMonth;
        cin >> endYear;


        for (int i = 0; i < sickLeaves.size(); i++) {
            if (sickLeaves[i]->getDayStart() >= beginDay && sickLeaves[i]->getDayEnd() <= endDay &&
                sickLeaves[i]->getMonthStart() >= beginMonth && sickLeaves[i]->getMonthEnd() <= endMonth &&
                sickLeaves[i]->getYearStart() >= beginYear && sickLeaves[i]->getYearEnd() <= endYear) {
                sickLeaves[i]->getPerson();
            }
        }
    }

    void searchSickLeaves() {
        string surname;
        cin.ignore();

        string name;
        string patronymic;

        cout << "Введите фамилию" << endl;
        getline(cin, surname);

        cout << "Введите Имя" << endl;
        getline(cin, name);

        cout << "Введите Отчество" << endl;
        getline(cin, patronymic);

        for (int i = 0; i < sickLeaves.size(); i++) {
            bool countS = false;
            bool countN = false;
            bool countP = false;
            for (int j = 0; j < surname.size(); j++) {
                countS = surname[j] == sickLeaves[i]->getSurname()[j];
            }

            for (int j = 0; j < name.size(); j++) {
                countN = name[j] == sickLeaves[i]->getName()[j];
            }

            for (int j = 0; j < patronymic.size(); j++) {
                countP = patronymic[j] == sickLeaves[i]->getPatronymic()[j];
            }
            if (countS && countN && countP) {
                sickLeaves[i]->getPerson();
            }
        }
    }

    void deleteBySurname() {
        string word;
        cin.ignore();

        cout << "Введите фамилию" << endl;
        getline(cin, word);

        for (int i = 0; i < sickLeaves.size(); i++) {
            bool count;
            for (int j = 0; j < word.size(); j++) {
                count = word[j] == sickLeaves[i]->getSurname()[j];
                if (count) {
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
        cout << "        Фамилия|"
             << "            Имя|"
             << "       Отчество|"
             << "            Пол|"
             << "  Начало больничного|"
             << "   Конец больничного|"
             << "      Выплатить|" << endl;
        cout << "_______________|"
             << "_______________|"
             << "_______________|"
             << "_______________|"
             << "____________________|"
             << "____________________|"
             << "_______________|" << endl;
        for (int i = 0; i < sickLeaves.size(); i++) {
            sickLeaves[i]->getPerson();
        }

    }

    void fileInput() {
        ofstream ofs("E:\\text.txt");
        ofs << "        Фамилия|"
            << "            Имя|"
            << "       Отчество|"
            << "            Пол|"
            << "  Начало больничного|"
            << "   Конец больничного|"
            << "      Выплатить|\r\n";
        ofs << "_______________|"
            << "_______________|"
            << "_______________|"
            << "_______________|"
            << "____________________|"
            << "____________________|"
            << "_______________|\r\n";
        for (int i = 0; i < sickLeaves.size(); i++) {
            ofs << setw(15) << sickLeaves[i]->getSurname() << '|';
            ofs << setw(15) << sickLeaves[i]->getName() << '|';
            ofs << setw(15) << sickLeaves[i]->getPatronymic() << '|';
            ofs << setw(15) << sickLeaves[i]->getSex() << '|';
            ofs << setw(12) << sickLeaves[i]->getDayStart() << '.'
                    << sickLeaves[i]->getMonthStart() << '.'
                    << sickLeaves[i]->getYearStart() << '|';
            ofs << setw(12) << sickLeaves[i]->getDayEnd() << '.'
                << sickLeaves[i]->getMonthEnd() << '.'
                << sickLeaves[i]->getYearEnd() << '|';
            ofs << setw(15) << sickLeaves[i]->getSalary() << "|\r\n";
        }
        ofs.close();
    }

    void fileOutput() {
        ifstream ifs("E:\\text.txt");
        string s;
        while(getline(ifs, s)){
            cout << s << endl;
        }

        ifs.close();
    }

};


#endif //SICKLEAVES_WORKER_H

#ifndef SICKLEAVES_EMPLOYEE_H
#define SICKLEAVES_EMPLOYEE_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Employee {
private:
    string name;
    string surname;
    string patronymic;
    string sex;
    int salaryPerDay;

public:

    Employee() {}

    int getSalaryPerDay() const {
        return salaryPerDay;
    }

    void setSalaryPerDay(int salaryPerDay) {
        this->salaryPerDay = salaryPerDay;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getSurname() {
        return surname;
    }

    void setSurname(string surname) {
        this->surname = surname;
    }

    string getPatronymic() {
        return patronymic;
    }

    void setPatronymic(string patronymic) {
        this->patronymic = patronymic;
    }

    string getSex() {
        return sex;
    }

    void setSex(string sex) {
        this->sex = sex;
    }

};


#endif //SICKLEAVES_EMPLOYEE_H

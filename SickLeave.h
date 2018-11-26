//
// Created by user on 26.11.2018.
//

#ifndef SICKLEAVES_SICKLEAVE_H
#define SICKLEAVES_SICKLEAVE_H


#include "Employee.h"
#include "Date.h"

using namespace std;

class SickLeave {
private:
    Employee employee;

    Date start;
    Date end;

public:
    SickLeave() {}

    void getPerson() {
        cout << employee.getName() << " " << employee.getPatronymic() << " " << employee.getSurname() << endl;
        cout << "Пол: " << employee.getSex() << endl;
    }

    string getSurname() {
        return employee.getSurname();
    }

    string getName() {
        return employee.getName();
    }
    void setEmployee(Employee employee) {
        this->employee = employee;
    }

    void getStart() {
        start.getDate();
    }

    void setStart(Date start) {
        this->start = start;
    }

    void getEnd() {
        end.getDate();
    }

    void setEnd(Date end) {
        this->end = end;
    }
};


#endif //SICKLEAVES_SICKLEAVE_H

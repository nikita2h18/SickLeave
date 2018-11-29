#ifndef SICKLEAVES_SICKLEAVE_H
#define SICKLEAVES_SICKLEAVE_H

#include <iostream>
#include <iomanip>
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
        cout << setw(15) << employee.getSurname() << '|';
        cout << setw(15) << employee.getName() << '|';
        cout << setw(15) << employee.getPatronymic() << '|';
        cout << setw(15) << employee.getSex() << '|';
        start.getTableDate();
        end.getTableDate();
        cout << setw(15) << getSalary() << '|' << endl;
    }

    string getSurname() {
        return employee.getSurname();
    }

    string getName() {
        return employee.getName();
    }

    string getPatronymic() {
        return  employee.getPatronymic();
    }

    string getSex() {
        return employee.getSex();
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

    int getDayStart() {
        return start.getDay();
    }

    int getMonthStart() {
        return start.getMonth();
    }

    int getYearStart() {
        return start.getYear();
    }

    int getDayEnd() {
        return end.getDay();
    }

    int getMonthEnd() {
        return end.getMonth();
    }

    int getYearEnd() {
        return end.getYear();
    }

    int daysCount() {

        return (abs(end.getMonth() - start.getMonth()) * end.getMonthDayCount() + end.getDay() - start.getDay());

    }

    int getSalary() {
        if (daysCount() > 10) {
            return abs(daysCount() * employee.getSalaryPerDay());
        } else {
            return abs(int(0.8 * daysCount() * employee.getSalaryPerDay()));
        }
    }
};


#endif //SICKLEAVES_SICKLEAVE_H

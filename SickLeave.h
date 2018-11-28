#ifndef SICKLEAVES_SICKLEAVE_H
#define SICKLEAVES_SICKLEAVE_H


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
        cout << employee.getName() << " " << employee.getPatronymic() << " " << employee.getSurname() << endl;
        cout << "Пол: " << employee.getSex() << endl;
        cout << "Начало больничного: ";
        start.getDate();
        cout << "Конец больничного: ";
        end.getDate();
        cout << "Выплатить: " << getSalary() << "руб" << endl << endl;
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

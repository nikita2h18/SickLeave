#ifndef SICKLEAVES_DATE_H
#define SICKLEAVES_DATE_H


vector<int> validDt;
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:

    Date() {}

    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void setDay() {
        int day1;
        cin >> day1;
        this->day = day1;
    }

    void setMonth() {
        int month1;
        cin >> month1;
        this->month = month1;
    }

    void setYear() {
        int year1;
        cin >> year1;
        this->year = year1;
    }

    void getDate() {
        cout << this->day << "." << this->month << "." << this->year << endl;
    }

    bool isValid() {

        validDt = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month % 4 == 0) {
            validDt[1] = 29;
        } else {
            validDt[1] = 28;
        }

        if (month > 12 || month < 1) {
            return false;
        }

        for (int i = 0; i < 12; i++) {
            if (month == i + 1) {
                if (day > validDt[i] || day < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};


#endif //SICKLEAVES_DATE_H

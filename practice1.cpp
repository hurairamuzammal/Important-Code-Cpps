#include <iostream>
using namespace std;

class Date {
    int day;
    int month;
    int year;
    static Date defaultDate;

public:
    Date(int aDay = 0, int aMonth = 0, int aYear = 0) {
        if (aDay == 0) {
            this->day = defaultDate.day;
        } else {
            setDay(aDay);
        }
        if (aMonth == 0) {
            this->month = defaultDate.month;
        } else {
            setMonth(aMonth);
        }
        if (aYear == 0) {
            this->year = defaultDate.year;
        } else {
            setYear(aYear);
        }
    }

    void setDay(int aDay) {
        if (aDay > 0 && aDay <= 31) {
            day = aDay;
        }
    }

    int getDay() const {
        return day;
    }

    void addDay(int x) {
        day += x;
    }

    void setMonth(int aMonth) {
        if (aMonth > 0 && aMonth <= 12) {
            month = aMonth;
        }
    }

    int getMonth() const {
        return month;
    }

    void addMonth(int x) {
        month += x;
    }

    void setYear(int aYear) {
        year = aYear;
    }

    int getYear() const {
        return year;
    }

    void addYear(int x) {
        year += x;
    }
};

Date Date::defaultDate(01, 01, 2019);

int main() {
    Date date1(15, 8, 2021);
    cout << "The date is: " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << endl;

    return 0;
}

#include <iostream>
#include <ctime>    

struct Date {
    int year;
    int month; 
    int day;   
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

Date today(void) {
    std::time_t t = std::time(NULL);
    std::tm tl = *std::localtime(&t);// Перетворюємо отриманий час в локальний час і отримуємо вказівник на структуру tm

    Date today_date;
    today_date.year = tl.tm_year + 1900;
    today_date.month = tl.tm_mon + 1;   
    today_date.day = tl.tm_mday;    
    return today_date;
}


long long daysSinceBeginning(Date date) {
    long long days = 0;
    for (int y = 1; y < date.year; ++y) {
        days += isLeap(y) ? 366 : 365;
    }

    for (int m = 1; m < date.month; ++m) {
        days += monthLength(date.year, m);
    }

    days += date.day;
    return days; 
}

int main(void) {
    Date t = today(); 
    std::cout << "Поточна дата: " << t.year << "-" << t.month << "-" << t.day << std::endl; 

    int birthYear, birthMonth, birthDay; 
    std::cout << "Введіть рік народження: ";
    std::cin >> birthYear;              
    std::cout << "Введіть місяць народження: "; 
    std::cin >> birthMonth;              
    std::cout << "Введіть день народження: ";   
    std::cin >> birthDay;                

    Date birthday = {birthYear, birthMonth, birthDay}; 

    long long daysBirthday = daysSinceBeginning(birthday); 
    long long daysToday = daysSinceBeginning(t);        

    long long differenceInDays = daysToday - daysBirthday; 

    std::cout << "Кількість днів, що пройшли від вашого дня народження до поточної дати: "
              << differenceInDays << " днів." << std::endl; 

    return 0; 
}

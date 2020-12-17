#include "Expense.h"

void Expense::setYear (int year)
{
    this -> year = year;
}
void Expense::setMonth (int month)
{
    while (!conditionalMonth(month))
    {
        month = auxiliaryMethods.conversionStringToInt(auxiliaryMethods.loadLine());
    }
    this -> month = month;
}
void Expense::setDay (int day)
{
    while (!conditionalDay(day))
    {
        day = auxiliaryMethods.conversionStringToInt(auxiliaryMethods.loadLine());
    }
    this -> day = day;
}
void Expense::setExpenseName(string expenseName)
{
    this -> expenseName = expenseName;
}
void Expense::setExpenseValue (int expensealue)
{
    this -> expenseValue = expenseValue;
}

int Expense::getYear ()
{
    return year;
}
int Expense::getMonth ()
{
    return month;
}
int Expense::getDay ()
{
    return day;
}
string Expense::getExpenseName ()
{
    return expenseName;
}
int Expense::getExpenseValue ()
{
    return expenseValue;
}
bool Expense::conditionalMonth (int month)
{
    if(month > 12 || month < 0)
    {
        cout << "Podales miesiac: " << month << ", nie ma takiego miesiaca, podaj inny: " << endl;
        return false;
    }
    return true;
}
bool Expense::conditionalDay (int day)
{
    int maxDay;
    if (month == 2)
    {
        if(isLeapYear() == true)
            maxDay = 29;
        else
            maxDay = 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        maxDay = 31;
    else
        maxDay = 30;
    if(day > maxDay || day < 0)
    {
        cout << "Podales date:" <<year<<"-"<<month<<"-"<<day<<", ten miesiac nie posaida takiego dnia, podaj inny dzien: " << endl;
        return false;
    }
    return true;
}
bool Expense::isLeapYear ()
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}

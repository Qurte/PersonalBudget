#include "Income.h"

void Income::setYear (int year)
{
    this -> year = year;
}
void Income::setMonth (int month)
{
    while (!conditionalMonth(month))
    {
        month = auxiliaryMethods.conversionStringToInt(auxiliaryMethods.loadLine());
    }
    this -> month = month;
}
void Income::setDay (int day)
{
    while (!conditionalDay(day))
    {
        day = auxiliaryMethods.conversionStringToInt(auxiliaryMethods.loadLine());
    }
    this -> day = day;
}
void Income::setIncomeName(string incomeName)
{
    this -> incomeName = incomeName;
}
void Income::setIncomeValue (int incomeValue)
{
    this -> incomeValue = incomeValue;
}

int Income::getYear ()
{
    return year;
}
int Income::getMonth ()
{
    return month;
}
int Income::getDay ()
{
    return day;
}
string Income::getIncomeName ()
{
    return incomeName;
}
int Income::getIncomeValue ()
{
    return incomeValue;
}
bool Income::conditionalMonth (int month)
{
    if(month > 12 || month < 0)
    {
        cout << "Podales miesiac: " << month << ", nie ma takiego miesiaca, podaj inny: " << endl;
        return false;
    }
    return true;
}
bool Income::conditionalDay (int day)
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
bool Income::isLeapYear ()
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}

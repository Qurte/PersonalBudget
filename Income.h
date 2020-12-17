#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Income
{
    AuxiliaryMethods auxiliaryMethods;
    int year;
    int month;
    int day;
    string incomeName;
    int incomeValue;
    bool conditionalMonth (int);
    bool conditionalDay (int);
    bool isLeapYear ();
public:
    void setYear (int);
    void setMonth (int);
    void setDay (int);
    void setIncomeName(string);
    void setIncomeValue (int);

    int getYear ();
    int getMonth ();
    int getDay ();
    string getIncomeName ();
    int getIncomeValue ();
};
#endif

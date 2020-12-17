#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Expense
{
    AuxiliaryMethods auxiliaryMethods;
    int year;
    int month;
    int day;
    string expenseName;
    int expenseValue;

    bool conditionalMonth (int);
    bool conditionalDay (int);
    bool isLeapYear ();
public:
    void setYear (int);
    void setMonth (int);
    void setDay (int);
    void setExpenseName(string);
    void setExpenseValue (int);

    int getYear ();
    int getMonth ();
    int getDay ();
    string getExpenseName ();
    int getExpenseValue ();
};
#endif

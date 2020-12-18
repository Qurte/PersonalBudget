#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include "Date.h"

using namespace std;

class Expense : public Date
{

    string expenseName;
    int expenseValue;

public:
    void setExpenseName(string);
    void setExpenseValue (int);

    string getExpenseName ();
    int getExpenseValue ();
};
#endif

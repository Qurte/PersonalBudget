#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include "Date.h"

using namespace std;

class Income : public Date
{
    string incomeName;
    int incomeValue;

public:

    void setIncomeName(string);
    void setIncomeValue (int);

    string getIncomeName ();
    int getIncomeValue ();
};
#endif

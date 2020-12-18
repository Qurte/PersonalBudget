#include "Income.h"

void Income::setIncomeName(string incomeName)
{
    this -> incomeName = incomeName;
}
void Income::setIncomeValue (int incomeValue)
{
    this -> incomeValue = incomeValue;
}

string Income::getIncomeName ()
{
    return incomeName;
}
int Income::getIncomeValue ()
{
    return incomeValue;
}

#include "Expense.h"


void Expense::setExpenseName(string expenseName)
{
    this -> expenseName = expenseName;
}
void Expense::setExpenseValue (int expenseValue)
{
    this -> expenseValue = expenseValue;
}
string Expense::getExpenseName ()
{
    return expenseName;
}
int Expense::getExpenseValue ()
{
    return expenseValue;
}

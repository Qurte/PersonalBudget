#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include <windows.h>
#include "FileWithIncome.h"
#include "Expense.h"
#include "FileWithExpense.h"

#include <vector>

using namespace std;

class OperationManager
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;
    FileWithIncome fileWithIncome;
    FileWithExpense fileWithExpense;
    vector <Income> incomes;
    vector <Expense> expenses;
    bool checkCorrectnessFormat (string);
    bool checkTheTimeInterval(int, int, int);

    Income setDateToVectorIncome (string date);
    Expense setDateToVectorExpense (string date);
public:
    OperationManager (string nameFileWithIncome, string nameFileWithExpense, User LOGGEDINUSER): fileWithIncome (nameFileWithIncome, LOGGEDINUSER), loggedInUser(LOGGEDINUSER), fileWithExpense(nameFileWithExpense, LOGGEDINUSER)
    {
        incomes = fileWithIncome.loadIncomeFromFile();
        expenses = fileWithExpense.loadExpenseFromFile();
    };
    void addIncome();
    void addExpense();

};
#endif

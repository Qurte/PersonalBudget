#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include <windows.h>
#include "FileWithIncome.h"

#include <vector>

using namespace std;

class OperationManager
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;
    FileWithIncome fileWithIncome;
    vector <Income> incomes;
    bool checkCorrectnessFormat (string);
    bool checkTheTimeInterval(Income);

    Income setDateToVectorIncome (string date);
public:
    OperationManager (string nameFileWithIncome, User LOGGEDINUSER): fileWithIncome (nameFileWithIncome, LOGGEDINUSER), loggedInUser(LOGGEDINUSER)
    {
        incomes = fileWithIncome.loadIncomeFromFile();
    };
    void addIncome();

};
#endif

#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include <windows.h>

#include <vector>

using namespace std;

class OperationManager
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;
    vector <Income> incomes;
    bool checkCorrectnessFormat (string);
    bool checkTheTimeInterval(Income);

    Income setDateToVectorIncome (string date);
public:
    void addIncome();

};
#endif

#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "OperationManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    OperationManager *operationManager;
    AuxiliaryMethods auxiliaryMethods;
    int IdSignInUser;
    const string NAME_FILE_WITH_INCOME;
    const string NAME_FILE_WITH_EXPENSE;

public:
    PersonalBudget (string nameFileWithUsers, string nameFileWithIncome, string nameFileWithExpense): userManager(nameFileWithUsers), NAME_FILE_WITH_INCOME(nameFileWithIncome), NAME_FILE_WITH_EXPENSE(nameFileWithExpense)
    {

    };
    void userRegistration();
    void writeAllUsers();
    void SignInUser();
    void signOutUser ();
    bool isTheUserSignIn();
    char chooseOptionAtMeinMenu();
    char chooseOptionAtOperationMenu();
    void addIncome();
    void addExpense();
    void showBalanceSheetForTheCurrentMonth ();
    void showBalanceSheetForThePreviousMonth ();
    void showBalanceSheetForTheSelectedPeriod ();
};
#endif

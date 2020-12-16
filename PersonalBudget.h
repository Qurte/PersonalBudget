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

public:
    PersonalBudget (string nameFileWithUsers, string nameFileWithIncome): userManager(nameFileWithUsers), NAME_FILE_WITH_INCOME(nameFileWithIncome)
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
};
#endif

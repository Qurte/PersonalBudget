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
    OperationManager operationManager;
    AuxiliaryMethods auxiliaryMethods;
    int IdSignInUser;
public:
    PersonalBudget (string nameFileWithUsers): userManager(nameFileWithUsers){};
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

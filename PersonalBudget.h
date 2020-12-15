#ifndef PersonalBudget_H
#define PersonalBudget_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    AuxiliaryMethods auxiliaryMethods;
    int IdSignInUser;
    char loadCharacter();
public:
    PersonalBudget (string nameFileWithUsers): userManager(nameFileWithUsers){};
    void userRegistration();
    void writeAllUsers();
    void SignInUser();
    void signOutUser ();
    bool isTheUserSignIn();
    char chooseOptionAtMeinMenu();
    char chooseOptionAtOperationMenu();
};
#endif

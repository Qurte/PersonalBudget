#ifndef PersonalBudget_H
#define PersonalBudget_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    int IdSignInUser;
public:
    PersonalBudget (string nameFileWithUsers): userManager(nameFileWithUsers){};
    void userRegistration();
    void writeAllUsers();
    void SignInUser();
};
#endif

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include <vector>
#include <algorithm>

using namespace std;

class UserManager
{
    FileWithUsers fileWithUsers;
    AuxiliaryMethods auxiliatyMethods;
    vector<User> users;

    User getDataNewUser();
    User loggedInUser;
    int loadIdNewUser();
    bool doesLoginExist(string login);
    string changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text);

public:
    UserManager (string nameFileWithUsers): fileWithUsers (nameFileWithUsers)
    {
        users = fileWithUsers.loadUsersFromFile();
        loggedInUser.setUserId(0);
    };
    void userRegistration();
    void writeAllUsers();
    void signInUser();
    void signOutUser ();
    bool isTheUserSignIn();
    User getLoggedInUser();

};
#endif

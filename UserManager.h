#ifndef UserManager_H
#define UserManager_H

#include "User.h"
#include "FileWithUsers.h"
#include <vector>
#include <algorithm>

using namespace std;

class UserManager
{
    FileWithUsers fileWithUsers;
    vector<User> users;

    User getDataNewUser();
    User loggedInUser;
    int loadIdNewUser();
    bool doesLoginExist(string login);
    string changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text);
    string loadLine();

public:
    UserManager (string nameFileWithUsers): fileWithUsers (nameFileWithUsers)
    {
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    void writeAllUsers();
    void signInUser();

};
#endif

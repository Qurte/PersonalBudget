#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");

    personalBudget.writeAllUsers();
    cout << endl;
    personalBudget.SignInUser();

    return 0;
}

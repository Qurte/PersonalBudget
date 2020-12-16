#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = getDataNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UserManager::getDataNewUser()
{
    User user;

    user.setUserId(loadIdNewUser());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin())== true);
    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "podaj imie: ";
    cin >> name;
    name = changeTheFirstLetterToUppercaseAndTheRestToLowercase(name);
    user.setName(name);

    string surName;
    cout << "podaj nazwisko: ";
    cin >> surName;
    surName = changeTheFirstLetterToUppercaseAndTheRestToLowercase(surName);
    user.setSurname(surName);

    return user;
}
int UserManager::loadIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            {
                cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
                return true;
            }
        }
    }
    return false;
}
void UserManager::writeAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}
string UserManager::changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
void UserManager::signInUser()
{
    User user;
    string login = "", password= "";

    cout << endl << "Podaj login: ";
    login = auxiliatyMethods.loadLine();

    for (int i = 0 ; i < users.size(); i++)
    {
        if (login == users[i].getLogin())
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempt << ": ";
                password = auxiliatyMethods.loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUser.setLogin(users[i].getLogin());
                    loggedInUser.setPassword(users[i].getPassword());
                    loggedInUser.setUserId(users[i].getUserId());
                    loggedInUser.setName(users[i].getName());
                    loggedInUser.setSurname(users[i].getSurname());
                    return ;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return ;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return ;
}
void UserManager::signOutUser ()
{
    loggedInUser.setLogin("");
    loggedInUser.setPassword("");
    loggedInUser.setName("");
    loggedInUser.setSurname("");
    loggedInUser.setUserId(0);

}
bool UserManager::isTheUserSignIn()
{
    if (loggedInUser.getUserId() > 0)
        return true;
    else
        return false;
}
User UserManager::getLoggedInUser()
{
    return loggedInUser;
}

#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}
void PersonalBudget::writeAllUsers()
{
    userManager.writeAllUsers();
}
void PersonalBudget::SignInUser()
{
    userManager.signInUser();
}
void PersonalBudget::signOutUser ()
{
    userManager.signOutUser();
}
bool PersonalBudget::isTheUserSignIn()
{
    userManager.isTheUserSignIn();
}
char PersonalBudget::chooseOptionAtMeinMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = loadCharacter();

    return choice;
}
char PersonalBudget::chooseOptionAtOperationMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU OPERACJI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychód" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bie¿¹cego miesi¹ca" << endl;
    cout << "4. Bilans z porzedniego miesi¹ca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = loadCharacter();

    return choice;
}
char PersonalBudget::loadCharacter()
{
    string in = "";
    char character  = {0};

    while (true)
    {
        getline(cin, in);

        if (in.length() == 1)
        {
            character = in[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

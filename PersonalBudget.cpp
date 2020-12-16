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
    if (isTheUserSignIn() == true)
    {
        operationManager = new OperationManager (NAME_FILE_WITH_INCOME, userManager.getLoggedInUser());
    }
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
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}
char PersonalBudget::chooseOptionAtOperationMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU OPERACJI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bie��cego miesi�ca" << endl;
    cout << "4. Bilans z porzedniego miesi�ca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}
void PersonalBudget::addIncome()
{
    operationManager -> addIncome();
}

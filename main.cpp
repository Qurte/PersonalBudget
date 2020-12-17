#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
 char choice;
    PersonalBudget personalBudget ("users.xml","income.xml");

    while (true)
    {
        if (personalBudget.isTheUserSignIn() == false)
        {
            choice = personalBudget.chooseOptionAtMeinMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.SignInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.chooseOptionAtOperationMenu();

            switch (choice)
            {
            case '1':
                    personalBudget.addIncome();
                break;
            case '2':
               // ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
              //  ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                // ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                // ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
               // ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                    personalBudget.signOutUser();
                break;
            }
        }



    }

    return 0;
}
int t_main()
{
    PersonalBudget personalBudget ("users.xml", "income.xml");
    personalBudget.addIncome();
}

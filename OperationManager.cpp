#include "OperationManager.h"

void OperationManager::addIncome()
{
    system("cls");
    char character;
    string date = "";
    string incomeName = "";
    string incomeValue ="";
    Income income;
    cout << "Czy przychod dotyczy dzisjszego dnia? potwierdz literka t " << endl;
    character = auxiliaryMethods.loadCharacter();
    if (character == 't')
    {
        SYSTEMTIME systemTime;
        GetSystemTime(&systemTime);
        income.setYear(systemTime.wYear);
        income.setMonth(systemTime.wMonth);
        income.setDay(systemTime.wDay);
    }
    else
    {
        do
        {
            do
            {
                cout << "podaj date przychodu w formacie rrrr-mm-dd: " << endl;
                date = auxiliaryMethods.loadLine();
            }
            while (!checkCorrectnessFormat(date));
            income = setDateToVectorIncome(date);
        }
        while(!checkTheTimeInterval(income.getYear(), income.getMonth(), income.getDay()));


        }
    cout << "Czego dotyczy przychod? " << endl;
    incomeName = auxiliaryMethods.loadLine();
    income.setIncomeName(incomeName);

    cout << "Podaj wartosc przychodu: " << endl;
    incomeValue = auxiliaryMethods.loadLine();
    income.setIncomeValue(auxiliaryMethods.conversionStringToInt(incomeValue));

    fileWithIncome.addIncomeToFile(income);
    incomes.push_back(income);
    cout << "Przychod zostal dodany" << endl;
    Sleep(1500);
}
Income OperationManager::setDateToVectorIncome (string date)
{
    date += '-';
    int length = date.length();
    Income income;
    string integer;
    int numberSupervention = 1;
    for (int i = 0; i < length; i++)
    {
        if (date[i] != '-')
        {
            integer += date[i];
        }
        else
        {
            switch (numberSupervention)
            {
            case 1:
                income.setYear(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 2:
                income.setMonth(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 3:
                income.setDay(auxiliaryMethods.conversionStringToInt(integer));
                break;
            }
            integer = "";
            numberSupervention++;
        }
    }
    return income;
}
bool OperationManager::checkCorrectnessFormat (string date)
{
    bool isCorrectness = true;
    if (date.length() != 10 )
        isCorrectness = false;

    for (int i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                isCorrectness = false;
        }
        else
        {
            if (!isdigit(date[i]))
                isCorrectness = false;
        }
    }
    if (isCorrectness == false)
    {
        cout << "format daty jest nie poprawny" << endl;
        Sleep(1500);
        return false;
    }
    else
        return true;

}
bool OperationManager::checkTheTimeInterval(int year, int month, int day)
{
    bool isTheInterval = true;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    if(year > systemTime.wYear || year < 2000)
    {
        cout << "Rok ktory podales nie miesci sie w przedziale 2000 - (obecny rok)" << endl;
        isTheInterval = false;
    }
    else if (year == systemTime.wYear)
    {
        if (month > systemTime.wMonth)
        {
            isTheInterval = false;
            cout << "data ktora podales jest czasowo przekracza dzisiejsza date" << endl;
        }
        else if (month == systemTime.wMonth)
        {
            if (day > systemTime.wDay)
                {
                   isTheInterval = false;
                   cout << "data ktora podales czasowo przekracza dzisiejsza date" << endl;
                }
            else if (day == systemTime.wDay)
            {
                cout << "podales dzisiejsza date" << endl;
                Sleep(1500);
            }
        }
    }
    return isTheInterval;
}
void OperationManager::addExpense()
{
    system("cls");
    char character;
    string date = "";
    string expenseName = "";
    string expenseValue ="";
    Expense expense;
    cout << "Czy wydatek dotyczy dzisjszego dnia? potwierdz literka t " << endl;
    character = auxiliaryMethods.loadCharacter();
    if (character == 't')
    {
        SYSTEMTIME systemTime;
        GetSystemTime(&systemTime);
        expense.setYear(systemTime.wYear);
        expense.setMonth(systemTime.wMonth);
        expense.setDay(systemTime.wDay);
    }
    else
    {
        do
        {
            do
            {
                cout << "podaj date przychodu w formacie rrrr-mm-dd: " << endl;
                date = auxiliaryMethods.loadLine();
            }
            while (!checkCorrectnessFormat(date));
            expense = setDateToVectorExpense(date);
        }
        while(!checkTheTimeInterval(expense.getYear(), expense.getMonth(), expense.getDay() ));


        }
    cout << "Czego dotyczy wydatek? " << endl;
    expenseName = auxiliaryMethods.loadLine();
    expense.setExpenseName(expenseName);

    cout << "Podaj wartosc wydatek: " << endl;
    expenseValue = auxiliaryMethods.loadLine();
    expense.setExpenseValue(auxiliaryMethods.conversionStringToInt( expenseValue));

    fileWithExpense.addExpenseToFile(expense);
    expenses.push_back(expense);
    cout << "Wydatek zostal dodany" << endl;
    Sleep(1500);
}
Expense OperationManager::setDateToVectorExpense (string date)
{
    date += '-';
    int length = date.length();
    Expense expense;
    string integer;
    int numberSupervention = 1;
    for (int i = 0; i < length; i++)
    {
        if (date[i] != '-')
        {
            integer += date[i];
        }
        else
        {
            switch (numberSupervention)
            {
            case 1:
                expense.setYear(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 2:
                expense.setMonth(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 3:
                expense.setDay(auxiliaryMethods.conversionStringToInt(integer));
                break;
            }
            integer = "";
            numberSupervention++;
        }
    }
    return expense;
}


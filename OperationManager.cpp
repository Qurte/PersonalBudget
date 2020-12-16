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
        while(!checkTheTimeInterval(income));


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
bool OperationManager::checkTheTimeInterval(Income income)
{
    bool isTheInterval = true;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    if(income.getYear() > systemTime.wYear || income.getYear() < 2000)
    {
        cout << "Rok ktory podales nie miesci sie w przedziale 2000 - (obecny rok)" << endl;
        isTheInterval = false;
    }
    else if (income.getYear() == systemTime.wYear)
    {
        if (income.getMonth() > systemTime.wMonth)
        {
            isTheInterval = false;
            cout << "data ktora podales jest czasowo przekracza dzisiejsza date" << endl;
        }
        else if (income.getMonth() == systemTime.wMonth)
        {
            if (income.getDay() > systemTime.wDay)
                {
                   isTheInterval = false;
                   cout << "data ktora podales czasowo przekracza dzisiejsza date" << endl;
                }
            else if (income.getDay() == systemTime.wDay)
            {
                cout << "podales dzisiejsza date" << endl;
                Sleep(1500);
            }
        }
    }
    return isTheInterval;
}

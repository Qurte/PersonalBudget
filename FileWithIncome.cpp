#include "FileWithIncome.h"

void FileWithIncome::addIncomeToFile (Income income)
{

    CMarkup xml;
    bool fileExists = xml.Load( getNameFile() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Income");
    }
    if (fileExists)
    {
        xml.Load(getNameFile());
        while (xml.FindChildElem("User"))
        {
            xml.IntoElem();
            xml.FindChildElem("UserId");
            if (atoi(xml.GetChildData().c_str()) == loggedInUser.getUserId())
            {
                xml.IntoElem();
                xml.AddElem("Incomes");
                xml.IntoElem();
                xml.AddElem("IncomeName", income.getIncomeName());
                xml.AddElem("IncomeYear", income.getYear());
                xml.AddElem("IncomeMonth", income.getMonth());
                xml.AddElem("IncomeDay", income.getDay());
                xml.AddElem("IncomeValue", income.getIncomeValue());
                xml.Save(getNameFile());
                return;
            }
            xml.OutOfElem();
        }
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", loggedInUser.getUserId());
    xml.AddElem("Incomes");
    xml.IntoElem();
    xml.AddElem("IncomeName", income.getIncomeName());
    xml.AddElem("IncomeYear", income.getYear());
    xml.AddElem("IncomeMonth", income.getMonth());
    xml.AddElem("IncomeDay", income.getDay());
    xml.AddElem("IncomeValue", income.getIncomeValue());
    xml.Save(getNameFile());
}

vector <Income> FileWithIncome::loadIncomeFromFile()
{
    vector <Income> income;
    CMarkup xml;
    int i = 0;
    xml.Load(getNameFile());
    while (xml.FindChildElem("User"))
    {
        xml.IntoElem();
        xml.FindChildElem("UserId");
        if (atoi(xml.GetChildData().c_str()) == loggedInUser.getUserId())
        {

            while (xml.FindChildElem("Incomes"))
            {
                income.push_back(Income());
                xml.IntoElem();
                xml.FindChildElem("IncomeName");
                income[i].setIncomeName(xml.GetChildData());
                xml.FindChildElem("IncomeYear");
                income[i].setYear(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeMonth");
                income[i].setMonth(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeDay");
                income[i].setDay(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeValue");
                income[i].setIncomeValue(atoi(xml.GetChildData().c_str()));
                xml.OutOfElem();
                i++;
            }
            for (int j = 0; j < income.size(); j ++)
            {
                cout << "Name: " << income[j].getIncomeName() << endl;
                cout << "Year: " << income[j].getYear() << endl;
                cout << "Month: " << income[j].getMonth() << endl;
                cout << "Day: " << income[j].getDay() << endl;
                cout << "Value: " <<income[j].getIncomeValue() << endl;
            }
            system("pause");
            return income;
        }
    }
}

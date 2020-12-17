#include "FileWithExpense.h"

void FileWithExpense::addExpenseToFile (Expense expense)
{

    CMarkup xml;
    bool fileExists = xml.Load( getNameFile() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
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
                xml.AddElem("Expense");
                xml.IntoElem();
                xml.AddElem("ExpenseName", expense.getExpenseName());
                xml.AddElem("ExpenseYear", expense.getYear());
                xml.AddElem("ExpenseMonth", expense.getMonth());
                xml.AddElem("ExpenseDay", expense.getDay());
                xml.AddElem("ExpenseValue", expense.getExpenseValue());
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
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseName", expense.getExpenseName());
    xml.AddElem("ExpenseYear", expense.getYear());
    xml.AddElem("ExpenseMonth", expense.getMonth());
    xml.AddElem("ExpenseDay", expense.getDay());
    xml.AddElem("ExpenseValue", expense.getExpenseValue());
    xml.Save(getNameFile());
}

vector <Expense> FileWithExpense::loadExpenseFromFile()
{
    vector <Expense> expenses;
    CMarkup xml;
    int i = 0;
    xml.Load(getNameFile());
    while (xml.FindChildElem("User"))
    {
        xml.IntoElem();
        xml.FindChildElem("UserId");
        if (atoi(xml.GetChildData().c_str()) == loggedInUser.getUserId())
        {

            while (xml.FindChildElem("Expense"))
            {
                expenses.push_back(Expense());
                xml.IntoElem();
                xml.FindChildElem("ExpenseName");
                expenses[i].setExpenseName(xml.GetChildData());
                xml.FindChildElem("ExpenseYear");
                expenses[i].setYear(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("ExpenseMonth");
                expenses[i].setMonth(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("ExpenseDay");
                expenses[i].setDay(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("ExpenseValue");
                expenses[i].setExpenseValue(atoi(xml.GetChildData().c_str()));
                xml.OutOfElem();
                i++;
            }
            cout << "tutaj doszedlem" << endl;
            for (int j = 0; j < expenses.size(); j ++)
            {
                cout << "Name: " << expenses[j].getExpenseName() << endl;
                cout << "Year: " << expenses[j].getYear() << endl;
                cout << "Month: " << expenses[j].getMonth() << endl;
                cout << "Day: " << expenses[j].getDay() << endl;
                cout << "Value: " <<expenses[j].getExpenseValue() << endl;
            }
            system("pause");
            return expenses;
        }
    }
}


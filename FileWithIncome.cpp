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
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("UserId", loggedInUser.getUserId());
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeName", income.getIncomeName());
    xml.AddElem("IncomeYear", income.getYear());
    xml.AddElem("IncomeMonth", income.getMonth());
    xml.AddElem("IncomeDay", income.getDay());
    xml.AddElem("IncomeValue", income.getIncomeValue());
    xml.Save(getNameFile());
}

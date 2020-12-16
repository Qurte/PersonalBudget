#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include "TextFile.h"
#include "Markup.h"
#include "Income.h"
#include "User.h"
#include <vector>

using namespace std;

class FileWithIncome : public TextFile
{
    User loggedInUser;
public:
    FileWithIncome(string nameFileWtihIncome, User LOGGEDINUSER) : TextFile(nameFileWtihIncome), loggedInUser(LOGGEDINUSER) {};
    void addIncomeToFile (Income income);

};
#endif

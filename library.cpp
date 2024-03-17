#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};

int main()
{
    temp obj; // Create an instance of the temp class
    char choice;

    cout << "-------------------------------------------------------\n";
    cout << "1- Show all books\n";
    cout << "2- Extract Books\n";
    cout << "3- Add books by admin\n";
    cout << "4- Exit\n";
    cout << "-------------------------------------------------------\n";
    cout << "Enter your choice :: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;
    case '2':
        cin.ignore();
        obj.extractBook();
        break;
    case '3':
        cin.ignore();
        obj.addBook();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid choice...!";
    }
    return 0;
}

void temp::addBook()
{
    cout << "\nEnter Book ID :: ";
    cin.ignore();
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book's Author name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void temp::showAll()
{
    file.open("bookData.txt", ios::in);
    if (!file.is_open())
    {
        cout << "No books found!\n";
        return;
    }
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
    cout << "\n\n";
    cout << "\t\t Book Id \t\t\tBook Name\t\t\t Author's name" << endl;
    while (!file.eof())
    {
        cout << "\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');
    }
    file.close();
}

void temp::extractBook()
{
    showAll();
    cout << "Enter Book ID :: ";
    cin.ignore();
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file.is_open())
    {
        cout << "No books found!\n";
        return;
    }
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');

    cout << "\n\n";
    cout << "\t\t Book Id \t\t\tBook Name\t\t\t Author's name" << endl;
    while (!file.eof())
    {
        if (search == id)
        {
            cout << "\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            cout << "Book Extracted Successfully ....!\n";
        }
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');
    }
    file.close();
}

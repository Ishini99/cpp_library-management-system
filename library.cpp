#include <iostream>
#include <fstream>
using namespace std;
class temp
{
    string id, name, author;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};
int main()
{
    cout << "-------------------------------------------------------";
    cout << "1-Show all books";
    cout << "2-Extract Books";
    cout << "3-Add books by admin";
    cout << "4-Exit";
    cout << "-------------------------------------------------------";
    cout << "Enter your choice :: ";
    cin >> choice;

    switch (choice)
    {
    case '1':

        break;
    case '2':

        break;
    case '3':

        break;
    case '4':

    default:
        cout << "Invalid choice...!";
    }
    return 0;
}
void temp ::addBook()
{
    cout << "\nEnter Book ID :: ";
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book 's Author name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios ::out | ios ::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}
void temp ::showAll()
{
    file.open("bookData.txt", ios::in);
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
void temp ::extractBook()
{
    file.open("bookData.txt", ios::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');

    cout << "\n\n";
    cout << "\t\t Book Id \t\t\tBook Name\t\t\t Author's name" << endl;
}
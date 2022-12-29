#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Library
{
public:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;
};
int main()
{
    Library lib[20];
    int input = 0;
    int count = 0;

    while (input != 5)
    {
        cout << "\n Press 1 to input details like id, name, author, student, price, pages \n ";
        cout << "Press 2 to display details \n ";
        cout << "Press 3 to Quit \n";
        cin >> input;

        switch (input)
        {
        case 1:
        start:
            cout << "Enter Book Id \n ";
            cin >> lib[count].id;
            cout << "Enter Book Name \n ";
            cin >> lib[count].name;
            // cin.getline(lib[count].name,100,'$');
            cout << "Enter Author Name \n ";
            cin >> lib[count].author;
            // cin.getline(lib[count].author,100,'$');
            cout << "Enter Student Name \n ";
            cin >> lib[count].student;
            // cin.getline(lib[count].student,100,'$');
            cout << "Enter Book Price \n ";
            cin >> lib[count].price;
            cout << "Enter Book Pages \n ";
            cin >> lib[count].pages;
            count++;
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                cout << "Book Id : "
                     << lib[i].id;
                cout << "\n Book Name : "
                     << lib[i].name;
                cout << "\n Author Name : "
                     << lib[i].author;
                cout << "\n Book Student : "
                     << lib[i].student;
                cout << "\n Book Price : "
                     << lib[i].price;
                cout << "\n Book Pages : "
                     << lib[i].pages;
            }
            break;

        case 3:
            exit(0);

        default:
            cout << "You have entered wrong value , please try again. \n";
            goto start;
        }
    }
}
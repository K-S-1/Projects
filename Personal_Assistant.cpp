#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void showTime()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    cout << "Current time: " << asctime(timeinfo);
}

void addReminder(vector<string> &reminders)
{
    cout << "Enter a new reminder: ";
    string reminder;
    getline(cin, reminder);
    reminders.push_back(reminder);
    cout << "Reminder added." << endl;
}

void viewReminders(const vector<string> &reminders)
{
    if (reminders.empty())
    {
        cout << "No reminders to display." << endl;
    }
    else
    {
        cout << "Your reminders are: " << endl;
        for (size_t i = 0; i < reminders.size(); i++)
        {
            cout << i + 1 << ". " << reminders[i] << endl;
        }
    }
}

int main()
{
    cout << "Welcome to the personal assistant program!" << endl;
    vector<string> reminders;
    while (true)
    {
        cout << endl;
        cout << "Menu: " << endl;
        cout << "1. Show current time and date" << endl;
        cout << "2. Add a reminder" << endl;
        cout << "3. View reminders" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            showTime();
            break;
        case 2:
            addReminder(reminders);
            break;
        case 3:
            viewReminders(reminders);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

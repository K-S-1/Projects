#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <cstdlib>
using namespace std;

void introduction()
{
    cout << "*********** Word Searching Puzzle Game ********** \n";
    cout << "A word search puzzle is shown on screen. \nYou have to guess the hidden correct word from the puzzle. \nFor each correct guessing you will get one score. \n";
}

int game()
{
    string array[10] = {"laravel", "flutter", "java", "python", "html", "css", "javascript", "php", "ruby", "react"};
    char matrix[10][10];
    int r;
    char c;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            r = rand() % 26; // r=0
            c = 'a' + r;     // c=97+0=97='a'
            matrix[i][j] = c;
        }
    }
    int index = rand() % 10;
    string output = array[index];
    if (array[index].length() % 2 == 0)
    {
        // horizontally
        int row = rand() % 10;
        int col = rand() % 3;
        for (int i = 0; array[index][i] != '\0'; i++, col++)
        {
            matrix[row][col] = array[index][i];
        }
    }
    else
    {
        // vertically
        int row = rand() % 10;
        int col = rand() % 3;
        for (int i = 0; array[index][i] != '\0'; i++, row++)
        {
            matrix[row][col] = array[index][i];
        }
    }
    cout << "*********** PUZZLE ***********\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << " ";
            Sleep(100);
        }
        cout << "\n";
    }
    cout << "\n\n";
    string guess;
    int hint;
    cout << "Press 1 for direct guess input \n";
    cout << "Press 2 for first see hint and then enter guess input \n";
a:
    cout << "Enter input \n";
    cin >> hint;
    if (hint == 1)
    {
        cout << "Enter guessing word : \n";
        cin >> guess;
    }
    else if (hint == 2)
    {
        cout << "The guessing word size is \n"
             << output.length();
        cout << "Enter guessing word :  \n";
        cin >> guess;
    }
    else
    {
        cout << "Enter valid input \n";
        goto a;
    }
    if (output == guess)
    {
        cout << "Congratulations! You guessed the right word in the puzzle \n\n";
        return 1;
    }
    else
    {
        cout << "Oh! You guessed the wrong word \n";
        return 0;
    }
}

int main()
{
    string name;
    cout << "Enter your name: \n";
    getline(cin, name);
    int score = 0;
    char input;
    do
    {
        system("cls"); // clears the screen inputs
        introduction();
        score = score + game();
        cout << "Would you like to play again y/n : \n";
        cin >> input;
    } while (input != 'n');
    cout << name << " your score is " << score;
    cout << "*********************************************************************** \n";
    return 0;
}

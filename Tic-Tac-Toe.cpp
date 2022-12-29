#include <iostream>
using namespace std;
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction()
{
    cout << "Press [ENTER] to begin: ";
    getchar();
    cout << "\n";
    cout << "***********\n";
    cout << "Tic-Tac-Toe\n";
    cout << "***********\n";
    cout << "Player 1) X \n";
    cout << "Player 2) 0 \n";
    cout << "The 3x3 grid is shown below:\n\n";
    cout << "       |       |       \n";
    cout << "   1   |   2   |   3   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   4   |   5   |   6   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   7   |   8   |   9   \n";
    cout << "       |       |       \n\n";
}

bool is_winner()
{
    bool winner;
    winner = false;
    // checking the rows
    if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ")
    {
        winner = true;
    }
    else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ")
    {
        winner = true;
    }
    // checking the columns
    else if ((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
    {
        winner = true;
    }
    else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ")
    {
        winner = true;
    }
    // checking the diagonals
    else if ((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " ")
    {
        winner = true;
    }
    return winner;
}

bool is_filled()
{
    bool filled = true;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == " ")
        {
            filled = false;
        }
    }
    return filled;
}

void display()
{
    cout << "       |       |       \n";
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   \n";
    cout << "       |       |       \n\n";
}

void set_position()
{
    cout << "Player " << player << "'s Turn (Enter: (1-9))\n";
    while (!(cin >> position))

    {
        cout << "Please enter a valid number between (1-9)\n";
        cin.clear();
        cin.ignore();
    }
    while (board[position - 1] != " ")
    {
        cout << "Oops,that position is already filled\n";
        cout << "Player " << player << "'s Turn (Enter 1-9): \n";
        cin >> position;
    }
}

void update_board()
{
    if (player % 2 == 1)
    {
        board[position - 1] = 'X';
    }
    else
    {
        board[position - 1] = "0";
    }
}

void change_player()
{
    if (player == 1)
    {
        player++;
    }
    else
    {
        player--;
    }
}

void take_turn()
{
    while (!is_winner() && !is_filled())
    {
        set_position();
        update_board();
        change_player();
        display();
    }
}

void end_game()
{
    if (is_winner())
    {
        cout << "Congratulations you won the game!\n";
    }
    else if (is_filled())
    {
        cout << "There is a tie!\n";
    }
}
int main()
{
    introduction();
    take_turn();
    end_game();
    return 0;
}
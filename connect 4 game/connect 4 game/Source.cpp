#include<iostream>
using namespace std;

const int N = 6;
const int M = 7;
const int n_players = 2;
char marks[n_players] = { 'X', 'O' };
char grid[N][M];

//This function prints the grid of Connect Four Game as the game progresses
void print_grid() {
    for (int i = 0; i < n_players; i++) {
        cout << "Player " << i + 1 << ": " << marks[i] << "  ";
        if (i < n_players - 1)
            cout << "vs  ";
    }
    cout << "\n";
    cout << "--";
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < M; cout << "---", i++);
        cout << "--\n";
    }
}
//This function checks if the game has a win state or not
bool check_win() {
    //check row
    for (int i = 0; i < M - 3; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[j][i] == 'X' && grid[j][i + 1] == 'X' && grid[j][i + 2] == 'X' && grid[j][i + 3] == 'X')
                return true;
            if (grid[j][i] == 'O' && grid[j][i + 1] == 'O' && grid[j][i + 2] == 'O' && grid[j][i + 3] == 'O')
                return true;

        }

    }
    //check colume

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 3; j++) {
            if (grid[j][i] == 'X' && grid[j + 1][i] == 'X' && grid[j + 2][i] == 'X' && grid[j + 3][i] == 'X')
                return true;
            if (grid[j][i] == 'O' && grid[j + 1][i] == 'O' && grid[j + 2][i] == 'O' && grid[j + 3][i] == 'O')
                return true;
        }
    }
    // check diagonal 
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M - 3; j++) {


            if (grid[j][i] == 'X' && grid[j + 1][i + 1] == 'X' && grid[j + 2][i + 2] == 'X' && grid[j + 3][i + 3] == 'X')
                return true;
            if (grid[j][i] == 'O' && grid[j + 1][i + 1] == 'O' && grid[j + 2][i + 2] == 'O' && grid[j + 3][i + 3] == 'O')
                return true;

        }

    }
    return false;
}
//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (counter != ' ') {
                counter++;
            }
            if (counter == 42 && not check_win()) {
                return true;
            }
            else
                return false;

        }



    }
}
//This function checks if the game has a tie state or not
bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}
//This function checks if given cell is empty or not 
bool check_empty(int i) {
    if (grid[0][i] == ' ') {
        return true;

    }
    else
        return false;
}
//This function checks if given position is valid or not 
bool check_valid_column(int i) {

    if (i <= 6 && i >= 0) {

        return true;
    }
    else
        return false;

}
//This function sets the given mark to the given column
void set_cell(int i, char mark) {
    for (int j = 5; j >= 0; j--) {

        if (grid[j][i] == ' ') {

            grid[j][i] = mark;
            break;
        }

    }


}
//This function clears the game structures
void grid_clear() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            grid[i][j] = ' ';

        }
}
//This function reads a valid position input
void read_input(int& i) {
    cout << "Enter the column index: ";
    cin >> i;
    while (!check_valid_column(i) || !check_empty(i)) {
        cout << "Enter a valid column index: ";
        cin >> i;
    }
}
//MAIN FUNCTION
void play_game() {
    cout << "Connect Four Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i;
        read_input(i);
        //Set the input position with the mark
        set_cell(i, marks[player]);
        //Check if the state of the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the state of the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = (player + 1) % n_players;
    }
}
int main() {
    while (true) {
        grid_clear();
        play_game();
        char c;
        cout << "Play Again [Y/N] ";
        cin >> c;
        if (c != 'y' && c != 'Y')
            break;
    }
}

#include <iostream>
#include <vector>
using namespace std;

void Display_board(const vector<char>& b) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << b[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "\n";
            if (i < 6) cout << "---*---*---\n";
        } else {
            cout << "|";
        }
    }
    cout << "\n";
}

char Check_the_winner(const vector<char>& b) {
    const int winningPatterns[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        
    for (const auto& p : winningPatterns) {
        if (b[p[0]] == b[p[1]] &&
            b[p[1]] == b[p[2]] &&
            b[p[0]] != ' ') {
            return b[p[0]];
        }
    }
    for (const char& c : b) {
        if (c == ' ') 
            return ' '; 
    }

    return 'T';
}

void Play() {
    vector<char> board(9, ' '); // Initialize a 3x3 board
    char currentPlayer = 'X';
    char winner = ' ';

    cout << "Welcome to Tic Tac Toe!\n";

    while (winner == ' ') {
        Display_board(board);

        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move - 1] = currentPlayer;
        winner = Check_the_winner(board);

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    Display_board(board);

    if (winner == 'T') {
        cout << "It's a tie!\n";
    } else {
        cout << "Player " << winner << " wins! Congratulations!\n";
    }
}

int main(){
    Play();

    return 0;
}
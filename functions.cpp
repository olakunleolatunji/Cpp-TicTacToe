#include <iostream>
#include <vector>
#include <limits>
#include "header.h"
using std::cin, std::cout, std::endl, std::vector, std::streamsize, std::numeric_limits;

void start(Player& P1, Player& P2){
    do {
        cout << "Please select X or O as Player 1: ";
        cin >> P1.letter;

        if(P1.letter == 'X') {
            P2.letter = 'O';
        }
        else if(P1.letter == 'O') {
            P2.letter = 'X';
        }
        else {
            cout << "Invalid input. Please select either X or O.\n";
        }

    } while(P1.letter != 'X' && P1.letter != 'O');
    cout << "\n" << "Player 1: " << P1.letter;
    cout << "\nPlayer 2: " << P2.letter;
}

// This function is where the gaming happens
void fill_up(char Game[][3], Player& P1, Player& P2){
    cout << "\nPlayer 1 goes first, select 1 to 9 to play in any box\n\n";
    cout << "1 | 2 | 3\n---------\n4 | 5 | 6 \n---------\n7 | 8 | 9";

    unsigned int count = 0;
    bool winner = false;
    vector<int> played;

    do {
        int play{0};
        bool legal = false;

        // Player 1 always goes first
        if ((count + 2) % 2 == 0) {
            do {
                cout << "\n\nPlayer 1 (" << P1.letter << ") Plays: ";
                cin >> play;

                if (cin.fail()) {
                    cout << "\nInvalid input. Please enter a number between 1 and 9." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                legal = true;
                for (int num : played) {
                    if (num == play) {
                        cout << "That box has been taken!\n";
                        legal = false;
                        break;
                    }
                }

                // If the play was legal, then the game continues
                // Or else the do while loop runs again
                if (legal) {
                    played.push_back(play);
                    which_box(Game, play, P1.letter);
                }

            } while (!legal);
        }
        else {
            do {
                cout << "\n\nPlayer 2 (" << P2.letter << ") Plays: ";
                cin >> play;

                if (cin.fail()) {
                    cout << "\nInvalid input. Please enter a number between 1 and 9." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; // Continue to prompt for input
                }

                legal = true;
                for (int num : played) {
                    if (num == play) {
                        cout << "That box has been taken!\n";
                        legal = false;
                        break;
                    }
                }

                // If the play was legal, then the game continues
                // Or else the do while loop runs again
                if (legal) {
                    played.push_back(play);
                    which_box(Game, play, P2.letter);
                }

            } while (!legal);
        }

        // You can't win tic tac toe until at least 5 plays so we only begin to check at that point
        if (count >= 4){
            check(Game, P1, P2, winner);
        }

        cout << "\n" << Game[0][0] << "  " << Game[0][1] << "  " << Game[0][2] <<
                "\n\n" << Game[1][0] << "  " << Game[1][1] << "  " << Game[1][2] <<
                "\n\n" << Game[2][0] << "  " << Game[2][1] << "  " << Game[2][2] << endl;

        ++count;

        if (count == 9 && !winner) {
            cout << "\nIt's a tie!\n";
            winner = true;
        }
    } while (!winner);
}

// replace the dot in the box with X or O
void which_box(char Game[][3], int play, char letter){
    switch (play) {
        case 1:
            Game[0][0] = letter;
            break;
        case 2:
            Game[0][1] = letter;
            break;
        case 3:
            Game[0][2] = letter;
            break;
        case 4:
            Game[1][0] = letter;
            break;
        case 5:
            Game[1][1] = letter;
            break;
        case 6:
            Game[1][2] = letter;
            break;
        case 7:
            Game[2][0] = letter;
            break;
        case 8:
            Game[2][1] = letter;
            break;
        case 9:
            Game[2][2] = letter;
            break;
        default:
            break;
    }
}

void check(char Game[][3], Player& P1, Player& P2, bool& winner){
    for(int i=0; i<3; ++i){
        // Check rows
        if(Game[i][0] == Game[i][1] && Game[i][1] == Game[i][2] && Game[i][1] != '.'){
            if(Game[i][0] == P1.letter){
                cout << "Player 1 Wins\n";
                winner = true;
                return;
            }
            else{
                cout << "Player 2 Wins\n";
                winner = true;
                return;
            }
        }
        // Check columns
        if(Game[0][i] == Game[1][i] && Game[1][i] == Game[2][i] && Game[1][i] != '.'){
            if(Game[0][i] == P1.letter){
                cout << "Player 1 Wins\n";
                winner = true;
                return;
            }
            else{
                cout << "Player 2 Wins\n";
                winner = true;
                return;
            }
        }
    }
        // Check Diagonals
        if((Game[0][0] == Game[1][1] && Game[1][1] == Game[2][2]) ||
           (Game[0][2] == Game[1][1] && Game[1][1] == Game[2][0]) && Game[1][1] != '.'){
            if(Game[1][1] == P1.letter){
                cout << "Player 1 Wins\n";
                winner = true;
                return;
            }
            else{
                cout << "Player 2 Wins\n";
                winner = true;
                return;
            }
        }
}

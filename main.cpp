#include <iostream>
#include "header.h"

using std::cin, std::cout;

int main()
{
    // The dots fill up the boxes and will be replaced by X or O once the game begins
    char Game[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};

    Player P1, P2;

    int playing{0};

    do{
        start(P1, P2);

        fill_up(Game, P1, P2);

        cout << "To continue the game, enter \"0\" ";
        cin >> playing;
    } while (playing == 0);


    return 0;
}

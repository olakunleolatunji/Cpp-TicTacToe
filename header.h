#ifndef HEADER_H
#define HEADER_H

struct Player{
    char letter;
};

void start(Player&, Player&);
void fill_up(char[][3], Player&, Player&);
void which_box(char[][3], int, char);
void check(char[][3], Player&, Player&, bool&);

#endif // HEADER_H

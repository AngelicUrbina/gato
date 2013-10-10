//
//  board.h
//  gato
//
//  Created by abcsds on 9/10/13.
//  Copyright (c) 2013 abcsds. All rights reserved.
//

#ifndef __gato__board__
#define __gato__board__

#include <iostream>
#include <stack>
#include "player.h"

using namespace std;

struct grid {
    int cell[9];
};

class player;

class board {
private:
    grid grid;     //Acceptable inputs are -1, 0, and 1.
    stack<int> freeSpaces;
    stack<int> lastMoves;
    int winer;
    //TODO add a player class to add p1 and p2
    player *p1, *p2;
    
    
public:
    board(player *player1, player *player2);
    board(struct grid g, player *player1, player *player2);
    ~board();
    bool put(int n, int player); //n =  cell number, player = (-1,1)
    int checkWin(); // returns -1, 1, or zero if no win
    bool checkWin(int Player);
    bool checkFull();
    bool checkOver();
    struct grid getGrid();
    stack<int> getFreeSpaces();
    void undoLastMove();
    void print();
    void pPrint();
    void genRandomGrid();
    
    //TODO add a play function
    
    
};

#endif /* defined(__gato__board__) */

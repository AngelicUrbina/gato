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
#include <list>
#include "player.h"

using namespace std;

struct grid {
    int cell[9];
};

class player;

class board {
private:
    grid grid;     //Acceptable inputs are -1, 0, and 1.
    list<int> freeSpaces;

    stack<int> lastMoves;
    int winer;
    player *p1, *p2;
    
    
public:
    board();
    board(struct grid g);
    board(player *player1, player *player2);
    board(struct grid g, player *player1, player *player2);
    ~board();
    bool put(int n, int player); // N =  cell number, player = (-1,1)
    int checkWin();              // Returns -1, 1, or zero if no win
    bool checkWin(int Player);   // Checks for a winer
    bool checkFull();            // Checks for a full board
    bool checkOver();            // Checks for a GameOver
    bool setPlayers(player* pl1,player* pl2);
    struct grid getGrid();       // Returns game Grid
    list<int> getFreeSpaces(); // Returns cells in Grid that have not been played
    void undoLastMove();         // Reverts last move
    void print();                // Print grid numbers
    void pPrint();               // Grid's pretty print
    void genRandomGrid();        // Generates a random grid
    void removePlayers();        // Makes player* = NULL
    void printFreeSpaces();      // Debug function to print Free Spaces
    
    // Play function
    void play();
    void playSilent();
    void clean();
    
    
};

#endif /* defined(__gato__board__) */

//
//  board.cpp
//  gato
//
//  Created by abcsds on 9/10/13.
//  Copyright (c) 2013 abcsds. All rights reserved.
//

#include "board.h"
board::board() {
    p1 = NULL;
    p2 = NULL;
    for (int i = 0; i<9; i++) {
        grid.cell[i] = 0;
    }
    winer = 0;
}
board::board(struct grid g) {
    p1 = NULL;
    p2 = NULL;
    grid = g;
    winer = checkWin();
}
board::board(player *player1, player *player2) {
    p1 = player1;
    p2 = player2;
    for (int i = 0; i<9; i++) {
        grid.cell[i] = 0;
    }
    winer = 0;
}
board::board(struct grid g, player *player1, player *player2) {
    p1 = player1;
    p2 = player2;
    grid = g;
    winer = checkWin();
}
board::~board() {
    
}
bool board::put(int n, int player) {
    if (grid.cell[n] == 0 && abs(player) == 1) {
        grid.cell[n] = player;
        lastMoves.push(n);
        return true;
    }
    else return false;
    
    
}
int board::checkWin() {
    if (abs(grid.cell[0]+grid.cell[1]+grid.cell[2]) == 3) return grid.cell[0];
    else if (abs(grid.cell[3]+grid.cell[4]+grid.cell[5]) == 3) return grid.cell[3];
    else if (abs(grid.cell[6]+grid.cell[7]+grid.cell[8]) == 3) return grid.cell[6];
    else if (abs(grid.cell[6]+grid.cell[4]+grid.cell[2]) == 3) return grid.cell[6];
    else if (abs(grid.cell[6]+grid.cell[3]+grid.cell[0]) == 3) return grid.cell[6];
    else if (abs(grid.cell[7]+grid.cell[4]+grid.cell[1]) == 3) return grid.cell[7];
    else if (abs(grid.cell[8]+grid.cell[5]+grid.cell[2]) == 3) return grid.cell[8];
    else if (abs(grid.cell[8]+grid.cell[4]+grid.cell[0]) == 3) return grid.cell[8];
    else return 0;
    
}
bool board::checkWin(int Player) {
    if (grid.cell[0]+grid.cell[1]+grid.cell[2] == 3*Player) return true;
    else if (grid.cell[3]+grid.cell[4]+grid.cell[5] == 3*Player) return true;
    else if (grid.cell[6]+grid.cell[7]+grid.cell[8] == 3*Player) return true;
    else if (grid.cell[6]+grid.cell[4]+grid.cell[2] == 3*Player) return true;
    else if (grid.cell[6]+grid.cell[3]+grid.cell[0] == 3*Player) return true;
    else if (grid.cell[7]+grid.cell[4]+grid.cell[1] == 3*Player) return true;
    else if (grid.cell[8]+grid.cell[5]+grid.cell[2] == 3*Player) return true;
    else if (grid.cell[8]+grid.cell[4]+grid.cell[0] == 3*Player) return true;
    else return false;
}
bool board::checkFull() {
    for (int i = 0; i<9; i++) {
        if(grid.cell[i] == 0) return false;
    }
    return true;
    
}
bool board::checkOver() {
    if (checkWin() || checkFull()) return true;
    else return false;
}
bool board::setPlayers(player* pl1,player* pl2) {
    if (pl1 && pl2) {
        p1 = pl1;
        p2 = pl2;
        return true;
    }
    else return false;
}
struct grid board::getGrid() {
    return grid;
}
stack<int> board::getFreeSpaces() {
    for (int i= 0; i<9; i++) {
        if (grid.cell[i]==0) {
            freeSpaces.push(i);
        }
    }
    return freeSpaces;
}
void board::undoLastMove() {
    if (!lastMoves.empty()) {
        grid.cell[lastMoves.top()] = 0;
        lastMoves.pop();
        winer = 0;
    }
}
void board::print() {
    cout << "--- GAME ---" << endl;

    for (int i = 0; i < 3; i++) {
        cout << grid.cell[i];
    }
    cout << endl;
    for (int i = 3; i < 6; i++) {
        cout << grid.cell[i];
    }
    cout << endl;
    for (int i = 6; i < 9; i++) {
        cout << grid.cell[i];
    }
    cout << endl;

}

void board::pPrint() {
    cout << "--- GAME ---" << endl;
    
    for (int i = 0; i < 3; i++) {
        switch (grid.cell[i]) {
            case -1:
                cout << " O ";
                break;
            case 1:
                cout << " X ";
                break;
            default:
                cout << " - ";
                break;
        }
    }
    cout << endl;
    for (int i = 3; i < 6; i++) {
        switch (grid.cell[i]) {
            case -1:
                cout << " O ";
                break;
            case 1:
                cout << " X ";
                break;
            default:
                cout << " - ";
                break;
        }
    }
    cout << endl;
    for (int i = 6; i < 9; i++) {
        switch (grid.cell[i]) {
            case -1:
                cout << " O ";
                break;
            case 1:
                cout << " X ";
                break;
            default:
                cout << " - ";
                break;
        }
    }
    cout << endl;
    
}
void board::genRandomGrid() {
    srand((unsigned int)time(NULL));
    for (int i =0 ; i<9; i++) {
        grid.cell[i] = rand()%3 - 1;
    }
}
void board::removePlayers() {
    p1 = NULL;
    p2 = NULL;
}
void board::play() {
    if (p1!=NULL && p2!=NULL) {
        cout << " Tic Tac Toe " <<endl;
        cout << " Gird setup: " << endl;
        cout << " 0 1 2 " << endl;
        cout << " 3 4 5 " << endl;
        cout << " 6 7 8 " << endl;
        for (int i = 0; i<9; i++) {
            pPrint();
            if (i%2 == 0) {
                if (p1->getPlayerType() == HUMAN) cout << "Human Moves"<< endl;
                else cout << "Computer Moves"<< endl;
                put(p1->move(),p1->getPlayerN());
            }
            else {
                if (p1->getPlayerType() == HUMAN) cout << "Human Moves"<< endl;
                else cout << "Computer Moves"<< endl;
                put(p2->move(),p2->getPlayerN());
            }
            winer = checkWin();
            if (checkOver()) {
                pPrint();
                if (winer == 0) cout << "It's a draw" << endl;
                else cout << "Winer: " << winer << endl; //TODO Print p1 or p2
            }
        }
        
    }
    
}
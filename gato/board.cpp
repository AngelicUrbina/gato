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
        freeSpaces.push_back(i);
    }
    winer = 0;
}
board::board(struct grid g) {
    p1 = NULL;
    p2 = NULL;
    grid = g;
    for (int i = 0; i<9; i++) {
        freeSpaces.push_back(i);
    }
    winer = checkWin();
}
board::board(player *player1, player *player2) {
    p1 = player1;
    p2 = player2;
    for (int i = 0; i<9; i++) {
        grid.cell[i] = 0;
        freeSpaces.push_back(i);
    }
    winer = 0;
}
board::board(struct grid g, player *player1, player *player2) {
    p1 = player1;
    p2 = player2;
    grid = g;
    for (int i = 0; i<9; i++) {
        freeSpaces.push_back(i);
    }
    winer = checkWin();
}
board::~board() {
    
}
bool board::put(int n, int player) {
    if (grid.cell[n] == 0 && abs(player) == 1) {
        grid.cell[n] = player;
        lastMoves.push(n);
        
        
        winer = checkWin();
        getFreeSpaces();
        
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
list<int> board::getFreeSpaces() {
    freeSpaces.clear();
    for (int i= 0; i<9; i++) {
        if (grid.cell[i]==0) {
            freeSpaces.push_back(i);
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
void board::printFreeSpaces() {
    cout << " Printing Free Spaces: " << endl;
    for (list<int>::iterator it = freeSpaces.begin(); it!=freeSpaces.end(); it++) {
        cout << *it << endl;
    }
    cout << " End of Free Spaces " << endl;
}
void board::play() {
    bool brk = false;
    if (p1!=NULL && p2!=NULL) {
        cout << " Tic Tac Toe " <<endl;
        cout << " Gird setup: " << endl;
        cout << " 0 1 2 " << endl;
        cout << " 3 4 5 " << endl;
        cout << " 6 7 8 " << endl;
        
        
        while (!checkOver()) {
            
            // Player 1
            while (!brk) {
                pPrint();
                if (p1->getPlayerType() == HUMAN) cout << "P1 Human Moves"<< endl;
                else cout << "P1 Computer Moves"<< endl;
                brk = put(p1->move(this),p1->getPlayerN());
            }
            brk = false;
            
            if (checkOver()) {
                break;
            }
            
            // Player 2
            while (!brk) {
                pPrint();
                if (p1->getPlayerType() == HUMAN) cout << "P2 Human Moves"<< endl;
                else cout << "P2 Computer Moves"<< endl;
                brk = put(p2->move(this),p2->getPlayerN());
            }
            brk = false;

            
        }
        pPrint();
        winer = checkWin();
        if (winer == 0) cout << "It's a draw" << endl;
        else cout << "Winer: " << winer << endl; //TODO Print p1 or p2
        
    }
    
    
}
void board::playSilent() {
    bool brk = false;
    if (p1!=NULL && p2!=NULL) {
        
        while (!checkOver()) {
            
            // Player 1
            while (!brk) {
                pPrint();
                brk = put(p1->move(this),p1->getPlayerN());
            }
            brk = false;
            
            if (checkOver()) {
                break;
            }
            
            // Player 2
            while (!brk) {
                brk = put(p2->move(this),p2->getPlayerN());
            }
            brk = false;
            
            
        }
        pPrint();
        winer = checkWin();
        if (winer == 0) cout << "It's a draw" << endl;
        else cout << "Winer: " << winer << endl; //TODO Print p1 or p2
        
    }
}

void board::clean() {
    freeSpaces.empty();
    for (int i = 0; i<9; i++) {
        grid.cell[i] = 0;
        freeSpaces.push_back(i);
    }
    winer = 0;}

//
//  player.cpp
//  gato
//
//  Created by abcsds on 10/10/13.
//  Copyright (c) 2013 abcsds. All rights reserved.
//

#include "player.h"

player::player(int pType, int playerNumber) {
    playerType = pType;
    playerN = playerNumber;
    if (playerN == -1) oponentN = 1;
    else oponentN = -1;
}
player::~player() {
    
}
int player::move(board *b) {
    if (playerType == HUMAN) return humanMove(b);
    else return computerMove(b);
}
int player::humanMove(board *b) {
    //int free[b->getFreeSpaces().size()];
    vector<int> freeSpaces = b->getFreeSpaces();
    bool err = true;
    int n;
    do {
        cout << "  Please choose a free cell acording to Grid Setup " << endl;
        cin >> n;
        for (vector<int>::iterator it = freeSpaces.begin(); it != freeSpaces.end(); it++) {
            if (n == *it) {
                err = false;
            }
        }
    } while (err);
    return n;
}

int player::getPlayerType() {
    return playerType;
}
int player::getPlayerN() {
    return playerN;
}
void player::setPlayerType(int pType) {
    playerType = pType;
}
void player::setPlayerN(int pNum) {
    playerN = pNum;
}

int player::computerMove(board *b) {
    return 0; //TODO
}
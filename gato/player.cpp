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
    list<int> freeSpaces = b->getFreeSpaces();
    bool err = true;
    int n;
    do {
        cout << "  Please choose a free cell acording to Grid Setup " << endl;
        cin >> n;
        for (list<int>::iterator it = freeSpaces.begin(); it != freeSpaces.end(); it++) {
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

int player::computerMove(board *b) { // TODO Clean up :)
    int score;
    return max(b,&score);    
}
// TODO Check minimax
int player::max(board *b, int* score) {
    int bestMove = 0;
    int bestScore = 0;
    int newScore = 0;
    list<int> freeSpaces = b->getFreeSpaces();
    for (list<int>::iterator it = freeSpaces.begin(); it != freeSpaces.end(); it++) {
        b->put(*it, playerN);
        if (b->checkOver()) newScore = getScore(b);
        else min(b, &newScore);
        b->undoLastMove();
        if (newScore > bestScore) {
            bestMove = *it;
            bestScore = newScore;
        }
        
    }
    *score = bestScore;
    return bestMove;
}
int player::min(board *b, int* score) {
    int bestMove = 0;
    int bestScore = 0;
    int newScore = 0;
    list<int> freeSpaces = b->getFreeSpaces();
    for (list<int>::iterator it = freeSpaces.begin(); it != freeSpaces.end(); it++) {
        b->put(*it, oponentN);
        if (b->checkOver()) newScore = getScore(b);
        else max(b, &newScore);
        b->undoLastMove();
        if (newScore < bestScore) {
            bestMove = *it;
            bestScore = newScore;
            cerr << *it << endl;
        }
    }
    *score = bestScore;
    return bestMove;
}
int player::getScore(board *b) {
    if (b->checkOver()) {
        if (b->checkWin()==playerN) return 1;
        else return -1;
    }
    return 0;
}
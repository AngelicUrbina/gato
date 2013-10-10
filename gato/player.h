//
//  player.h
//  gato
//
//  Created by abcsds on 10/10/13.
//  Copyright (c) 2013 abcsds. All rights reserved.
//

#ifndef __gato__player__
#define __gato__player__

#include <iostream>
#include "board.h"
#define COMPUTER = -1;
#define HUMAN = 1;

class player {
private:
    int playerType;
    int playerN;
public:
    player(int pType, int playerNumber);
    ~player();
};


#endif /* defined(__gato__player__) */

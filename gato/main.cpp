//
//  main.cpp
//  gato
//
//  Created by abcsds on 8/10/13.
//  Copyright (c) 2013 abcsds. All rights reserved.
//

#include <iostream>
#include "board.h"
#include "player.h"

using namespace std;

int main(int argc, const char * argv[])
{
    player p1(COMPUTER,1);
    player p2(COMPUTER,-1);
    board b(&p1,&p2);
    b.playSilent();
//    for (int i = 0; i<9; i++) {
//        b.clean();
//
//    }
    return 0;
}


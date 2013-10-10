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
    player p1(HUMAN,1);
    player p2(HUMAN,2);
    board b(&p1,&p2);
    b.genRandomGrid();
    b.pPrint();
    
    if (b.checkWin()) cout << "Player won!" << endl;
    else cout << "Player didn't win!" << endl;
    return 0;
}


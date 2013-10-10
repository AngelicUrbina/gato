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

    grid g;
    g = {1,0,1,-1,1,-1,0,0,1};
    player p1(1,1);
    player p2(1,2);
    board b(g,&p1,&p2);
    //b.checkWin()
    b.genRandomGrid();
    b.pPrint();
    
    if (b.checkWin()) cout << "Player won!" << endl;
    else cout << "Player didn't win!" << endl;
    return 0;
}


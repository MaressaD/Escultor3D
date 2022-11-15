#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

int main(void)
{
   /* Sculptor trono(10,10,10);
    trono.setColor(0.0,0.0,1.0,1.0);
    trono.putBox(0,9,0,9,0,9);
    trono.cutBox(1,8,1,9,1,9);
    trono.writeOFF("trono.off");*/

    Sculptor melancia(20,20,20);
    melancia.setColor(0.5,0.9,0.5,0.5);
    melancia.putSphere(10,10,10,10);
    melancia.setColor(0.9,0.1,0.1,0.5);
    melancia.putEllipsoid(10,10,10,9,9,9);
    melancia.putSphere(10,10,10,9);
    melancia.cutBox(10,20,10,20,10,20);
    melancia.writeOFF("melancia2.off");
}

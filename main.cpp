#include "sculptor.h"
#include <iostream>

int main() {
    Sculptor coqueiro(40, 40, 40);
    //base de areia
    coqueiro.setColor(0.9, 0.82, 0.65, 1.0);
    coqueiro.putBox(0, 39, 0, 39, 0, 2);

    //tronco
    coqueiro.setColor(0.40, 0.30, 0.20, 1.0);
    coqueiro.putBox(17, 22, 17, 22, 3, 25);

    //base verde
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(17, 22, 17, 22, 26, 27);

    //primeiro ramo
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(21, 26, 21, 22, 28, 29);

    //segundo ramo
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(21, 26, 17, 18, 28, 29);

    //terceiro ramo
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(13, 18, 17, 18, 28, 29);

    //quarto ramo
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(13, 18, 21, 22, 28, 29);

    //quinto ramo
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(19, 20, 21, 26, 28, 29);

    //sexto ramo
    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(19, 20, 13, 18, 28, 29);

    //ramos no eixo z abaixo:

    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(13, 14, 17, 18, 19, 27);

    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(19, 20, 25, 26, 19, 27);

    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(13, 14, 21, 22, 19, 27);

    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(19, 20, 13, 14, 19, 27);

    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(25, 26, 17, 18, 19, 27);

    coqueiro.setColor(0.37, 0.98, 0, 1.0);
    coqueiro.putBox(25, 26, 21, 22, 19, 27);

    //cocos
    coqueiro.setColor(0.35, 0.20, 0.10, 1.0);
    coqueiro.putEllipsoid(15, 16, 22, 1, 1, 1.5);

    coqueiro.setColor(0.35, 0.20, 0.10, 1.0);
    coqueiro.putEllipsoid(15, 23, 22, 1, 1, 1.5);

    coqueiro.setColor(0.35, 0.20, 0.10, 1.0);
    coqueiro.putEllipsoid(24, 23, 22, 1, 1, 1.5);

    coqueiro.setColor(0.35, 0.20, 0.10, 1.0);
    coqueiro.putEllipsoid(24, 16, 22, 1, 1, 1.5);


    coqueiro.writeOFF("coqueiro.off");
    return 0;
}

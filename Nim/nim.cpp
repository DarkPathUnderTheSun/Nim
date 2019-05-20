#include<iostream>
int globalCoins;

int randomNum(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
} 

void board (int option, int coins, std::string player) {
    if (option == 0) {
        std::cout<<"\n------------------------\n"<<"Quedan "<< globalCoins << " monedas: ";
        for (int i = 0; i < globalCoins; i++) {
            std::cout<<"O ";
        }
        std::cout<<"\n------------------------\n";
    }

    if (option == 1) {
        globalCoins = globalCoins - coins;
        if (globalCoins <= 0) {
            globalCoins = 0;
            std::cout<<"\n\n--------------Ganó "<< player << " --------------\n\n";
        }
    }
}

void playerTurn () {
    std::cout<<"\nTu turno. ";
    int correctMove = 0;
    int takeCoins = 0;
    while (correctMove == 0) {
        std::cout<<"Cuántas monedas vas a tomar? ";
        std::cin>>takeCoins;
        if ((takeCoins < 4) && (takeCoins > 0)) {
            board(1, takeCoins, "el jugador");
            correctMove = 1;
        }
        else {
        std::cout<<"Solo puedes tomar de una a tres monedas.\n";
        }
    }
    if (globalCoins > 0) {
        board(0, 0, "0");
    }
}

void machineTurn () {
    int takeCoins;
    takeCoins = globalCoins % 4;
    if (takeCoins == 0) {
        takeCoins = randomNum(1, 3);
    }
    if (takeCoins == 1) {
        std::cout<<"\nMi turno. Tomaré "<<takeCoins<<" moneda.";
    }
    else {
        std::cout<<"\nMi turno. Tomaré "<<takeCoins<<" monedas.";
    }
    board(1, takeCoins, "la computadora");
    if (globalCoins > 0) {
        board(0, 0, "la computadora");
    }
}

int main () {
    std::cout<<"Autómata para jugar NIM en C++\n"<<"Con cuántas monedas jugaremos? ";
    std::cin>>globalCoins;
    board(0, 0, "nadie");
    while (globalCoins > 0) {
        playerTurn();
        if (globalCoins > 0) {
            machineTurn();
        }
    }
}

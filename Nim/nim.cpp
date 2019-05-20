#include<iostream>
int globalCoins;
void board (int option, int coins, std::string player) {
    if (option == 0) {
        std::cout<<"\n------------------------\n"<<"Quedan "<< globalCoins << " monedas.";
        for (int i = 1; i < globalCoins; i++) {
            std::cout<<"O ";
        }
        std::cout<<"\n------------------------\n";
    }

    if (option == 1) {
        globalCoins = globalCoins - coins;
        if (globalCoins < 0) {
            globalCoins = 0;
            std::cout<<"\n\n--------------Ganó "<< player << " --------------\n\n";
        }
    }
}

void playerTurn () {
    std::cout<<"\nTu turno.";
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
        std::cout<<"Solo puedes tomar de una a tres monedas.";
        }
    }
    if (globalCoins > 0) {
        board(0, 0, "0");
    }
}

int main () {
    std::cout<<"Autómata para jugar NIM en C++\n"<<"Con cuántas monedas jugaremos? ";
    std::cin>>globalCoins;
    board(0, 0, "nadie");
    while (globalCoins > 0) {
        playerTurn;
    }
}

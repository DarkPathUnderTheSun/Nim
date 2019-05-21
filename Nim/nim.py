def board(option, coins, player):
    if option == "show":
        print ("\n------------------------")
        print ("\nQuedan ", globalCoins, " monedas.")
        for i in range(globalCoins):
            print ("O ")
        print ("\n------------------------")
    if option == "take":
        globalCoins = globalCoins - coins
        if globalCoins <= 0:
            globalCoins = 0
            print ("\n\n--------------Ganó ", player, " --------------\n\n")

def playerTurn():
    print ("\nTu turno. ")
    correctMove = 0
    while correctMove == 0:
        takeCoins = input("Cuantas monedas vas a tomar? ")
        if (takeCoins < 4) and (takeCoins > 0):
            board("take", takeCoins, "el jugador")
            correctMove = 1
        else:
            print ("Solo puedes tomar de una a tres monedas.")
    if globalCoins > 0:
        board("show", 0, "el jugador")

def machineTurn():
    takeCoins = globalCoins % 4
    if takeCoins == 0:
        takeCoins = random.randrange(1,3,1)
    if takeCoins == 1:
        print ("\nMi turno. Tomaré ", takeCoins, " monedas.")
    else:
        print ("\nMi turno. Tomaré ", takeCoins, " monedas.")
    board("take", takeCoins, "la computadora")
    if globalCoins > 0:
        board("show", 0, "la computadora")

print ("Autómata para jugar NIM en Python\n")
global globalCoins 
globalCoins = input("Con cuántas monedas jugaremos? ")
board("show", 0, "nadie")

while globalCoins > 0:
    playerTurn
    if globalCoins > 0:
        machineTurn

def board(option, coins, player)
    if option == "show"
        puts "\n------------------------"
        print "Quedan #{$coins} monedas: "
        for i in 1..$coins
            print "O "
        end
        puts "\n------------------------"
    end
    if option == "take"
        $coins = $coins - coins
        if $coins <= 0
            $coins = 0
            puts "\n\n--------------Ganó #{player}--------------\n\n"
        end
    end
end

def playerTurn
    print "\nTu turno. "
    correctMove = 0
    while correctMove == 0
        print "Cuantas monedas vas a tomar? "
        takeCoins = gets.chomp.to_i
        if (takeCoins < 4) && (takeCoins > 0)
            board("take", takeCoins, "el jugador")
            correctMove = 1
        else
            puts "Solo puedes tomar de una a tres monedas."
        end
    end
    if $coins > 0
        board("show", 0, "el jugador")
    end
end

def machineTurn
    takeCoins = $coins % 4
    if takeCoins == 0
        takeCoins = rand(1..3)
    end
    if takeCoins == 1
        puts "\nMi turno. Tomaré #{takeCoins} moneda."
    else
        puts "\nMi turno. Tomaré #{takeCoins} monedas."
    end
    board("take", takeCoins, "la computadora")
    if $coins > 0
        board("show", 0, "la computadora")
    end
end

puts "Autómata para jugar NIM en Ruby"
print "Con cuántas monedas jugaremos? "
$coins = gets.chomp.to_i
board("show", 0, "nadie")

while $coins > 0
    playerTurn
    if $coins > 0
        machineTurn
    end
end

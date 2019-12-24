
import os

listTest = [
    [2, 0, 1],
    [0, 1, 0],
    [0, 0, 1]
]

def InitTable(table):
    for iter in range(0, 3):
        for jiter in range(0, 3):
            table[iter][jiter] = 0

def PrintTable(table):
    os.system("cls")
    print('[' + ('-' * 4) + '|' + ('-' * 5) + '|' + ('-' * 5) + ']')
    for iter in range(0, 3):
        print("[", end=' ')
        for jiter in range(0, 2):
            print(table[iter][jiter], " | ", end= ' ')
        print(table[iter][2], " ]")
        print('[' + ('-' * 4) + '|' + ('-' * 5) + '|' + ('-' * 5) + ']')


def VerificaCastig1(list):
    win = True
    for iter in range(0, len(list)):
        if list[iter][iter] != 1:
            win = False
    if win:
        return True
    win = True
    linie = 0
    for iter in range(2, -1, -1): #for ( i = 2; i > 0; i--)
        if list[linie][iter] != 1:
            win = False
        linie += 1
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[0][iter] != 1:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[1][iter] != 1:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[2][iter] != 1:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[iter][0] != 1:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[iter][1] != 1:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[iter][2] != 1:
            win = False
    if win:
        return True
    return False

def VerificaCastig2(list):
    win = True
    for iter in range(0, len(list)):
        if list[iter][iter] != 2:
            win = False
    if win:
        return True
    win = True
    linie = 0
    for iter in range(len(list) - 1, 0, -1):
        if list[linie][iter] != 2:
            win = False
        linie += 1
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[0][iter] != 2:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[1][iter] != 2:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[2][iter] != 2:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[iter][0] != 2:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[iter][1] != 2:
            win = False
    if win:
        return True
    win = True
    for iter in range(0, len(list)):
        if list[iter][2] != 2:
            win = False
    if win:
        return True
    return False

def PozitiiDifdeZero(tabla):
    for iter in range(0, 3):
        for jiter in range(0, 3):
            if tabla[iter][jiter] == 0:
                return False
    return True

def Game(player, x, y):
    while True:
        print("Tura jucatorului {0}".format(player))
        x = int(input("alege x"))
        y = int(input("alege y"))
        if player == 1:
            if listTest[x][y] == 0:
                listTest[x][y] = 1
                PrintTable(listTest)
                if VerificaCastig1(listTest):
                    print("Player 1 won")
                    return
                elif VerificaCastig2(listTest):
                    print("Player 2 won")
                    return
                elif PozitiiDifdeZero(listTest) and not VerificaCastig1(listTest) and not VerificaCastig2(listTest):
                    print("Egalitate")
                    return
            else:
                PrintTable(listTest)
                print("Exista deja valoare pe aceste coordonate")
                Game(player, x, y)
            player = 2
        else:
            if listTest[x][y] == 0:
                listTest[x][y] = 2
                PrintTable(listTest)
                if VerificaCastig1(listTest):
                    print("Player 1 won")
                    return
                elif VerificaCastig2(listTest):
                    print("Player 2 won")
                    return
                elif PozitiiDifdeZero(listTest) and not VerificaCastig1(listTest) and not VerificaCastig2(listTest):
                    print("Egalitate")
                    return
            else:
                PrintTable(listTest)
                print("Exista deja valoare pe aceste coordonate")
                Game(player, x, y)
            player = 1

def Play_game():
    InitTable(listTest)
    player = 1; x = 0; y = 0
    PrintTable(listTest)
    Game(player, x, y)

if __name__ == "__main__":
    Play_game()
else:
    print("No tic tac toe available")

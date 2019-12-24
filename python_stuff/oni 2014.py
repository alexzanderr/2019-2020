
from random import randint

def ConstructionRandom(matrix):
    for _ in range(n):
        line = []
        for _ in range(n):
            line.append(randint(10, 99))
        matrix.append(line)

def Construction(matrix):
    for i in range(1, n + 1):
        line = []
        for j in range(1, n + 1):
            line.append(i * j)
        matrix.append(line)

def CreateNone(matrix):
    for i in range(n):
        matrix.append([None] * n)

def PrintMatrixAes(matrix):
    for line in matrix:
        print("[", end=" ")
        for item in line:
            print(item, end=" ")
        print("]")

def PrintMatrix(matrix):
    #print("[")
    for line in matrix:
        print(line)
    #print("]")

def Right(matrix, i, j):
    #print(matrix[i][j], "->", sep="", end="")
    if j < n - 1:
        j += 1
        return i, j
    elif j == n - 1:
        if i < n - 1:
            i += 1
            return i, j

def Down(matrix, i, j):
    #print(matrix[i][j], "->", sep="", end="")
    if i < n - 1:
        i += 1
        return i, j
    elif i == n - 1:
        if j < n - 1:
            j += 1
            return i, j


def DownSecondDiag(matrix, i, j, start):
    while True:
        if j == 0 or i == n - 1:
            matrix[i][j] = start
            start += 1
            print(matrix[i][j], "->", sep="", end="")
            return i, j, start
        matrix[i][j] = start
        start += 1
        print(matrix[i][j], "->", sep="", end="")
        i += 1
        j -= 1

def UpSecondDiag(matrix, i, j, start):
    while True:
        if i == 0 or j == n - 1:
            matrix[i][j] = start
            start += 1
            print(matrix[i][j], "->", sep="", end="")
            return i, j, start
        matrix[i][j] = start
        start += 1
        print(matrix[i][j], "->", sep="", end="")
        i -= 1
        j += 1

def ArrowWalking(matrix):
    i, j = 0, 0
    start = 1
    matrix[i][j] = start
    start += 1
    print(matrix[i][j], "->", sep="", end="")
    while i < n - 1 or j < n - 1:
        i, j = Right(matrix, i, j)
        i, j, start = DownSecondDiag(matrix, i, j, start)
        i, j = Down(matrix, i, j)
        i, j, start = UpSecondDiag(matrix, i, j, start)
    print()

def CalculateCenterdSum(matrix):
    result = 0
    for i in range(1, n - 1):
        for j in range(1, n - 1):
            result +=  matrix[i - 1][j - 1] + \
                       matrix[i - 1][j] + \
                       matrix[i - 1][j + 1] + \
                       matrix[i][j - 1] + \
                       matrix[i][j] + \
                       matrix[i][j + 1] + \
                       matrix[i + 1][j - 1] + \
                       matrix[i + 1][j] + \
                       matrix[i + 1][j + 1]
    return result

# olimpiada nationala de informatica pe gimnaziu 2014
if __name__ == '__main__':
    n = 5
    matrix = []
    CreateNone(matrix)
    #PrintMatrix(matrix)
    # punctul a
    ArrowWalking(matrix)
    PrintMatrix(matrix)
    # punctul b
    print(CalculateCenterdSum(matrix))
    # la b nr de valori distincte este 9
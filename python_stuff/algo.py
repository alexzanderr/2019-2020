
import math
import random
from datetime import datetime
import itertools
import collections
import numpy as np

E = math.e
PI = math.pi

class ComputatinalAlgortihms:

    def AbsoluteValue(self, number):
        return number if number > 0 else -number

    def PerfectSquare(self, number):
        return math.sqrt(number) == math.floor(math.sqrt(number))

    def PrimeNumber(self, number):
        if number < 2:
            return False
        elif number > 2 and number % 2 == 0:
            return False
        else:
            for div in range(3, int(math.sqrt(number)) + 1, 2):
                if number % div == 0:
                    return False
        return True

    def Factorial(self, number):
        if number < 0:
            return
        if number == 0 or number == 1:
            return 1
        result = 2
        for i in range(3, number + 1):
            result *= i
        return result

    def RFactorial(self, number):
        if number == 0:
            return 1
        return number * self.RFactorial(number - 1)

    def Factorization(self, number):
        print("Prime factors of {0} are:".format(number), end=' ')
        count = 0
        while number % 2 == 0:
            count += 1
            number //= 2
        if count:
            print("2^{0}".format(count), end=' ')
        div = 3
        while div * div <= number:
            count = 0
            while number % div == 0:
                count += 1
                number //= div
            if count:
                print("{0}^{1}".format(div, count), end=' ')
            div += 2
        if number > 2:
            print(number)

    def RealComp(self, x, y):
        """ Return true if x and y are identical in floating points
            Classic version of c++ real numbers comparison
            ==============================================
            x = .1 * 3
            print("{:.100f}".format(x))
            y = .3
            print("{:.100f}".format(y))
            print(Real_num_comparison(x, y))
            print(x == y)
            ==============================================
            Great example to watch
        """
        epsilon = 1e-100
        print("{:.100f}".format(epsilon))
        print("{:.100f}".format(abs(x - y)))
        return math.abs(x - y) < epsilon

    def Reversed(self, number):
        reverse = 0
        while number:
            reverse = reverse * 10 + number % 10
            number //= 10
        return reverse

    def Palindrome(self, number):
        return number == self.Reversed(number)

    def Rebuild(self, number):
        """ Reconstruction algoritm for an integer"""
        new = 0
        power = 1
        while number:
            new = new + (number % 10) * power
            power *= 10
            number //= 10
        return new

    def DivisorsSum(self, number):
        result = 0
        for div in range(1, int(math.sqrt(number)) + 1):
            result += div + number // div
        return result

    def SieveEratosthenes(self, limit):
        if limit <= 1:
            return
        sieve = [True for _ in range(limit)]
        sieve[0] = sieve[1] = False
        for i in range(2, int(math.sqrt(limit)) + 1):
            if sieve[i] is True:
                for j in range(limit + 1):
                    exp = i ** 2 + j * i
                    if exp < limit:
                        sieve[exp] = False
        primes = []
        for index in range(len(sieve)):
            if sieve[index]:
                primes.append(index)
        return primes

    def __ComputeDeterminant(self, matrix, summ_array=None, product=1):
        if summ_array is None:
            summ_array = []
        if len(matrix) == 1:
            summ_array.append(matrix[0][0])
        elif len(matrix) == 2:
            summ_array.append((matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) * product)
        else:
            for index in range(len(matrix[0])):
                transposee = [list(line) for line in zip(*matrix[1:])]
                del transposee[index]
                minor = [list(line) for line in zip(*transposee)]
                summ_array = self.__ComputeDeterminant(minor, summ_array, product * matrix[0][index] * (-1) ** (index + 2))
        return summ_array

    def Determinant(self, matrix):
        return sum(self.__ComputeDeterminant(matrix))

class Strings:

    def Anagram(self, word1, word2):
        import collections
        return collections.Counter(word1) == collections.Counter(word2)

class Arrays:

    def BinarySearch(self, array, elem=None):
        """ Complexity O(logN)"""
        if elem is None:
            elem = random.choice(array)
        start = 0
        stop = len(array) - 1
        while start <= stop:  # trebuie mereu sa fie egale
            mid = (start + stop) // 2
            if array[mid] == elem:
                print("elemetul {0} a fost gasit cu succes\n"
                      "si se afla pe indexul {1}, si da incep de la 0".format(elem, mid))
                return mid
            elif array[mid] < elem:
                start = mid + 1
            else:
                stop = mid - 1
        print("Elementul {0} cautat nu a fost gasit".format(elem))
        return -1

class Binarys:

    # bin repr for a 2 byte integer
    def BinaryRepr(self, number):
        """ Return an aesthetic representaion of binary version of the transmited number. """
        binaryv = bin(number)
        byte = [0 for _ in range(8)]
        index_byte = len(byte) - 1
        index_bin = len(binaryv) - 1

        for _ in range(len(binaryv)):
            if binaryv[index_bin] == "1":
                byte[index_byte] = 1
            elif binaryv[index_bin] == "b":
                break
            index_bin -= 1
            index_byte -= 1

        # print("Binary representation: {}(base 10) ----> {}(base 2)".format(number, byte))
        fill = ""
        result = ['i' for _ in range(len(str(number)))]
        for char in result:
            fill += char

        str_byte = "[ "
        for b in byte:
            str_byte += str(b) + " "
        str_byte += "]"

        indexes = [i for i in range(7, -1, -1)]
        str_indexes = "[ "
        for i in indexes:
            str_indexes += str(i) + " "
        str_indexes += "]"

        print("{:=^25}".format("BinaryRepr"))
        print("{} : {}".format(number, str_byte))
        print("{} : {}".format(fill, str_indexes))
        print("=" * 25)
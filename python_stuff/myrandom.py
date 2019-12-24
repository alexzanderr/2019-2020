

from random import randint, uniform, random, choice
from andrew_packages.util.exceptions import ParameterException
import time
from datetime import datetime

class Random:
    """ Random tool for everything"""

    # Unicode codes
    # a-z 97-122
    # A-Z 65-90
    # 0-9 48 57

    def CharLow(self):
        return chr(randint(97, 122))

    def CharUpp(self):
        return chr(randint(65, 90))

    def Number(self, size=None):
        s = size
        if size is None:
            size = randint(0, 20)
        return int(str(randint(1, 9)) + "".join([str(randint(0, 9)) for _ in range(size - 1)]))

    def WordLower(self, total_chars=None):
        total_c = total_chars
        if total_chars is None:
            total_c = randint(0, 20)
        return "".join([self.CharLow() for _ in range(total_c)])

    def WordUpper(self, total_chars=None):
        total_c = total_chars
        if total_chars is None:
            total_c = randint(0, 20)
        return "".join([self.CharUpp() for _ in range(total_c)])

    def WordLowUpp(self, total_chars=None):
        total_c = total_chars
        if total_chars is None:
            total_c = randint(0, 20)
        return "".join([choice([self.CharLow(), self.CharUpp()]) for _ in range(total_c)])

    def PropositionLower(self, total_words=None, word_size=None):
        word_s = word_size
        total_w = total_words
        if word_size is None:
            word_s = randint(0, 20)
        if total_words is None:
            total_w = randint(0, 20)
        return " ".join([self.WordLower(word_s) for _ in range(total_w)])

    def PropositionUpper(self, total_words=None, word_size=None):
        word_s = word_size
        total_w = total_words
        if word_size is None:
            word_s = randint(0, 20)
        if total_words is None:
            total_w = randint(0, 20)
        return " ".join([self.WordUpper(word_s) for _ in range(total_w)])

    def PropositionLowUpp(self, total_words=None, word_size=None):
        word_s = word_size
        total_w = total_words
        if word_size is None:
            word_s = randint(0, 20)
        if total_words is None:
            total_w = randint(0, 20)
        return " ".join([choice([self.WordLower(), self.WordUpper()]) for _ in range(total_w)])

    def DateStr(self, start=None, stop=None):
        if start is None or stop is None:
            raise ParameterException("Args are None.")
        df = "%d.%m.%Y"
        start_time = time.mktime(time.strptime(start, df))
        stop_time = time.mktime(time.strptime(stop, df))
        random_time = start_time + random() * (stop_time - start_time)
        return time.strftime(df, time.localtime(random_time))

    def DateStruct(self, start=None, stop=None):
        if start is None or stop is None:
            raise ParameterException("Args are None.")
        df = "%d.%m.%Y"
        start_time = time.mktime(time.strptime(start, df))
        stop_time = time.mktime(time.strptime(stop, df))
        random_time = start_time + random() * (stop_time - start_time)
        return time.strptime(time.strftime(df, time.localtime(random_time)), df)


if __name__ == '__main__':
    df = "%d.%m.%Y"
    r = Random()
    start = '01.01.1971'
    stop = datetime.now().strftime(df)
    print(r.DateStr(start, stop))
    print(r.DateStruct(start, stop))
    print(r.WordUpper(10))
    print(r.WordLower())
    print(r.PropositionUpper(10, 6))
    print(r.PropositionLower())
    print(r.Number(5))
    print(r.PropositionUpper())
    print(r.PropositionLowUpp())
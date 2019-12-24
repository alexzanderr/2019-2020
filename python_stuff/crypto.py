
import string
from andrew_packages.util.exceptions import InstatiationException, ParameterException
from andrew_packages.util.myrandom import Random

class CryptoGraphy:

    __alpha = string.printable

    def __init__(self, message=None, shift_size=None):
        if message is None or shift_size is None:
            raise InstatiationException(f"<Arguments of construsctor of class: {CryptoGraphy.__name__} are invalid>")
        self.message = message
        self.shift_size = shift_size
        self.encrypted = None
        self.decrypted = None

    def Crypt(self, message=None):
        mess = message
        if message is None:
            mess = self.message
        encrypted = "".join([self.__alpha[(self.__alpha.index(char) + self.shift_size ** self.shift_size) % len(self.__alpha)]
                             for char in mess])
        self.encrypted = encrypted
        return self.encrypted

    def Decrypt(self, encypted=None):
        enc = encypted
        if encypted is None:
            enc = self.encrypted if self.encrypted is not None else None
            if not enc:
                raise ValueError("You cant decrypt something that is not encrypted")
        decrypted = "".join([self.__alpha[(self.__alpha.index(char) - self.shift_size ** self.shift_size) % len(self.__alpha)] for char in enc])
        self.decrypted = decrypted
        return self.decrypted

    def __str__(self):
        result = \
        f"""<Message: '{self.message}'>\n"""
        if self.encrypted is not None:
            result += f"<Encrypted: '{self.encrypted}'>\n"
        else:
            result += f"<No encryption>\n"

        if self.decrypted is not None:
            result += f"<Decrypted: '{self.decrypted}'>\n"
        else:
            result += f"<No decryption>\n"
        return result

if __name__ == '__main__':
    rand = Random()
    message = rand.PropositionLowUpp(total_words=5, word_size=5)
    crypt = CryptoGraphy(input(), shift_size=3)
    print(crypt)
    crypt.Crypt()
    print(crypt)
    crypt.Decrypt()
    print(crypt)
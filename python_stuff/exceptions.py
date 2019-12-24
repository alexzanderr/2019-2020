
class CustomBuiltException(Exception):

    def __init__(self, message=None):
        if message is None or message == '':
            self.__message = 'There is no specification for the error.'
        else:
            self.__message = message

    @property
    def Message(self):
        return self.__message

    @Message.setter
    def Message(self, message=None):
        if message is None or message == '':
            print("You cant set an invalid message.")
            return
        self.__message = message

    @Message.deleter
    def Message(self):
        print(f"The internal message of class: {self.__class__} was successfully deleted.")
        del self.__message

    def __str__(self):
        result = \
            f"""
            <---->
                <The error is : {self.__class__}>
                <With cause: {self.__message}>
            <---->
            """
        return result

class InstatiationException(CustomBuiltException):
    """ If we create objects with invalid input. """
    pass

class ParameterException(CustomBuiltException):
    """ If we enter in functions with invalid args or no args"""
    pass


if __name__ == '__main__':
    try:
        raise InstatiationException("Eroare de instantiere, parametrii invalizi")
    except InstatiationException as err:
        print(err)

    try:
        raise ParameterException("parametrii invalizi pentru functie")
    except ParameterException as err:
        print(err)
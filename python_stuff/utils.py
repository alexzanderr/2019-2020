

def ExecutionTime(function):
    import time
    def Wrapper(*args, **kwargs):
        start = time.time()
        executed = function(*args, **kwargs)
        stop = time.time()
        print(f"Execution time for function: '{function.__name__}' was {stop - start} seconds.")
        return executed
    return Wrapper

@ExecutionTime
def TestBoy():
    counter = 0
    for i in range(int(1e+8)):
        counter += 1
    return counter

@ExecutionTime
def Factorial(value):
    if value == 0:
        return 1
    return value * Factorial(value - 1)

if __name__ == '__main__':
    #result = TestBoy()
    #print(result)
    #result = Factorial(100)
    print(Factorial.__name__)
    print(Factorial.__dir__())
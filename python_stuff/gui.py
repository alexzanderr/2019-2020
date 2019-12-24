
from tkinter import *
from tkinter import messagebox
import webbrowser
from datetime import datetime

size = 400

def Frames(root, side, exp, fill):
    frame = Frame(root)
    frame.pack(side=side, expand=exp, fill=fill)
    return frame

def Buttons(root, text, function, side, exp, fill):
    button = Button(root, text=text, command=function)
    button.pack(side=side, expand=exp, fill=fill)
    return button

if __name__ == '__main__':
    wind = Tk()
    wind.geometry("{0}x400+700+0".format(size))
    wind.title("First working gui in python")

    frame1 = Frames(wind, LEFT, YES, BOTH)
    counter = 0
    for i in range(10):
        Buttons(frame1, "{}".format(counter), lambda : print(datetime.now()), TOP, YES, BOTH)
        counter += 1

    frame2 = Frames(wind, LEFT, YES, BOTH)
    for i in range(10):
        Buttons(frame2, "{}".format(counter), lambda : print(datetime.now()), TOP, YES, BOTH)
        counter += 1

    frame3 = Frames(wind, LEFT, YES, BOTH)
    for i in range(10):
        Buttons(frame3, "{}".format(counter), lambda : print(datetime.now()), TOP, YES, BOTH)
        counter += 1

    wind.mainloop()
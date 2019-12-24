
import os
import sys
from datetime import  datetime

cls = lambda : os.system("cls")
pau = lambda : os.system("pause")
exit = lambda : sys.exit(0)

class UltraMenu:

    def __init__(self):
        input("<Press enter to initialize ultramenuapp>")
        self.MenuFunction()

    def DisplayTimeTitle(self):
        title = "ultramenuapp"
        TITLE = '_' * 25 + title + '_' * 25 + '\n'
        print(TITLE)
        print(datetime.now().strftime("\nCurrent datetime: %H:%M:%S - %d-%m-%Y\n"))

    def Applications(self):
        self.DisplayTimeTitle()
        print("[ 1 ]. __System_Application__")
        print("[ 2 ]. __Accounts_Database__")
        print("[ 3 ]. __Email_Sender__")
        print("[ 4 ]. __Wapp_Sender__")
        print("[ 5 ]. __Open_Andrew's_site__")
        print("[ 6 ]. __Drive_Injector__")
        print("[ 7 ]. __Cards_Database__")
        print("[ 8 ]. __iCalendar__")
        print("[ 9 ]. __Music_Application__")
        print("[ 10 ]. __TicTacToe__")
        print("[ 15 ]. ____EXIT____\n")

    def MenuFunction(self):
        cls()
        self.Applications()
        choice = input("<Choose wisely your application>:\n")
        try:
            choice = int(choice)
        except Exception as err:
            if choice == '':
                self.MenuFunction()
            else:
                cls()
                print("[You must enter something valid]\n")
                print(type(err))
                print(err)
                pau()
                self.MenuFunction()
        else:
            if choice == 1:
                from andrew_packages.util.systemapp import FavouriteSites
                FavouriteSites()
                self.MenuFunction()
            elif choice == 2:
                from andrew_packages.util.accounts import Console_interface
                Console_interface()
                self.MenuFunction()
            elif choice == 3:
                from andrew_packages.util.emailsender import EmailSender
                EmailSender()
                self.MenuFunction()
            elif choice == 4:
                from andrew_packages.util.wappsender import ConnectionDriver
                ConnectionDriver()
                self.MenuFunction()
            elif choice == 5:
                from run_andrewsite import OpenWebPage
                OpenWebPage()
                self.MenuFunction()
            elif choice == 6:
                from andrew_packages.util.injection import DriveInjector
                DriveInjector()
                self.MenuFunction()
            elif choice == 7:
                from andrew_packages.util.cards import CardsDatabase
                CardsDatabase()
                self.MenuFunction()
            elif choice == 8:
                from andrew_packages.util.icalendar import iCalendar
                iCalendar()
                self.MenuFunction()
            elif choice == 9:
                from andrew_packages.util.musicapp import MusicPlayList
                MusicPlayList()
                self.MenuFunction()
            elif choice == 10:
                from andrew_packages.util.tictactoe import Play_game
                Play_game()
                self.MenuFunction()
            elif choice == 15:
                cls()
                print("[Ultra menu app was shut down]")
                # pau()
                exit()
            else:
                cls()
                print("[Invalid input]\n")
                pau()
                self.MenuFunction()

if __name__ == '__main__':
    menu = UltraMenu()
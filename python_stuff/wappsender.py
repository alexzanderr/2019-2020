
from selenium import webdriver
import sys
import os
import time

# for more simplity
sleep_time = 1 # second(s)

general_greetings = [
    "*This __message was automated by Andrew with python programming language using selenium module.*",
    "*Thank you for your attention.*",
    "*Have a great day!*",
    "*Bye!*"
]

cls = lambda : os.system("cls")
pause = lambda : os.system("pause")

class ConnectionDriver:

    def __init__(self):
        self.driver = webdriver.Chrome(paths["chdr"])
        self.driver.get(sites["wapp"])
        print("Connection established with the browser trought chrome driver.")
        input("Please login on wapp web with QR code to be able to run.\n")
        self.MenuFunction()

    def Options_list(self):
        options = ["Send message", "Send message to all", "Exit"]
        for index, option in enumerate(options, start=1):
            print("[ {} ]. {}".format(index, option))

    def MenuFunction(self):
        cls()
        self.Options_list()
        choice = input("<Choose wisely>:\n")
        try:
            choice = int(choice)
        except Exception as err:
            if choice == '':
                self.MenuFunction()
            else:
                cls()
                print("You must enter something valid.")
                pause()
                self.MenuFunction()
        else:
            if choice == 1:
                self.Send_message_to_one()
            elif choice == 2:
                self.Send_message_to_ALL()
            elif choice == 3:
                cls()
                self.Exit()
            else:
                cls()
                print("not a good input")
                pause()
                self.MenuFunction()
        print("MenuFunction ended manually, worst case.")

    def Exit(self):
        print("Connection with the driver was killed.")
        try:
            self.driver.close()
            print("Application was shut down.")
            sys.exit(0)
        except Exception:
            print("Application was shut down.")
            sys.exit(0)

    def Send_message_to_one(self):
        cls()
        if not contacts:
            print("No contacts available.")
            self.MenuFunction()

        print("Here are your options:")
        for index, key in enumerate(contacts, start=1):
            print("[ {} ]. {} -> {}".format(index, key, contacts[key]))
            
        choice = int(input("Please select contact:\n"))
        # keys of contacts
        for index, key in enumerate(contacts, start=1):
            if choice == index:
                print("You selected contact:", contacts[key])
                try:
                    times = int(input("Enter number of times:\n"))
                except Exception as err:
                    pass
                else:
                    decision = input("General message or custom? [g/c]:\n")
                    if decision == "g":
                        choice = input("Are you sure u wanna do this action? [y/n]:\n")
                        if choice == 'y':
                            self.Send_message_to(contacts[key], general_greetings, times)
                        elif choice == 'n':
                            print("Okay, then.")
                            break
                        else:
                            print("not a valid answer.")
                            break
                    elif decision == "c":
                        message = input("Enter message to send:\n")
                        choice = input("Are you sure u wanna do this action? [y/n]:\n")
                        if choice == 'y':
                            self.Send_message_to(contacts[key], message, times)
                        elif choice == 'n':
                            print("Okay, then.")
                            break
                        else:
                            print("not a valid answer.")
                            break
                break
        pause()
        self.MenuFunction()

    def Send_message_to_ALL(self):
        cls()
        if not contacts:
            print("No contacts available.")
            self.MenuFunction()
        print("All of your contacts:")
        for index, key in enumerate(contacts, start=1):
            print("[ {} ]. {} -> {}".format(index, key, contacts[key]))
        try:
            times = int(input("Enter number of times:\n"))
        except Exception as err:
            pass
        else:
            decision = input("General message or custom? [g/c]:\n")
            if decision == "g":
                choice = input("Are you sure u wanna do this action? [y/n]:\n")
                if choice == 'y':
                    for key in contacts:
                        self.Send_message_to(contacts[key], general_greetings, times)
                        time.sleep(sleep_time)
                elif choice == 'n':
                    print("Okay, then.")
                else:
                    print("not a valid answer.")
            elif decision == "c":
                message = input("Enter message to send:\n")
                choice = input("Are you sure u wanna do this action? [y/n]:\n")
                if choice == 'y':
                    for key in contacts:
                        self.Send_message_to(contacts[key], message, times)
                        time.sleep(sleep_time)
                elif choice == 'n':
                    print("Okay, then.")
                else:
                    print("not a valid answer.")
        pause()
        self.MenuFunction()

    def Send_message_to(self, contact, message, times=1):
        """ Sending a wapp message for several times to a specified person"""
        for _ in range(times):
            try:
                # getting contancts
                user = self.driver.find_element_by_xpath("//span[@title = \"{}\"]".format(contact))
                user.click()
                if isinstance(message, list):
                    for line in message:
                        msg_box = self.driver.find_element_by_class_name("_13mgZ")
                        msg_box.send_keys(line)
                        button = self.driver.find_element_by_class_name('_3M-N-')
                        button.click()
                else:
                    msg_box = self.driver.find_element_by_class_name("_13mgZ")
                    msg_box.send_keys(message)
                    button = self.driver.find_element_by_class_name('_3M-N-')
                    button.click()
            except Exception as err:
                print("Ooops we got an exception")
                print(err)
                print(type(err))
            else:
                print("Execution of sending messages with python works successfully.")


# Warning: this script works only for chrome browser and u have to authenticate manually first
if __name__ == '__main__':
    drive = ConnectionDriver()
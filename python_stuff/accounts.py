
import os
import sys
import json

# TODO exception system
class Accounts:

    path_notepad = "D:\\__Alexzander_files__\\supreme_folder\\notepads\\accounts.txt"

    emails = [
        "alexxander18360@gmail.com",
        "playman.ac93@gmail.com",
        "andrew.alexandru14@gmail.com",
        "alexxander360000@gmail.com"
    ]

    keys = ["first_name", "second_name", "username", "email", "password"]
    delimiter = "=" * 10 + '\n'

    # list with json format for every account
    accounts_json_format = []

    # list with real dictionaries for every account
    accounts_dict = []

    def __init__(self):
        input("<Press enter to initialize accounts>")
        self.accounts_json_format, self.accounts_dict = self.Autocomplete_attributes()
        print(self.accounts_json_format)
        print(self.accounts_dict)

    def Autocomplete_attributes(self):
        """Alocates data to the atributes of the class"""
        accounts_json = []
        accounts_dicts = []
        try:
            with open(self.path_notepad, "r+", encoding='utf-8') as accounts_file:
                # creating the json format strings vector
                account = """"""
                line = accounts_file.readline()
                while line:
                    if line != self.delimiter:
                        account += line
                    if line == self.delimiter:
                        accounts_json.append(account)
                        account = """"""
                    line = accounts_file.readline()

                # creating the real dicts with accounts vector
                for acc in accounts_json:
                    accounts_dicts.append(dict(eval(acc)))
                accounts_file.close()
                return accounts_json, accounts_dicts
        except FileNotFoundError as err:
            print(err)
            print(type(err))
            # in case the file doesnt exists we create it
            with open(self.path_notepad, "x+", encoding='utf-8') as accounts_file:
                accounts_file.close()
                return accounts_json, accounts_dicts


    def Search_account(self):
        with open(self.path_notepad, "r+", encoding='utf-8') as accounts_file:
            accounts = []
            dicts = []
            account = """"""
            line = accounts_file.readline()
            while line:
                if line != self.delimiter:
                    account += line
                if line == self.delimiter:
                    accounts.append(account)
                    account = """"""
                line = accounts_file.readline()

            for acc in accounts:
                print(acc)
                dicts.append(dict(eval(acc)))
            print(dicts)

            found = False
            wanted_domain = input("enter a domain:\n")
            for acc in dicts:
                if wanted_domain in acc.keys():
                    found = True
                    print("exista domeniul pe care il cauti")
                    json_format = json.dumps(acc, indent=4)
                    print(json_format)
                    print(type(json_format))
            if not found:
                print("nu ai gasit ce cautai")
            accounts_file.close()



    # TODO create validation for every inputed data
    def Add_account(self):
        with open(self.path_notepad, "a+", encoding='utf-8') as accounts_file:
            account = {}
            domain = input("enter a domain:\n")
            account[domain] = {}
            first_name = input("enter first name:\n")
            second_name = input("enter second name:\n")
            username = input("enter a username:\n")
            for index, email in enumerate(self.emails, start=1):
                print("[{0}]. {1}".format(index, email))

            email_choice = int(input("choose an email:\n"))
            password = input("enter a password:\n")
            inputs = [first_name, second_name, username, self.emails[email_choice - 1], password]

            # creating the dictionary object account
            for index, key in enumerate(self.keys, start=0):
                account[domain][key] = inputs[index]

            # creating the message with json format for dictionary object account
            account_json_format = json.dumps(account, indent=4)
            accounts_file.write(account_json_format + '\n')
            accounts_file.write(self.delimiter)
            self.accounts_json_format.append(account_json_format + '\n')
            self.accounts_dict.append(dict(eval(account_json_format)))
            accounts_file.close()


    def Delete_account(self):
        """Deletes the first encounter"""

        wanted_acc = input("Enter the account that u want to del.\n")
        exists = False
        encounters = 0
        # verifying its existence
        for dict_acc in self.accounts_dict:
            key = str([item for item in dict_acc.keys()][0])
            if wanted_acc == key:
                print(key)
                exists = True
                encounters += 1

        if exists:
            print("Your account appears " + str(encounters) + " times.")

            print(self.accounts_json_format)
            print(self.accounts_dict)

            choice = input("Are you sure? [y/n]:")
            if choice == 'y':
                # here we are deleting the frist encounter
                for dict, json in zip(self.accounts_dict, self.accounts_json_format):
                    key = str([item for item in dict.keys()][0])
                    if wanted_acc == key:
                        self.accounts_dict.remove(dict)
                        self.accounts_json_format.remove(json)
                        break

                print(self.accounts_json_format)
                print(self.accounts_dict)

                with open(self.path_notepad, "w+", encoding='utf-8') as accounts_file:
                    accounts_file.truncate(0)
                    for json in self.accounts_json_format:
                        accounts_file.write(json)
                        accounts_file.write(self.delimiter)
                    accounts_file.close()
            elif choice == 'n':
                print("ok then.")
            else:
                print("not correct input")
        else:
            print("Your input doesnt exists.")

    def Delete_ALL(self):
        print("[DELETE ALL ACCOUNTS]")
        choice = input("Are you sure? [y/n]:")
        if choice == 'y':
            choice = input("Are dobule you sure? [y/n]:")
            if choice == 'y':
                with open(self.path_notepad, "w+", encoding='utf-8') as accounts_file:
                    accounts_file.truncate(0)
                    accounts_file.close()
                    self.accounts_json_format.clear()
                    self.accounts_dict.clear()
            elif choice == 'n':
                print("good")
            else:
                print("not a choice")
        elif choice == 'n':
            print("good")
        else:
            print("not a choice")


    def Update_account(self):
        pass

    def Total_accounts(self):
        total = 0
        with open(self.path_notepad, "r+", encoding='utf-8') as accounts_file:
            line = accounts_file.readline()
            while line:
                line = accounts_file.readline()
                if line == self.delimiter:
                    total += 1
            accounts_file.close()
        return total


    def Open_notepad(self):
        os.system(self.path_notepad)

cls = lambda : os.system("cls")
pau = lambda : os.system("pause")

class Console_interface:

    # class atribute
    # __accounts = Accounts()
    # aici se ruleaza codul indiferent daca se creeaza obiect sau nu

    def __init__(self):
        self.__accounts = Accounts()
        self.Options()

    def Options(self):
        cls()
        print("[1]. List all names")
        print("[2]. List every account")
        print("[3]. Add new account")
        print("[4]. Delete account")
        print("[5]. Total accounts")
        print("[6]. Open text file")
        print("[7]. DELETE ALL ACCOUNTS")
        print("[10]. Exit")

        choice = input("\nEnter a value:\n")
        try:
            choice = int(choice)
        except Exception as err:
            if choice == '':
                self.Options()
            else:
                cls()
                print("something is wrong....")
                print("try again..")
                print(err)
                print(type(err))
                pau()
                self.Options()

        if choice == 1:
            self.Accounts_list()
        elif choice == 2:
            self.List_every_account()
        elif choice == 3:
            self.Add_new_account()
        elif choice == 4:
            self.Delete_account()
        elif choice == 5:
            self.Print_total_accounts()
        elif choice == 6:
            self.Open_accounts_file()
        elif choice == 7:
            self.Delete_all()
        elif choice == 10:
            self.Exit()
        else:
            cls()
            print("something is wrong....")
            print("try again..")
            pau()
            self.Options()


    def Add_new_account(self):
        """Creates a new acc and adds it to the txt file"""
        cls()
        self.__accounts.Add_account()
        print("Your account was successfully created and added to the text file list.")
        pau()
        self.Options()

    def Delete_account(self):
        cls()
        self.__accounts.Delete_account()
        pau()
        self.Options()

    def Accounts_list(self):
        cls()
        print("All of your active accounts.")
        # this is a list with dicts, we iterate it
        for index, dict in enumerate(self.__accounts.accounts_dict, start=1):
            # dict.keys() has only one element
            print("[{}]. {}".format(index, tuple(item for item in dict.keys())[0]))
        pau()
        self.Options()

    def List_every_account(self):
        cls()
        print("All of your accounts in details.")
        for acc in self.__accounts.accounts_json_format:
            print('=' * 100)
            print(acc, end='')
            print('=' * 100)
        pau()
        self.Options()

    def Open_accounts_file(self):
        cls()
        os.system(self.__accounts.path_notepad)
        print("Your file was opened successfully.")
        pau()
        self.Options()

    def Delete_all(self):
        cls()
        self.__accounts.Delete_ALL()
        pau()
        self.Options()

    def Exit(self):
        cls()
        print("Accounts menu was successfully shut down.")
        pau()
        return

    def Print_total_accounts(self):
        cls()
        print(self.__accounts.Total_accounts())
        pau()
        self.Options()


abs_path = "D:\\__Alexzander_files__\\computer_science\\python_stuff\\andrew_packages\\util\\accounts.py"

if __name__ == "__main__":
    menu = Console_interface()
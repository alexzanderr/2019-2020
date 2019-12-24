
import calendar
import time
import os, sys
from datetime import datetime, timedelta
import re
import json
from copy import deepcopy

class CardsDatabase:

    df = "%d.%m.%Y"
    hf = '%H:%M'
    delimiter = "=" * 10 + '\n'
    path_cards = "D:\\__Alexzander_files__\\supreme_folder\\notepads\\cards.txt"

    andrew = "Alexandru Andrew"
    card_type = ['visa', 'mastercard', 'simple']
    card_use = ['banking', 'health', 'gym', 'discount', 'student']

    card_json_formats = []
    card_dicts = []

    def AutoCompleteAttributes(self):
        jsons = []
        dicts = []
        try:
            with open(self.path_cards, "r+", encoding='utf-8') as cards_file:
                card = """"""
                line = cards_file.readline()
                while line:
                    if line != self.delimiter:
                        card += line
                    if line == self.delimiter:
                        jsons.append(card)
                        card = """"""
                    line = cards_file.readline()

                for ev in jsons:
                    dicts.append(dict(eval(ev)))
                cards_file.close()
                return jsons, dicts
        except FileNotFoundError as err:
            with open(self.path_cards, "x+", encoding='utf-8') as cards_file:
                cards_file.close()
                return jsons, dicts

    def __init__(self):
        input("<Press enter to initalize cards database>")
        self.card_json_formats, self.card_dicts = self.AutoCompleteAttributes()
        self.MenuFunction()

    def SeachCard(self):
        cls()
        found = False
        wan = input("<Enter the name of the event you want to find:>\n")
        result = []
        for card, json in zip(self.card_dicts, self.card_json_formats):
            name = card['company'].lower()
            if re.fullmatch(wan, name) and json not in result:
                result.append(json)
            if re.match(wan, name) and json not in result:
                result.append(json)
            if re.search(wan, name) and json not in result:
                result.append(json)
            if re.findall(wan, name) and json not in result:
                result.append(json)

            worst_case = True
            temp = []
            for char in wan:
                if char in name:
                    temp.append(wan.index(char))
            if temp == sorted(temp) and len(wan) == len(temp) and json not in result:
                worst_case = False
                result.append(json)

            if worst_case:
                num = 0
                name_copy = [x for x in name]
                for char in wan:
                    if re.search(char, "".join(name_copy)):
                        num += 1
                        name_copy.remove(char)
                if num == len(wan) and json not in result:
                    result.append(json)

        if result:
            print("< Your result is: >")
            for i, e in enumerate(result, start=1):
                print(f"[ {i} ]:\n")
                print(e)
                print('-' * 50 + '\n')
        else:
            print("<Unfortunately, your wanted card doesnt exist>")
        pau()

    def AddCard(self):
        cls()
        card = {}
        company = input("<Enter company:>\n")
        if company == '':
            self.MenuFunction()
        card['company'] = company

        for i, type in enumerate(self.card_type, start=1):
            print(f"[ {i} ]. {type}")
        card_type = input("\n<Enter card type:>\n")
        try:
            card_type = int(card_type)
        except ValueError:
            self.MenuFunction()
        card_type = self.card_type[card_type - 1]
        card['card_type'] = card_type

        for i, use in enumerate(self.card_use, start=1):
            print(f"[ {i} ]. {use}")
        card_use = input("\n<Enter card use:>\n")
        try:
            card_use = int(card_use)
        except ValueError:
            self.MenuFunction()
        card_use = self.card_use[card_use - 1]
        card['use'] = card_use

        code = input("<Enter card code:>\n")
        if code == 'null':
            pass
        elif not 19 <= len(code) <= 30:
            self.MenuFunction()
        card['code'] = code

        expiration_date = input("<Enter expiration date:>\n")
        try:
            expiration_date = tstruct(expiration_date, self.df)
        except Exception:
            self.MenuFunction()
        card['exp_date'] = tstr(expiration_date, self.df)

        #owner = input("<Enter the owner name:>\n")
        #if not re.fullmatch("[a-zA-z]+\s[a-zA-Z]+", owner):
        #    self.MenuFunction()
        card['owner_name'] = self.andrew

        cvc_code = input("<Enter cvc code:>\n")
        if cvc_code == 'null':
            pass
        elif not re.fullmatch("[0-9]{3}", cvc_code):
            self.MenuFunction()
        card['cvc_code'] = cvc_code

        choice = input("<Do you want a description for the card? [y/n]>")
        if choice == 'y':
            description = input("<Enter description:>\n")
            card['description'] = description
        elif choice == 'n':
            card['description'] = 'null'
        else:
            self.MenuFunction()
        with open(self.path_cards, 'a+', encoding='utf-8') as cards_file:
            card_json = json.dumps(card, indent=4)
            cards_file.write(card_json + '\n')
            cards_file.write(self.delimiter)
            cards_file.close()
            self.card_json_formats.append(card_json + '\n')
            self.card_dicts.append(card)
            print("\nYour inputed card is:")
            print(card_json + '\n')
        pau()

    def DeleteCard(self):
        cls()
        self.PrintAllCards()
        choice = input("\n<Enter the number of the card you want to delete:>\n")
        try:
            choice = int(choice)
            for index, json in enumerate(self.card_json_formats, start=1):
                if choice == index:
                    print("<You want to delete this card:>\n")
                    print(self.card_json_formats[index - 1])
                    choice = input('<Are you sure u wanna perform this action? [y/n]:>\n')
                    if choice == 'y':
                        self.card_dicts.remove(self.card_dicts[index - 1])
                        self.card_json_formats.remove(json)
                        with open(self.path_cards, 'w+', encoding='utf-8') as cards_file:
                            cards_file.truncate(0)
                            for cjs in self.card_json_formats:
                                cards_file.write(cjs)
                                cards_file.write(self.delimiter)
                            cards_file.close()
                    else:
                        self.MenuFunction()
        except Exception:
            self.MenuFunction()
        pau()

    def DeleteAllCards(self):
        cls()
        print("<You want to delete all cards in the database. >")
        decision = input("< Are you sure? [y/n]>\n")
        if decision == 'y':
            double = input("< Are you double sure? [y/n]>\n")
            if double == 'y':
                with open(self.path_events, 'w+', encoding='utf-8') as cards_file:
                    cards_file.truncate(0)
                    cards_file.close()
                    self.card_json_formats.clear()
                    self.card_dicts.clear()
            else:
                self.MenuFunction()
        else:
            self.MenuFunction()
        pau()

    def PrintAllCards(self):
        cls()
        print("<Your available cards are:>\n")
        for i, card in enumerate(self.card_json_formats, start=1):
            print(f"[ {i} ]:\n")
            print(card)
            print('-' * 50 + '\n')

    def NumberOfCards(self):
        return len(self.card_dicts)

    def OpenFile(self):
        os.system(self.path_cards)

    def DisplayInformation(self):
        title = "CardsDatabase"
        TITLE = "_" * 40 + title + "_" * 40 + '\n'
        print(TITLE)
        print(datetime.now().strftime("Current datetime: %H:%M:%S - %d-%m-%Y\n"))

    def Options(self):
        print("[ 1 ]. Add new card")
        print("[ 2 ]. Print ALL cards")
        print("[ 3 ]. Delete a card")
        print("[ 4 ]. Total number of cards")
        print("[ 5 ]. Delete ALL cards")
        print("[ 7 ]. Search for a card")
        print("[ 9 ]. Open file at location")
        print("[ 10 ]. __EXIT__")

    def MenuFunction(self):
        cls()
        self.DisplayInformation()
        self.Options()

        choice = input("\n<Enter something>:\n")
        try:
            choice = int(choice)
            if choice == 1:
                self.AddCard()
                self.MenuFunction()
            elif choice == 2:
                self.PrintAllCards()
                pau()
                self.MenuFunction()
            elif choice == 3:
                self.DeleteCard()
                self.MenuFunction()
            elif choice == 4:
                cls()
                print(f"<Total number of cards is: {self.NumberOfCards()} >")
                pau()
                self.MenuFunction()
            elif choice == 5:
                self.DeleteAllCards()
                self.MenuFunction()
            elif choice == 6:
                self.MenuFunction()
            elif choice == 7:
                self.SeachCard()
                self.MenuFunction()
            elif choice == 8:
                self.MenuFunction()
            elif choice == 9:
                self.OpenFile()
                self.MenuFunction()
            elif choice == 10:
                cls()
                print("<Cards was shut down, thank you for your presence.>")
                return
            else:
                cls()
                print("<Invalid input was detected>\n")
                self.MenuFunction()
        except ValueError:
            if choice == '':
                self.MenuFunction()
            else:
                cls()
                print("<Invalid input was detected>\n")
                self.MenuFunction()

tstruct = lambda x, f : datetime.strptime(x, f)
tstr = lambda x, f : datetime.strftime(x, f)
cls = lambda : os.system("cls")
pau = lambda : os.system("pause")
exitt = lambda : sys.exit(0)

if __name__ == '__main__':
    database = CardsDatabase()
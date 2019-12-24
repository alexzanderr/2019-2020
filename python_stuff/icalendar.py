
import calendar
import time
import os, sys
from datetime import datetime, timedelta
import re
import json
from copy import deepcopy

class iCalendar:
    days = [calendar.day_name[x] for x in range(7)]

    df = "%d.%m.%Y"
    hf = '%H:%M'
    delimiter = "=" * 10 + '\n'
    path_events = "D:\\__Alexzander_files__\\supreme_folder\\notepads\\icalendar.txt"

    event_json_formats = []
    event_dicts = []

    def __init__(self):
        input("<Press enter to initialize iCalendar>")
        self.event_json_formats, self.event_dicts = self.AutoCompleteAttributes()
        self.MenuFunction()

    def AutoCompleteAttributes(self):
        jsons = []
        dicts = []
        try:
            with open(self.path_events, "r+", encoding='utf-8') as events_file:
                event = """"""
                line = events_file.readline()
                while line:
                    if line != self.delimiter:
                        event += line
                    if line == self.delimiter:
                        jsons.append(event)
                        event = """"""
                    line = events_file.readline()

                for ev in jsons:
                    dicts.append(dict(eval(ev)))
                events_file.close()
                return jsons, dicts
        except FileNotFoundError as err:
            with open(self.path_events, "x+", encoding='utf-8') as events_file:
                events_file.close()
                return jsons, dicts

    def SeachEvent(self):
        cls()
        found = False
        wan = input("<Enter the name of the event you want to find:>\n")
        result = []
        for event, json in zip(self.event_dicts, self.event_json_formats):
            name = event['name'].lower()
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
            print("<Unfortunately, your wanted event doesnt exist>")
        pau()

    def AddEvent(self):
        cls()
        event = {}
        oneday_event = True
        choice = input("< One day event? [y/n] >\n")
        if choice == 'n':
            oneday_event = False
        elif choice == '':
            self.MenuFunction()
        if oneday_event:
            name = input("< Enter name: >\n")
            if name == '':
                self.MenuFunction()
            event["name"] = name
            date = input("< Enter date: >\n")
            try:
                date = tstruct(date, self.df)
            except Exception:
                self.MenuFunction()
            event["date"] = tstr(date, self.df)

            time = input("< Enter time: >\n")
            try:
                time = tstruct(time, self.hf)
            except Exception:
                self.MenuFunction()
            event["time"] = tstr(time, self.hf)
            event["dayname"] = calendar.day_name[date.weekday()]

            location = input("<Enter location:>\n")
            event["location"] = location
            choice = input("<Do you wanna add extra info to your event? [y/n]>")
            if choice == 'y':
                info = input("<Enter the extra information:>\n")
                event["description"] = info
            elif choice == 'n':
                event["description"] = "null"
            else:
                self.MenuFunction()
        else:
            name = input("<Enter name:>\n")
            if name == '':
                self.MenuFunction()
            event["name"] = name

            start_date = input("<Enter start date:>\n")
            try:
                start_date = tstruct(start_date, self.df)
            except Exception:
                self.MenuFunction()
            stop_date = input("<Enter stop date:>\n")
            try:
                stop_date = tstruct(stop_date, self.df)
            except Exception:
                self.MenuFunction()

            if start_date > stop_date:
                self.MenuFunction()

            event["start_date"] = tstr(start_date, self.df)
            event["stop_date"] = tstr(stop_date, self.df)

            days_interval = []
            total_days = abs((stop_date - start_date).days)

            # these are time structs
            copy_start_date = deepcopy(start_date)
            copy_stop_date = deepcopy(stop_date)

            while copy_start_date <= copy_stop_date:
                days_interval.append('(' + str(calendar.day_name[copy_start_date.weekday()]) +
                                     ' - ' + str(tstr(copy_start_date, self.df)) + ')')
                copy_start_date += timedelta(days=1)

            event["from"] = ", ".join(days_interval)
            event["days"] = total_days

            start_time = input("< Enter start time: >\n")
            try:
                start_time = tstruct(start_time, self.hf)
            except Exception:
                self.MenuFunction()

            stop_time = input("< Enter stop time: >\n")
            try:
                stop_time = tstruct(stop_time, self.hf)
            except Exception:
                self.MenuFunction()

            if start_time > stop_time:
                self.MenuFunction()

            event["start_time"] = tstr(start_time, self.hf)
            event["stop_time"] = tstr(stop_time, self.hf)
            event["hours"] = abs(int((stop_time - start_time).seconds // 60))

            location = input("< Enter location: >\n")
            event["location"] = location

            choice = input("< Do you wanna add extra info to your event? [y/n] >")
            if choice == 'y':
                info = input("< Enter the extra information: >\n")
                event["description"] = info
            elif choice == 'n':
                event["description"] = "null"
            else:
                self.MenuFunction()

        with open(self.path_events, 'a+', encoding='utf-8') as events_file:
            event_json = json.dumps(event, indent=4)
            events_file.write(event_json + '\n')
            events_file.write(self.delimiter)
            events_file.close()
            self.event_json_formats.append(event_json + '\n')
            self.event_dicts.append(event)
            print("\nYour inputed event is:")
            print(event_json + '\n')
        pau()

    def DeleteEvent(self):
        cls()
        self.PrintAllEvents()
        choice = input("\n< Enter the number of the event you want to delete: >\n")
        try:
            choice = int(choice)
            for index, json in enumerate(self.event_json_formats, start=1):
                if choice == index:
                    print("< You want to delete this event: >\n")
                    print(self.event_json_formats[index - 1])

                    choice = input('< Are you sure u wanna perform this action? [y/n]:>\n')
                    if choice == 'y':
                        event_dict = self.event_dicts[index - 1]
                        event_json = self.event_json_formats[index - 1]
                        self.event_dicts.remove(event_dict)
                        self.event_json_formats.remove(event_json)
                        with open(self.path_events, 'w+', encoding='utf-8') as events_file:
                            events_file.truncate(0)
                            for ejs in self.event_json_formats:
                                events_file.write(ejs)
                                events_file.write(self.delimiter)
                            events_file.close()
                    else:
                        self.MenuFunction()
        except Exception:
            self.MenuFunction()
        pau()

    def DeleteAllEvents(self):
        cls()
        print("<You want to delete all events in the database>")
        decision = input("<Are you sure? [y/n]>\n")
        if decision == 'y':
            double = input("<Are you double sure? [y/n]>\n")
            if double == 'y':
                with open(self.path_events, 'w+', encoding='utf-8') as events_file:
                    events_file.truncate(0)
                    events_file.close()
                    self.event_json_formats.clear()
                    self.event_dicts.clear()
            else:
                self.MenuFunction()
        else:
            self.MenuFunction()
        pau()

    def PrintAllEvents(self):
        cls()
        print("<Your available events are:>\n")
        for e, json in zip(enumerate(self.event_dicts, start=1), self.event_json_formats):
            print(f"[ {e[0]} ]:\n")
            event_format = None
            event = e[1]
            if len(event.keys()) == 6:
                event_format = "Event: {e}, {day} - {date} at {time} located at {location}."
                event_format = event_format.format(e=event["name"], day=event["dayname"], date=event["date"],
                                                   time=event["time"], location=event["location"])
                if event["description"] != 'null':
                    event_format += '\nDescription: {des}'.format(des=event['description'])
            elif len(event.keys()) == 10:
                event_format = "Event: {e}, starts from {day1} - {date1} - {h1} and ends on {day2} - {date2} - {h2} " \
                               "located at {location}.\nInterval: {inter}.\nDays: {days}.\nHours: {hours}."
                event_format = event_format.format(e=event["name"],
                                                   day1=day_name(tstruct(event['start_date'], self.df)),
                                                   date1=event['start_date'],
                                                   h1=event['start_time'],
                                                   day2=day_name(tstruct(event['stop_date'], self.df)),
                                                   date2=event['stop_date'],
                                                   h2=event['stop_time'],
                                                   location=event['location'],
                                                   inter=event['from'],
                                                   days=event['days'],
                                                   hours=event['hours'])
                if event["description"] != 'null':
                    event_format += '\nDescription: {des}'.format(des=event['description'])
            print(event_format + '\n')
            print(json)
            print('-' * 50 + '\n')

    def NumberOfEvents(self):
        return len(self.event_dicts)

    def OpenFile(self):
        os.system(self.path_events)

    def PrintCalendar(self):
        cls()
        year = input("<enter year to print>:")
        try:
            year = int(year)
            print(calendar.calendar(year))
            pau()
        except ValueError:
            if year == '':
                self.MenuFunction()
            else:
                print("[Invalid input was detected]\n")
                self.MenuFunction()

    def UpdateEvent(self):
        pass

    def DisplayInformation(self):
        title = "iCalendar"
        TITLE = "_" * 40 + title + "_" * 40 + '\n'
        print(TITLE)
        print(datetime.now().strftime("Current datetime: %H:%M:%S - %d-%m-%Y\n"))

    def Options(self):
        print("[ 1 ]. Print calendar")
        print("[ 2 ]. Create new event")
        print("[ 3 ]. Print all events")
        print("[ 4 ]. Total number of events")
        print("[ 5 ]. Delete an event")
        print("[ 6 ]. Delete ALL events")
        print("[ 7 ]. Search for event")
        print("[ 9 ]. Open file at location")
        print("[ 10 ]. __EXIT__ iCalendar")

    def MenuFunction(self):
        cls()
        self.DisplayInformation()
        self.Options()

        choice = input("\n<Enter something>:\n")
        try:
            choice = int(choice)
            if choice == 1:
                self.PrintCalendar()
                self.MenuFunction()
            elif choice == 2:
                self.AddEvent()
                self.MenuFunction()
            elif choice == 3:
                self.PrintAllEvents()
                pau()
                self.MenuFunction()
            elif choice == 4:
                cls()
                print(f"<Total number of events is: {self.NumberOfEvents()}>")
                pau()
                self.MenuFunction()
            elif choice == 5:
                self.DeleteEvent()
                self.MenuFunction()
            elif choice == 6:
                self.DeleteAllEvents()
                self.MenuFunction()
            elif choice == 7:
                self.SeachEvent()
                self.MenuFunction()
            elif choice == 9:
                self.OpenFile()
                self.MenuFunction()
            elif choice == 10:
                print("<iCalendar was shut down, thank you for your presence.>")
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

day_name = lambda date : calendar.day_name[date.weekday()]
tstruct = lambda x, f : datetime.strptime(x, f)
tstr = lambda x, f : datetime.strftime(x, f)
cls = lambda : os.system("cls")
pau = lambda : os.system("pause")
exitt = lambda : sys.exit(0)

if __name__ == '__main__':
    cal = iCalendar()
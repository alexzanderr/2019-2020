
import webbrowser as webb
from datetime import datetime
import os, sys
import re

class MusicPlayList:

    __music_playlist = [
        {"Electronic": {
            "Trap": {
                "Songs" : [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "Remixes" : [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "MixesOfHours": [
                    {"song1": "link1"},
                    {"": ""},
                ]
            },
            "Trance": {
                "Songs": [
                    {"Armin-BlahBlahBlah": "https://www.youtube.com/watch?v=mfJhMfOPWdE"},
                    {"": ""},
                ],
                "Remixes": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "MixesOfHours": [
                    {"armin-tiesto-oprah-sound-of-trance": "https://www.youtube.com/watch?v=aoxO5u-oA9U&t=804s"},
                    {"": ""},
                ]
            },
            "House": {
                "Songs": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "Remixes": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "MixesOfHours": [
                    {"bass boosted songs for car 2019": "https://www.youtube.com/watch?v=uPQ0AlPk1Ic"},
                    {"best car music 2017": "https://www.youtube.com/watch?v=O0Pb6i0OAmY&t=1833s"},
                    {"": ""},
                    {"": ""},
                ]
            },
            "Soundtracks": {
                "Songs": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "Remixes": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "MixesOfHours": [
                    {"Epic Badass Hybrid Music | Aggressive Modern Orchestral Mix": "https://www.youtube.com/watch?v=aJ1YH6pXGBg&t=2406s"},
                    {"": ""},
                ]
            },
            "Electronic Dance Music (EDM)" : {
                "Songs": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "Remixes": [
                    {"song1": "link1"},
                    {"": ""},
                ],
                "MixesOfHours": [
                    {"New Electro & House 2013 Best Of EDM Mix": "https://www.youtube.com/watch?v=kzDyx_dLrhc&t=1112s"},
                    {"": ""},
                ]
            },
        }},

    ]

    def __init__(self):
        input("<Press enter to initialize musicapp>")
        self.MenuFunction()

    def DisplayInformation(self):
        title = "musicapp"
        TITLE = "_" * 40 + title + "_" * 40 + '\n'
        print(TITLE)
        print(datetime.now().strftime("Current datetime: %H:%M:%S - %d-%m-%Y\n"))

    def MenuFunction(self):
        cls()
        self.DisplayInformation()
        self.PrintPlayList()
        result = self.SearchEngine()
        if result == 'found':
            choice = input("<Enter something>:\n")
            try:
                choice = int(choice)
                if 1 <= choice <= self.NumberOfSongs():
                    self.OpenSong(choice)
                    self.MenuFunction()
                elif choice == self.NumberOfSongs() + 1:
                    cls()
                    print("<musicapp was shut down>\n")
                    print("Thank you for your time.")
                    return
                else:
                    cls()
                    print("[Invalid input was detected]\n")
                    self.MenuFunction()
            except ValueError:
                if choice == '':
                    self.MenuFunction()
                else:
                    cls()
                    print("[Invalid input was detected]\n")
                    self.MenuFunction()
        elif result == 'exit':
            cls()
            print("<musicapp was shut down>\n")
            print("Thank you for your time.")
            return

    def FindSongs(self, string_input):
        counter = 0
        found_songs = []
        content = [x for x in string_input.lower()]
        for genre in self.__music_playlist:
            for subgenre in list(genre[list(genre.keys())[0]].keys()):
                for option in genre[list(genre.keys())[0]][subgenre].keys():
                    for pair in genre[list(genre.keys())[0]][subgenre][option]:
                        for song in pair.keys():
                            if song != '':
                                counter += 1
                                elem = (counter, song)
                                if re.search(string_input, song.lower()) and elem not in found_songs:
                                    found_songs.append(elem)
                                if re.findall(string_input, song.lower()) and elem not in found_songs:
                                    found_songs.append(elem)

                                # trying to find inclusions of chars in original song
                                worst_case = True
                                temp = []
                                num = 0
                                for char in content:
                                    if char in song.lower():
                                        num += 1
                                        temp.append(song.lower().index(char))
                                if temp == sorted(temp) and len(temp) == len(content) and elem not in found_songs:
                                    worst_case = False
                                    found_songs.append(elem)

                                if re.match(string_input, song.lower()) and elem not in found_songs:
                                    found_songs.append(elem)
                                if re.fullmatch(string_input, song.lower()) and elem not in found_songs:
                                    found_songs.append(elem)

                                # worst case scenario
                                if worst_case:
                                    num = 0
                                    song_copy = [x for x in song.lower()]
                                    for char in list(content):
                                        if re.search(char, "".join(song_copy)):
                                            num += 1
                                            song_copy.remove(char)
                                    if num == len(content) and elem not in found_songs:
                                        found_songs.append(elem)
        return found_songs

    def SearchEngine(self):
        choice = input("<Find something or open something>:\n")
        try:
            choice = int(choice)
            if 1 <= choice <= self.NumberOfSongs():
                self.OpenSong(choice)
                self.MenuFunction()
            elif choice == self.NumberOfSongs() + 1:
                return "exit"
            else:
                print("Invalid input was caught.")
                self.MenuFunction()
        except ValueError:
            if choice == '':
                self.MenuFunction()
            else:
                found_songs = self.FindSongs(choice)
                if found_songs:
                    for song in found_songs:
                        print(f"[ {song[0]} ]. {song[1]}")
                    print()
                    return "found"
                else:
                    print("[Nothing found from your search...]\n")
                    self.MenuFunction()

    def PrintPlayList(self):
        counter = 1
        for genre in self.__music_playlist:
            print('\\\\\\\\\\' + '_' * 50)
            print(f"[{list(genre.keys())[0]}]:")
            for subgenre in list(genre[list(genre.keys())[0]].keys()):
                print(f"  _{subgenre}_:")
                for option in genre[list(genre.keys())[0]][subgenre].keys():
                    print(f"    _{option}_:")
                    for pair in genre[list(genre.keys())[0]][subgenre][option]:
                        for song in pair.keys():
                            if song != '':
                                print(f"      [ {counter} ]. {song}")
                                counter += 1
            print('//////////' + '_' * 50 + '\n')

    def NumberOfSongs(self):
        counter = 0
        for genre in self.__music_playlist:
            for subgenre in list(genre[list(genre.keys())[0]].keys()):
                for option in genre[list(genre.keys())[0]][subgenre].keys():
                    for pair in genre[list(genre.keys())[0]][subgenre][option]:
                        for song in pair.keys():
                            if song != '':
                                counter += 1
        return counter

    def OpenSong(self, choice):
        counter = 1
        for genre in self.__music_playlist:
            for subgenre in list(genre[list(genre.keys())[0]].keys()):
                for option in genre[list(genre.keys())[0]][subgenre].keys():
                    for pair in genre[list(genre.keys())[0]][subgenre][option]:
                        for song in pair.keys():
                            if song != '':
                                if choice == counter:
                                    webb.open(pair[song])
                                    return
                                counter += 1

cls = lambda : os.system("cls")
pau = lambda : os.system("pause")
exitt = lambda : sys.exit(0)

if __name__ == '__main__':
    playlist = MusicPlayList()
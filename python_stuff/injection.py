
import os
import sys
from datetime import datetime

cls = lambda : os.system("cls")
pau = lambda : os.system("pause")

class DriveInjector:

    def __init__(self):
        self.drive_string = """"""
        self.additional_path = "__Alexzander_files__\\computer_science\\python_stuff"
        self.path_to_save = "D:\\drive_storage.txt"
        self.MenuFunction()

    def DisplayTimeTitle(self):
        title = "DriveInjector"
        TITLE = '_' * 25 + title + '_' * 25 + '\n'
        print(datetime.now().strftime("Current time: [____%H:%M:%S____%D-%M-%Y____]").rjust(50))

    def Options(self):
        self.DisplayTimeTitle()
        print("[ 1 ]. Save Storage From Drive")
        print("[ 2 ]. Print Storage From Drive")
        print("[ 3 ]. Save To Folder")
        print("[ 4 ]. Open File")
        print("[ 5 ]. Delete Existing File")
        print("[ 10 ]. Exit\n")

    def MenuFunction(self):
        cls()
        self.Options()
        choice = input("<choose your action>:\n")
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
                cls()
                self.SaveStorageFromDrive(additional_path=self.additional_path)
                pau()
                self.MenuFunction()
            elif choice == 2:
                cls()
                self.PrintStorageFromDrive(additional_path=self.additional_path)
                pau()
                self.MenuFunction()
            elif choice == 3:
                cls()
                self.SaveToFolder()
                pau()
                self.MenuFunction()
            elif choice == 4:
                cls()
                self.OpenFile()
                pau()
                self.MenuFunction()
            elif choice == 5:
                cls()
                self.DeleteExistingFile()
                pau()
                self.MenuFunction()
            elif choice == 10:
                cls()
                print("[Injector was shut down.]")
                # pau()
                return
            else:
                cls()
                print("[Invalid input]\n")
                pau()
                self.MenuFunction()

    def SaveItemsFromDrive(self, path, spacing):
        try:
            list_file = os.listdir(path)
        except Exception:
            pass
        else:
            for file in list_file:
                if os.path.isfile(path + "\\" + file):
                    file_name = file.rjust(len(file) + spacing + 3)
                    self.drive_string += file_name + '\n'
                else:
                    folder_name = file.rjust(len(file) + spacing + 3)
                    self.drive_string += folder_name + '\n'
                    r_paran = "[".rjust(len("") + spacing + 4)
                    self.drive_string += r_paran + '\n'
                    self.SaveItemsFromDrive(path + "\\" + file, spacing + 3)
                    l_paran = "]".rjust(len("") + spacing + 4)
                    self.drive_string += l_paran + '\n'

    def PrintItemsFromDrive(self, path, spacing):
        try:
            list_file = os.listdir(path)
        except Exception:
            pass
        else:
            for file in list_file:
                if os.path.isfile(path + "\\" + file):
                    file_name = file.rjust(len(file) + spacing + 3)
                    print(file_name)
                else:
                    folder_name = file.rjust(len(file) + spacing + 3)
                    print(folder_name)
                    r_paran = "[".rjust(len("") + spacing + 4)
                    print(r_paran)
                    self.PrintItemsFromDrive(path + "\\" + file, spacing + 3)
                    l_paran = "]".rjust(len("") + spacing + 4)
                    print(l_paran)

    def SaveStorageFromDrive(self, drive='D', additional_path=None, spacing=1):
        absolute_path = f"{drive}:\\"
        if additional_path is not None:
            absolute_path += additional_path
        self.drive_string += f"Your target's storage information on {absolute_path}:\n[\n"
        self.SaveItemsFromDrive(absolute_path, spacing)
        self.drive_string += ']\n'

    def PrintStorageFromDrive(self, drive='D', additional_path=None, spacing=1):
        abs_path = f"{drive}:\\"
        if additional_path:
            abs_path += additional_path
        print(f"Your target's storage information on {abs_path}:")
        print('[')
        self.PrintItemsFromDrive(abs_path, spacing)
        print(']')

    def SaveToFolder(self):
        if self.drive_string:
            try:
                with open(self.path_to_save, "x+", encoding="utf-8") as file:
                    file.writelines(self.drive_string)
                    file.close()
            except FileExistsError as err:
                print("Your file already exists, so we will overwrite it.")
                with open(self.path_to_save, "w+", encoding="utf-8") as file:
                    file.truncate(0)
                    file.writelines(self.drive_string)
                    file.close()

    def OpenFile(self):
        try:
            os.system(self.path_to_save)
        except Exception:
            print("So we have an error here.")

    def DeleteExistingFile(self):
        d = input("Are you sure? [y/n]")
        if d == 'y':
            try:
                os.remove(self.path_to_save)
                print("File deleted successfully.")
            except Exception:
                print("So we have an error here.")

if __name__ == "__main__":
    inj = DriveInjector()
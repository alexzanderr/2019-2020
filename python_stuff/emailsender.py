
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import webbrowser
import os, sys
from datetime import datetime
from collections import OrderedDict

cls = lambda : os.system("cls")
pau = lambda : os.system("pause")

class Messages:
    expp = "An exception has occured in your program."
    err = "Ooooops an error has occured in the system."
    inputt = "The input you inserted is invalid."
    abortt = "Action aborted by choice."
    exit = "Email Sender was shut down. Thank you for you time!"
    def Err(self):
        print(self.err)
    def Inn(self):
        print(self.inputt)
    def Abb(self):
        print(self.abortt)
    def Expp(self):
        print(self.expp)
    def Exitt(self):
        print(self.exit)

class EmailSender:

    # my account
    MY_EMAIL = "N\A"
    MY_PASS = "N\A"

    # some targets
    EMAILS = {
        "N\A": "N\A",
    }

    URLS = {
        "N\A": "N\A"
    }

    LIMIT = 50

    general_message = """
        Type of encryption used: TLS(Transport layer security) - standard encryption
        This __message was sent with python programming language using simple mail transfer protocol library (smtplib).
        Thank you for your attention!
        Have a great day!
        Bye.
    """

    custom_built = []

    def __init__(self):
        self.m = Messages()
        c = EmailMessages()
        self.custom_built = c.ReturnList()
        del c
        input("Press enter to initialize the Email Sender 2020.")
        choice = input("Do you want to open the 'Less secure apps webpage'? [y or something else]:")
        if choice == 'y':
            webbrowser.open(self.URLS["lessecure"])
            print("Less secure apps page was opened successfully.")
        self.MenuFunction()

    def Options(self):
        title = "EmailSender"
        TITLE = '_' * 25 + title + '_' * 25 + '\n'
        print(TITLE)
        print(datetime.now().strftime("The actual time:[____%H:%M:%S____%D-%M-%Y____]\n").rjust(45))
        print("[ 1 ]. Send mail to specific person.")
        print("[ 2 ]. Exit.\n")

    def MenuFunction(self):
        cls()
        self.Options()
        choice = input("Your willings are above to be chosen:\n")
        try:
            choice = int(choice)
        except (ValueError, TypeError) as err:
            if choice == '':
                self.MenuFunction()
            else:
                self.m.Exp()
                self.MenuFunction()
        else:
            if choice == 1:
                self.SendMailFunction()
            elif choice == 2:
                self.ExitFunction()
            else:
                self.m.Inn()
                self.MenuFunction()

    def SendMailFunction(self):
        cls()
        print("Your entire contact list:\n")
        for index, person in enumerate(self.EMAILS, start=1):
            print(f"[ {index} ]. {person} --> {self.EMAILS[person]}")
        choice = input("\nSelect person to send mail:\n")
        try:
            choice = int(choice)
        except (ValueError, TypeError) as err:
            if choice == '':
                self.SendMailFunction()
            elif choice == 'abort':
                self.m.Abb()
                self.MenuFunction()
            else:
                self.m.Inn()
                self.SendMailFunction()
        else:
            if 1 <= choice <= len(self.EMAILS.keys()):
                for index, person in enumerate(self.EMAILS, start=1):
                    if index == choice:
                        print(f"You selected: {person} ---- {self.EMAILS[person]}\n")
                        choice = input("Do you prefer a custom-built __message or general __message? [c/g]:\n")
                        if choice == 'c':
                            choice = input("Do you want to choose an existent custom built __message? [y/n]:\n")
                            if choice == 'y':
                                print("Your existent custom-built messages are:\n")
                                for it, mail_content in enumerate(self.custom_built, start=1):
                                    print('-' * 100)
                                    print(f"Custom-built __message number {it}:\n")
                                    print(f"The subject is: {mail_content['subject']}\n")
                                    print("The __message is:\n")
                                    print(mail_content['__message'])
                                    print('-' * 100)
                                choice = input("\nSelect the number of your mail content to send to the contact:\n")
                                try:
                                    choice = int(choice)
                                except ValueError as err:
                                    if choice == '':
                                        self.SendMailFunction()
                                    elif choice == 'abort':
                                        self.m.Abb()
                                        self.MenuFunction()
                                    else:
                                        self.m.Inn()
                                        self.SendMailFunction()
                                else:
                                    if 1 <= choice <= len(self.custom_built):
                                        for it, mail_content in enumerate(self.custom_built, start=1):
                                            if choice == it:
                                                print(f"You selected the mail content number {it}.\n")
                                                print(f"Contact receiver is: {person} --- {self.EMAILS[person]}")
                                                print('-' * 100)
                                                print(f"The subject is: {mail_content['subject']}\n")
                                                print("The __message is:\n")
                                                print(mail_content['__message'])
                                                print('-' * 100)
                                                times = input("\nSelect number of times you want to send this mail content:\n")
                                                try:
                                                    times = int(times)
                                                except ValueError as err:
                                                    if times == '':
                                                        self.SendMailFunction()
                                                    elif times == 'abort':
                                                        self.m.Abb()
                                                        self.MenuFunction()
                                                    else:
                                                        self.m.Inn()
                                                        self.SendMailFunction()
                                                else:
                                                    if 1 <= times <= self.LIMIT:
                                                        decision = input("\nAre you sure you want to perform this action? [y/n]:\n")
                                                        if decision == 'y':
                                                            for _ in range(times):
                                                                self.SendEmailTo(sender_address=self.MY_EMAIL,
                                                                                 sender_password=self.MY_PASS,
                                                                                 reciever_address=self.EMAILS[person],
                                                                                 subject=mail_content["subject"],
                                                                                 mail_content=mail_content["__message"])
                                                            print("\nYour action was successfully performed.")
                                                            print("Going back to the interface...\n")
                                                            pau()
                                                            self.MenuFunction()
                                                        elif decision == 'n':
                                                            print(
                                                                "Your __message was deleted and the action was aborted.")
                                                            self.MenuFunction()
                                                        else:
                                                            self.m.Inn()
                                                            self.SendMailFunction()
                                                    else:
                                                        self.m.Inn()
                                                        self.SendMailFunction()
                                    else:
                                        self.m.Inn()
                                        self.SendMailFunction()
                            elif choice == 'n':
                                subject = input("What is the subject of the mail?\n")
                                lines = input("How many lines you want the __message to have? [ 1 -> 10(max) ]:\n")
                                try:
                                    lines = int(lines)
                                except ValueError as err:
                                    if lines == '':
                                        self.SendMailFunction()
                                    elif lines == 'abort':
                                        self.m.Abb()
                                        self.MenuFunction()
                                    else:
                                        self.m.Inn()
                                        self.SendMailFunction()
                                else:
                                    if 1 <= lines <= 10:
                                        text = """"""
                                        print("Insert the whole text into this separated lines:\n")
                                        for line in range(lines):
                                            text += input(f"Enter line number {line + 1}:")
                                            text += '\n'
                                        print("\nYour custom-built inputed mail content is:\n")
                                        print(f"Subject: {subject}\n")
                                        print("Containings:\n")
                                        print(text)
                                        times = input("\nSelect number of times you want to send this text:\n")
                                        try:
                                            times = int(times)
                                        except ValueError as err:
                                            if times == '':
                                                self.SendMailFunction()
                                            elif times == 'abort':
                                                self.m.Abb()
                                                self.MenuFunction()
                                            else:
                                                self.m.Inn()
                                                self.SendMailFunction()
                                        else:
                                            if 1 <= times <= self.LIMIT:
                                                decision = input("\nAre you sure you want to perform this action? [y/n]:\n")
                                                if decision == 'y':
                                                    for _ in range(times):
                                                        self.SendEmailTo(sender_address=self.MY_EMAIL,
                                                                         sender_password=self.MY_PASS,
                                                                         reciever_address=self.EMAILS[person],
                                                                         subject=subject,
                                                                         mail_content=text)
                                                    print("\nYour action was successfully performed.")
                                                    print("Going back to the interface...\n")
                                                    pau()
                                                    self.MenuFunction()
                                                elif decision == 'n':
                                                    print("Your __message was deleted and the action was aborted.")
                                                    self.MenuFunction()
                                                else:
                                                    self.m.Inn()
                                                    self.SendMailFunction()
                                            else:
                                                self.m.Inn()
                                                self.SendMailFunction()
                                    else:
                                        self.m.Inn()
                                        self.SendMailFunction()
                            else:
                                print("This is not a valid option.")
                                self.SendMailFunction()
                        elif choice == 'g':
                            subject = "Just an email test send with python."
                            text = self.general_message
                            print("\nYour mail content is:\n")
                            print(f"Subject: {subject}\n")
                            print("Containings:\n")
                            print(text)
                            times = input("\nSelect number of times you want to send this text:\n")
                            try:
                                times = int(times)
                            except ValueError as err:
                                if times == '':
                                    self.SendMailFunction()
                                elif times == 'abort':
                                    self.m.Abb()
                                    self.MenuFunction()
                                else:
                                    self.m.Inn()
                                    self.SendMailFunction()
                            else:
                                if 1 <= times <= self.LIMIT:
                                    decision = input("\nAre you sure you want to perform this action? [y/n]:\n")
                                    if decision == 'y':
                                        for _ in range(times):
                                            self.SendEmailTo(sender_address=self.MY_EMAIL,
                                                             sender_password=self.MY_PASS,
                                                             reciever_address=self.EMAILS[person],
                                                             subject=subject,
                                                             mail_content=text)
                                        print("\nYour action was successfully performed.")
                                        print("Going back to the interface...\n")
                                        pau()
                                        self.MenuFunction()
                                    elif decision == 'n':
                                        print("Your __message was deleted and the action was aborted.")
                                        self.MenuFunction()
                                    else:
                                        self.m.Inn()
                                        self.SendMailFunction()
                                else:
                                    self.m.Inn()
                                    self.SendMailFunction()
                        elif choice == 'abort':
                            self.m.Abb()
                            self.MenuFunction()
                        else:
                            self.m.Inn()
                            self.SendMailFunction()
            else:
                self.m.Inn()
                self.SendMailFunction()

    def ExitFunction(self):
        cls()
        self.m.Exitt()
        #pau()
        sys.exit(0)

    def SendEmailTo(self, sender_address,
                   sender_password,
                   reciever_address,
                   subject,
                   mail_content,
                   file_location=None):
        # setup MIME short for multipurpose internet mail extensions
        message = MIMEMultipart()
        message['From'] = sender_address
        message['To'] = reciever_address
        message['Subject'] = subject
        message.attach(MIMEText(mail_content, 'plain'))
        # setup the attachment

        if file_location is not None:
            # file location contatins the path and the file name
            file_read = open(file_location, 'rb')
            pay_load = MIMEBase('application', 'octate-stream')
            pay_load.set_payload(file_read.read())
            encoders.encode_base64(pay_load)
            pay_load.add_header('Content-Decomposition', 'attachment', filename=file_location)
            message.attach(pay_load)

        # setup server login
        try:
            server = smtplib.SMTP('smtp.gmail.com', 587)
            server.starttls()
            server.login(sender_address, sender_password)
            content = message.as_string()
            server.sendmail(sender_address, reciever_address, content)
            server.quit()
            print(f"Email sent to '{reciever_address}' with success!")
        except Exception as e:
            print(type(e))
            print("Mail failed to sent!")
            print("There may be a problem with the system or you dont have less secure apps activated.")

class EmailMessages:

    custom_built = []



    def ReturnList(self):
        return self.custom_built

if __name__ == "__main__":
    sender = EmailSender()
else:
    print("Email protocol can't be used from import[Not yet]")
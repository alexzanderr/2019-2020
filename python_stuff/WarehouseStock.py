
"""
    @auth: Alexandru Andrew
    cerinte rezolvate:
     1 pygal,
     4 regex,
     9(2 metode creations-built) - aici in loc de 2 metode am scris un intreb meniu care contine 6 metode,
     3(dar nu se vede extensia de fisier in mail, deci nu se pune)
"""

from datetime import datetime, timedelta
import re as regex
import pygal
import getpass
import os
import sys
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import random

CATEGORII = {
    'carnuri' : ['carnati', 'sunca', 'salam'],
    'jucarii' : ['mingi', 'supererou', 'avioane'],
    'calculatoare' : ['laptop', 'desktop', 'raspberryPI'],
    'electrocasnice' : ['toaster', 'aragaz', 'frigider']
}
UNITATI = ['bucata', 'kilogram', 'litru']

DATETIME_FORMAT = "%d.%m.%Y"

MY_PATH = "N\A"
PAUL_PATH = "N\A"

# sfat: rulati modulul cu browserul default deja deschis
class Stoc:
    """Tine stocul unui depozit de produse"""
    __lista_produse = [] # e de forma: [produs1, produs2, produs3, ....]
    dictionar_categorii = {} # e de forma: {categorie1 : [produs1, produs2, ...], categorie2 : [.....]}
    __total_produse = 0
    __total_categorii = 0
    __unitati_de_masura = {'buc' : 'bucata', 'kg' : 'kilogram', 'l' : 'litru'}

    # self.dictionar_miscari este de forma
    # {cheie_numerica1 : (data, intrare, iesire), cheie_numerica2 : (data, intrare, iesire) ....}

    def __init__(self, denumire_produs, categorie, unitate_de_masura = 'buc', sold = 0):
        """Doar un simplu constructor
            :param denumire_produs
            :param categorie
            :param unitate_de_masura
            :param sold
            parametrii sunt validati
            daca nu sunt corecti se arunca eroare de instantiere
        """

        if not self.Valideaza_denumire_produs(denumire_produs) \
            or not self.Valideaza_categorie(categorie) \
            or not self.Valideaza_unitate_masura(unitate_de_masura) \
            or not self.Valideaza_sold(sold):
            print("Datele introduse: {0}, {1}, {2}, {3} "
                  "sunt invalide".format(denumire_produs, categorie, unitate_de_masura, sold))
            raise InterruptedError

        self.denumire_produs = denumire_produs
        self.categorie = categorie
        self.unitate_de_masura = unitate_de_masura
        self.sold = sold

        Stoc.__total_produse += 1
        if self.categorie not in Stoc.dictionar_categorii.keys():
            Stoc.__total_categorii += 1

        self.dictionar_miscari = {} # acesta va contine tupluri pentru miscari din depozit
        # este de forma (data intrarii sau iesirii, numarul de intrari, numarul de iesiri)
        self.lista_produse = Stoc.__lista_produse
        self.dictionar_categorii = Stoc.dictionar_categorii
        self.lista_produse.append(self.denumire_produs)
        if self.categorie in self.dictionar_categorii.keys():
            self.dictionar_categorii[self.categorie] += [self.denumire_produs]
        else:
            self.dictionar_categorii[self.categorie] = [self.denumire_produs]

    def Valideaza_denumire_produs(self, denumire_produs):
        """ Foloseste regex pentru validare nume produse
            un produs poate sa aiba 'litere', 'cifre' si '-', nimic altceva
            se presupune ca denumire_produs este message
        """
        if denumire_produs is None:
            return False
        if type(denumire_produs) != str:
            return False
        denumire = denumire_produs.strip()
        if not regex.fullmatch("[a-z \- A-Z \- 0-9]+", denumire):
            return False
        return True

    def Valideaza_categorie(self, categorie):
        """ Foloseste regex pentru validare categorie
            o cateogrie poate sa ai 'litere' si '-', nimic altceva
        """
        if categorie is None:
            return False
        if type(categorie) != str:
            return False
        categ = categorie.strip()
        if not regex.fullmatch("[a-z \- A-Z \-]+", categ):
            return False
        return True

    def Valideaza_unitate_masura(self, unitate_de_masura):
        """Daca unit de mas nu face parte din lista clasei -> return False"""
        if unitate_de_masura is None:
            return False
        if type(unitate_de_masura) != str:
            return False
        unit = unitate_de_masura.strip()
        if not regex.fullmatch("[a-z]+|[A-Z]+", unit):
            return False
        unit = unit.lower()
        if unit not in Stoc.__unitati_de_masura.keys() \
            and unit not in Stoc.__unitati_de_masura.values():
            return False
        return True

    def Valideaza_sold(self, sold):
        """Cand un produs se instantiaza nu are voie soldul sa fie negativ"""
        if sold is None:
            return False
        try:
            sold_c = int(sold)
        except (TypeError, ValueError):
            return False
        if sold_c < 0:
            return False
        return True

    def Valideaza_cant(self, cantitate):
        """Cand se creeaza o tranzactie cantitatea nu poate sa fie negativa"""
        if cantitate is None:
            return False
        if type(cantitate) != int:
            return False
        if cantitate < 0:
            return False
        return True

    def Valideaza_data(self, data):
        """Incearca sa o converteasca la formatul :globals() DATETIME_FORMAT
            eroare daca nu poate
            daca reuseste inseamna ca este formatul corect si data calendaristica corecta
        """
        # Atentie, data este un message introdus de contact sau programator, NU datetime object
        if data is None:
            return False
        if type(data) != str:
            return False
        try:
            datetime.strptime(data, DATETIME_FORMAT)
            return True
        except ValueError:
            return False

    def Validare_interval(self, data_start, data, data_sfarsit):
        """Returneaza daca :param data_start <= :param data <= :param data_sfarsit
           Tipul de formatare: '%d.%m.%Y'
        """
        data_start = datetime.strptime(data_start, DATETIME_FORMAT)
        data = datetime.strptime(data, DATETIME_FORMAT)
        data_sfarsit = datetime.strptime(data_sfarsit, DATETIME_FORMAT)
        if data_start <= data <= data_sfarsit:
            return True
        return False

    # cerinta 4 cu regex
    def Cauta_produs(self):
        """Se utilizeaza regex pentru cautarea unui produs introdus de la tastatura"""
        print('=' * 120)
        print("Cautare in depozit a unui produs introdus de la tastatura.")
        print('-' * 120)
        repeta = True
        produs_input = None
        while repeta:
            repeta = False
            produs_input = input("Introduceti un produs de la tastatura pentru a fi cautat.\n"
                                 "Atentie, scrieti numele exact al produsului:\n"
                                 "Daca vreti sa iesiti din sistemul de cautare, tastati 'exit'\n")
            if produs_input == 'exit':
                print("Iesire din cautare a fost efectuata cu succes")
                print('=' * 120)
                print('\n')
                return
            if not self.Valideaza_denumire_produs(produs_input):
                print("Nume de produs invalid, try again")
                repeta = True
                print('-' * 120)
        # cauta daca exista sau nu in lista
        # e de forma: [produs1, produs2, produs3, ....]
        gasit = False
        for produs in Stoc.__lista_produse:
            if regex.match(produs_input, produs):
                print("Produsul '{0}' exista in stocul depozitului.".format(produs_input))
                gasit = True
                break
        if not gasit:
            print("Produsul '{0}' NU exista in stocul depozitului.".format(produs_input))
        print('=' * 120)
        print('\n')

    # cerinta 4 metoda 1
    # nu pot sa folosesc regex daca vreau sa caut un int in dictionar_miscari :(
    def Cauta_tranzactie_cantitate(self):
        """ Nu are parametrii
            Se introduce o cantitate de la tastatura
            Se cauta in depozit daca exista iesiri si intrari cu acea 'cantitate', le afiseaza daca exista
            Salveaza in 2 liste tot ce a gasit sau nimic in caz contrar
            Printeaza listele la final
        """
        print('=' * 120)
        print("Cautare in tranzactiile din depozit pentru cantitatea introdusa de la tastatura")
        print('-' * 120)
        repeta = True
        cantitate_input = None
        while repeta:
            repeta = False
            try:
                cantitate_input = int(input("Introduceti o cantitate pentru a fi procesata:\n"))
                if cantitate_input <= 0:
                    print("Canitatea nu poate fi negativa sau 0")
                    repeta = True
            except (ValueError, TypeError):
                print("Tip de date invalid, trebuie doar numar intreg")
                repeta = True
        # cauta daca exista in dictionar in tuplu self.dictionar_miscari[cheie][1 sau 2]
        # self.dictionar_miscari este de forma
        # {cheie_numerica1 : (data, intrare, iesire), cheie_numerica2 : (data, intrare, iesire) ....}
        lista_intrari = []
        lista_iesiri = []
        for cheie in self.dictionar_miscari.keys():
            if cantitate_input == self.dictionar_miscari[cheie][1]:
                lista_intrari.append(self.dictionar_miscari[cheie])

            if cantitate_input == self.dictionar_miscari[cheie][2]:
                lista_iesiri.append(self.dictionar_miscari[cheie])

        if lista_intrari:
            print("Avem aici tranzactii de intrare in depozit pentru: {0}".format(cantitate_input))
            for tranzactie in lista_intrari:
                print(tranzactie)
        else:
            print("Nu exista in depozit nicio tranzactie de intrare cu cantitatea: {0}".format(cantitate_input))
        if lista_iesiri:
            print("Avem aici tranzactii de iesire in depozit pentru: {0}".format(cantitate_input))
            for tranzactie in lista_iesiri:
                print(tranzactie)
        else:
            print("Nu exista in depozit nicio tranzactie de intrare cu cantitatea: {0}".format(cantitate_input))
        print('=' * 120)
        print("\n")

    # cerinta 4 cu regex: metoda 2
    def Cauta_tranzactie_data(self):
        """Se utilizeaza regex pentru cautarea unei tranzactii introduse de la tastatura
            format exclusiv: 'dd.mm.yyyy'
            dar pentru simplitate utilizatorul poate introduce si ddmmyyyy
        """
        def Val_dat(data):
            """Aici putem primi format simplu ddmmyyyy
                :param data este automat message de la input
                aici validam pentru 8 caractere si 10 caractere
                validare creations-built
            """
            if data is None:
                return False
            if len(data) == 10:
                try:
                    datetime.strptime(data, DATETIME_FORMAT)
                    return data
                except ValueError:
                    return False
            elif len(data) == 8:
                try:
                    int(data)
                except TypeError:
                    return False
                lista_data = []  # are maxim 8 caractere
                for caracter in data:
                    lista_data.append(caracter)
                zi = lista_data[0] + lista_data[1]
                luna = lista_data[2] + lista_data[3]
                an = lista_data[4] + lista_data[5] + lista_data[6] + lista_data[7]
                data_calen = zi + '.' + luna + '.' + an
                try:
                    datetime.strptime(data_calen, DATETIME_FORMAT)
                    return data_calen
                except ValueError:
                    return False
            else:
                return False
            # end inner function
        print('=' * 120)
        print("Cautare in tranzactiile din depozit pentru data introdusa de la tastatura")
        print('-' * 120)
        repeta = True
        tranzactie_input = None
        while repeta:
            repeta = False
            tranzactie_input = input("Introduceti o tranzactie de la tastatura pentru a fi cautata.\n"
                                     "Atentie, format tranzactie 'dd.mm.yyyy' sau 'ddmmyyy' pentru simplitate :\n"
                                     "Daca vrei sa iesiti din cautare, tastati 'exit'\n")
            if tranzactie_input == 'exit':
                print("Iesirea din cautare a fost efectuata cu succes")
                print('=' * 120)
                print('\n')
                return

            if not Val_dat(tranzactie_input):
                print("Tranzactie invalida, zic ca data viitoare ar trebui sa introduci corect.")
                repeta = True
            print('-' * 120)
        tranzactie_input = Val_dat(tranzactie_input)
        # cauta daca exista in dictionar in tuplu self.dictionar_miscari[cheie][0]
        # self.dictionar_miscari este de forma
        # {cheie_numerica1 : (data, intrare, iesire), cheie_numerica2 : (data, intrare, iesire) ....}
        gasit = False
        for cheie in self.dictionar_miscari.keys():
            if regex.match(tranzactie_input, self.dictionar_miscari[cheie][0]):
                print("Tranzactia la data '{0}' a fost "
                      "indentificata in dictionarul de miscari.".format(tranzactie_input))
                gasit = True
                break

        if gasit:
            print('-' * 120)
            print("Toate tranzactiile efectuate la data: {0}".format(tranzactie_input))
            for cheie in self.dictionar_miscari.keys():
                if tranzactie_input == self.dictionar_miscari[cheie][0]:
                    if type(self.dictionar_miscari[cheie][1]) == int:
                        print(self.dictionar_miscari[cheie], '||---->', 'intrare')
                    elif type(self.dictionar_miscari[cheie][1]) == str:
                        print(self.dictionar_miscari[cheie], '||---->', 'iesire')
        else:
            print("Tranzactia '{0}' NU a fost indentificata in dictionarul de miscari.".format(tranzactie_input))
        print('=' * 120)
        print('\n')

    # cerinta 1: proiecte grafica cu pygal
    def Afisaj_tranzactii(self,
                          data_start = '01.01.1900',
                          data_stop = str(datetime.now().strftime(DATETIME_FORMAT))):
        """ Aceasta functie creeaza o proiectie grafica pentru toate tranzactiie din depozit.
            Apoi salveaza intr un fisier .svg si deschide acel fisier in driver
        """
        # interval afisare: start <= grafic <= stop
        date_datetime = []
        for cheie in self.dictionar_miscari.keys():
            data_str = self.dictionar_miscari[cheie][0]
            data_struct = datetime.strptime(data_str, DATETIME_FORMAT)
            if data_struct not in date_datetime and self.Validare_interval(data_start, data_str, data_stop):
                date_datetime.append(data_struct)

        date_datetime.sort() # vrem sa fie sortate corect
        # pentru ca sortarea pe stringuri care sunt date calendaristice nu merge intotdeauna perfect
        date_calen = []
        for data_datetime in date_datetime:
            date_calen.append(datetime.strftime(data_datetime, DATETIME_FORMAT))
        dict_plot = {} # e de forma {data1 : (total_intari1, total_iesiri1), ....}
        lista_intari = []
        lista_iesiri = []
        # indecsii acestor doua corespund si corespund cu indecsii din date_calen
        for data in date_calen:
            suma_intrari = 0
            suma_iesiri = 0
            for cheie in self.dictionar_miscari.keys():
                tuplu_trzc = self.dictionar_miscari[cheie] # (data, intrari, iesiri)
                if tuplu_trzc[0] == data:
                    if type(tuplu_trzc[1]) == int:
                        suma_intrari += tuplu_trzc[1]
                    elif type(tuplu_trzc[2]) == int:
                        suma_iesiri += tuplu_trzc[2]
            dict_plot[data] = (suma_intrari, suma_iesiri)

        tranzactii_chart = pygal.Line()
        tranzactii_chart.title = "Proiectia grafica pentru toate tranzactiile asupra " \
                                 "produsului '{0}'".format(self.denumire_produs)
        tranzactii_chart.x_labels = date_calen
        tranzactii_chart.add("Intrari", [dict_plot[cheie][0] for cheie in dict_plot.keys()])
        tranzactii_chart.add("Iesiri", [dict_plot[cheie][1] for cheie in dict_plot.keys()])
        # locatie_proiectie = MY_PATH + "tranzactii_" + self.denumire_produs + ".svg" ///locatie Andrew
        locatie_proiectie = PAUL_PATH + "tranzactii_" + self.denumire_produs + ".svg" #///locatie Paul
        tranzactii_chart.render_to_file(locatie_proiectie)
        print("Proiectia grafica pentru produsul "
              "'{0}' a fost rendata intr-un fisier cu extensia .svg cu succes.".format(self.denumire_produs))
        os.system(locatie_proiectie)

    # protocolul de email a dat fail pentru ca nu trimite calumea fisierul
    # pe scurt, in inbox fisierul nu are extensie si nu poate fi vizualizat
    # decat daca este downloadat si schimbata extensia manuala in cea originala(spre exemplu: .txt)
    def Informare_email(self):
        """Trimite fisa produsului pe email"""
        mail_content = self.Fisa_produsului() # message pe mai multe linii
        # setup de data for transfer
        sender_address = 'N\\A'
        sender_password = 'N\\A'
        reciever_address = 'N\\A'
        # setup MIME short for multipurpose internet mail extensions
        message = MIMEMultipart()
        message['From'] = sender_address
        message['To'] = reciever_address
        message['Subject'] = 'Fisa produsului ' + self.denumire_produs + ':'
        message.attach(MIMEText(mail_content, 'plain'))
        # setup the attachment
        """
            file_location = MY_PATH + "test.txt"
            file_read = open(file_location, 'rb')
            pay_load = MIMEBase('application', 'octate-stream')
            pay_load.set_payload(file_read.read())
            encoders.encode_base64(pay_load)
            pay_load.add_header('Content-Decomposition', 'attachment', filename=file_location)
            __message.attach(pay_load)
        """
        # setup server login
        try:
            server = smtplib.SMTP('smtp.gmail.com', 587)
            server.starttls()
            server.login(sender_address, sender_password)
            text = message.as_string()
            server.sendmail(sender_address, reciever_address, text)
            server.quit()
            print("Fisa produsului a fost trimisa pe email cu succes!")
        except Exception as e:
            print(type(e))
            print("Mail failed to sent!")
        print('\n')


    def Intrari(self, nr_intrari, data = str(datetime.now().strftime(DATETIME_FORMAT))):
        """Contorizeaza numarul de intrari in depozit la o data specificata sau 'cea din ziua respectiva' ca default
            :param nr_intrari -> numarul de intrari
            :param data
        """
        if not self.Valideaza_cant(nr_intrari) \
            or not self.Valideaza_data(data):
            print("Aceste date pentru iesire din depozit: {0}, {1} sunt invalide.".format(nr_intrari, data))
            raise ValueError

        self.cantitatea = nr_intrari # acest atribut retine numarul de produse la ultima intrare sau iesire
        self.data = data
        self.sold += nr_intrari
        cheie = None
        if self.dictionar_miscari.keys():
            cheie = max(self.dictionar_miscari.keys()) + 1
        else:
            cheie = 1
        self.dictionar_miscari[cheie] = (self.data, self.cantitatea, '------')

    def Iesiri(self, nr_iesiri, data = str(datetime.now().strftime(DATETIME_FORMAT))):
        """Contorizeaza numarul de iesiri din stoc
            :param nr_iesiri
            :param data
        """
        if not self.Valideaza_cant(nr_iesiri) \
            or not self.Valideaza_data(data):
            print("Aceste date pentru intrare in depozit: {0}, {1} sunt invalide".format(nr_iesiri, data))
            raise ValueError

        if self.dictionar_miscari == {}:
            print("Nu poti executa iesiri din depozit cat timp este gol")
            raise AttributeError
        elif self.dictionar_miscari.keys():
            if self.sold - nr_iesiri < 0:
                print("Nu se poate efectua iesire din depozit cu aceasta cantitate pentru ca soldul devine negativ")
                raise ArithmeticError

            self.cantitatea = nr_iesiri
            self.data = data
            self.sold -= nr_iesiri
            cheie = max(self.dictionar_miscari.keys()) + 1
            self.dictionar_miscari[cheie] = (self.data, '-------', self.cantitatea)


    def Fisa_produsului(self,
                        data_inceput = "01.01.1900",
                        data_sfarsit = str(datetime.now().strftime(DATETIME_FORMAT))):
        """Afiseaza detalii despre un produs specific
            format pentru data_inceput si data_sfarsit: '%d.%m.%Y'
            :param data_inceput este de tipul message
            :param data_sfarsit este de tipul message
            creeaza fisa produsului pe parcursul executiei si o returneaza la final
        """

        if not self.Valideaza_data(data_inceput) \
            or not self.Valideaza_data(data_sfarsit):
            print("Aceste date calendaristice: {0}, {1} sunt invalide")
            raise ValueError

        if self.dictionar_miscari == {}:
            print("Nu s-a efectuat nici un tip de miscare in " \
                  "depozit pentru produsul '{0}' pana la: {1}".format(self.denumire_produs,
                                                                      str(datetime.now().strftime(DATETIME_FORMAT))))
            return
        fisa_prod_string = ""
        tab1 = "CHEIE_DATA"
        tab2 = "DATA_OPERATIEI"
        tab3 = "INTRARE"
        tab4 = "IESIRE"
        dim = 15
        lung = 120
        cap_tabel = tab1 + tab2.rjust(len(tab2) + dim) + tab3.rjust(len(tab3) + dim) + tab4.rjust(len(tab4) + dim)
        delimitator = '=' * lung
        delimitator_n = delimitator + '\n'
        fisa_prod_string += delimitator_n
        titlu = "{:=^120}".format("FISA_PRODUSULUI_" + str(self.denumire_produs).upper())
        fisa_prod_string += titlu + '\n'
        fisa_prod_string += "Fisa produsului: {0}\n" \
                            "Unitate de masura: {1}".format(self.denumire_produs, self.unitate_de_masura) + '\n'
        fisa_prod_string += "Pe intervalul: {0} ----- {1}".format(data_inceput, data_sfarsit) + '\n'
        fisa_prod_string += delimitator_n
        fisa_prod_string += cap_tabel + '\n'
        fisa_prod_string += delimitator_n
        for cheie in self.dictionar_miscari.keys():
            if self.Validare_interval(data_inceput, self.dictionar_miscari[cheie][0], data_sfarsit):
                spatiere = len(self.dictionar_miscari[cheie][0]) + 15
                fisa_prod_string += str(cheie).ljust(len(tab1)) + ' '
                fisa_prod_string += str(self.dictionar_miscari[cheie][0]).rjust(spatiere + 1) + ' '
                fisa_prod_string += str(self.dictionar_miscari[cheie][1]).rjust(spatiere - 2) + ' '
                fisa_prod_string += str(self.dictionar_miscari[cheie][2]).rjust(spatiere - 5) + '\n'
        fisa_prod_string += delimitator_n
        fisa_prod_string += "Stoc actual al produsului: {0}".format(self.sold) + '\n'
        fisa_prod_string += delimitator_n
        fisa_prod_string += delimitator_n
        fisa_prod_string += '\n'
        return fisa_prod_string

    def Continut_Stoc(self):
        """Printeaza tot ce contin variabilele clasei"""
        leng = 120
        print('=' * leng)
        print("{:=^120}".format("CONTINUT_STOC"))
        print("Numarul total de produse este: {0}".format(Stoc.__total_produse))
        print('-' * leng)
        print("Numarul total de categorii este: {0}".format(Stoc.__total_categorii))
        print('-' * leng)
        print("Lista cu produse este:")
        for produs in Stoc.__lista_produse:
            print(produs)
        print('-' * leng)
        print("Dictionarul de categorii este:")
        for cheie in Stoc.dictionar_categorii:
            print("Pentru categoria '{0}' avem produsele: {1}".format(cheie, [produs for produs in
                                                                              Stoc.dictionar_categorii[cheie]]))
        print('=' * leng)
        print('=' * leng)
        print("\n")

    def Fisa_produse(self):
        """Printeaza toate fisele produselor din Stoc"""
        print('=' * 120)
        print('=' * 120)
        print("{:=^120}".format("FISELE_TUTUROR_RODUSELOR"))
        for produs in Stoc.__lista_produse:
            globals()[produs].Fisa_produsului()
        print('=' * 120)
        print('=' * 120)
        print('=' * 120)


    def __str__(self):
        """Afiseaza pe ecran produsul"""
        return self.Fisa_produsului()

    def __len__(self):
        """Returneaza numarul de produse"""
        return Stoc.__total_produse

    def __del__(self):
        """Sterge produsul specific"""
        # print("Produsul '{0}' a fost sters din memoria heap cu success".format(self.denumire_produs))


class Depozit_Pipera(Stoc):
    """Aceasta clasa retine depozitul de la Pipera cu proprietatile clasei Stoc"""

    def __init__(self, denumire_produs, categorie, unitate_de_masura = 'bucata', sold = 0):
        self.__tara = 'ro'
        super().__init__(denumire_produs, categorie, unitate_de_masura, sold)

    def Valoare_stoc(self, pret):
        """Returneaza valoarea pe care o are stocul cu un pret transmis ca parametru"""
        return self.sold * pret

    def Perisabilitati(self, cantitate_din_total):
        """Elimina din depozit numarul de produse transmise ca parametru care sunt perisabile"""
        perisabile = int(cantitate_din_total * self.sold)
        self.Iesiri(perisabile) # eliminam toate produsele perisabile transmise ca parametru

    def Afiseaza_locatie_pe_harta(self):
        """Afiseaza pe harta lumii unde este localizat depozitul Pipera"""
        locatie_depo = pygal.maps.world.World()
        locatie_depo.title = 'Locatia pe harta lumii a depozitului din Pipera'
        locatie_depo.add('Depozit_Pipera', [self.__tara])
        # locatie_fisier = MY_PATH + "depozit_Pipera.svg" /// A
        locatie_fisier = PAUL_PATH + "depozit_Pipera.svg" # /// P
        locatie_depo.render_to_file(locatie_fisier)
        print("Proiectia pentru locatia depozitului Pipera a fost generata cu succes.")
        os.system(locatie_fisier)

# cerinta 9: meniu pentru intreg depozitul care contine mai mult de 2 metode :)
class Meniu_depozit(Depozit_Pipera):

    __lista_obiecte_produse = [] # pentru simplitate ca sa pot sa apelez metode din interiorul listei

    def __init__(self):
        print("Meniul a fost initializat cu succes pentru a opera pe depozit")
        self.delim = '=' * 120

    # 1
    def Instantiaza_produs(self):
        """Creeaza un produs nou, manual"""
        os.system("cls")
        print(self.delim)
        nume_produs = input("Introduceti numele produsului:\n")
        categorie = input("Introduceti cateogria:\n")
        unitate = input("Introduceti unitatea de masura:\n")
        try:
            sold = int(input("Introduceti sold:\n"))
        except Exception:
            print("sold invalid, inapoi la meniul principal")
            self.Meniu_principal()
        # valideaza
        if not self.Valideaza_denumire_produs(nume_produs) \
                or not self.Valideaza_categorie(categorie) \
                or not self.Valideaza_unitate_masura(unitate) \
                or not self.Valideaza_sold(sold):
            print("produse invalide, inapoi la meniul principal")
            os.system("pause")
            self.Meniu_principal()
        # instantiaza dupa nume
        # aici numele obiectului este identic cu numele produsului ca
        # sa pot sa-l caut in locals
        exec("{nume} = Depozit_Pipera('{nume}', '{categ}', '{unit}', {s})".format(nume=nume_produs,
                                                                                    categ=categorie,
                                                                                    unit=unitate,
                                                                                    s=sold))

        for nume_obiect in locals():
            if nume_obiect == nume_produs:
                Meniu_depozit.__lista_obiecte_produse.append(locals()[nume_obiect])
                break
        if isinstance(locals()[nume_produs], Stoc):
            print("produsul '{0}' a fost instantiat cu succes".format(nume_produs))
        print(self.delim)

    # 2
    def Instantiaza_random(self):
        """ Se instantiaza un produs random din cele existente la inceputul modulului
            Simplitate pentru testarea modulului
        """
        os.system("cls")
        print(self.delim)
        print("De cate ori instantiam random?")
        try:
            operatii = int(input("Alege un numar:\n"))
        except Exception:
            print("valoare invalida, try again")
            self.Instantiaza_random()

        for operatie in range(0, operatii):
            categorie = random.choice(list(CATEGORII.keys()))
            nume_produs = random.choice(CATEGORII[categorie])
            unitate = random.choice(UNITATI)
            sold = random.choice([numar for numar in range(0, 1001, 25)])
            if nume_produs not in locals(): # daca exista deja o sa am duplicate
                exec("{nume} = Depozit_Pipera('{nume}', '{categ}', '{unit}', {s})".format(nume=nume_produs,
                                                                                      categ=categorie,
                                                                                      unit=unitate,
                                                                                      s=sold))
                for nume_obiect in locals():
                    if nume_obiect == nume_produs:
                        Meniu_depozit.__lista_obiecte_produse.append(locals()[nume_obiect])
                        break
                if isinstance(locals()[nume_produs], Stoc):
                    print("produsul '{0}' a fost instantiat cu succes".format(nume_produs))
            else:
                print("produsul '%s' exista deja" % nume_produs)
        print(self.delim)


    def Actuni_per_produs(self, obiect_produs):
        """ Afiseaza tot ce pot sa fac pentru un produs specific
            :param obiect_produs este obiect al clasei Stoc
        """
        os.system("cls")
        print(self.delim)
        print("Optiuni valabile pentru: {0}".format(obiect_produs.denumire_produs))
        print("[1]. Cauta tranzactie dupa cantitate")
        print("[2]. Cauta tranzactie dupa data")
        print("[3]. Afisaj grafic pentru tranzactii")
        print("[4]. Fisa produsului")
        print("[5]. Intrari")
        print("[6]. Iesiri")
        print("[7]. Inapoi in lista produse")

        try:
            alegere = int(input("Alege o optiune:\n"))
        except ValueError as e:
            print(type(e))
            print(e)
            os.system("pause")
            self.Actuni_per_produs(obiect_produs)

        if alegere == 1:
            def data():
                os.system("cls")
                obiect_produs.Cauta_tranzactie_data()
                os.system("pause")
                self.Actuni_per_produs(obiect_produs)
            data()
        elif alegere == 2:
            def cant():
                os.system("cls")
                obiect_produs.Cauta_tranzactie_cantitate()
                os.system("pause")
                self.Actuni_per_produs(obiect_produs)
            cant()
        elif alegere == 3:
            def afis():
                os.system("cls")
                obiect_produs.Afisaj_tranzactii()
                # aici exista o exceptie
                # daca browserul este inchis si se deschide prin intermediul fisierului svg
                # browserul si fisierul svg o sa fie aceleasi thread uri si comanda os.system("pause")
                # nu ruleaza absolut deloc pentru ca asteapta sa inchid browserul
                os.system("pause")
                self.Actuni_per_produs(obiect_produs)
            afis()
        elif alegere == 4:
            def fisa():
                os.system("cls")
                print(obiect_produs.Fisa_produsului())
                os.system("pause")
                self.Actuni_per_produs(obiect_produs)
            fisa()
        elif alegere == 5:
            def intr():
                os.system("cls")
                intrari = 123
                try:
                    intrari = int(input("Introdu numarul de intari:\n"))
                    obiect_produs.Intrari(intrari)
                except Exception:
                    print("numar invalid")
                    intr()
                os.system("pause")
                self.Actuni_per_produs(obiect_produs)
            intr()
        elif alegere == 6:
            def ies():
                os.system("cls")
                try:
                    iesiri = int(input("Introdu numarul de iesiri:\n"))
                    obiect_produs.Iesiri(iesiri)
                except Exception:
                    print("numar invalid")
                    ies()
                os.system("pause")
                self.Actuni_per_produs(obiect_produs)
            ies()
        elif alegere == 7:
            self.Lista_produse()
        else:
            os.system("cls")
            print("alegere invalida")
            os.system("pause")
            self.Actuni_per_produs(obiect_produs)

    def Lista_produse(self):
        """Afiseaza toate produsele care exista in atributul acestei clase"""

        os.system("cls")
        print(self.delim)
        if not Meniu_depozit.__lista_obiecte_produse:
            print("nu avem produse in depozit, inapoi la meniu principal")
            os.system("pause")
            self.Meniu_principal()

        contor = 1
        print(self.delim)
        for produs in Meniu_depozit.__lista_obiecte_produse: # aici sunt obiectele cu produse
            print("[{0}]. {1}".format(contor, produs.denumire_produs))
            contor += 1
        print("[{0}]. Inapoi meniu principal".format(contor))

        try:
            alegere = int(input("Alege un produs:\n"))
        except (TypeError, ValueError):
            print("alegere invalida, try again")
            os.system("pause")
            self.Lista_produse()
        indecsi = [index for index in range(0, len(Meniu_depozit.__lista_obiecte_produse), 1)]
        if alegere - 1 in indecsi:
            self.Actuni_per_produs(Meniu_depozit.__lista_obiecte_produse[alegere - 1])
        elif alegere == contor:
            self.Meniu_principal()
        else:
            print("nu exista acest produs")
            os.system("pause")
            self.Meniu_principal()
        print(self.delim)

    def Sterge_produs(self):
        """Sterge un produs existent"""
        os.system("cls")
        print(self.delim)
        if not Meniu_depozit.__lista_obiecte_produse:
            print("nu avem produse in depozit")
            self.Meniu_principal()

        contor = 1
        print(self.delim)
        for produs in Meniu_depozit.__lista_obiecte_produse: # aici sunt obiectele cu produse
            print("[{0}]. {1}".format(contor, produs.denumire_produs))
            contor += 1
        print("[{0}]. Inapoi meniu principal".format(contor))
        try:
            alegere = int(input("Sterge un produs:\n"))
        except (TypeError, ValueError):
            print("alegere invalida, try again")
            os.system("pause")
            self.Sterge_produs()
        indecsi = [index for index in range(0, len(Meniu_depozit.__lista_obiecte_produse), 1)]
        if alegere - 1 in indecsi:
            print("produsul {0} a fost sters cu "
                  "succes".format(Meniu_depozit.__lista_obiecte_produse[alegere - 1].denumire_produs))
            Meniu_depozit.__lista_obiecte_produse.remove(Meniu_depozit.__lista_obiecte_produse[alegere - 1])
        elif alegere == contor:
            self.Meniu_principal()
        else:
            print("nu exista acest produs")
            os.system("pause")
            self.Meniu_principal()
        print(self.delim)

    def Meniu_principal(self):
        """ Meniu principal pentru toate produsele
            Meniul se va afisa in consola si va avea backend creations-built
        """
        os.system("cls")
        print(self.delim)
        print("[1]. Instantiere manuala")
        print("[2]. Instantiere random")
        print("[3]. Lista produse")
        print("[4]. Sterge produs")
        print("[5]. Exit")
        print(self.delim)
        try:
            alegere = int(input("Alege ceva:\n"))
        except ValueError as e:
            print("Valoare invalida, inapoi la meniu")
            print(type(e))
            print(e)
            os.system("pause")
            self.Meniu_principal()

        if alegere == 1:
            self.Instantiaza_produs()
            os.system("pause")
            self.Meniu_principal()
        elif alegere == 2:
            self.Instantiaza_random()
            os.system("pause")
            self.Meniu_principal()
        elif alegere == 3:
            self.Lista_produse()
            os.system("pause")
            self.Meniu_principal()
        elif alegere == 4:
            self.Sterge_produs()
            os.system("pause")
            self.Meniu_principal()
        elif alegere == 5:
            os.system("cls")
            print("meniu a fost inchis, la revedere")
            os.system("pause")
            sys.exit(0)
        else:
            print("alegere invalida, try again")
            os.system("pause")
            self.Meniu_principal()

if __name__ == '__main__':
    try:
        meniu = Meniu_depozit()
        meniu.Meniu_principal()

        """
        teste pentru clasa noastra
        
        carnati = Depozit_Pipera('carnati', 'carnuri')
        salam = Depozit_Pipera('salam', 'carnuri')
        sunca = Depozit_Pipera('sunca', 'carnuri')

        mingi = Depozit_Pipera('mingi', 'jucarii')
        supererou = Depozit_Pipera('supererou', 'jucarii')

        laptop = Depozit_Pipera('laptop', 'calculatoare')
        desktop = Depozit_Pipera('desktop', 'calculatoare')
        
        # carnati.continut_Stoc()

        carnati.Intrari(10)
        carnati.Iesiri(5)
        carnati.Intrari(80)
        carnati.Iesiri(64)
        carnati.Intrari(100)
        carnati.Iesiri(45)
        carnati.Intrari(34)
        carnati.Iesiri(2)
        # carnati.Intrari(100000, '12.0xxxx3.2019') eroare date invalide
        carnati.Iesiri(66, '13.08.2019')
        carnati.Intrari(90, '12.07.2019')
        carnati.Iesiri(34, '02.01.2019')    
        
           
        #carnati.Informare_email()
        #print(carnati)
        #carnati.Perisabilitati(.01)
        #carnati.Cauta_produs()
        #carnati.Cauta_tranzactie_data()
        #carnati.Cauta_tranzactie_cantitate()
        #carnati.Fisa_produsului()
        #carnati.Afisaj_tranzactii('12.06.2019', '05.08.2019')
        #carnati.Afisaj_tranzactii()
        #carnati.Afiseaza_locatie_pe_harta()
        #print(carnati)
        #carnati.Fisa_produse()
        #carnati.Fisa_produsului()
        #carnati.Continut_Stoc()
        #carnati.Fisa_produsului("01.07.2019", "01.09.2019")
        """
        print('\n\n\n\n\n')
        print("No errors")
        print("Executia pentru acest modul s-a finalizat")

    except (InterruptedError, ValueError, AttributeError, ArithmeticError) as e:
        print("Ceva dubios s-a intamplat pe parcurs...ooops")
        print(e)
        print(type(e))
else:
    print("You cant use class Stoc from import[Not Yet]")
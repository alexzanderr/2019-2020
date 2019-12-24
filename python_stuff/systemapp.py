
import webbrowser as webb
import os, sys, re
from datetime import datetime

cls = lambda : os.system("cls")
pau = lambda : os.system("pause")
open_file = lambda p : os.system(p)
exit = lambda : sys.exit(0)

class FavouriteSites:
    __sitesList = \
    [
        {"Programming" :
            [
                {"StackOverflow" : "https://stackoverflow.com/"},
                {"Programiz" : "https://www.programiz.com/"},
                {"NullByte" : "https://null-byte.wonderhowto.com/"},
                {"ProblemeInfo": "http://info.mcip.ro/"},
                {"InvataInfo": "https://invata.info"},
                {"ToptalDeveloper" : "https://www.toptal.com"},
                {"LaboratoarePoli" : "https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-01"},
                {"Epoch1_2019" : "https://colab.research.google.com/drive/1-4rZ7WshtGNTWjD-26aMlUMEQS9_ldRG#scrollTo=AMaIhqC8Ws2D"},
                {"Geeks4Geeks" : "https://www.geeksforgeeks.org/"},
                {"PbInfo" : "https://www.pbinfo.ro"},
                {"SoftPedia" : "https://forum.softpedia.com/topic/1094222-unibuc-2017-admitere-informatica/"},
                {"AndreiCiorba" : "http://andrei.clubcisco.ro/cursuri/"},
                {"RossetaCode" : "https://rosettacode.org/wiki/Category:Programming_Tasks"},
                {"Cplusplus" : "http://www.cplusplus.com"},
                {"FmiSubRezolvate" : "http://fmi.unibuc.ro/ro/pdf/2017/admitere/licenta/FMI_Rezolvari_admitere_2017.pdf"},
                {"HackTheBox" : "https://www.hackthebox.eu/home"},
                {"MicrosoftDocs" : "https://docs.microsoft.com/en-us/dotnet/csharp/tour-of-csharp/types-and-variables"},
                {"InfoArena" : "https://infoarena.ro/operatii-pe-biti"},
                {"GitHub" : "https://github.com"},
                {"W3Schools" : "https://www.w3schools.com"},
                {"CodingGame": "https://www.codingame.com/start"},
                {"Support_NTP": "http://support.ntp.org/bin/view/Servers/StratumOneTimeServers"},
                {"Real Python.com": "https://realpython.com/"},
                {"Hacker Noon.com": "https://hackernoon.com/"},
                {"Comet.ml Supercharging machine learning": "https://www.comet.ml/"},
                {"Oracle.com": "https://docs.oracle.com/en/"},
                {"Bit.ly": "https://bitly.com/"},
                {"Tutoriale pe net": "https://tutoriale-pe.net/"},
                {"Best of alogritmi elementari" : "https://eniavlad.wordpress.com/"},
                {"Codecademy": "https://www.codecademy.com/"},
                {"Hackerrank(problem solving)": "https://www.hackerrank.com/"},
                {"Programarea alogritmilor": "https://sites.google.com/site/fiicoursepa/curriculum"},
                {"PA Politehnica": "https://ocw.cs.pub.ro/courses/pa"},
                {"Tehnici web fmi": "https://sites.google.com/site/fmitehniciweb/"},
                {"Python.org": "https://www.python.org/"},
                {"Ai script mihai sturza": "https://github.com/sturzamihai?fbclid=IwAR3PHk-HawAU3D8UXaubcexOq3xZG7kf9jUn3QOHb4045-kDZdFt9QP5P7M"},
                {"Sturza depo github": "https://github.com/sturzamihai/unleashing-ml?fbclid=IwAR1j58DGi1gMIn5PFLyFJZgcpSpzuVDuKrj1frEVYnCC2tSyCXLPn4MPOf4"},
                {"Netacad.com": "https://www.netacad.com/"},
                {"NTP site": "http://support.ntp.org/bin/view/Servers/StratumOneTimeServers"},
                {"Repl.it online c++ compiler": "https://repl.it/languages/cpp"},
                {"Codeforces.com": "https://codeforces.com/?fbclid=IwAR2lFTj6_0VXSzlr4mEcOGIlEVRI5cJ8yTkjPjm79utZbv93yNyyyI47QQI"},
                {"Regex simulator.com": "https://regexr.com/"},
                {"Crypting and decrypting site": "https://www.dcode.fr/"},
                {"WikiPython.org": "https://wiki.python.org/"},
                {"DjangoCentral.com": "https://djangocentral.com/python-program-to-check-if-a-number-is-perfect-square/"},
                {"C OnlineCompiler(repl.it)": "https://repl.it/languages/c"},
                {"SUPREME KNOWLEDGE(620 free online courses)": "https://www.freecodecamp.org/news/new-online-courses/"},
                {"Google/Careers/Students": "https://careers.google.com/students/"},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
            ]},

        {"Hacking": [
            {"NullByte yt channel":"https://www.youtube.com/channel/UCgTNupxATBfWmfehv21ym-g"},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
        ]},

        {"Warnings": [
            {"curs dl mate":"http://math.ucv.ro/~gorunescu/courses/en/CS/indexcs.html"},
            {"elem de calcul stiintific":"http://math.ucv.ro/~gorunescu/courses/CS/indexcs.html"},
            {"calcul numeric":"http://math.ubbcluj.ro/~tradu/cn.htm"},
            {"Tehnici de programare":"https://sites.google.com/site/razvanaciu/tehnici-de-programare"},
            {"":""},
            {"":""},
            {"":""},
        ]},

        {"Computers" :
            [
                {"HowToGeek": "https://www.howtogeek.com/"},
                {"Filelist" : "https://filelist.ro/browse.php"},
                {"Dwavesys quantum computing": "https://www.dwavesys.com/home"},
                {"TempleOS" : "https://www.templeos.org/"},
                {"SpeedTest.net" : "https://www.speedtest.net/"},
                {"Wikipedia of programmers" : "https://www.howtoanswer.com/category"},
                {"" : ""},
                {"" : ""},
                {"" : ""},
                {"" : ""},
                {"" : ""},
            ]},

        {"News" :
            [
                {"HackerNews" : "https://news.ycombinator.com"},
                {"SlashDot": "https://slashdot.org/recent"},
                {"ZiarulNatiunea.ro": "https://www.ziarulnatiunea.ro/"},
                {"TechSpot" : "https://www.techspot.com/"},
                {"Teslarati.com" : "https://www.teslarati.com/"},
                {"codeburst.io" : "https://codeburst.io/"},
                {"Live Science.com" : "https://www.livescience.com/"},
                {"The Verge.com": "https://www.theverge.com/"},
                {"The Verge.com": "https://www.theverge.com/"},
                {"Medium.com": "https://medium.com/"},
                {"Business Insider.com": "https://www.businessinsider.com/"},
                {"Space.com": "https://www.space.com/"},
                {"Romania Insider.com": "https://www.romania-insider.com/"},
                {"The Things.com": "https://www.thethings.com/"},
                {"Daily Express.co.uk": "https://www.express.co.uk/"},
                {"Jet Brains Blog": "https://blog.jetbrains.com/"},
                {"The Register.co.uk": "https://www.theregister.co.uk/"},
                {"Phys.org": "https://phys.org/"},
                {"Gadgets NDTV": "https://gadgets.ndtv.com/"},
                {"Extreme Tech.com": "https://www.extremetech.com/"},
                {"The Conversation.com/uk": "https://theconversation.com/uk"},
                {"News 18.com": "https://www.news18.com/"},
                {"Visual Studio Blog.com": "https://devblogs.microsoft.com/visualstudio/"},
                {"SciTech Europa.eu": "https://www.scitecheuropa.eu/"},
                {"Wccftech.com": "https://wccftech.com/"},
                {"ZDNet.com": "https://www.zdnet.com/"},
                {"Towards Data Science.com": "https://towardsdatascience.com/"},
                {"Dexerto.com": "https://www.dexerto.com/"},
                {"Forbes.com": "https://www.forbes.com/#6f6709b2254c"},
                {"Stack Overflow Blog": "https://stackoverflow.blog/"},
                {"CNBC.com": "https://www.cnbc.com/world/?region=world"},
                {"Malware Tips.com": "https://malwaretips.com/"},
                {"Dev.to": "https://dev.to/"},
                {"Product Hunt.com": "https://www.producthunt.com/"},
                {"Quanta Magazine.org": "https://www.quantamagazine.org/"},
                {"WABeta Info.com": "https://wabetainfo.com/"},
                {"": ""},
                {"": ""},
                {"": ""},
            ]},

        {"Math":
            [
                {"DerivativeCalculator" : "https://www.derivative-calculator.net/"},
                {"IntegralCalculator" : "https://www.integral-calculator.com"},
                {"VarianteMate" : "https://variante-mate.ro/"},
                {"WolframAlpha" : "https://www.wolframalpha.com"},
                {"MathIsFun" : "https://www.mathsisfun.com"},
                {"StackExchangeMath" : "https://math.stackexchange.com"},
                {"Symbolab" : "https://www.symbolab.com"},
                {"MateOnline": "https://www.mateonline.net"},
                {"MatePedia": "https://matepedia.ro/determinarea-punctelor-de-inflexiune/"},
                {"WikiBooks": "https://ro.wikibooks.org/wiki/Probleme_cu_derivate_și_nu_numai/Teoreme_importante"},
                {"Math StackExchange.com": "https://math.stackexchange.com/"},
                {"Mate blog spot": "http://problemerezolvatedematematica02.blogspot.com/2014/10/lista-temelor.html?m=1"},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
            ]},

        {"Games":
            [
                {"Typeracer" : "https://play.typeracer.com/"},
                {"Leauge of legends.com": "https://na.leagueoflegends.com/en/news/champions-skins/champion-preview/champion-insights-jhin"},
                {"10Fastfingers": "https://10fastfingers.com/typing-test/romanian"},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""}
            ]},

        {"Educational":
            [
                {"Edu" : "https://www.edu.ro/"},
                {"Scribd" : "https://www.scribd.com/"},
                {"Fmi" : "http://fmi.unibuc.ro/ro/admitere_licenta/examen_admitere_iulie_2019/"},
                {"Briliant" : "https://brilliant.org/courses/#recent"},
                {"DexOnline" : "https://dexonline.ro"},
                {"Wikipedia": "https://ro.wikipedia.org/wiki"},
                {"AlgoExpert": "https://www.algoexpert.io/devon"},
                {"LexicoTranslate": "https://www.lexico.com/en/definition/witness"},
                {"CambridgeDex": "https://dictionary.cambridge.org/dictionary/english/witness"},
                {"ACM": "http://acm.ro/"},
                {"SubiecteEdu": "http://subiecte.edu.ro/2019/"},
                {"StackExchange": "https://stackexchange.com/sites"},
                {"Concursuri informatica si tic.ro": "http://webserv.lgrcat.ro/ci/Concursuri/default.html"},
                {"Skill share.com": "https://www.skillshare.com/"},
                {"Simulator fizica[WARNING: INSECURE SITE!]": "http://www.walter-fendt.de/html5/phro/inclinedplane_ro.htm"},
                {"Andrei Ciorba.ro[WARNING: INSECURE SITE!]": "http://andrei.clubcisco.ro/cursuri/misc.html"},
                {"Cambridge English": "https://www.cambridgeenglish.org/"},
                {"IELTS practice": "https://www.ielts.org/about-the-test/sample-test-questions"},
                {"Patreon.com": "https://www.patreon.com/"},
                {"Lexico(explaining meaning of expressions)": "https://www.lexico.com/en"},
                {"Cambridge dictionary": "https://dictionary.cambridge.org/dictionary/english/"},
                {"Cursuri unibuc(Warning)": "https://cs.unibuc.ro//~lleustean/Teaching/2018-LOGICINFO/index.html"},
                {"MoodleFmi": "http://moodle.fmi.unibuc.ro/"},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
                {"": ""},
            ]},

        {"Social":
            [
                {"Google" : "https://www.google.com/"},
                {"GoogleTranslate" : "https://www.google.ro/search?q=translate"},
                {"Tumblr" : "https://www.tumblr.com/dashboard"},
                {"Facebook": "https://www.facebook.com/"},
                {"Twitter": "https://twitter.com/elonmusk?ref_src=twsrc%5Egoogle%7Ctwcamp%5Eserp%7Ctwgr%5Eauthor"},
                {"9Gag.com" : "https://9gag.com/"},
                {"Reddit.com" : "https://www.reddit.com/"},
                {"Youtube.com" : "https://www.youtube.com/"},
                {"Twitch.tv" : "https://www.twitch.tv/"},
                {"Catalog virtual fmi" : "https://ums.unibuc.ro/ums/do/secure/j_security_check"},
                {"What'sApp.com" : "https://web.whatsapp.com/"},
                {"" : ""},
                {"" : ""},
            ]},

        {"Brands": [
            {"Corsair.com" : "https://www.corsair.com/ww/en/"},
            {"Intel.com" : "https://www.intel.com/content/www/us/en/homepage.html"},
            {"Asus.ro" : "https://www.asus.com/ro/"},
            {"Asus rog.com" : "https://rog.asus.com/"},
            {"Luxoft" : "https://career.luxoft.com/referral/"},
            {"Ultra-rare" : "https://ultrarare.com/"},
            {"FAN-courier tracking" : "https://www.fancourier.ro/en/awb-tracking/"},
            {"InfoAcademy.net" : "https://www.infoacademy.net/"},
            {"Binatex.com" : "https://binatex.com/"},
            {"GoTech World" : "https://gotech.world/"},
            {"Rinf Tech" : "https://www.rinftech.com/"},
            {"NextCloud.com for cloud computing" : "https://nextcloud.com/"},
            {"" : ""},
            {"" : ""},
            {"" : ""},
            {"" : ""},
            {"" : ""},
        ]},

        {"Politics": [
            {"Camera deputatilor" : "http://www.cdep.ro/pls/dic/site.page?id=339"},
            {"Constitutia Romaniei": "https://www.constitutiaromaniei.ro/"},
            {"": ""},
            {"": ""},
            {"": ""},
            {"": ""},
            {"": ""},
            {"": ""},
            {"": ""},
            {"": ""},
        ]},

        {"Orgs": [
            {"Ejobs.ro":"https://www.ejobs.ro/"},
            {"OLX.ro":"https://www.olx.ro/"},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
        ]},

        {"Util": [
            {"WindowsCentral":"https://www.windowscentral.com/how-install-bash-shell-command-line-windows-10"},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
            {"":""},
        ]}
    ]

    def __init__(self):
        input("<Press enter to initialize systemapp>")
        self.MenuFunction()

    def DisplayInformation(self):
        title = "systemapp"
        TITLE = "_" * 40 + title + "_" * 40 + '\n'
        print(TITLE)
        print(datetime.now().strftime("<Current time: ____%H:%M:%S____%D-%M-%Y____>").rjust(50))

    def FindContent(self, string_input):
        counter = 0
        found_sites = []
        content = [x for x in string_input.lower()]
        for category in self.__sitesList:
            for sites_list in category[list(category.keys())[0]]:
                for site_name in sites_list.keys():
                    if site_name != '':
                        counter += 1
                        elem = (counter, site_name)
                        if re.search(string_input, site_name.lower()) and elem not in found_sites:
                            found_sites.append(elem)
                        if re.findall(string_input, site_name.lower()) and elem not in found_sites:
                            found_sites.append(elem)

                        # trying to find inclusions of chars in original site_name
                        worst_case = True
                        temp = []
                        num = 0
                        for char in content:
                            if char in site_name.lower():
                                num += 1
                                temp.append(site_name.lower().index(char))
                        if temp == sorted(temp) and len(temp) == len(content) and elem not in found_sites:
                            worst_case = False
                            found_sites.append(elem)

                        if re.match(string_input, site_name.lower()) and elem not in found_sites:
                            found_sites.append(elem)
                        if re.fullmatch(string_input, site_name.lower()) and elem not in found_sites:
                            found_sites.append(elem)

                        # worst case scenario
                        if worst_case:
                            num = 0
                            site_name_copy = [x for x in site_name.lower()]
                            for char in list(content):
                                if re.search(char, "".join(site_name_copy)):
                                    num += 1
                                    site_name_copy.remove(char)
                            if num == len(content) and elem not in found_sites:
                                found_sites.append(elem)
        return found_sites

    def SearchEngine(self):
        choice = input("<Find something or open something>:\n")
        try:
            choice = int(choice)
            if 1 <= choice <= self.NumberOfSites():
                self.OpenSite(choice)
                self.MenuFunction()
            elif choice == self.NumberOfSites() + 1:
                return "exit"
            else:
                print("Invalid input was caught.")
                self.MenuFunction()
        except ValueError:
            if choice == '':
                self.MenuFunction()
            else:
                found_sites = self.FindContent(choice)
                if found_sites:
                    for site in found_sites:
                        print(f"[ {site[0]} ]. {site[1]}")
                    print()
                    return "found"
                else:
                    print("[Nothing found from your search...]\n")
                    self.MenuFunction()

    def MenuFunction(self):
        cls()
        self.DisplayInformation()
        self.PrintSites()
        result = self.SearchEngine()
        if result == 'found':
            choice = input("<Enter something>:\n")
            try:
                choice = int(choice)
                if 1 <= choice <= self.NumberOfSites():
                    self.OpenSite(choice)
                    self.MenuFunction()
                elif choice == self.NumberOfSites() + 1:
                    cls()
                    print("<systemapp was shut down>\n")
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
            print("<systemapp was shut down>\n")
            print("Thank you for your time.")
            return

    def OpenSite(self, choice):
        counter = 1
        for category in self.__sitesList:
            for sites_list in category[list(category.keys())[0]]:
                for site_name in sites_list.keys():
                    if site_name != '':
                        if counter == choice:
                            webb.open(sites_list[site_name])
                            """
                            cls()
                            print(f"{site_name} was opened successfully")
                            pau()
                            """
                            return
                        counter += 1

    def PrintSites(self):
        counter = 1
        for category in self.__sitesList:
            print(f"[ {list(category.keys())[0]} ]:")
            for sites_list in category[list(category.keys())[0]]:
                for site_name in sites_list.keys():
                    if site_name != '':
                        print(f"\t[ {counter} ]. {site_name}")
                        counter += 1
        print(f"\n\t[ {counter} ][____EXIT____]\n")

    def NumberOfSites(self):
        counter = 0
        for category in self.__sitesList:
            for sites_list in category[list(category.keys())[0]]:
                for site_name in sites_list.keys():
                    if site_name != '':
                        counter += 1
        return counter

if __name__ == "__main__":
    menu = FavouriteSites()
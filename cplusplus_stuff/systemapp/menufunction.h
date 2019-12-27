#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>

#include "defs.h"

using namespace std;

//TODO: exceptions system and class FavouriteSites, using OOP

void Menu();
void DerivativeCalculator(const string str);
void IntegralCalculator(const string str);
void TypeRacer(const string str);
void StackOverflow(const string str);
void NullByte(const string str);

void LimbaRomana(); // second menu

void Edu(const string str);
void Scribd(const string str);
void ProblemeINFO(const string str);
void VarianteMATE(const string str);
void FMI2019(const string str);
void InvataINFO(const string str);
void WolframAlpha(const string str);
void Tumblr(const string str);
void Toptal(const string str);
void Mathisfun(const string str);
void Translate(const string str);
void LaboratorPoli(const string str);
void Pythoncrash1(const string str);
void Brilliant(const string str);
void Howtogeek(const string str);
void Geekforgeeks(const string str);
void Stackexchange(const string str);
void Pbinfo(const string str);
void Symbolab(const string str);
void Programmiz(const string str);
void filelist(const string str);
void dex(const string str);
void softpedia(const string str);
void andrei(const string str);
void ross(const string str);
void cpp(const string str);
void rezolvare(const string str);
void mateonline(const string str);
void hacker(const string str);
void slash(const string str);
void thebox(const string str);
void docs(const string str);
void infoarena(const string str);
void tutoriale(const string str);
void matebac(const string str);
void wikipedia(const string str);
void algoexpert(const string str);
void github(const string str);
void LexicoTranslate(const string str);
void cambridge(const string str);
void acm(const string str);
void twitter(const string str);
void w3schools(const string str);
void ziarul(const string str);
void matepedia(const string str);
void subedu(const string str);
void wikibooks(const string str);
void codinggame(const string str);

void Exit();


void Menu() {
	CLS;

	cout << "These are your options:" << en;
	cout << "[1].Derivative calculator" << en;
	cout << "[2].Integral calculator" << en;
	cout << "[3].TypeRacer" << en;
	cout << "[4].StackOverflow" << en;
	cout << "[6].NullByte" << en;
	cout << "[7].Limba si literatura romana" << en;
	cout << "[8].EDU" << en;
	cout << "[9].Scribd" << en;
	cout << "[10].ProblemeINFO" << en;
	cout << "[11].VarianteMATE" << en;
	cout << "[12].FMI2019" << en;
	cout << "[13].InvataINFO" << en;
	cout << "[14].WolframAlpha" << en;
	cout << "[15].Tumblr" << en;
	cout << "[16].Toptal\Developers" << en;
	cout << "[17].MathIsFun" << en;
	cout << "[18].Google Translate" << en;
	cout << "[19].Laboratoare Politehnica" << en;
	cout << "[20].Python Crash Course 1" << en;
	cout << "[21].Brilliant.org" << en;
	cout << "[22].HowToGeek.com" << en;
	cout << "[23].Geeks4geeks" << en;
	cout << "[24].StackExchange-Mathematics" << en;
	cout << "[25].Pbinfo.ro" << en;
	cout << "[26].Symbolab - Mathematics.com" << en;
	cout << "[27].Programmiz.com" << en;
	cout << "[28].Filelist.ro" << en;
	cout << "[29].Dexonline.ro" << en;
	cout << "[30].SoftPedia - forum - INFO" << en;
	cout << "[31].Andrei Ciorba Cursuri POLI (Algoritmi and stuff)" << en;
	cout << "[32].Rosseta Code - Programming" << en;
	cout << "[33].Cplusplus.com" << en;
	cout << "[34].Rezolvare subiecte FMI" << en;
	cout << "[35].MateOnline.net" << en;
	cout << "[36].Hacker News" << en;
	cout << "[37].SlashDot - News" << en;
	cout << "[38].HackTheBox" << en;
	cout << "[39].Microsoft programming documentation" << en;
	cout << "[40].InfoArena.ro" << en;
	cout << "[41].Tutoriale pe net - info" << en;
	cout << "[42].Matebac.ro - Tutoriale mate bac" << en;
	cout << "[43].Wikipedia" << en;
	cout << "[44].AlgoExpert.io" << en;
	cout << "[45].Github.com" << en;
	cout << "[46].LexicoTranslate" << en;
	cout << "[47].Cambridge Dictionary" << en;
	cout << "[48].ACM" << en;
	cout << "[49].Twitter" << en;
	cout << "[50].W3Schools - Tutorials" << en;
	cout << "[51].Ziarul Natiunii" << en;
	cout << "[52].Matepedia - Teorie" << en;
	cout << "[53].SubiecteEdu2019" << en;
	cout << "[54].WikiBooks.org" << en;
	cout << "[55].CodingGame.com" << en;



	cout << "\n[50].Exit systemApp" << en;


	UI list[60] = { 0 };
	for (size_t iter = 0; iter < 60; iter++) {
		list[iter] = iter + 1;
	}

	UI choice;
	cin >> choice;

	if (choice == 0) {
		cout << "asda";

		choice = 10;
	}

	switch (choice) {

	case 1:
		DerivativeCalculator("Derivative calculator");
		return;
	case 2:
		IntegralCalculator("Integral calculator");
		return;
	case 3:
		TypeRacer("TypeRacer");
		return;
	case 4:
		StackOverflow("StackOverflow");
		return;
	case 6:
		NullByte("NullByte");
		return;
	case 7:
		LimbaRomana();
		return;
	case 8:
		Edu("Edu");
		return;
	case 9:
		Scribd("Scribd");
		return;
	case 10:
		ProblemeINFO("ProblemeINFO");
		return;
	case 11:
		VarianteMATE("VarianteMATE");
		return;
	case 12:
		FMI2019("FMI2019");
		return;
	case 13:
		InvataINFO("InvataINFO");
		return;
	case 14:
		WolframAlpha("WolframAlpha");
		return;
	case 15:
		Tumblr("Tumblr");
		return;
	case 16:
		Toptal("Toptal\Developers");
		return;
	case 17:
		Mathisfun("MathIsFun");
		return;
	case 18:
		Translate("Google Translate");
		return;
	case 19:
		LaboratorPoli("Laboratoare Politehnica");
		return;
	case 20:
		Pythoncrash1("Python crash course 1");
		return;
	case 21:
		Brilliant("Brilliant.org");
		return;
	case 22:
		Howtogeek("HowToGeek.com");
		return;
	case 23:
		Geekforgeeks("Geeks4geeks.org");
		return;
	case 24:
		Stackexchange("StackExchange-Mathematics");
		return;
	case 25:
		Pbinfo("Pbinfo.ro");
		return;
	case 26:
		Symbolab("Symblolab");
		return;
	case 27:
		Programmiz("Programmiz");
		return;
	case 28:
		filelist("Filelist.ro");
		return;
	case 29:
		dex("Dexonline.ro");
		return;
	case 30:
		softpedia("Softpedia-forum");
		return;
	case 31:
		andrei("Andrei Ciorba");
		return;
	case 32:
		ross("Rosseta Code - Programming");
		return;
	case 33:
		cpp("Cplusplus.com");
		return;
	case 34:
		rezolvare("Rezolvare sub FMI");
		return;
	case 35:
		mateonline("Mate online");
		return;
	case 36:
		hacker("Hacker news");
		return;
	case 37:
		slash("SlashDOt - News");
		return;
	case 38:
		thebox("hack the box");
		return;
	case 39:
		docs("Docs Microsoft");
		return;
	case 40:
		infoarena("Info arena");
		return;
	case 41:
		tutoriale("Tutoriale pe net");
		return;
	case 42:
		matebac("Mate bac.ro");
		return;
	case 43: 
		wikipedia("Wikipedia.ro");
		return;
	case 44:
		algoexpert("Algorithm expert.io");
		return;
	case 45:
		github("Github.com");
		return;
	case 46:
		LexicoTranslate("Lexico translate");
		return;
	case 47:
		cambridge("Cambridge dex");
		return;
	case 48:
		acm("ACM");
		return;
	case 49:
		twitter("Twitter");
		return;
	case 50:
		w3schools("Tutorials");
		return;
	case 51:
		ziarul("Ziarul Natiunii");
		return;
	case 52:
		matepedia("Matepedia");
		return;
	case 53:
		subedu("Subiecte edu");
		return;
	case 54:
		wikibooks("Wiki boooks");
		return;
	case 55:
		codinggame("Coding game.com");
		return;
	case 60:
		Exit();
		return;
	default:
		CLS;
		cout << "This is not an option!" << en;
		PAUSE;

		Menu();
	
	}

}


void DerivativeCalculator(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.derivative-calculator.net/");
	PAUSE;
	Menu();
}

void IntegralCalculator(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.integral-calculator.com/");
	PAUSE;
	Menu();
}

void TypeRacer(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://play.typeracer.com/");
	PAUSE;
	Menu();
}

void StackOverflow(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://stackoverflow.com/");
	PAUSE;
	Menu();
}

void NullByte(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.youtube.com/channel/UCgTNupxATBfWmfehv21ym-g");
	PAUSE;
	Menu();
}

void Edu(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.edu.ro/");
	PAUSE;
	Menu();
}

void Scribd(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.scribd.com/");
	PAUSE;
	Menu();
}

void ProblemeINFO(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://info.mcip.ro/");
	PAUSE;
	Menu();
}

void VarianteMATE(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://variante-mate.ro/bacalaureat/variante-m1/j/1");
	PAUSE;
	Menu();
}

void FMI2019(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://fmi.unibuc.ro/ro/admitere_licenta/examen_admitere_iulie_2019/");
	PAUSE;
	Menu();
}

void InvataINFO(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://invata.info/");
	PAUSE;
	Menu();
}


void WolframAlpha(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.wolframalpha.com/");
	PAUSE;
	Menu();
}



void Tumblr(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.tumblr.com/dashboard");
	PAUSE;
	Menu();
}

void Toptal(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.toptal.com");
	PAUSE;
	Menu();
}


void Mathisfun(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.mathsisfun.com/");
	PAUSE;
	Menu();
}


void Translate(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.google.ro/search?q=translate&rlz=1C1NDCM_enRO779RO779&oq=tra&aqs=chrome.0.69i59j0j69i57j35i39j0l2.5318j0j8&sourceid=chrome&ie=UTF-8");
	PAUSE;
	Menu();
}


void LaboratorPoli(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-01");
	PAUSE;
	Menu();
}


void Pythoncrash1(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://colab.research.google.com/github/bucharestschoolofai/python_crash_course/blob/master/Python%20Crash%20Course.ipynb#scrollTo=Y94RAfECV_2U");
	PAUSE;
	Menu();
}


void Brilliant(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://brilliant.org/courses/#recent");
	PAUSE;
	Menu();
}


void Howtogeek(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.howtogeek.com/");
	PAUSE;
	Menu();
}

void Geekforgeeks(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.geeksforgeeks.org/");
	PAUSE;
	Menu();
}


void Stackexchange(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://math.stackexchange.com/");
	PAUSE;
	Menu();
}

void Pbinfo(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.pbinfo.ro/");
	PAUSE;
	Menu();
}


void Symbolab(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.symbolab.com/");
	PAUSE;
	Menu();
}


void Programmiz(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.programiz.com");
	PAUSE;
	Menu();
}


void filelist(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://filelist.ro/browse.php");
	PAUSE;
	Menu();
}



void dex(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://dexonline.ro/");
	PAUSE;
	Menu();
}



void softpedia(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://forum.softpedia.com/topic/1094222-unibuc-2017-admitere-informatica/");
	PAUSE;
	Menu();
}


void andrei(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://andrei.clubcisco.ro/cursuri/");
	PAUSE;
	Menu();
}



void ross(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://rosettacode.org/wiki/Category:Programming_Tasks");
	PAUSE;
	Menu();
}



void cpp(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://www.cplusplus.com/");
	PAUSE;
	Menu();
}

void rezolvare(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://fmi.unibuc.ro/ro/pdf/2017/admitere/licenta/FMI_Rezolvari_admitere_2017.pdf");
	PAUSE;
	Menu();
}


void mateonline(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.mateonline.net/");
	PAUSE;
	Menu();
}


void hacker(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://news.ycombinator.com/");
	PAUSE;
	Menu();
}


void slash(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://slashdot.org/recent");
	PAUSE;
	Menu();
}


void thebox(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.hackthebox.eu/home");
	PAUSE;
	Menu();
}



void docs(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://docs.microsoft.com/en-us/dotnet/csharp/tour-of-csharp/types-and-variables");
	PAUSE;
	Menu();
}


void infoarena(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://infoarena.ro/operatii-pe-biti");
	PAUSE;
	Menu();
}


void tutoriale(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://tutoriale-pe.net/rezolvare-subiecte-bac-informatica-2018-c-simulare/");
	PAUSE;
	Menu();
}


void matebac(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.mate-bac.ro/categorie-cursuri/algebra-clasa-12a/");
	PAUSE;
	Menu();
}

void wikipedia(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://ro.wikipedia.org/wiki/Num%C4%83r_complex");
	PAUSE;
	Menu();
}



void algoexpert(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.algoexpert.io/devon");
	PAUSE;
	Menu();
}


void github(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://github.com/");
	PAUSE;
	Menu();
}


void LexicoTranslate(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.lexico.com/en/definition/witness");
	PAUSE;
	Menu();
}



void cambridge(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://dictionary.cambridge.org/dictionary/english/witness");
	PAUSE;
	Menu();
}


void acm(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://acm.ro/");
	PAUSE;
	Menu();
}

void twitter(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://twitter.com/elonmusk?ref_src=twsrc%5Egoogle%7Ctwcamp%5Eserp%7Ctwgr%5Eauthor");
	PAUSE;
	Menu();
}


void w3schools(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.w3schools.com/sql/");
	PAUSE;
	Menu();
}

void ziarul(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.w3schools.com/sql/");
	PAUSE;
	Menu();
}


void matepedia(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://matepedia.ro/determinarea-punctelor-de-inflexiune/");
	PAUSE;
	Menu();
}



void subedu(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start http://subiecte.edu.ro/2019/");
	PAUSE;
	Menu();
}



void wikibooks(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://ro.wikibooks.org/wiki/Probleme_cu_derivate_%C8%99i_nu_numai/Teoreme_importante");
	PAUSE;
	Menu();
}



void codinggame(const string str) {
	CLS;
	cout << str << " opened." << endl;
	system("start https://www.codingame.com/start");
	PAUSE;
	Menu();
}







void Exit() {
	CLS;
	cout << "System shut down." << endl;
	PAUSE;
	exit(0);
}

//########################################################################################################################################################

// functions and menu for limba romana

void TeorieLiterara(const string str);
void Depozit(const string str);
void Junimea(const string str);
void Enigma(const string str);
void UltimaNoapte(const string str);
void DaciaLiterara(const string str);
void JocSecund(const string str);
void CorolaDeMinuni(const string str);
void FloriDeMucigai(const string str);
void DulceleStil(const string str);
void Iona(const string str);
void Morometii(const string str);
void Poema(const string str);


//second menu
void LimbaRomana() {
	CLS;

	cout << "[LIMBA ROMANA]:" << en;
	cout << "[1].Teorie literara" << en;
	cout << "[2].Depozit" << en;
	cout << "[3].Junimea" << en;
	cout << "[4].Enigma Otiliei" << en;
	cout << "[5].Ultima noapte de dragoste" << en;
	cout << "[6].Dacia literara" << en;
	cout << "[7].Joc secund" << en;
	cout << "[8].Corola de minuni a lumii" << en;
	cout << "[9].Flori de mucigai" << en;
	cout << "[10].In dulcele stil clasic" << en;
	cout << "[11].Iona" << en;
	cout << "[12].Morometii" << en;
	cout << "[13].Poema Chiuvetei" << en;
	cout << "[15].Back to menu" << en;
	cout << "[16].Exit" << en;

	UI choice;
	cin >> choice;

	switch (choice) {
	case 1:
		TeorieLiterara("TeorieLiterara");
		break;
	case 2:
		Depozit("Depozit");
		break;
	case 3:
		Junimea("JunimeaCriticismulJunimist+TituMaiorescu");
		break;
	case 4:
		Enigma("GeorgeCalinescu-EnigmaOtiliei");
		break;
	case 5:
		UltimaNoapte("CamilPetrescu-UltimaNoapteDeDragoste");
		break;
	case 6:
		DaciaLiterara("DaciaLiterara+AlexandruLapusneanul");
		break;
	case 7:
		JocSecund("IonBarbu-JocSecund");
		break;
	case 8:
		CorolaDeMinuni("LucianBlaga-CorolaDeMinuniALumii");
		break;
	case 9:
		FloriDeMucigai("TudorArghezi-FloriDeMucigai");
		break;
	case 10:
		DulceleStil("NichitaStanescu-InDulceleStilClasic");
		break;
	case 11:
		Iona("MarinSorescu-Iona");
		break;
	case 12:
		Morometii("MarinPreda-Morometii");
		break;
	case 13:
		Poema("Poema Chiuvetei - Mircea Cartarescu");
		break;
	case 15:
		Menu();
	case 16:
		Exit();
	default:
		CLS;
		cout << "This is not an option!" << en;
		PAUSE;
		LimbaRomana();
		break;
	}

}
/// D:\\alexzander files\\Supreme folder
/// D:\\AlexzanderFiles\\SupremeFolder

void TeorieLiterara(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\TeorieLiterara.docx");
	PAUSE;
	LimbaRomana();
}

void Depozit(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\Depozit.docx");
	PAUSE;
	LimbaRomana();
}

void Junimea(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\JunimeaCriticismulJunimist+TituMaiorescu.docx");
	PAUSE;
	LimbaRomana();
}

void Enigma(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\GeorgeCalinescu-EnigmaOtiliei.docx");
	PAUSE;
	LimbaRomana();
}

void UltimaNoapte(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\CamilPetrescu-UltimaNoapteDeDragoste.docx");
	PAUSE;
	LimbaRomana();
}

void DaciaLiterara(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\DaciaLiterara+AlexandruLapusneanul.docx");
	PAUSE;
	LimbaRomana();
}


void JocSecund(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\IonBarbu-JocSecund.docx");
	PAUSE;
	LimbaRomana();
}


void CorolaDeMinuni(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\LucianBlaga-CorolaDeMinuniALumii.docx");
	PAUSE;
	LimbaRomana();
}


void FloriDeMucigai(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\TudorArghezi-FloriDeMucigai.docx");
	PAUSE;
	LimbaRomana();
}


void DulceleStil(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\NichitaStanescu-InDulceleStilClasic.docx");
	PAUSE;
	LimbaRomana();
}


void Iona(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\MarinSorescu-Iona.docx");
	PAUSE;
	LimbaRomana();
}




void Morometii(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\MarinPreda-Morometii.docx");
	PAUSE;
	LimbaRomana();
}



void Poema(const string str) {
	CLS;
	cout << str << " opened." << en;
	system("start D:\\AlexzanderFiles\\SupremeFolder\\IMPORTANT!\\eseuriSub3\\PoemaChiuvetei-MirceaCartarescu.docx");
	PAUSE;
	LimbaRomana();
}







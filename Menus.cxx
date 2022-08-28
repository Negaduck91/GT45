#include <iostream>
#include <fstream>
#include <sstream>

#include "umlaute.h"
#include "BaseScaff.hxx"
#include "Logger.hxx"


//This lets us safely read User input with std::getline()
//and cast it afterwards to check if the input was right  
template<typename Target,typename Source>
Target lexical_cast(Source arg)
{
    std::stringstream interpreter;
    Target result;
    if(   !(interpreter << arg)
       || !(interpreter >> result)
       || !(interpreter >> std::ws).eof())
            return 0;
        return result;
}

void Banner();

int MainMenu(){
	int Choice=0;
	std::string Temp("");
	Banner();
	std::cout << "\n\n\t[1] Fassadenger"<< ue << "st\n";
	std::cout << "\t[2] Modulger"<< ue << "st\n";
	std::cout << "\t[3] Beenden\n\n";
	std::cout << "Ihre Auswahl: ";
	std::getline(std::cin,Temp);
	Choice = lexical_cast<int,std::string>(Temp);
	return Choice;
}

int FacadeScaffMenu(){
	system("cls");
	int Choice=0;
	std::string Temp("");
	Banner();
	std::cout << "\n\n\t[1] Aufbau Variante 1 (30er Konsole nur Oberster Lage)\n";
	std::cout << "\t[2] Aufbau Variante 2 (30er Konsole in jeder Lage)\n\n";
	std::cout << "\t[2] Aufbau Variante 3 (70er Konsole nur Oberster Lage)\n\n";
	std::cout << "Ihre Auswahl: ";
	std::getline(std::cin,Temp);
	Choice = lexical_cast<int,std::string>(Temp);
	return Choice;
}

int BaseScaffMenu(){
	//system("cls");
	int Choice=0;
	std::string Temp("");
	Banner();
	std::cout << "\n\n\t[1] Aufbau\n";
	std::cout << "\t[2] Abbau\n\n";
	std::cout << "Ihre Auswahl: ";
	std::getline(std::cin,Temp);
	Choice = lexical_cast<int,std::string>(Temp);
	return Choice;
}

void Banner(){
	std::cout << "\t************  *****   *****   ***********    ******   *****" << std::endl;
    std::cout << "\t*   ********  *   *   *   *   *  .....  *    *    *  *   *" << std::endl;
	std::cout << "\t*   *         *   *   *   *   *  :...:  *    *    * *   *" <<std::endl;
    std::cout << "\t*   *         *   *****   *   *         *    *    **   *" <<std::endl;
	std::cout << "\t*   ****      *           *   *   *****      *    *   *" << std::endl;
	std::cout << "\t*   ****      *   *****   *   *  .....  *    *       *" << std::endl;
	std::cout << "\t*   *         *   *   *   *   *  :...:  *    *         *" <<std::endl;
	std::cout << "\t*   *         *   *   *   *   *         *    *     **   *"  <<std::endl;
    std::cout << "\t*****         *****   *****   ***********    ******  *****" <<std::endl;
}

void GetUserInput(UserInput &ToFill){
	std::string temp("");
	std::cout << "\n\tBevorzugte Bohlen\n\t<1> Alubohlen\n"
					 "\t<2> Stahlbohlen\n\t<3> Holzbohlen\n";
	std::cout << "\tIhre Wahl: ";
	std::getline(std::cin,temp);
	ToFill.PlankChoice = lexical_cast<int,std::string>(temp);
	//system("cls");
	std::cout << "\tLastklasse: ";
	std::getline(std::cin,temp);
	ToFill.LoadClass = lexical_cast<int,std::string>(temp);
	if( ToFill.LoadClass <= 0 || ToFill.LoadClass > 6) {
		std::cout <<"*****************************************\n";
		std::cout << "Falsche Eingabe\t\t\t\t*\nLastklasse zwischen 1 und 6\t\t*\n";
		std::cout <<"*****************************************\n";
		std::cout << "\tLastklasse: ";
		std::cin >>  ToFill.LoadClass;
	}
	if((ToFill.LoadClass == 5 || ToFill.LoadClass == 6) && ToFill.PlankChoice == 3) {
		std::cout << "Unwirtschaftlich...\nVerwenden Sie Alu-oder Stahlbohlen!!!\n";
		exit(0);
	}
	if( ToFill.LoadClass == 6 && ToFill.PlankChoice == 2) {
		std::cout << "Unwirtschaftlich...\nVerwenden Sie Alubohlen!!!\n";
		exit(0);
	}
	std::cout << "\tHoehe: ";
	std::getline(std::cin,temp);
	ToFill.Height = lexical_cast<double,std::string>(temp);
	std::cout << "\tLaenge: ";
	std::getline(std::cin,temp);
	ToFill.Length = lexical_cast<double,std::string>(temp);
	system("cls");
}

void NewBaseScaff(const UserInput& Input){
		BaseScaff NewScaff(Input);
		NewScaff.SetStamp(&std::cout);
		//Input.ConstructionSite += ".data";
		std::cout << "Wollen Sie die Daten speichern?" << std::endl;
		std::cout << "[J]a" << std::endl;
		std::cout << "[N]ein" << std::endl;
		char answer;
		std::cin >> answer;
		if(answer == 'J' || answer =='j'){
			WriteCalcedMaterial(NewScaff);
		}
}

/*void new_modul(){
	m_input user_input;
	std::string temp;
	double h;
	std::cout << "Arbeitslage: ";
	std::getline(std::cin,temp);
	h = lexical_cast<double,std::string>(temp);
	user_input.height = (h *= 100);
	std::cout << "Laenge: ";
	std::getline(std::cin,temp);
	h = lexical_cast<double,std::string>(temp);
	user_input.length = (h *= 100);
	std::cout << "Breite: ";
	std::getline(std::cin,temp);
	h = lexical_cast<double,std::string>(temp);
	user_input.width = (h *= 100);
	std::cout << "Lastklasse: ";
	std::getline(std::cin,temp);
	user_input.LoadClass = lexical_cast<int,std::string>(temp);
	modul_scaff mscaff(user_input);

}*/





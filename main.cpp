#include <sstream>
#include <fstream>
//#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "Menus.hxx"            //Recoding 99% done
#include "BaseScaff.hxx"        //Recoding 99% done
#include "Logger.hxx"           //Singleton pattern Logger Class to Log 
                                //every problem that occurs while executing 

//
//TODO
//
//Implement the different calc functions
//for the classes, test if every class
//calculates the wright numbers and look
//when everything is putting together
//if it works like the old program plus the
//added flexibility
//

int main(int argc, char* argv[]){
    //
    if(argc == 3 ){
        double L,H=0;
        std::vector<std::string> args;
        args.push_back(argv[1]);
        args.push_back(argv[2]);
        L = std::stod(args[0]);
        H = std::stod(args[1]);        
        clock_t Start = clock();
        BaseScaff NewScaff(L,H);
        clock_t Stop = clock();
        double Elapsed = (double)(Stop - Start) * 1000.0 / CLOCKS_PER_SEC;
        NewScaff.SetStamp(&std::cout);
        std::cout << Elapsed << std::endl;
        std::cout << "Wollen Sie die Daten speichern?" << std::endl;
		std::cout << "[J]a" << std::endl;
		std::cout << "[N]ein" << std::endl;
		char answer;
		std::cin >> answer;
		if(answer == 'J' || answer == 'j' ){
			WriteCalcedMaterial(NewScaff);
        }else{
            exit(0);
        }
    exit(0);
    }
	UserInput Input;
    switch(MainMenu()) {
		//Normal scaffold without extensions
    case 1:
        switch(BaseScaffMenu()) {
            //CONSTRUCTION
			//Then get some User Data required to calculate the scaff
        case 1:
            GetUserInput(Input);
			NewBaseScaff(Input);
			break;

			//DISMANTLING
            //Do we want to delete the File from our 
            //Data base or do we just want to look it up 
            //for some reason??
        case 2:
            BaseScaff Data;
            ReadCalcedMaterial(Data);
            break;
        }
        break;

        //Here the User wants a Allround Scaffolld
    case 2: //new_modul();
            break;

    }
    return 0;
}


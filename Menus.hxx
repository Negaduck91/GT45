#ifndef MENUS_HXX
#define MENUS_HXX

# include "BaseScaff.hxx"

/*
    In this file we define the most of the functions that interacts with 
    the User. All the menu functions give back an integer that indicates 
    the choice which the user choose. 
*/

//Custom delete function that simple 
//overwrites the file with '/0'
int Erase(const char *FileName);
//Facade or Allround??
int MainMenu();

//Ok Facade, montage or demontage?
int BaseScaffMenu();

//Montage, lets get the Data
void GetUserInput(UserInput &ToFill);

//If we have the Data, we can create the Scaffold 
//and eventually save the calculations
void NewBaseScaff(UserInput &Input);

//This functions is to savely convert the user inserted
//data in the needed type
template<typename Target,typename Source>
Target lexical_cast(Source arg);


void Banner();

void NewBaseScaff(const UserInput& Input);


#endif
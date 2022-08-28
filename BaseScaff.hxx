#ifndef BASESCAFF_HXX
#define BASESCAFF_HXX

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include "umlaute.h"

struct Dimensions{
    double  CalcedLength,
            Height,
            Weight,
            Squaremetre,
            MaxStalkLoad;
    int     Floors,
            AllFieldsL,
            LongFieldsL,
            ShortFieldsL;
};

struct UserInput {
    std::string ConstructionSite;
    int PlankChoice,LoadClass;
    double Height, Length;
    UserInput()=default;
};


//Here are stored all common length
//of the three types of planks that
//are used in all types of Scaffolds
template<typename T>
struct Planks {
    T alu[6];
    T steel[6];
    T wodden[6];
    Planks()=default;
};

//All unique comps in one struct
//from which all the other classes
//will inherit from
template<class T>
struct BaseComponents{
    Planks<T> UsedPlanks;
    T SideGuard[5];
    T ToeBoard[5];
    T Dia[5];
    T Frames[4];
    T EndGuard[2];
    T Ladder[2];
    T BaseJack;
    BaseComponents()=default;
};

//Used Multiplier to calculate
//the planks dependent on the 
//Fieldwidth
enum FieldWidth :
int{W06=2,W09};


//Passed as argument for the Fields
//funtion to determine which fields
//we have to calculate
enum FieldLength :
int {one,one_h,two,two_h,three,three_h};


//Determines the height of the first floor
//Used as indicator for the Frames array
enum FloorCompensation:
int {mini,small,medium,normal};

//This is our Base class which holds
//all functions and components that are
//equal in every Scaffold
//This class only supports calculating
//some keydata for the two the Scaffold
//The derived classes have to implement
//upon that for their speicial reqiurements
//for Material calculation...
class BaseScaff{
private:
    BaseComponents<int> Material=  { {  {0,0,0,0,0},      //alu-planks
                                        {0,0,0,0,0},      //steel-planks
                                        {0,0,0,0,0}},     //wodden-planks
                                        {0,0,0,0,0},      //guards
                                        {0,0,0,0,0},      //toe board
                                        {0,0,0,0},        //vertical-braces
                                        {0,0,0,0},        //normal-frames
                                        {0,0},            //end-guard
                                             0};                       //base jack;
   /* BaseComponents<double> MatWeight=  { {  {4.0,5.8,7.6,9.5,11.3},      //alu-planks
                                            {8.0,11.2,15.0,18.0,21.0},   //steel-planks
                                            {7.7,10.8,13.9,17.0,20.1}},  //wodden-planks
                                            {2.2,3.0,3.8,4.6,6.6},       //guards
                                            {2.5,3.8,5.0,6.3,7.3},       //toe board
                                            {7.6,7.8,8.8,9.8},           //vertical-braces
                                            {8.4,12.0,15.0,19.0},        //normal-frames
                                            {3.0,4.0},                   //end-guard
                                             3.2};                       //base jack;*/
    Dimensions CalcedData;
    FieldLength FL[2];
    FloorCompensation FC;
    FieldWidth FW;
    double  RestLenght,RestHeight;
    int Floors,
        AllFieldsL,
        LongFieldsL,
        ShortFieldsL,
        PlankChoice;

public:
    BaseScaff();
	BaseScaff(double WishedLength, double WishedHeight);
	BaseScaff(const UserInput& Input);
    ~BaseScaff()=default;

    void CalcFloors(double WishedHeight);
    void CalcFieldsL(double MaxLength);
    void CalcMaterial();
    void CalcTechnicalData();
    int friend WriteCalcedMaterial(BaseScaff &FilledScaff);
    int friend ReadCalcedMaterial(BaseScaff &FilledScaff);

    inline void SetFieldsL(int CalcedFields){ this->CalcedData.AllFieldsL = CalcedFields;}
    inline void SetFloors(int CalcedFloors){ this->CalcedData.Floors    = CalcedFloors;}

    inline unsigned int GetALLFieldsL(){return this->CalcedData.AllFieldsL;}
    inline unsigned int GetLongFieldsL(){return this->CalcedData.LongFieldsL;}
    inline unsigned int GetShortFieldsL(){return this->CalcedData.ShortFieldsL;}
    inline unsigned int GetFloors(){return this->CalcedData.Floors;}

	void SetStamp(std::ostream* WhereToPrint);

private:

    void CalcMaterial();
    void VisualizeOne(std::ostream* WhereToPrint);
    void VisualizeSecond(std::ostream* WhereToPrint);
    void FieldBase300L(double MaxLength);
    void FieldBase250L(double MaxLength);

};

#endif // SCAFF_H

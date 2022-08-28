#include "BaseScaff.hxx"
#include "Logger.hxx"

int Erase(const char *FileName) {
   unsigned long size;
   FILE *Remove=fopen(FileName, "w+b");
   if(Remove != NULL)  {
      fseek(Remove, 0L, SEEK_END);
      size=ftell(Remove);
      fwrite((char *)'\0', 1, size, Remove);
      fclose(Remove);
      remove(FileName);
	  return 0;
   }
   return 1;
}

    Floors = AllFieldsL=LongFieldsL=ShortFieldsL=0;
    RestHeight = RestLenght = 0.0L;
    FL[0] =  one;
    FL[1] =  three;
}


BaseScaff::BaseScaff(UserInput Input){
	Floors = AllFieldsL=LongFieldsL=ShortFieldsL=0;
    FL[0] =  three_h;
    FL[1] =  two_h;
	FC = normal;
    FW=W06;
    if(Input.LoadClass >= 4)
        FW=W09;
    this->CalcedData.Height = Input.Height;
    this->PlankChoice = Input.PlankChoice;
    this->RestHeight = RestLenght = 0.0;
	CalcFieldsL(Input.Length);
	CalcFloors(Input.Height);
	CalcMaterial();
}


void BaseScaff::CalcFloors(double WishedHeight){
    int Height = WishedHeight*100;
    int CalcFloors =0;
    if(Height % 200) {
        RestHeight = Height % 200;
        CalcFloors = Height / 200;
        if(RestHeight <= 50) {
        } else if(RestHeight >= 51 && RestHeight <= 100) {
            CalcFloors+=1;
            FC = mini;
        } else if(RestHeight >= 101 && RestHeight <= 150) {
            CalcFloors+=1;
            FC = small;
        } else if(RestHeight >= 151) {
            this->CalcedData.Floors+=1;
            FC = medium;
        }
    } else
        CalcFloors = Height / 200;
    BaseScaff::CalcedData.Floors = CalcFloors;
}


//Just a function to decide which 
//mainfield is used and which algorithm
//we use to calculate the fields
void BaseScaff::CalcFieldsL(double MaxLength){
    if(FL[1] == three)
        FieldBase300L(MaxLength);
    else if (FL[1] == two_h)
        FieldBase250L(MaxLength);
    else
        FieldBase250L(MaxLength);
}


//This is a small algorithm that starts with 3,07m
//fields and tries to use as less small fields as possible
void BaseScaff::FieldBase300L(double MaxLength){

    int ConvertedLength = MaxLength * 100;
    this->CalcedData.AllFieldsL = ConvertedLength / 307;
    RestLenght = ConvertedLength % 307;

    /* Here happens the magic.
       We basically just check how much length
       we got left and change then the ammount 
       of the different fields length to get the
       needed centimeters 
    */
    if(RestLenght != 0  ) {
        if(RestLenght <= 30) {
            //one_field(fw,three);
        } else if(RestLenght >= 31 && RestLenght <= 75) {
            this->CalcedData.AllFieldsL += 1;
            if(this->CalcedData.AllFieldsL > 5) {
                this->CalcedData.ShortFieldsL = 5;
                this->CalcedData.LongFieldsL -= 4;
            } else {
                this->CalcedData.ShortFieldsL = 1;
                this->CalcedData.LongFieldsL -= 1;
                FL[1] = one;
            }
        } else if(RestLenght >= 76 && RestLenght <= 125) {
            this->CalcedData.AllFieldsL += 1;
            if(this->CalcedData.AllFieldsL > 4) {
                this->CalcedData.ShortFieldsL = 4;
                this->CalcedData.LongFieldsL -= 4;
            } else {
                this->CalcedData.ShortFieldsL = 1;
                this->CalcedData.LongFieldsL -= 1;
                FL[1] = one;
            }
        } else if(RestLenght >= 126 && RestLenght <= 175) {
            this->CalcedData.AllFieldsL += 1;
            if(this->CalcedData.AllFieldsL > 3) {
                this->CalcedData.ShortFieldsL = 3;
                this->CalcedData.LongFieldsL -= 3;
            } else {
                this->CalcedData.ShortFieldsL = 1;
                this->CalcedData.LongFieldsL -= 1;
                FL[1] = one_h;
            }
        } else if(RestLenght >= 176 && RestLenght <= 225) {
            this->CalcedData.AllFieldsL +=1;
            if(this->CalcedData.AllFieldsL > 2) {
                this->CalcedData.ShortFieldsL = 2;
                this->CalcedData.LongFieldsL -= 2;
            } else {
                this->CalcedData.ShortFieldsL = 1;
                this->CalcedData.LongFieldsL -= 1;
                FL[1] = two;
            }
        } else if(RestLenght >= 226 && RestLenght <= 275) {
            this->CalcedData.AllFieldsL +=1;
            this->CalcedData.ShortFieldsL = 1;
            this->CalcedData.LongFieldsL -= 1;
        } else if( RestLenght >= 276) {
            this->CalcedData.AllFieldsL +=1 ;
        } 
    } else{

    } 
}


//This is a small algorithm that starts with 2,57m
//fields and tries to use as less small fields as possible
void BaseScaff::FieldBase250L(double MaxLength){
    

    //These are the import values we need to calculate the 
    //amount of Fields
    int ConvertedLength = MaxLength * 100 + 1;
    this->CalcedData.AllFieldsL = ConvertedLength / 257;
    RestLenght = ConvertedLength % 257;

    //Here happens the magic
    //We basically just check how much length 
    //we got left and change then the ammount 
    //of the different fields length to get the
    //needed centimeters
    if(RestLenght != 0) {
        if(RestLenght >= 40 && RestLenght <= 60 ) {
            std::cout << "A" << std::endl;
            this->CalcedData.AllFieldsL += 1;
            FL[0] = three;
            FL[1] = two_h;
            ShortFieldsL = AllFieldsL - 1;
            LongFieldsL = 1;
        } else if(RestLenght >= 31 && RestLenght <= 75) {
            std::cout << "B" << std::endl;
            this->CalcedData.AllFieldsL += 1;
            this->CalcedData.ShortFieldsL =2;
            this->CalcedData.LongFieldsL = this->CalcedData.AllFieldsL -this->CalcedData.ShortFieldsL;
            FL[0] = one_h;
        } else if(RestLenght >= 76 && RestLenght <= 125) {
            std::cout << "C" << std::endl;
            this->CalcedData.ShortFieldsL =3;
            FL[0] = two;
            LongFieldsL = AllFieldsL - 2;
            AllFieldsL = LongFieldsL + ShortFieldsL;
        } else if(RestLenght >= 126 && RestLenght <= 175) {
            std::cout << "D" << std::endl;
            this->CalcedData.AllFieldsL+=1;
            this->CalcedData.ShortFieldsL =2;
            FL[0] = two;
            LongFieldsL = AllFieldsL -ShortFieldsL;
        } else if(RestLenght >= 176 && RestLenght <= 225) {
            std::cout << "F" << std::endl;
            this->CalcedData.AllFieldsL+=1;
            this->CalcedData.ShortFieldsL =1;
            this->CalcedData.LongFieldsL = this->CalcedData.AllFieldsL -this->CalcedData.ShortFieldsL;;
            FL[0] = two;
        } else if(RestLenght >= 226) {
            std::cout << "G" << std::endl;
            AllFieldsL+=1;
            LongFieldsL = AllFieldsL;
            CalcedLength = (double)(AllFieldsL * 257)/100;
        }
    }else{ 
        std::cout << "H" << std::endl;
        LongFieldsL = AllFieldsL;
    }
    this->CalcedData.Squaremetre = this->CalcedData.CalcedLength * (this->CalcedData.Height+1.0);
}

void BaseScaff::CalcMaterial(){

    //FIrst of all we go to calculate the frames
    if(FC != normal)
        Material.Frames[FC] = BaseScaff::CalcedData.AllFieldsL + 1;
    Material.Frames[3] = (BaseScaff::CalcedData.AllFieldsL+1)*(BaseScaff::CalcedData.Floors+1);
	
	//And here we check, as always, which main field we are using
	//and then calculate the other base components
    
        Material.Dia[FL[1]] = ( (int)( AllFieldsL / 5)+1)* Floors;
        if(AllFieldsL <= 5)
            Material.Dia[FL[1]] = Floors;
        Material.SideGuard[FL[1]]     = ((AllFieldsL*2*Floors)+AllFieldsL)-(((Floors*2)+1) * ShortFieldsL);
        Material.SideGuard[FL[0]]    = (2*Floors+1)* ShortFieldsL;
        Material.ToeBoard[FL[1]]  = (Floors * AllFieldsL) - ( Floors * ShortFieldsL);
        Material.ToeBoard[FL[0]] = Floors * ShortFieldsL;
        Material.BaseJack 		 = (AllFieldsL+1)*2;
        Material.Ladder[FL[1]]      		 = Floors;
       
        switch(PlankChoice) {
        case 1:
            Material.UsedPlanks.alu[FL[0]]   = (( this->CalcedData.Floors * FW ) * this->CalcedData.ShortFieldsL);
            Material.UsedPlanks.alu[FL[1]]   = (( this->CalcedData.AllFieldsL * this->CalcedData.Floors)*FW) - (( this->CalcedData.Floors * FW ) * this->CalcedData.ShortFieldsL);
            break;
        case 2:
            Material.UsedPlanks.steel[FL[0]]   = (( this->CalcedData.Floors * FW ) * this->CalcedData.ShortFieldsL);
            Material.UsedPlanks.steel[FL[1]]   = (( this->CalcedData.AllFieldsL * this->CalcedData.Floors)*FW) - (( this->CalcedData.Floors * FW ) * this->CalcedData.ShortFieldsL);
            break;
        case 3:
            Material.UsedPlanks.wodden[FL[0]]   = (( this->CalcedData.Floors * FW ) * this->CalcedData.ShortFieldsL);
            Material.UsedPlanks.wodden[FL[1]]   = (( this->CalcedData.AllFieldsL * this->CalcedData.Floors)*FW) - (( this->CalcedData.Floors * FW ) * this->CalcedData.ShortFieldsL);
            break;
        }
        CalcTechnicalData();
}

void BaseScaff::SetStamp(std::ostream* WhereToPrint) {
    *WhereToPrint << "\n\t\t\tMaterialliste\n";
    *WhereToPrint<<"\n\t\t70er\t100er\n\n";
    *WhereToPrint<<"Endschutz  \t" << Material.EndGuard[0] <<"\t"<<Material.EndGuard[1] << std::endl;
    *WhereToPrint<< "66er Rahmen\t" << Material.Frames[0] << std::endl;
    *WhereToPrint<< "1.0m Rahmen\t" << Material.Frames[1] << std::endl;
    *WhereToPrint<< "1,50er Rahmen\t" << Material.Frames[2] << std::endl;
    *WhereToPrint<<"2.0m Rahmen\t" << Material.Frames[3] << std::endl << std::endl;
    *WhereToPrint<<"\t\t\tBelaege " << std::endl;
    *WhereToPrint<<"\n        \t3m\t2.5m\t2m\t1.5m\t1m\n";
    *WhereToPrint<<"Alu\t\t" 
            <<Material.UsedPlanks.alu[4]<< "\t"
            <<Material.UsedPlanks.alu[3]<< "\t"
            <<Material.UsedPlanks.alu[2]<< "\t"
            <<Material.UsedPlanks.alu[1]<< "\t"
            <<Material.UsedPlanks.alu[0]<< std::endl;

    *WhereToPrint<<"Holz\t\t" 
            <<Material.UsedPlanks.wodden[4]<< "\t"
            <<Material.UsedPlanks.wodden[3]<< "\t"
            <<Material.UsedPlanks.wodden[2]<< "\t"
            <<Material.UsedPlanks.wodden[1]<< "\t"
            <<Material.UsedPlanks.wodden[0]<< std::endl;
    
    *WhereToPrint<<"Stahl\t\t" 
            <<Material.UsedPlanks.steel[4]<< "\t"
            <<Material.UsedPlanks.steel[3]<< "\t"
            <<Material.UsedPlanks.steel[2]<< "\t"
            <<Material.UsedPlanks.steel[1]<< "\t"
            <<Material.UsedPlanks.steel[0]
            << std::endl<< std::endl<< std::endl;

    *WhereToPrint<<"        \t3m\t2.5m\t2m\t1.5m\t1m\n";
    *WhereToPrint<<"Lehnen\t\t" 
            <<Material.SideGuard[4] << "\t"
            <<Material.SideGuard[3] << "\t"
            <<Material.SideGuard[2] << "\t"
            <<Material.SideGuard[1]<< "\t"
            <<Material.SideGuard[0]<< std::endl;
    
    *WhereToPrint<<"Bordbretter\t" 
            <<Material.ToeBoard[4] << "\t"
            <<Material.ToeBoard[3] << "\t"
            <<Material.ToeBoard[2] << "\t"
            <<Material.ToeBoard[1]<< "\t"
            <<Material.ToeBoard[0]<< std::endl;
   
    *WhereToPrint<<"Diagonalen\t" 
            <<Material.Dia[4] << "\t"
            <<Material.Dia[3] << "\t"
            <<Material.Dia[2] << "\t"
            <<Material.Dia[1]<< "\t"
            <<Material.Dia[0]<< std::endl;
    
    *WhereToPrint <<"\nDurchtiege \t" << Material.Ladder[1]<< std::endl;
    *WhereToPrint<<"Fuesse      \t" << Material.BaseJack <<'\t'<<"\nUnterlagen\t" <<Material.BaseJack << std::endl;
   
    BaseScaff::VisualizeOne(WhereToPrint);
    *WhereToPrint<<"Eingaben: "<< std::endl;
    *WhereToPrint<<"\nEckdaten:\n";
    *WhereToPrint<<"\nLange Felder: "<< LongFieldsL <<
    "\t\tGewicht: "<< 0 <<
    "t\nKurze Felder: "<< BaseScaff::ShortFieldsL <<
    "\t\tStiellast: ca. " << 0 <<
    "kN\nLagen : "<< BaseScaff::Floors << std::endl << std::endl;
}

void BaseScaff::VisualizeOne(std::ostream* WhereToPrint){
    for(int i=1; i<=this->CalcedData.AllFieldsL; i++) {
        *WhereToPrint<< " ___";
        if(i == this->CalcedData.AllFieldsL)
            *WhereToPrint<< "\n";
    }
    VisualizeSecond(WhereToPrint);
}

void BaseScaff::VisualizeSecond(std::ostream* WhereToPrint){
    for(int k=1; k<=this->CalcedData.Floors; k++)
        for(int j=1; j<=this->CalcedData.AllFieldsL; j++) {
            *WhereToPrint<< "|___";
            if(j==this->CalcedData.AllFieldsL)
                *WhereToPrint<< "|\n";
        }
    *WhereToPrint<< "\n";
}

void BaseScaff::CalcTechnicalData(){
    this->CalcedData.Weight =  (CalcedData.Squaremetre*10)/1000;
    this->CalcedData.MaxStalkLoad = (CalcedData.Height +1) * 58;
}

int WriteCalcedMaterial(BaseScaff &FilledScaff){
    std::cout << "Geben Sie den Baustellen namne ein..." << std::endl;
	std::string ConstructionSite(".\\Baustellen\\"),temp;
	std::cin>>temp;
    temp += ".bin";
    ConstructionSite += temp;
    std::ofstream file1;
    file1.open(ConstructionSite.c_str(), std::ios::binary);
    if(file1.good()){
        file1.write((char*)&FilledScaff.Material,sizeof(BaseComponents<int>));
        file1.write((char*)&FilledScaff.CalcedData,sizeof(Dimensions));
        file1.close();
    }else if(file1.bad()){
        LOGGER->Log("Could not open the file to store Data\n");
        exit(1);
    }
    return 0;
}

int ReadCalcedMaterial(BaseScaff &FilledScaff){
	system("clear");
	system("dir .\\Baustellen");
	std::string del_name(".\\Baustellen\\"),temp;
	std::cout << "\nGeben Sie den Baustellenamen OHNE ENDUNG ein:  " << std::endl;
	std::cin >> temp;
	temp += ".bin";
	del_name += temp;
	ifstream file2;
    file2.open(del_name.c_str(),std::ios::in);
	if(file2.bad()){
		LOGGER->Log("Couldt not open file to read Data\n");
		exit(1);
	}
    file2.seekg(0);
    file2.read((char*)&FilledScaff.Material,sizeof(BaseComponents<int>));
    file2.read((char*)&FilledScaff.CalcedData,sizeof(Dimensions));
	file2.close();
    std::cout << "Wollen Sie die Datei loeschen?\n";
    std::cout << "\n\t[J]a" << std::endl;
	std::cout << "\t[N]ein" << std::endl;
	char answer;
	std::cin >> answer;
	if(answer == 'J' || answer =='j'){
        if(Erase(del_name.c_str()))
		LOGGER->Log("Couldnt delete File\n");
    }
    return 0;
}
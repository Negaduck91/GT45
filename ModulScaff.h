#ifndef MODULFACADESCAFF_H
#define MODULFACADESCAFF_H

#include "FrameScaff.h"


template<typename T>
struct ModulComponents :public Components<T>{
    T Standard[7];
};

class ModulScaff : protected Scaff{
    private:
        ModulComponents<int> Material;
        ModulComponents<double> Weight;

    public:

        ModulScaff()=default;
        ~ModulScaff()=default;

        virtual void CalcMaterial();


};







#endif // MODULSCAFF_H

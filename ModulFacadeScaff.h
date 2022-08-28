#ifndef MODULFACADESCAFF_H
#define MODULFACADESCAFF_H

#include "FrameScaff.h"


template<typename T>
struct ModulComponents :public Components<T>{
    T Standard[7];
};

class ModulFacadeScaff : public Scaff{
    protected:
        ModulComponents<int> Material;
        ModulComponents<double> Weight;

    public:

        ModulFacadeScaff()=default;
        ~ModulFacadeScaff()=default;

        void CalcMaterial();


};







#endif // MODULSCAFF_H

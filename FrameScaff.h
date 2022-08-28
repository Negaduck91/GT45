#ifndef FACADESCAFF_H
#define FACADESCAFF_H

#include "Scaff.hxx"

template<typename T>
struct Frames {
    T Frame[4];
    T WideFrame[4];
    Frames()=default;
};

template<typename T>
struct FacadeComponents : public Components<T>{
    Frames<T> UsedFrames;
};


class FrameScaff : public Scaff{
     protected:
        FacadeComponents<int> Material;
        FacadeComponents<double> Weight;

    public:

        FrameScaff()=default;
        ~FrameScaff()=default;

        void CalcMaterial();
        void CalcFieldsL(double);

};








#endif // FACADESCAFF_H

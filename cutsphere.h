#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica{
protected:
    int radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H

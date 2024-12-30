#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

class CutBox : public FiguraGeometrica{
protected:
    int xf, yf, zf;
public:
    CutBox(int x0, int y0, int z0, int x1, int y1, int z1);
    void draw(Sculptor &s);
};

#endif // CUTBOX_H

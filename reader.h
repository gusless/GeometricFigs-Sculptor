#ifndef READER_H
#define READER_H
#include "figurageometrica.h"
#include <vector>

class Reader{
    int dimX, dimY, dimZ;
    std::vector<FiguraGeometrica*> figs;

public:
    Reader(const char *filename);
    ~Reader();
    void draw(Sculptor &s);
    int getDimX(); int getDimY(); int getDimZ();
};

#endif // READER_H

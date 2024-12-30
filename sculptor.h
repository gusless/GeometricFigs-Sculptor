#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

class Sculptor{
public:
    Voxel ***v;
    int nx, ny, nz;
    float r, g, b, a;
    Sculptor(int _nx, int _ny, int nz);
    ~Sculptor();
    void setColor(float r, float g, float b, float a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(const char *filename);
    int getX();
    int getY();
    int getZ();
};

#endif // SCULPTOR_H

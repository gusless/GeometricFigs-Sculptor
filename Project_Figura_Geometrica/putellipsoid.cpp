#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    x = xcenter;
    y = ycenter;
    z = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutEllipsoid::draw(Sculptor &s){
    for(int i = 0; i<s.getX(); i++){
        for(int j = 0; j<s.getY(); j++){
            for(int k = 0; k<s.getZ(); k++){
                int ellipsoid = ((x-i)*(x-i))/rx + ((y-j)*(y-j))/ry + ((z-k)*(z-k))/rz - 1;
                if((i<s.getX() && i>=0) && (j<s.getY() && j>=0) && (k<s.getZ() && k>=0)){
                    if(ellipsoid<=rx && ellipsoid<=ry && ellipsoid<=rz){
                        s.setColor(r, g, b, a);
                        s.putVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

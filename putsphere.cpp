#include "putsphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    x = xcenter;
    y = ycenter;
    z = zcenter;
    this-> radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutSphere::draw(Sculptor &s){
    for(int i = 0; i<s.getX(); i++){
        for(int j = 0; j<s.getY(); j++){
            for(int k = 0; k<s.getZ(); k++){
                int sphere = (x-i)*(x-i) + (y-j)*(y-j) + (z-k)*(z-k);
                if((i<s.getX() && i>=0) && (j<s.getY() && j>=0) && (k<s.getZ() && k>=0)){
                    if(sphere<=radius*radius){
                        s.setColor(r, g, b, a);
                        s.putVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

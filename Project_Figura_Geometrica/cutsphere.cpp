#include "cutsphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    x = xcenter;
    y = ycenter;
    z = zcenter;
    this-> radius = radius;
}

void CutSphere::draw(Sculptor &s){
    for(int i = 0; i<s.nx; i++){
        for(int j = 0; j<s.ny; j++){
            for(int k = 0; k<s.nz; k++){
                int sphere = (x-i)*(x-i) + (y-j)*(y-j) + (z-k)*(z-k);
                if((i<s.nx && i>=0) && (j<s.ny && j>=0) && (k<s.nz && k>=0)){
                    if(sphere<=radius*radius){
                        s.cutVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

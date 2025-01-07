#include "putbox.h"

PutBox::PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a){
    x = x0;
    y = y0;
    z = z0;
    xf = x1;
    yf = y1;
    zf = z1;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;

}

void PutBox::draw(Sculptor &s){
    for(int i = x; i<xf; i++){
        for(int j = y; j<yf; j++){
            for(int k = z; k<zf; k++){
                if((i<s.getX() && i>=0) && (j<s.getY() && j>=0) && (k<s.getZ() && k>=0)){
                    s.setColor(r, g, b, a);
                    s.putVoxel(i, j, k);
                }
            }
        }
    }
}

#include <iostream>
#include "reader.h"
#include <vector>
#include <fstream>
#include <string>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"


Reader::Reader(const char *filename){
    std::ifstream fin;
    fin.open(filename);

    if(!fin.is_open()){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        std::cin.get();
        exit(1);
    }

    std::string s;

    while(fin.good()){
        fin >> s;
        if(!fin.good())
            break;
        if(s.compare("DIM")==0){
            int x,y,z;
            fin >> x >> y >> z;
            dimX = x; dimY = y; dimZ = z;
        }
        if(s.compare("PUTVOXEL")==0){
            int x,y,z;
            float r,g,b,a;
            fin >> x >> y >> z;
            fin >> r >> g >> b >> a;
            figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
        }
        if(s.compare("CUTVOXEL")==0){
            int x,y,z;
            fin >> x >> y >> z;
            figs.push_back(new CutVoxel(x,y,z));
        }
        if(s.compare("PUTBOX")==0){
            int x0,y0,z0,x1,y1,z1;
            float r,g,b,a;
            fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
            fin >> r >> g >> b >> a;
            figs.push_back(new PutBox(x0,y0,z0,x1,y1,z1,r,g,b,a));
        }
        if(s.compare("CUTBOX")==0){
            int x0,y0,z0,x1,y1,z1;
            fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
            figs.push_back(new CutBox(x0,y0,z0,x1,y1,z1));
        }
        if(s.compare("PUTSPHERE")==0){
            int xcenter, ycenter, zcenter, radius;
            float r,g,b,a;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            fin >> r >> g >> b >> a;
            figs.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }
        if(s.compare("CUTSPHERE")==0){
            int xcenter, ycenter, zcenter, radius;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            figs.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
        }
        if(s.compare("PUTELLIPSOID")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r,g,b,a;
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            fin >> r >> g >> b >> a;
            figs.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }
        if(s.compare("CUTELLIPSOID")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figs.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }

        if(s.compare("FOR_PUTVOXEL")==0){
            int it,for_i;
            int x,y,z;
            float r,g,b,a;
            fin >> it >> for_i;
            fin >> x >> y >> z;
            fin >> r >> g >> b >> a;
            for(int i=it; i<for_i; i++){
                if(x==-1){
                    figs.push_back(new PutVoxel(i,y,z,r,g,b,a));
                }
                if(y==-1){
                    figs.push_back(new PutVoxel(x,i,z,r,g,b,a));
                }
                if(z==-1){
                    figs.push_back(new PutVoxel(x,y,i,r,g,b,a));
                }
            }
        }
        if(s.compare("FOR_CUTVOXEL")==0){
            int it,for_i;
            int x,y,z;
            fin >> it >> for_i;
            fin >> x >> y >> z;
            for(int i=it; i<for_i; i++){
                if(x==-1){
                    figs.push_back(new CutVoxel(i,y,z));
                }
                if(y==-1){
                    figs.push_back(new CutVoxel(x,i,z));
                }
                if(z==-1){
                    figs.push_back(new CutVoxel(x,y,i));
                }
            }
        }
        if(s.compare("FOR_PUTSPHERE")==0){
            int it, for_i;
            int xcenter, ycenter, zcenter, radius;
            float r,g,b,a;
            fin >> it >> for_i;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            fin >> r >> g >> b >> a;
            for(int i=it; i<for_i; i++){
                if(xcenter==-1){
                    figs.push_back(new PutSphere(i,ycenter,zcenter,radius,r,g,b,a));
                }
                if(ycenter==-1){
                    figs.push_back(new PutSphere(xcenter,i,zcenter,radius,r,g,b,a));
                }
                if(zcenter==-1){
                    figs.push_back(new PutSphere(xcenter,ycenter,i,radius,r,g,b,a));
                }
            }
        }
        if(s.compare("FOR_CUTSPHERE")==0){
            int it, for_i;
            int xcenter, ycenter, zcenter, radius;
            fin >> it >> for_i;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            for(int i=it; i<for_i; i++){
                if(xcenter==-1){
                    figs.push_back(new CutSphere(i,ycenter,zcenter,radius));
                }
                if(ycenter==-1){
                    figs.push_back(new CutSphere(xcenter,i,zcenter,radius));
                }
                if(zcenter==-1){
                    figs.push_back(new CutSphere(xcenter,ycenter,i,radius));
                }
            }
        }
        if(s.compare("FOR_PUTELLIPSOID")==0){
            int it, for_i;
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r,g,b,a;
            fin >> it >> for_i;
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            fin >> r >> g >> b >> a;
            for(int i=it; i<for_i; i++){
                if(xcenter==-1){
                    figs.push_back(new PutEllipsoid(i,ycenter,zcenter,rx,ry,rz,r,g,b,a));
                }
                if(ycenter==-1){
                    figs.push_back(new PutEllipsoid(xcenter,i,zcenter,rx,ry,rz,r,g,b,a));
                }
                if(zcenter==-1){
                    figs.push_back(new PutEllipsoid(xcenter,ycenter,i,rx,ry,rz,r,g,b,a));
                }
            }
        }
        if(s.compare("FOR_CUTELLIPSOID")==0){
            int it, for_i;
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fin >> it >> for_i;
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            for(int i=it; i<for_i; i++){
                if(xcenter==-1){
                    figs.push_back(new CutEllipsoid(i,ycenter,zcenter,rx,ry,rz));
                }
                if(ycenter==-1){
                    figs.push_back(new CutEllipsoid(xcenter,i,zcenter,rx,ry,rz));
                }
                if(zcenter==-1){
                    figs.push_back(new CutEllipsoid(xcenter,ycenter,i,rx,ry,rz));
                }
            }
        }
    }
}

Reader::~Reader(){
    for(auto i : figs){
        delete i;
    }
}

void Reader::draw(Sculptor &s){
    for(auto i : figs){
        i->draw(s);
    }
}

int Reader::getDimX(){
    return dimX;
}

int Reader::getDimY(){
    return dimY;
}

int Reader::getDimZ(){
    return dimZ;
}

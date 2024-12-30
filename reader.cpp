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






cmake_minimum_required(VERSION 3.16)

project(Project_Figura_Geometrica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Project_Figura_Geometrica main.cpp
    figurageometrica.h figurageometrica.cpp
    sculptor.h sculptor.cpp
    voxel.h
    file_functions.h
    cutbox.h cutbox.cpp
    cutellipsoid.h cutellipsoid.cpp
    cutsphere.h cutsphere.cpp
    cutvoxel.h cutvoxel.cpp
    putbox.h putbox.cpp
    putellipsoid.h putellipsoid.cpp
    putsphere.h putsphere.cpp
    putvoxel.h putvoxel.cpp
    reader.h reader.cpp)

include(GNUInstallDirs)
install(TARGETS Project_Figura_Geometrica
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

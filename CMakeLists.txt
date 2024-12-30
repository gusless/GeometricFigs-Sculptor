cmake_minimum_required(VERSION 3.16)

project(figura_geometrica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(figura_geometrica main.cpp
    voxel.h
    figurageometrica.h figurageometrica.cpp
    putvoxel.h putvoxel.cpp
    sculptor.h sculptor.cpp
    cutvoxel.h cutvoxel.cpp
    putbox.h putbox.cpp
    cutbox.h cutbox.cpp
    putellipsoid.h putellipsoid.cpp
    cutellipsoid.h cutellipsoid.cpp
    putsphere.h putsphere.cpp
    cutsphere.h cutsphere.cpp
    reader.h reader.cpp
    file_functions.h
)

include(GNUInstallDirs)
install(TARGETS figura_geometrica
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
}
void Sculptor::setColor(float r_, float g_, float b_, float a_)
{
    r=r_;
    g=g_;
    b=b_;
    a=a_;
}
void Sculptor::putVoxel(int x, int y, int z)
{
    //Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    //Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    //Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    //Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    //Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a)
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    //Desativa todos os voxels que satisfazem à equação da esfera
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    //Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    //Desativa todos os voxels que satisfazem à equação do elipsóide
}
void Sculptor::writeOFF(const char* filename)
{
    //grava a escultura no formato OFF no arquivo filename

}

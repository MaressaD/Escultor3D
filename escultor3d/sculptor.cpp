#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstlib>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    /**Construtor da classe Sculptor:
    Inicializa as dimensões e aloca memória para a matriz tridimensional de Voxels**/
    nx = _nx;
    ny = _ny;
    nz = _nz;

    r=0;
    g=0;
    b=0;
    a=0.5;

    int i,j,k;
    v = new Voxel**[nx];

    for(i=0;i<nx;i++){
        v[i] = new Voxel*[ny];
    }

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            v[i][j] = new Voxel[nz];
        }
    }

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                v[i][j][k].r=r;
                v[i][j][k].g=g;
                v[i][j][k].b=b;
                v[i][j][k].a=a;
                v[i][j][k].isOn=false;
           }
        }
    }
}

Sculptor::~Sculptor()
{
    /**Destrutor da classe Sculptor:
   Libera memória da matriz tridimensional de Voxels e coloca as dimensões em valor nulo**/
    int i,j;
    nx=0;
    ny=0;
    nz=0;

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            delete [] v[i][j];
        }
    }

    for(i=0;i<nx;i++){
        delete [] v[i];
    }

    delete [] v;

}

void Sculptor::setColor(float r, float g, float b, float a)
{

    /**Responsável por atribuir a para a cor da imagem os valores r, g e b dos parametros**/
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;

}
void Sculptor::putVoxel(int x, int y, int z)
{
    /**Cria um Voxel nas coordenadas x ,y e z com as cores já definidas par a o desenho**/
    v[x][y][z].isOn=true;
    v[x][y][z].r=r;
    v[x][y][z].g=g;
    v[x][y][z].b=b;

}
void Sculptor::cutVoxel(int x, int y, int z)
{
    /**Apaga um Voxel nas coordenadas x ,y e z**/
    v[x][y][z].isOn=false;

}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;
    for(i=x0;i<x1;i++){
        for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                v[i][j][k].isOn=true;
                v[i][j][k].r=r;
                v[i][j][k].g=g;
                v[i][j][k].b=b;
                v[i][j][k].a=a;
            }
        }
    }

    //Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;
    for(i=x0;i<x1;i++){
        for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                v[i][j][k].isOn=false;
            }
        }
    }
    //Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k,aux;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;i++){
            for(k=0;k<nz;k++){
                aux=(i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) +(k-zcenter)*(k-zcenter);
                if(aux<=(radius*radius)){
                v[i][j][k].isOn=true;
                v[i][j][k].r=r;
                v[i][j][k].g=g;
                v[i][j][k].b=b;
                v[i][j][k].a=a;
                }
            }
        }
    }

    //Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a)
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k,aux;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;i++){
            for(k=0;k<nz;k++){
               aux=(i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter);
                if(aux<=(radius*radius)){
                v[i][j][k].isOn=false;
                }
            }
        }
    }

    //Desativa todos os voxels que satisfazem à equação da esfera
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    float x,y,z,aux;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;i++){
            for(k=0;k<nz;k++){
                x =(float)(i-xcenter)*(float)(i-xcenter)/rx*rx;
                y =(float)(j-ycenter)*(float)(j-ycenter)/ry*ry;
                z =(float)(k-zcenter)*(float)(k-zcenter)/rz*rz;
                aux=x+y+z;
                if(aux<=1){
                v[i][j][k].isOn=true;
                v[i][j][k].r=r;
                v[i][j][k].g=g;
                v[i][j][k].b=b;
                v[i][j][k].a=a;
                }
            }
        }
    }

    //Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    float x,y,z,aux;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;i++){
            for(k=0;k<nz;k++){
                x =(float)(i-xcenter)*(float)(i-xcenter)/rx*rx;
                y =(float)(j-ycenter)*(float)(j-ycenter)/ry*ry;
                z =(float)(k-zcenter)*(float)(k-zcenter)/rz*rz;
                aux=x+y+z;
                if(aux<=1){
                v[i][j][k].isOn=false;
                }
            }
        }
    }

    //Desativa todos os voxels que satisfazem à equação do elipsóide
}
void Sculptor::writeOFF(const char* filename)
{
    int nvertices,nfaces,i,j,k;
    std::ofstream fout;
    fout.open(filename);
    if(!fout.is_open()){
        std::cout<<"falha ao abrir o arquivo, o programa será encerrado"<<std::endl;
        exit(1);
    }

    fout<<"OFF\n";

    nvertices=nx*8;
    nfaces=ny*6;

    fout<<nvertices<<" "<<nfaces<<" 0\n";

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                   fout<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<"\n";
                   fout<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<"\n";
                   fout<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<"\n";
                   fout<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<"\n";
                   fout<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<"\n";
                   fout<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<"\n";
                   fout<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<"\n";
                   fout<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<"\n";
                }
           }
        }
    }
int contVertice=0;
    for(i=0;i<nx;i++){
           for(j=0;j<ny;j++){
               for(k=0;k<nz;k++){
                    if(v[i][j][k].isOn==true){
                        fout<<"4 "<<0+8*contVertice<<" "<<3+8*contVertice<<" "<<2+8*contVertice<<" "<<1+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<"\n"; /*face1*/
                       /* 4 corresponde ao numero de vertices na face, como todas as faces são quadradas esse valor sempre será o mesmo*/
                        fout<<"4 "<<4+8*contVertice<<" "<<5+8*contVertice<<" "<<6+8*contVertice<<" "<<7+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<"\n"; /*face2*/
                        fout<<"4 "<<0+8*contVertice<<" "<<1+8*contVertice<<" "<<5+8*contVertice<<" "<<4+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<"\n"; /*face3*/
                        fout<<"4 "<<0+8*contVertice<<" "<<4+8*contVertice<<" "<<7+8*contVertice<<" "<<3+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<"\n"; /*face4*/
                        fout<<"4 "<<3+8*contVertice<<" "<<7+8*contVertice<<" "<<6+8*contVertice<<" "<<2+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<"\n"; /*face5*/
                        fout<<"4 "<<1+8*contVertice<<" "<<2+8*contVertice<<" "<<6+8*contVertice<<" "<<5+8*contVertice<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<"\n"; /*face6*/
                        contVertice++;
                    }
              }
           }
       }
    fout.close();
    //grava a escultura no formato OFF no arquivo filename

}

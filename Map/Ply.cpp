
#include <fstream>
#include "Ply.h"
#include "SimulationData.h"
#include <locale>

class punct_facet: public std::numpunct<char> {
    protected:
        char do_decimal_point() const {
            return ',';
            }
    };

Ply::Ply ( World * world ) {

    std::ofstream out ( "output.PLY" );
    buildHeader(out);
    out.imbue ( std::locale ( out.getloc(),new punct_facet ) );

    buildVertices ( world,out );
  buildFaces ( world, out );

    out.close();



    }

void Ply::buildHeader ( std::ofstream& output ) {
    int height=SimulationData::getInst()->mapHeightToSet;
    int width =SimulationData::getInst()->mapWidthToSet;
    int verticesNum=height*width;
    int facesNum= ( height-1 ) * ( width-1 );
    output<<"ply"<<std::endl;
    output<<"format ascii 1.0"<<std::endl;
    output<<"element vertex";


    output<<' '<<verticesNum<<std::endl;
    output<<"property float x"<<std::endl;
    output<<"property float y"<<std::endl;
    output<<"property float z"<<std::endl;
    output<<"property uchar red"<<std::endl;
     output<<"property uchar green"<<std::endl;
    output<<"property uchar blue"<<std::endl;
    output<<"element face";
    output<<' '<<facesNum<<std::endl;
    output<<"property list uchar int vertex_index"<<std::endl;

    output<<"end_header"<<std::endl;

    }


void Ply::buildVertices ( World* world, std::ofstream& output ) {

    int height=SimulationData::getInst()->mapHeightToSet;
    int width =SimulationData::getInst()->mapWidthToSet;

    for ( int y=0; y<height; y++ ) {
        for ( int x=0; x<width; x++ ) {
            int color = 255*( world->map[y][x].cellHeight-world->minHeight ) /world->heightsRange;
	    int red = color;
	    int blue = 0;
	    int green = color/2;
           output<<x<<' '<<y<<' '<<world->map[y][x].cellHeight <<' '<<red<<' '<<green<<' '<<blue<<std::endl;
            }
        }

    }

void Ply::buildFaces ( World* world, std::ofstream& output ) {
    int height=SimulationData::getInst()->mapHeightToSet;
    int width =SimulationData::getInst()->mapWidthToSet;

    for ( int y=0; y<height-1; y++ ) {
        for ( int x=0; x<width-1; x++ ) {
//  	    int color =255*(world->map[y][x].cellHeight-world->minHeight)/world->heightsRange;
            output<<4<<' '<<x+y*width<<' '<<x+1+y*width<<' '<<(y+1)*width+x+1<<' '<<(y+1)*width+x<<std::endl;
            }
        }


    }

Ply::~Ply() {



    }

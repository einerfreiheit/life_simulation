#include "World.h"

World::World ( const int mapHeightToSet, const int mapWidthToSet ) {
    this->mapHeight = mapHeightToSet;
    this->mapWidth = mapWidthToSet;
    init();
    }

World::~World() {
    }

void World::init() {

    map.resize ( mapHeight );

    for ( int y = 0; y < mapHeight; y++ ) {
        map[y].resize ( mapWidth );
        }


    creatures.reserve ( 100 );
    }


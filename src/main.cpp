#include <iostream>
#include "Terrain.h"

using namespace std;

// ======================================================
// Main Function
// ======================================================

int main()
{
    cout << "===== Intelligent Terrain Analysis System =====\n";

    Terrain terrain;

    terrain.loadTerrain("data/terrain.txt");

    if (terrain.isEmpty())
    {
        return 1;
    }

    terrain.printTerrain();

    terrain.terrainStatistics();

    return 0;
}
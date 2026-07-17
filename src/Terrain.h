#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <string>

class Terrain
{
private:
    std::vector<std::vector<int>> terrain;

public:
    Terrain();

    void loadTerrain(const std::string& filename);

    void printTerrain() const;

    void terrainStatistics() const;

    bool isEmpty() const;
};

#endif
#include "Terrain.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ======================================================
// Constructor
// ======================================================

Terrain::Terrain()
{
}

// ======================================================
// Load Terrain From File
// ======================================================

void Terrain::loadTerrain(const string& filename)
{
    terrain.clear();

    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error: Could not open terrain file.\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        vector<int> row;
        stringstream ss(line);

        int value;

        while (ss >> value)
        {
            row.push_back(value);
        }

        if (!row.empty())
        {
            terrain.push_back(row);
        }
    }

    file.close();
}

// ======================================================
// Print Terrain Matrix
// ======================================================

void Terrain::printTerrain() const
{
    cout << "\n========== Terrain Matrix ==========\n\n";

    for (const auto& row : terrain)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    cout << endl;
}

// ======================================================
// Terrain Statistics
// ======================================================

void Terrain::terrainStatistics() const
{
    if (terrain.empty())
    {
        cout << "Terrain is empty.\n";
        return;
    }

    int maxHeight = terrain[0][0];
    int minHeight = terrain[0][0];

    int maxRow = 0;
    int maxCol = 0;

    int minRow = 0;
    int minCol = 0;

    double sum = 0;
    int totalCells = 0;

    for (int i = 0; i < terrain.size(); i++)
    {
        for (int j = 0; j < terrain[i].size(); j++)
        {
            int currentHeight = terrain[i][j];

            if (currentHeight > maxHeight)
            {
                maxHeight = currentHeight;
                maxRow = i;
                maxCol = j;
            }

            if (currentHeight < minHeight)
            {
                minHeight = currentHeight;
                minRow = i;
                minCol = j;
            }

            sum += currentHeight;
            totalCells++;
        }
    }

    double averageElevation = sum / totalCells;

    cout << "========== Terrain Analysis Report ==========\n\n";

    cout << "Rows               : " << terrain.size() << endl;
    cout << "Columns            : " << terrain[0].size() << endl;

    cout << "\nHighest Elevation  : " << maxHeight << " meters\n";
    cout << "Location           : (" << maxRow << ", " << maxCol << ")\n";

    cout << "\nLowest Elevation   : " << minHeight << " meters\n";
    cout << "Location           : (" << minRow << ", " << minCol << ")\n";

    cout << "\nAverage Elevation  : " << averageElevation << " meters\n";

    cout << "\n=============================================\n";
}

// ======================================================
// Check if Terrain is Empty
// ======================================================

bool Terrain::isEmpty() const
{
    return terrain.empty();
}
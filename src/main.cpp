#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// ======================================================
// Load Terrain From File
// ======================================================

void loadTerrain(const string& filename, vector<vector<int>>& terrain)
{
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

        terrain.push_back(row);
    }

    file.close();
}

// ======================================================
// Print Terrain Matrix
// ======================================================

void printTerrain(const vector<vector<int>>& terrain)
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

void terrainStatistics(const vector<vector<int>>& terrain)
{
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
// Main Function
// ======================================================

int main()
{
    cout << "===== Intelligent Terrain Analysis System =====\n";

    vector<vector<int>> terrain;

    loadTerrain("data/terrain.txt", terrain);

    if (terrain.empty())
    {
        return 1;
    }

    printTerrain(terrain);

    terrainStatistics(terrain);

    return 0;
}
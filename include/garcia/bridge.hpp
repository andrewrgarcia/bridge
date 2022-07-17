// BRIDGE
// Connecting array data between Python and C++ through the use of JSON files
// Andrew Garcia, PhD

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include <fstream> // std::ofstream

using json = nlohmann::json;

void tojson(std::string filename, std::vector<int> vector, std::vector<int> DIMS)
{

    // int N = (std::cbrt(vector.size()) + 0.5);
    std::vector<std::vector<int>> map_vars;
    std::vector<int> val_vars;

    std::ofstream ofs(filename, std::ofstream::out);

    int ND{static_cast<int>(DIMS.size())};

    if (ND == 1)
    {
        int N = DIMS[0];
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            int item{vector[i]};
            if (item) // item must be non-zero
            {
                map_vars.push_back({i});
                val_vars.push_back(item);
                count++;
            }
        }

        ofs << "{\"map\": [";
        for (int j = 0; j < count; j++)
        {
            ofs << "[";
            ofs << map_vars[j][0];

            if (j == count - 1)
                ofs << "]";
            else
                ofs << "],";
        }
        ofs << "]";

        ofs << ",\"value\": [";
        for (int j = 0; j < count; j++)
        {
            // ofs << "[";

            ofs << val_vars[j];

            if (j == count - 1)
                ofs << "";
            else
                ofs << ",";
        }
        ofs << "]";
    }
    else if (ND == 2)
    {
        int Y{DIMS[0]}, X{DIMS[1]};
        int count = 0;
        for (int j = 0; j < Y; j++)
        {
            for (int i = 0; i < X; i++)
            {
                int item{vector[Y * j + i]};
                if (item) // item must be non-zero
                {
                    map_vars.push_back({j, i});
                    val_vars.push_back(item);
                    count++;
                }
            }
        }

        ofs << "{\"map\": [";
        for (int j = 0; j < count; j++)
        {
            ofs << "[";
            for (int i = 0; i < 2; i++)
                if (i == 1)
                    ofs << map_vars[j][i];
                else
                    ofs << map_vars[j][i] << ",";
            if (j == count - 1)
                ofs << "]";
            else
                ofs << "],";
        }
        ofs << "]";

        ofs << ",\"value\": [";
        for (int j = 0; j < count; j++)
        {
            // ofs << "[";

            ofs << val_vars[j];

            if (j == count - 1)
                ofs << "";
            else
                ofs << ",";
        }
        ofs << "]";
    }
    else
    {
        int Z{DIMS[0]}, Y{DIMS[1]}, X{DIMS[2]};
        int count = 0;
        for (int k = 0; k < Z; k++)
        {
            for (int j = 0; j < Y; j++)
            {
                for (int i = 0; i < X; i++)
                {
                    int item{vector[(Z * Y) * k + Y * j + i]};
                    if (item) // item must be non-zero
                    {
                        map_vars.push_back({k, j, i});
                        val_vars.push_back(item);
                        count++;
                    }
                }
            }
        }

        ofs << "{\"map\": [";
        for (int j = 0; j < count; j++)
        {
            ofs << "[";
            for (int i = 0; i < 3; i++)
                if (i == 2)
                    ofs << map_vars[j][i];
                else
                    ofs << map_vars[j][i] << ",";
            if (j == count - 1)
                ofs << "]";
            else
                ofs << "],";
        }
        ofs << "]";

        ofs << ",\"value\": [";
        for (int j = 0; j < count; j++)
        {
            // ofs << "[";

            ofs << val_vars[j];

            if (j == count - 1)
                ofs << "";
            else
                ofs << ",";
        }
        ofs << "]";
    }

    ofs << ",\"odims\": [";

    for (int i = 0; i < ND; i++)
    {
        if (i == ND - 1)
            ofs << DIMS[i];
        else
            ofs << DIMS[i] << ",";
    }
    ofs << "]}";

    ofs.close();
}

std::vector<int> jsonload(std::string filename)
{
    // dictionary of keys (DOK)
    std::cout << "DOK:" << std::endl;

    std::ifstream i(filename); // load JSON
    json deserl;
    i >> deserl;

    std::cout << std::setw(4) << deserl << std::endl; // print neatly

    nlohmann::basic_json<> loman{deserl};

    std::vector<int> arraydims = loman["odims"];

    std::vector<int> vector;

    if (arraydims.size() == 1)
    {
        int N{arraydims[0]};
        vector.resize(N);

        for (int c = 0; c < loman["value"].size(); c++)
        {
            int x{loman["map"][c][0]};
            vector[x] = loman["value"][c];
        }
    }
    else if (arraydims.size() == 2)
    {
        int Y{arraydims[0]}, X{arraydims[1]};
        vector.resize(Y * X);

        for (int c = 0; c < loman["value"].size(); c++)
        {
            int y{loman["map"][c][0]}, x{loman["map"][c][1]};
            vector[Y * y + x] = loman["value"][c];
        }
    }
    else
    {
        int Z{arraydims[0]}, Y{arraydims[1]}, X{arraydims[2]};
        vector.resize(Z * Y * X);
        for (int c = 0; c < loman["value"].size(); c++)
        {
            int z{loman["map"][c][0]}, y{loman["map"][c][1]}, x{loman["map"][c][2]};
            vector[(Z * Y) * z + Y * y + x] = loman["value"][c];
        }
    }

    return vector;
}

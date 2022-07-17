#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fstream> // std::ofstream

void jsonify(std::string filename, std::vector<int> vector, std::vector<int> DIMS)
{

    int N = (std::cbrt(vector.size()) + 0.5);
    std::vector<std::vector<int>> map_vars;
    std::vector<int> val_vars;

    int count = 0;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            int item{vector[N * j + i]};
            if (item) // item must be non-zero
            {
                map_vars.push_back({j, i});
                val_vars.push_back(item);
                count++;
            }
        }
    }

    std::ofstream ofs(filename + ".json", std::ofstream::out);

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

    ofs << ",\"odims\": [";

    for (int i = 0; i < DIMS.size(); i++)
    {
        if (i == DIMS.size() - 1)
            ofs << DIMS[i];
        else
            ofs << DIMS[i] << ",";
    }
    ofs << "]}";

    ofs.close();
}

int main()
{
    std::vector<int> vector(16, 1);
    std::vector<int> DIMS = {4, 4};
    std::string filename{"sample"};
    jsonify(filename, vector, DIMS);
}
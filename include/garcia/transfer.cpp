#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fstream> // std::ofstream

int main()
{
    std::vector<int> vector(16, 1);
    std::vector<int> DIMS = {4, 4};
    std::string filename{"sample.json"};
    jsonify(filename, vector, DIMS);

    load(filename);
    std::cout
        << "\nvectorized array: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
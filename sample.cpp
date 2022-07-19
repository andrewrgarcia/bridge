#include <iostream>
#include <vector>
#include <stdio.h>
// #include "include/garcia/bridge.hpp" // local call
#include <garcia/bridge.hpp> // global call

int main()
{
    // CREATE A VECTORIZED ARRAY
    std::vector<int> vector0(8, 1);
    std::vector<int> DIMS = {2, 2, 2};
    std::string filename{"sample.json"};
    // pack vector to .json file
    tojson(filename, vector0, DIMS);

    // PROCESS JSON FILE BACK TO VECTOR
    std::vector<int> vector = jsonload(filename);
    // print vector
    std::cout << "\nvectorized array: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
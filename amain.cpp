// BRIDGE
// by Andrew Garcia, PhD

#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    // template / sample string
    char string[] = R"(
     {
         "map": [[1,2],[1,5],[6,9]],
         "value": [1,6,3],
         "objdims" : [10,10]
     }
     )";

    json deserl = json::parse(string); // deserialization ("parsing")

    std::cout << std::setw(4) << deserl << std::endl; // print neatly

    nlohmann::basic_json<> loman{deserl};

    std::vector<int> vector;

    int map_dims{static_cast<int>(loman["map"][0].size())};

    for (int i = 0; i < loman["value"].size(); i++)
    {
        for (int j = 0; j < map_dims; j++)
            vector.push_back(loman["map"][i][j]);
    }

    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }

    std::cout << std::endl;
}

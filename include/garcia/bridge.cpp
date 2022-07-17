// BRIDGE
// Connecting array data between Python and C++ through the use of JSON files
// Andrew Garcia, PhD

#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

int main()
{
    // dictionary of keys (DOK)
    std::cout << "DOK:" << std::endl;

    std::ifstream i("sample.json"); // load JSON
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

    std::cout << "\nvectorized array: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

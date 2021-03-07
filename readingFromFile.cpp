#include "lab3func.h"

vector<int> readVectorFromFile(string fileName)
{
    std::ifstream infile(fileName);
    vector<int> list;
    if (infile.good() == 0)
    {
        cout << "Please enter the valid file path" << endl;
        return list;
    }

    fstream scan;
    scan.open(fileName.c_str());
    if (scan.is_open())
    {
        for (string line; getline(scan, line);)
        {
            if (isdigit(line[0]))
            {
                stringstream converter(line);
                int number = 0;
                converter >> number;
                list.push_back(number);
            }
            else
            {
                cout << "Invalid input in the file" << endl;
                return list;
            }
        }
    }
    return list;
}
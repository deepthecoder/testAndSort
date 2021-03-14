#include "lab3func.h"

/*
    This helper function checks 
    for the necessary condition 
    to verify if the input file has 
    the correct file extension and 
    correct input numbers.
*/
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
            int flag = 0;
            if (isdigit(line[0]) || (line[0] == '-' && isdigit(line[1])))
            {
                for (int i = 1; i < line.size(); i++)
                {
                    if (line[i] >= '0' && line[i] <= '9')
                    {
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    cout << "Invalid input in the file ---> " << line << endl;
                    list.clear();
                    return list;
                }
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
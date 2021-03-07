#include "lab3func.h"

int main(int argc, char **argv)
{

    if (argc != 3)
    {
        cout << "Insufficient/Excess number of arguments" << endl;
        return 1;
    }
    else
    {
        string algorithm = argv[1];
        string fileName = argv[2];
        if (algorithm != "quicksort" && algorithm != "mergesort" && algorithm != "timsort")
        {
            cout << "Please enter a valid algorithm" << endl;
            return 1;
        }
        else
        {
            vector<int> list=readVectorFromFile(fileName);
            if(algorithm=="mergesort")
            {
               mergeSort(list,0,list.size()-1);
               for(int i=0;i<list.size();i++)
                cout<<list[i]<<endl;
            }
            if(algorithm=="quicksort")
            {
            
               quickSort(list,0,list.size()-1);
               for(int i=0;i<list.size();i++)
                cout<<list[i]<<endl;
            }
        }
    }
}

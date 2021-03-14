/*
    The header file consists of necessary 
    header files and function signatures
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <functional>
#include <cmath>
using namespace std;

vector<int> readVectorFromFile(string);
void mergeSort(vector<int> &L, int, int);
void merge(vector<int> &L, int l, int m, int r);

void quickSort(vector<int> &L, int, int);
int partition(vector<int> &L, int, int);

void mergeForTimSort(vector<int> &v1, vector<int> &v2, vector<int> &res);

void timSort(vector<int> &list, int run);
void insertionSort(vector<int> &l, int left, int right);
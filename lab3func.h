#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <functional>
using namespace std;

vector<int> readVectorFromFile(string);
void mergeSort(vector<int> &L, int, int);
void merge(vector<int> &L, int l, int m, int r);

void quickSort(vector<int> &L, int, int);
int partition(vector<int> &L, int, int);

void mergeForTimSort(vector<int> &v1, vector<int> &v2,vector<int> &res);
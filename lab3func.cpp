#include "lab3func.h"

void mergeSort(vector<int> &L, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(L, left, mid);
        mergeSort(L, mid + 1, right);

        merge(L, left, mid, right);
    }
}

void merge(vector<int> &L, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = L.at(l + i);
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = L.at(m + 1 + i);
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            L[k] = left[i];
            i++;
        }
        else
        {
            L[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        L[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        L[k] = right[j];
        j++;
        k++;
    }
}

void quickSort(vector<int> &L, int left, int right)
{
    if (left < right)
    {
        int partIndex = partition(L, left, right);
        quickSort(L, left, partIndex - 1);
        quickSort(L, partIndex + 1, right);
    }
}

int partition(vector<int> &L, int low, int high)
{
    int pivot = L[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (L[j] <= pivot)
        {
            i++;
            int temp = L[i];
            L[i] = L[j];
            L[j] = temp;
        }
    }
    //swap(&L[i+1],&L[high]);
    int temp = L[i + 1];
    L[i + 1] = L[high];
    L[high] = temp;
    return i + 1;
}

void mergeForTimSort(vector<int> &v1, vector<int> &v2, vector<int> &res)
{
    int n = v1.size();
    int m = v2.size();
    int i = 0, j = 0, k = 0;
    res.clear();
    while (i < n && j < m)
    {
        //cout<<"n= "<<n<<" "<<"m= "<<m;
        if (v1[i] <= v2[j])
        {
            res.push_back(v1[i]);
            i++;
        }
        else
        {
            //res[k]=v2[j];
            res.push_back(v2[j]);
            j++;
        }

        k++;
    }
    while (i < n)
    {
        res.push_back(v1[i]);
        i++;
    }
    while (j < m)
    {
        res.push_back(v2[j]);
        j++;
    }

    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
}

void kWayMerge(vector<vector<int>> listOfLists, vector<int> &output)
{
    vector<int> myList = listOfLists[0];
    for (int i = 1; i < listOfLists.size(); i++)
    {
        mergeForTimSort(listOfLists[i], myList, output);
        myList = output;
    }
    output = myList;
}

void insertionSort(vector<int> &l, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = l[i];
        int j = i - 1;
        while (j >= left && l[j] > temp)
        {
            l[j + 1] = l[j];
            j--;
        }
        l[j + 1] = temp;
    }
}

void timSort(vector<int> &list, int run)
{
    vector<vector<int>> listOfRuns;
    int n = list.size();
    for (int i = 0; i < list.size(); i += run)
    {
        int end = min((i + run - 1), n - 1);
        insertionSort(list, i, end);
        int j = i;
        vector<int> sublist;
        for (j = i; j <= end; j++)
        {
            sublist.push_back(list[j]);
        }
        listOfRuns.push_back(sublist);
    }

    vector<int> output;
    kWayMerge(listOfRuns, output);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << "\n";
}
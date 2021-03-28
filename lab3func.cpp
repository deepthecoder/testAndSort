#include "lab3func.h"

/*
    The mergesort is a divide and 
    conquer technique which divides 
    the list into 2 parts and finally 
    the two lists(sorted) are merged.
*/
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

//The below helper function merges two sorted lists.
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
}

/*
    The helper function enables to merge k sorted lists.
*/

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

void mergeRecursive(int l, int r, int max_len, int *out)
{
    int l_in = l * max_len, r_in = ((l + r) / 2 + 1) * max_len;

    int l_c = ((l + r) / 2 - l + 1) * max_len;
    int r_c = (r - (l + r) / 2) * max_len;

    int l_arr[l_c], r_arr[r_c];

    // storing data in left array
    for (int i = 0; i < l_c; i++)
        l_arr[i] = out[l_in + i];

    // storing data in right array
    for (int i = 0; i < r_c; i++)
        r_arr[i] = out[r_in + i];

    int l_curr = 0, r_curr = 0, in = l_in;

    while (l_curr + r_curr < l_c + r_c)
    {
        if (r_curr == r_c || (l_curr != l_c && l_arr[l_curr] < r_arr[r_curr]))
            out[in] = l_arr[l_curr],
            l_curr++, in++;
        else
            out[in] = r_arr[r_curr],
            r_curr++, in++;
    }
}

void divide(int l, int r, int max_len, int *out, vector<vector<int>> list)
{
    if (l == r)
    {
        for (int i = 0; i < max_len; i++)
        {
            out[l * max_len + i] = list[l][i];
        }
        return;
    }
    divide(l, (l + r) / 2, max_len, out, list);
    divide((l + r) / 2 + 1, r, max_len, out, list);
    mergeRecursive(l, r, max_len, out);
}
/*
    The TimSort algorithm breaks the given 
    list into smaller partitions and each partition is 
    sorted using insertion sort and then merged finally into 
    the list.
*/
void timSort(vector<int> &list, int run)
{
    vector<vector<int>> listOfRuns;
    int n = list.size();
    int max_len = 99999, len = 0;
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
        if (sublist.size() < max_len)
        {
            max_len = sublist.size();
        }
        listOfRuns.push_back(sublist);
    }

    vector<int> output;
    int k = listOfRuns.size();
    int *out = new int[max_len * k];
    cout << "Do you want to implement the k way merge recursively?(Y/N) ->";
    char c;
    cin >> c;
    if (c == 'Y' || c == 'y')
    {
        divide(0, k - 1, max_len, out, listOfRuns);
        for (int i = 0; i < max_len * k; i++)
        {
            //cout << out[i] << " ";
            output.push_back(out[i]);
        }
        list=output;
        return;
    }
    kWayMerge(listOfRuns, output);
    list = output;
}

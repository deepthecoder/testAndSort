#include "lab3func.h"

void mergeSort(vector<int> &L, int left, int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergeSort(L,left,mid);
        mergeSort(L,mid+1,right);

        merge(L,left,mid,right);
    }
}

void merge(vector<int> &L,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int left[n1];
    int right[n2];

    for(int i=0;i<n1;i++)
    {
        left[i]=L.at(l+i);
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=L.at(m+1+i);
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            L[k]=left[i];
            i++;
        }
        else
        {
            L[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        L[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        L[k]=right[j];
        j++;
        k++;
    }
}


void quickSort(vector<int> &L,int left,int right)
{
    if(left<right)
    {
        int partIndex=partition(L,left,right);
        quickSort(L,left,partIndex-1);
        quickSort(L,partIndex+1,right);
    }
}

int partition(vector<int> &L, int low, int high)
{
    int pivot=L[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(L[j]<=pivot)
        {
            i++;
            int temp=L[i];
            L[i]=L[j];
            L[j]=temp;
        }
    }
    //swap(&L[i+1],&L[high]);
    int temp=L[i+1];
    L[i+1]=L[high];
    L[high]=temp;
    return i+1;
}

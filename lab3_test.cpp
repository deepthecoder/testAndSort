#include "lab3func.h"

void TestSorting(std::function<void(vector<int> &, int, int)> sort_func);
void Test(vector<int> a, vector<int> output, std::function<void(vector<int> &, int, int)> sort_func, int left = -1, int right = -1);

void printVector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void test(vector<int> a, vector<int> output, std::function<void(vector<int> &, int, int)> sort_func, int left, int right)
{
    cout << "Input: ";
    printVector(a);

    sort_func(a, left, right);
    cout << "\nExpected Output: ";
    printVector(output);
    cout << "\nActual Output: ";
    printVector(a);
    if (a == output)
    {
        cout << "\nTest Case Passed...\n";
    }
    else
        cout << "\nTest Case Failed...\n";
}

void testSorting(std::function<void(vector<int> &, int, int)> sort_func)
{
    vector<int> input;
    vector<int> output;

    test(input, output, sort_func, 0, input.size() - 1);

    input = {10, 2, -3, 1, 1, 2, -89};
    output = {-89, -3, 1, 1, 2, 2, 10};
    test(input, output, sort_func, 0, input.size() - 1);

    input = {10, 2, -3, 1, 1, 2, -89};
    output = {-3, 1, 1, 2, 10, 2, -89};
    test(input, output, sort_func, 0, 4);
    cout << "-------------------------\n";
}

void testMerge(std::function<void(vector<int> &, vector<int> &, vector<int> &)> merge_func)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> res;
    vector<int> output;
    v1 = {2, 3, 3, 4, 4, 5, 6};
    v2 = {1, 2, 3, 3, 3, 4};
    output = {1, 2,2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 6};
    merge_func(v1, v2, res);
    if (res == output)
    {
        cout << "\nTest Case Passed\n";
    }
    else
        cout << "\nTest Case failed\n";

    cout << "-------------------------\n";
}

int main()
{
    cout << "Testing MergeSort ...\n";
    testSorting(mergeSort);

    cout << "Testing QuickSort ...\n";
    testSorting(quickSort);

    cout << "Testing the merge functionality of Tim sort\n";
    testMerge(mergeForTimSort);
    //cout << "Testing TimSort \n";
    //testSorting();
}

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>


using namespace std;

void print(const vector<int>& vec) {
    printf("[");
    for (auto it = vec.begin(); it != vec.end(); it++) {
        (it == vec.end() - 1) ? printf("%d", *it) : printf("%d, ", *it);
    }
    printf("]");
}

vector<pair<int, vector<int>>> vecs;
static int MaxDepth = 0;

void merge(vector<int>& leftVector, vector<int>& rightVector, vector<int>& vectortoMerge)
{

    int lefttmostValue = leftVector.size();
    int rightmostValue = rightVector.size();
    int i = 0, j = 0, k = 0;

    //printMergeSort(leftVector, rightVector);

    while (j < lefttmostValue and k < rightmostValue)
    {
        
        if (leftVector[j] < rightVector[k])
        {

            vectortoMerge[i] = leftVector[j];
            //printf("%d ", vectortoMerge[i]);
            cout << "\a";
            ++j;

        }
        else
        {

            vectortoMerge[i] = rightVector[k];
            cout << "\a";
            //printf("%d ", vectortoMerge[i]);
            ++k;

        }
        cout << "\a";
        ++i;

    }
    while (j < lefttmostValue)
    {

        vectortoMerge[i] = leftVector[j];       
        //printf("%d ", vectortoMerge[i]);
        cout << "\a";
        ++j; ++i;

    }

    while (k < rightmostValue) 
    {

        vectortoMerge[i] = rightVector[k];
        //printf("%d ", vectortoMerge[i]);
        cout << "\a";
        ++k; ++i;

    }
    cout << "\a"<<endl;
}

void mergeSort(vector<int>& vectortoSort, int level = 0)
{
    if (level > MaxDepth) MaxDepth = level + 1;
    if (vectortoSort.size() <= 1)
    {
        return;
    }

    int middleElement = vectortoSort.size() / 2;
    vector<int> leftVector;
    vector<int> rightVector;

    for (int j = 0; j < middleElement; ++j)
        leftVector.push_back(vectortoSort[j]);
    for (int j = 0; j < (vectortoSort.size()) - middleElement; ++j)
        rightVector.push_back(vectortoSort[middleElement + j]);
        

    vecs.push_back(make_pair(level, leftVector));
    mergeSort(leftVector, level + 1);
    vecs.push_back(make_pair(level, rightVector));
    mergeSort(rightVector, level + 1);
    
    merge(leftVector, rightVector, vectortoSort);
    
    vecs.push_back(make_pair(MaxDepth +1 - level, vectortoSort));
    
}

void main()
{
    
    int size;
    cout << "input size: ";
    cin >> size;
    
    std::srand(unsigned(std::time(nullptr)));
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), std::rand);
    
    
    vecs.push_back(make_pair(-1, vec));
    cout << "\a";
    
    mergeSort(vec);
    cout << "\a";
    for (int i = -1; i < MaxDepth + 2; i++) {
        for (const auto& e : vecs) {
            if (e.first == i)
            {
                print(e.second);
                cout << "  ";
                std::this_thread::sleep_for (std::chrono::seconds(1));
            }
        }
        cout << "\n";
    }
}
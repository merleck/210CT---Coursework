#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>

using namespace std;

void shuffle(vector<int> arr)
{
    /*
    Function that takes in a vector and outputs a randomly shuffled
    version containing the same elements.
    Complexity: O(n) due to for loops
    */

    srand(time(NULL)); // generate random seed          //1
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) //iterate over array        //n
    {
        //choose random position within the remaining length of the array
        vector<int>::iterator r = it + (rand() % (distance(it, arr.end())));            //1
        //swap values from current position with the randomly chosen position
        int temp = *it;     //1
        *it = *r;           //1
        *r = temp;          //1
    }
    cout << "Shuffled Array: ";     //1
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)     //n
    {
        //print values of vertex
        cout << *it << ", ";        //1
    }
    cout << endl;       //1
};

void task1()
{
    //disallow negative lengths and non-numerical inputs
    int length = -1;
    while (true)
        {
        cout << "How long do you want the sequence?" << endl;
        //only allow numerical inputs
        while (!(cin >> length))
        {
            cout << "How long do you want the sequence?" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (length < 0)
        {
            cout << "Cannot have an array with less than 0 elements" << endl;
            cout << "please try again: " << endl;
        }
        else
        {
            break;
        }
    }
    vector<int> startArr;
    startArr.reserve(length); //reserve the space ahead of time instead of allocating
                              //memory every iteration
    //Populate the array
    int n; //temp storage
    cout << "enter an array of numbers" << endl;
    for ( int i = 0; i < length; ++i)
    {
        //only allow numerical inputs
        while (!(cin >> n))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        startArr.push_back(n);
    }
    shuffle(startArr);
}



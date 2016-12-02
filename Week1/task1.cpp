#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shuffle_old(int arr[], int length)
{
    /*
    Function that takes in an array and it's length and outputs a randomly shuffled
    version array containing the same elements.
    Complexity: O(n) due to for loops
    */

    srand(time(NULL)); // generate random seed

    for (int i = 0; i < length; i++) //iterate over array
    {
        int r = i + (rand() % (length - i)); //choose random index within the remaining length of the array

        //swap values from 1st index with random
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }

    cout << "Shuffled Array: ";

    for (int i = 0; i<length; i++)
    {
        //print values of array
        cout << arr[i] << ", ";
    }
    cout << endl;
};

void task1_old()
{
    int n;
    cout << "How long do you want the sequence?" << endl;
    cin >> n;
    int startArr[n];
    cout << "enter an array of numbers" << endl;
    for ( int i = 0; i < n; ++i)
    {
        cin >> startArr[i];
    }


    //divide size of the array variable by the size of it's pointer (size in bytes of array divided by the length of an element in the array)
    //int length = sizeof(startArr)/sizeof(*startArr);

    //cout << "the length of the array is: " << length << endl;  //Test whether length is correct

    shuffle_old(startArr, n);
}



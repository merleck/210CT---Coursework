#include <iostream>
#include <vector>

using namespace std;

vector<int> longestAscending(vector<int> origsequence)
{
    /*
    A function that takes in a vector of integers and outputs a vector of integers
    containing the largest sequence of ascending integers.
    6 variables
    O(n^2) Complexity due to nested for loops *average O(n log n) possible due to breaks in both loops
    */

    //initialise variables
    int start = 0;
    int maxLength = 0;
    int length = 0;

    //loop over input for recording start point
    for (int i = 0; i < origsequence.size(); i++)
    {
        //loop over input again recording distance from start point
        for (int j = i; j < origsequence.size(); j++)
        {
            //if start point and current point are the same place skip rest of this iteration
            if (j == i)
            {
                continue;
            }

            //if the current positions value is higher than the previous position value add one to distance, else exit loop
            if (origsequence[j] > origsequence[j-1])
            {
                length++;
            }
            else
            {
                break;
            }
        }

        //if the distance is higher than the highest distance we have encountered update the highest distance and where we started
        if (length > maxLength)
        {
            maxLength = length+1;
            start = i;
        }

        //if the amount of remaining elements is less than the greatest length we have found then exit loop
        if (origsequence.size() - i < maxLength - length)
        {
            break;
        }
        //reset temp length for the next iteration
        length = 0;
    }

    //create output sequence
    vector<int> result(origsequence.begin()+start, origsequence.begin()+start+maxLength);

    return result;
};

void task1()
{

    //Creation of the input sequence:
    int n;
    cout << "How long do you want the sequence?: " << endl;
    cin >> n;
    vector<int> sequence(n);
    for (int i=0; i < sequence.size(); i++)
    {
        cout << "input the value at element " << i << " in the sequence:" << endl;
        cin >> sequence[i];
    }

    //Function call:
    vector<int> resultvector = longestAscending(sequence);

    //Display output:
    cout << "The longest sequence of ascending numbers is: [";
    for (const auto i: resultvector) //C++ 11 ranged for used for ease
    {
        //if i is the last element in sequence then do not output the comma
        if (i == resultvector.back())
        {
            cout << i;
        }
        else
        {
            cout << i << ",";
        }
    }
    cout << "]" << endl;
}


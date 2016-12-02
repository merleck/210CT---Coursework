#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool binarySearchRanged(vector<int> sequence, int target1, int target2, int start, int finish)
{
    /*
    A function to do a standard binary search algorithm on a given range rather than
    individual value. Takes in an array, the search values that make the range, and
    the start position and end position of the array. This function is recursive.
    Time Complexity for this function is O(n) as it is recursive with no loops.
    */

    int mid, highnum, lownum;
    //store the higher of the the range values as the highhum and lower as the lownum
    //this allows the user to input them whichever way round they wish.
    if (target1 > target2)
    {
        highnum = target1;
        lownum = target2;
    }
    else
    {
        highnum = target2;
        lownum = target1;
    }

    //if the array has a length of zero

    if (start > finish)
    {
        return false;
    }
    else
    {
        mid = (start + finish)/2;

        //Is the value in between the range?
        if (sequence[mid] <= highnum && sequence[mid] >= lownum)
        {
            return true;
        }
        else if (sequence[mid] > highnum)
        {
            //Cut off top half of the array
            return binarySearchRanged(sequence, target1, target2, start, mid-1);
        }
        else
        {
            //Cut off the bottom half of the array
            return binarySearchRanged(sequence, target1, target2, mid+1, finish);
        }
    }
};

int getInt()
{
    /*
    Function to only allow numeric inputs and ignore everything else
    */
    int n;
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
}

int main()
{
    int n, num1, num2, input;
    vector<int> sequence;

    cout << "please input length of sequence: " << endl;
    n = getInt();

    //Populate the vector
    cout << "please input the values for the ordered sequence one at a time: " << endl;
    for (int i=0; i < n; i++)
    {
        input = getInt();
        sequence.emplace_back(input);
    }
    int start = 0;
    int finish = n-1; //offset for index

    //The search values
    cout << "Enter the start and end values you wish to search: " << endl;
    num1 = getInt();
    num2 = getInt();

    bool result = binarySearchRanged(sequence,num1,num2,start,finish); //The search

    cout << boolalpha; //So bool values will print out as true and false rather than 1 and 0
    cout << result << endl;

    return 0;
}


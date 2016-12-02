#include <iostream>
#include <limits>

using namespace std;

int zeroes(int factorial)
{
    /*
    Function that takes in a factorial number and returns the number
    of trailing zeroes there are
    Complexity: O(log n) a for loop that only runs once for every 5 (roughly)
    */

    int numberOfZeroes = 0;     //1

    if(factorial < 5)           //1
    {
        return numberOfZeroes;  //1
    }
    else                        //1
    {
        for(int i = 5; factorial/i >= 1; i*= 5)     //log n
        {
            numberOfZeroes += factorial/i;          //1
        }
        return numberOfZeroes;  //1
    }
};

void task2()
{
    int number;

    cout << "enter the factorial number: " << endl;

    while (!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    int result = zeroes(number);

    cout << "Number of trailing zeroes: " << result << endl;
}



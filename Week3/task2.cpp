#include <iostream>
#include <limits>

using namespace std;

bool isPrime(int number, int divide = 2 )
{
    /*
    A recursive function that checks whether a number is prime or not.
    O(n) due to recursion.
    */

    //If negative, 0 or 1 are not prime
    if( number <= 1)
    {
        return false;
    }
    //If we have reached the point that we are dividing the number by itself it is prime
    if(divide == number)
    {
        return true;
    }
    //if the number can be divided with no remainder it is not prime
    if ( number%divide == 0)
    {
        return false;
    }
    //recursive call incrementing the dividing number
    else
    {
        return isPrime(number, divide+1);
    }
};

void task2()
{
    cout << endl << "Task 2:" << endl << endl;

    cout << "Enter a Number: " << endl;
    int n;
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry - Please try again: " << endl;
    }

    //boolalpha makes the result print as true and false instead of 0 and 1
    cout << boolalpha << "This number is prime: " << isPrime(n) << endl;
}


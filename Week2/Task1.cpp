#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int largestPerfectSquare(int N)
{
    /*
    A Function that takes an integer and outputs the largest perfect square number that is less than it.
    Complexity: O(1) as no loops nor recursion is used.
    */

    //cast the result to an int to drop the remainder
    int x = sqrt(N);
    return x*x;
};

void task1()
{
    int n;
    cout << "Input your number: " << endl;
    while (!(cin >> n))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    int result = largestPerfectSquare(n);
    cout << "Largest Perfect Square: "<< result << endl;
}

/*
PSEUDOCODE:

LARGESTPERFECTSQR(N)
    X <- square_root(N)
    RETURN INT(x) * INT(x)
END
*/

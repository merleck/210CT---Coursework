#include <iostream>
#include <string>

using namespace std;

string reverseString(string text, int lindex, int rindex)
{
    /*
    A function that takes in a string with its start position and
    end position and then reverses it and outputs the reversed string.
    The complexity is O(n) due to a single loop
    */

    char temp;
    while (lindex < rindex)
    {
        //swap the first element with the last and increment and decrement
        //the index values appropriately.
        temp = text[lindex];
        text[lindex] = text[rindex];
        lindex = lindex + 1;
        text[rindex] = temp;
        rindex = rindex -1;
    }
    return text;
};

string reverseWords(string text)
{
    /*
    A function that takes in a string, reverses the whole string and
    and then reverses each word. This creates a string with only the word
    order reversed. This outputs the reversed word string.
    The complexity is O(n^2) due to the use of an O(n) function inside a loop
    (worst case).
    The complexity for the average case is O(n log n) as the reverseString
    function will only be called every time an empty space happens rather than
    every letter.
    */

    int start = 0;
    //store the length for future use
    int length = text.length();

    //if the string is not empty
    if (length > 0)
    {
        //reverse the whole string
        text = reverseString(text,start,length-1);

        //iterate over string and when you reach a space or the end reverse
        //the string between the current position and the first position of
        //the word
        for (int rindex = 0; rindex < length+1; rindex++) //O(n)
        {
            if (rindex == length || text[rindex] == ' ')    //O(log n)?
            {
                //reverse the word
                text = reverseString(text,start,rindex-1); //O(n) x O(n)
                //set start to beginning of next word
                start = rindex+1;
            }
        }
    }
    return text;
};

void task1()
{
    cout << "Task 1:" << endl << endl;

    cout << reverseWords("I hated this task") << endl;
}


/*
PSEUDOCODE:

REVERSESTRING ( TEXT , LINDEX , RINDEX )
    WHILE ( LINDEX < RINDEX )
        temp <- TEXT[LINDEX]
        TEXT[LINDEX] <- TEXT[RINDEX]
        LINDEX <- LINDEX + 1
        TEXT[RINDEX] <- temp
        RINDEX <- RINDEX - 1
    ENDWHILE
    RETURN TEXT
END

REVERSEWORDS ( TEXT )
    START <- 0
    IF ( length of TEXT > 0 )
        TEXT <- REVERSESTRING( TEXT, START, length of TEXT-1 )
        FOR ( RINDEX <- 0 TO length of TEXT+1 )
            IF ( RINDEX = length of TEXT OR TEXT[RINDEX] = space character)
                TEXT <- REVERSESTRING( TEXT, START, RINDEX-1 )
                START <- RINDEX+1
            ENDIF
        ENDFOR
    ENDIF
    RETURN TEXT
END
*/

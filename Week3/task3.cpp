#include <iostream>
#include <string>

using namespace std;

bool isVowel(char letter)
{
    /*
    A function that checks if a character is a vowel
    O(1) no loops or recursion.
    */

    letter = tolower(letter);
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
};

string removeVowels(string text)
{
    /*
    A recursive function that removes the vowels of a given string
    and returns everything else as it was. O(n) due to recursion.
    */

    //if at end of string (or is actually empty) return the string
    if (text.empty())
    {
        return text;
    }
    //if the first character is a vowel
    else if (isVowel(text.at(0)))
    {
        //run function on rest of string
        return removeVowels(text.substr(1));
    }
    //return the first character plus the result of the function on the rest of the string
    return  text[0] + removeVowels(text.substr(1));
};

void task3()
{
    cout << endl << "Task 3:" << endl << endl;

    string input;
    cout << "Input a string: " << endl;

    //needed to clear unread inputs due to populating cin for previous task
    cin.sync();

    //Use to get the input until a new line rather than until a space
    getline(cin ,input);

    cout << "Your input without vowels would look like: " << removeVowels(input) << endl;

}

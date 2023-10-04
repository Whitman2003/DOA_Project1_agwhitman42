/************************************
*   Filename:   agwhitman42_prog1   *
*   Author:     Aidan Whitman       *
*   Date:       August 28, 2023     *
*   Class:      Design of Algorithms*
*   Assignment: Project 1           *
************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

int Euclid(int*, int*, int*, int*);
int min(int*, int*);
int CICA(int*, int*);
int middleSchool(int, int);
void findFactors(int, int*);

int main()
{
    /////////////////
    //   Part 1    //
    /////////////////

    //Definition
    cout << "Part 1: Exercice 1.1: 11a /page 8 (Page 30 in my book)" << endl;
    cout << "A description of the extended Euclid's Algorithm is a set of steps used to find the greatest common divisor by applying repeated remainders through division." << endl;

    //Gather both integers used
    cout << "\nWhat is integer 1: ";
    int first;
    cin >> first;
    cout << endl;

    cout << "What is integer 2: ";
    int second;
    cin >> second;
    cout << endl;

    //Variables used for the extended euclid algorithm
    int x, y;

    int* rfirst = &first;
    int* rsecond = &second;

    //Runs Euclid to gather the answer and prints
    int gcd = Euclid(rfirst, rsecond, &x, &y);

    //If both are zero, the answer will always be undefined
    if(*rfirst == 0 && *rsecond == 0)
    {
        cout << "The answer is undefined." << endl;
    }

    else
    {
        cout << "gcd(" << first << ", " << second << ") = " << abs(gcd) << "." << endl << endl;
    }

    //////////////
    //  Part 2  //
    //////////////

    cout << "Part 2: Implement consecutive integer checking algorithm for computing gcd(m, n)." << endl;
    
    //Gather both integers
    cout << "What is integer m: ";
    int m;
    cin >> m;
    cout << endl;

    cout << "What is integer n: ";
    int n;
    cin >> n;
    cout << endl;

    //Runs CICA to gather the answer and prints
    int a = m;
    int b = n;

    int* ptrm = &a;
    int* ptrn = &b;
    int answer2 = CICA(ptrm, ptrn);

    //If both are zero, the answer will always be undefined
    if(*ptrm == 0 && *ptrn == 0)
    {
        cout << "The answer is undefined." << endl << endl;;
    }

    //Both else if check if one variable is 0
    //If so, the other integer will always be the answer
    else if(m == 0 && n != 0)
    {
        cout << "gcd(" << m << ", " << n << ") = " << abs(n) << endl << endl;
    }

    else if(m != 0 && n == 0)
    {
        cout << "gcd(" << m << ", " << n << ") = " << abs(m) << endl << endl;
    }

    else
    {
        cout << "gcd(" << m << ", " << n << ") = " << abs(answer2) << "." << endl << endl;
    }

    /////////////////////////
    //   Optional Part 3   //
    /////////////////////////

    cout << "Optional Part 3: " << endl;

    //Gathers both integers
    cout << "What is the first integer: ";
    int f;
    cin >> f;

    cout << "What is the second integer: ";
    int s;
    cin >> s;

    //Runs the middleSchool algorithm to find the gcd
    int gcd3 = middleSchool(f, s);

    //If both are zero the answer will always be undefined
    if(f == 0 && s == 0)
    {
        cout << "The gcd is undefined." << endl;
    }

    //If one is 0 but not the other, the answer will always be the other
    else if(f == 0 && s != 0)
    {
        cout << "gcd(" << f << ", " << s << ") = " << abs(s) << endl << endl;
    }

    else if(f != 0 && s == 0)
    {
        cout << "gcd(" << f << ", " << s << ") = " << abs(f) << endl << endl;
    }

    else
    {
        cout << "gcd(" << f << ", " << s << ") = " << abs(gcd3) << endl;
    }
}

//Purpose:      Computes the greatest common divisor by Euclid's Algorithm
//Parameters:   User given integers
int Euclid(int* first, int* second, int* x, int *y)
{
    //Base Case
   if(*first == 0)
   {
    *x = 0;
    *y = -1;
    return *second;
   }

   //Stores the results of the recursive call
   int x1, y1;

   //Makes new integers to compute the first % second
   int newSecond = *second;
   int newFirst = *first;
   int total = newSecond % newFirst;

   //Recursively calls Euclid
   int gcd = Euclid(&total, first, &x1, &y1);


    //Updates x and y based on the recursive call
   *x = y1 - (*second / *first) * x1;
   *y = x1;

    //Returns the answer (gcd)
   return gcd;
}

//Purpose:      Finds the minimum of 2 numbers
//Arguments:    User given integers
int min(int* m, int* n)
{
    //If m is greater than m, n will be the smallest
    if(*m > *n)
    {
        return *n;
    }

    return *m;
}

//Purpose:      To gather the greatest common divisor
//Parameters:   User given integers
int CICA(int* m, int* n)
{
    //Finds the minimum value and stores it in t
    int t = min(m, n);

    //Runs while t does not dip below 0
    while(t != -1)
    {
        int secondM = *m;
        int secondN = *n;

        //Base Case
        if(t == 0)
        {
            return t;
        }

        //Checks if t is a divisor of m
        if(secondM % t == 0)
        {
            //Checks if t is a divisor of n
            //If both, it is the gcd
            if(secondN % t == 0)
            {
                return t;
            }
        }
        t--;
    }

    //Run failed
    return -1;
}

//Purpose:      Finds the gcd by using the middle school technique
//Parameters:   User given integers
int middleSchool(int first, int second)
{
    //Creates an array filled with 0s and fills it based on the first integer
    int firstArray[first] = { 0 };
    findFactors(first, firstArray);

    //Creates an array filled with 0s and fills it based on the second integer
    int secondArray[second] = { 0 };
    findFactors(second, secondArray);

    //Sets starting values
    int i = 0;
    int j = 0;
    int gcd = 0;

    //Runs while both arrays are not 0s
    while(firstArray[i] != 0 && secondArray[j] != 0)
    {
        //If both are equal, the gcd will be set
        if(firstArray[i] == secondArray[j])
        {
            gcd = firstArray[i];
            i++;
            j++;
        }

        //If firstArray[i] is greater than secondArray[j], j should increment but not i
        else if(firstArray[i] > secondArray[j])
        {
            j++;
        }

        //If secondArray[j] is greater than firstArray[i], i should increment but not j
        else
        {
            i++;
        }
    }

    //Returns the gcd
    return gcd;
}

//Purpose:  Fills and array from user input
void findFactors(int num, int array[])
{
    //Starting value for the array
    int j = 0;

    //Runs until num-1 is reached
    for(int i = 1; i < num-1; i++)
    {
        //If i is a gcd, it is stored in the array
        if(num % i == 0)
        {
            array[j] = i;
            j++;
        }
    }
}
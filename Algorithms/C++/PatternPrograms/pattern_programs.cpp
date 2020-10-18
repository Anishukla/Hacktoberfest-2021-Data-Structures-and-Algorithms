/* 
 * Some useful logical pattern programs in C++ - Irfan Shaikh
 * 
*/

//                                #pattern 1
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
output-of-pattern-1: 

Enter a number: 5
*
**
***
****
*****
*/

/*
                                #pattern2
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i <= (n - 1); i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = n - i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
output: 
Enter a number: 5
    *
   **
  ***
 ****
*****
 ****
  ***
   **
    *
  
*/

/*
                                #pattern3
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 2; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i <= (n - 1); i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = n - i; j > 0; j--)
        {
            cout << "*";
        }
        for (int j = n - i; j > 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
output: 
Enter a number: 5
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
//Above program can be implemented with this logic also,
for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2*i-1; j++)    //note j <= 2*i-1;
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2*i-1; j++)    //note j <= 2*i-1;
        {
            cout << "*";
        }
        cout << endl;
*/

/*
                                #pattern4
//This program is exactly similar to the pattern2 program with only differnce
//being that we have added an extra space with print.                                 
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";   //note extra space
        }
        cout << "\n";
    }
    for (int i = 1; i <= (n - 1); i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = n - i; j > 0; j--)
        {
            cout << "* ";   //note extra space
        }
        cout << endl;
    }
}
output:
Enter a number: 5
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
 * * * * 
  * * * 
   * * 
    *                                 
*/

/*
                                #pattern5
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j; 
            
//if we type cast it like , static_cast<char>(j+64); we will get ouptut 2
        }
        cout << endl;
    }
}
output-1:
Enter a number: 5
1
12
123
1234
12345
output-2:
Enter a number: 5
A
AB
ABC
ABCD
ABCDE
*/

/*
                                #pattern6
#include <iostream>
#define el endl
using namespace std;
void pattern (int n);
int main() {
    int num {};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern (int n) {
    for (int i =1; i <= n; i++) {
       for (int j = 1; j <= n-i; j++) {
           cout << " ";
       }
       for (int j = 1; j <= i; j++) {
           cout << j;
       }
       for (int j = i-1; j >= 1; j--) {
           cout << j;
       }
       cout << el;
    }
}
output:
Enter a number: 5
    1
   121
  12321
 1234321
123454321                               
*/

/*
                                #pattern7
#include <iostream>
#define el endl
using namespace std;
void pattern (int n);
int main() {
    int num {};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern (int n) {
    for (int i =1, k = 1; i <= n; i++) {
       for (int j = 1; j <= i; j++) {
           cout << k++ << " ";
       }
       cout << el;
    }
}
output:
Enter a number: 4
1 
2 3 
4 5 6 
7 8 9 10                                 
//if we type cast value of k to character type then we wil get below pattern,
//example: cout << static_cast<char>(k+64) << " "; k++;
Enter a number: 5
A 
B C 
D E F 
G H I J 
K L M N O 
 
*/

/*
                                #pattern8
#include <iostream>
#define el endl
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j ++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << el;
    }
}
output:
Enter a number: 5
    1
   22
  333
 4444
55555                               
*/

/*
                                #pattern9
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; 
        }
        for (int j = 1; j <= i; j++) {
            cout << static_cast<char>(i+64) << " ";
        }
        cout << endl;
    }
}                               
 
output:
Enter a number: 4
   A 
  B B 
 C C C 
D D D D 
*/

/*
                                #pattern10
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << static_cast<char>(j + 79);
        }
        cout << endl;
    }
}
output:
Enter a number: 5
P
PQ
PQR
PQRS
PQRST
*/

/*
                                #pattern11
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        for (int j = 1; j <= i-1; j++)
        {
            cout << static_cast<char>(j+64);
        }
        cout << endl;
    }
}                                
output:
Enter a number: 5
    1
   21A
  321AB
 4321ABC
54321ABCD
*/

/*
                                #pattern12
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{5};
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1, k = 5; i <= n; i++,  k--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << k;
        }
        cout << endl;
    }
}
output:
5
44
333
2222
11111                                
*/

/*
                                #pattern13
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{4};
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i-1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= n - (i -1); j++) {
            cout << static_cast<char>(j + 64);
        }
        cout << endl;
    }
}
output:
ABCD
 ABC
  AB
   A
   
*/

/*
                                #pattern14
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{5};
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
            (j == i) ? cout << "*" : cout << j;
        cout << endl;
    }
}               
output:
5432*
543*1
54*21
5*321
*4321                 
*/

/*
                                #pattern15
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int k = 2*(i-1);
        for (int j = 1, k = i; j <= i; j++) {
            cout << k++;
        }
        for (int j = 1; j <= i - 1; j++) {
            cout << k--;
        }
        cout << endl;
    }
}
output:
Enter a number: 5
1
232
34543
4567654
567898765                                
*/

/*
                                #pattern16
#include <iostream>
using namespace std;
void pattern(int n);
int main()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    pattern(num);
    return 0;
}
void pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 1; j <= i; j++)
                cout << j;
        }
        else
        {
            for (int j = i; j > 0; j--)
                cout << j;
        }
        cout << endl;
    }
}
output:
Enter a number: 5
1
21
123
4321
12345                                
*/
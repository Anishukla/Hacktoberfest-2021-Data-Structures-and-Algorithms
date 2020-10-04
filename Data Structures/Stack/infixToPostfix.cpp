#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cout<<"Enter No. of Equation:";
	cin >> tc;
    string str;
    while (tc-- > 0) {
        stack<char> s;
	    cout<<"Enter Infix Equation:";
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] <= 'z' && str[i] >= 'a')
                cout << str[i];
            else if (str[i] != ')')
                s.push(str[i]);
            else {
                while (s.top() != '(') {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
        }
        cout << endl;
    }

    return 0;
}

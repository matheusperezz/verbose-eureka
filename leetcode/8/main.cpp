#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <climits>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 *  Test case failling: "words and 987"
 *  Try to use python :)
 *
 * **/

int myAtoi(string s)
{
    vector<int> v;
    int v_size;
    bool isPositive = true;
    int output = 0;
    string nums = "1234567890";
    string letters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.";
    string signals = "-+";
    unordered_map<char, int> alphanum;
    alphanum['1'] = 1;
    alphanum['2'] = 2;
    alphanum['3'] = 3;
    alphanum['4'] = 4;
    alphanum['5'] = 5;
    alphanum['6'] = 6;
    alphanum['7'] = 7;
    alphanum['8'] = 8;
    alphanum['9'] = 9;
    alphanum['0'] = 0;

    for (char c : s)
    {
        size_t pos = nums.find(c);
        size_t letpos = letters.find(c);
        size_t signpos = signals.find(c);
        if (letpos != string::npos)
        {
            int mapnum = alphanum[c];
            v.push_back(mapnum);
        }
        if (pos != string::npos)
        {
            cout << "Letter first" << endl;
        }

        if (signpos != string::npos)
        {
            if (c == '-')
            {
                isPositive = false;
            }
            else if (c == '+')
            {
                isPositive = true;
            }
        }
    }

    // Removing the initial 0's
    int count = 0;
    while (count < v.size() - 1)
    {
        if (v[count] == 0)
        {
            v.erase(v.begin() + count);
        }
        else
        {
            break;
        }
    }

    // Making the magic :p
    v_size = v.size() - 1;
    for (int i = 0; i < v.size(); i++)
    {
        output += (v[i] * pow(10, v_size - i));
    }

    // Printing the array
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;

    if (isPositive)
    {
        return output;
    }
    else
    {
        return output * -1;
    }
}

int main()
{
    string s = "000133ab-0.";
    cout << "Myatoi: " << myAtoi(s) << endl;

    return 0;
}
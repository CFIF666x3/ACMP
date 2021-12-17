
﻿using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#pragma warning(disable : 4996)

string to_string(int n)
{
    string s="";
    while (n > 0)
    {
        s = char(n % 10 + 48) + s;
        n = n / 10;
    }
    return s;
}
class Strong
{
private:
    string data;
    void mult(int val)
    {
        string ans = "", dop = "0"; int l = data.length();
        for (int i = 1; i <= l; i++)
        {
            int n = (data[l - i] - 48) * val + dop[0] - 48;
            ans = char(n % 10 + 48) + ans;
            dop = char(n / 10 + 48) + dop;
        }
        if (dop[0] != '0') ans = dop[0] + ans;
        data = ans;
    }
public:
    Strong(string n)
    {
        data = n;
    }
    Strong()
    {
        data = "";
    }
    Strong operator=(string s)
    {
        data = s;
        return *this;
    }
    Strong operator+(Strong s)
    {
        string ans = "", dop = "0"; int min, max, f;
        if (data.length() < s.data.length())
        {
            min = data.length();
            max = s.data.length();
            f = 0;
        }
        else
        {
            min = s.data.length();
            max = data.length();
            f = 1;
        }
        for (int i = 1; i <= min; i++)
        {
            int n = data[data.length() - i] + s.data[s.data.length() - i] + dop[0] - 144;
            ans = char(n % 10 + 48) + ans;
            dop = char(n / 10 + 48) + dop;
        }
        for (int i = min + 1; i <= max; i++)
        {
            int n;
            if (f == 1) n = data[data.length() - i] + dop[0] - 96;
            if (f == 0) n = s.data[data.length() - i] + dop[0] - 96;
            ans = char(n % 10 + 48) + ans;
            dop = char(n / 10 + 48) + dop;
        }
        if (dop[0] == '1') ans = '1' + ans;
        return ans;
    }
    Strong operator*(Strong s)
    {
        int min, max, f; Strong ans("0");
        if (data.length() < s.data.length())
        {
            min = data.length();
            max = s.data.length();
            f = 0;
        }
        else
        {
            min = s.data.length();
            max = data.length();
            f = 1;
        }
        for (int i = 1; i <= min; i++)
        {
            Strong dop;
            if (f == 1)
            {
                dop = data;
                //dop.mult(s.data[s.data.length() - i] - 48);
            }
            if (f == 0)
            {
                dop = s.data; 
                //dop.mult(data[data.length() - i] - 48);
            }
            for (int j = 0; j < i; j++) dop.data = dop.data + '0';
            ans = ans + dop;
        }
        return ans;
    }
    Strong opa(int n)
    {
        Strong a;
        a.data = data;
        a.mult(n);
        return a;
    }
    void print()
    {
        cout << data;
    }
};
int main() 
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
    Strong a("123"), b("11"), c;
    c = a * b;
    c.print();
}

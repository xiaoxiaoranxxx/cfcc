#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

map<int, int> mp;

int main()
{
    int n;

    mp[1] = 2;
    mp[2] = 3;
    mp[4] = 5;
    for (auto i : mp)
        cout << i.first << endl;
}
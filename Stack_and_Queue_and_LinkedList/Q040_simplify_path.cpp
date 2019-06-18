// #include<bits/stdc++.h>
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

string simplifyPath(string path)
{
    stack<string> dir;
    string res = "", val;
    stringstream ss(path);
    while (getline(ss, val, '/'))
    {
        if (val.size() == 0 || val == ".")
            continue;
        if (val == "..")
        {
            if (!dir.empty())
                dir.pop();
        }
        else
        {
            dir.push(val);
        }
    }

    if (dir.empty())
        return "/";

    while (!dir.empty())
    {
        res = "/" + dir.top() + res;
        dir.pop();
    }
    return res;
}

string simplifyPath_02(string path)
{
    stack<string> dir;
    int i = 0;
    while (i < path.length())
    {

        string s(1, path[i]);
        i++;
        while (i < path.length() && path[i] != '/')
        {
            s += path[i];
            i++;
        }

        if (s == "/.." && !dir.empty())
            dir.pop();
        else if (s != "" && s != "/." && s != "/" && s != "/..")

            dir.push(s);
    }

    if (dir.empty())
        return "/";

    string res = "";
    while (!dir.empty())
    {
        res = dir.top() + res;
        dir.pop();
    }
    return res;
}

void solve()
{
    string st;
    cin >> st;
    cout << simplifyPath_02(st) << endl;
}

int main(int args, char **argc)
{
    solve();
    return 1;
}
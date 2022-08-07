#include <iostream>
using namespace std;
#include <string>
int lcs3(string s, string t)
{ /// DP
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    // Fill 1st row
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // check if ist character matches
            if (s[m - i] == t[n - j])
            { ////  index of string
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}
int lcs2(string s, string t, int **ans)
{ // Memoization
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }
    // check if ans already exist
    if (ans[s.size()][t.size()] != -1)
    {
        return ans[s.size()][t.size()];
    }
    // recursive calls
    int out;
    if (s[0] != t[0])
    {
        int a = lcs2(s.substr(1), t, ans);
        int b = lcs2(s, t.substr(1), ans);
        int c = lcs2(s.substr(1), t.substr(1), ans);
        out = max(a, max(b, c));
    }
    else
    {

        out = 1 + lcs2(s.substr(1), t.substr(1), ans);
    }
    ans[s.size()][t.size()] = out;
    return out;
}
int lcs2(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            ans[i][j] = -1;
        }
    }

    return lcs2(s, t, ans);
}
int lcs(string s, string t)
{ //
    // Base case
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }
    // recursive calls
    if (s[0] != t[0])
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
    else
    {

        return 1 + lcs(s.substr(1), t.substr(1));
    }
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    cout << lcs2(s, t) << endl;
    cout << lcs3(s, t) << endl;
}
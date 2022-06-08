#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int siz;

int nums[100];

int bb (int i, int j)
{

    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = 0;

    for (int x = i; x <= j; x++)
    {
        int l = (i == 0) ? 1 : nums[i - 1];
        int r = (j == siz - 1) ? 1 : nums[j + 1];
        // int temp=bb(nums,i,x-1,)+bb(nums,x+1,j)+l*nums[x]*r;
        int temp = bb (i, x - 1) + bb (x + 1, j);
        int ans;

        if (l == 1 and r == 1)
            ans = nums[x];

        else
            ans = l * r;
        temp += ans;

        maxi = max (maxi, temp);
    }
    dp[i][j] = maxi;
    return maxi;
}

int main ()
{
//int siz;
cin >> siz;
//int A[siz];

for (int i = 0; i < siz; i++)
    cin >> nums[i];

memset (dp, -1, sizeof (dp));
int ans = bb (0, siz - 1);
cout << ans << endl;
return 0;
}
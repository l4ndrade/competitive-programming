#include<bits/stdc++.h>
using namespace std;

// Finds greatest subarray sum
int kadane(vector<int>& v)
{
    int curr = 0; // Current sum
    int best = 0; // Best sum
    int i = 0, j = 0; // Best range
    int last = 0; // Last reset
    for(int idx = 0 ; idx < v.size() ; idx++)
    {
        curr+=v[idx];

        if(curr > best)
        {
            best = curr;
            i = last;
            j = idx;
        }

        if(curr < 0)
        {
            last = i+1;
            curr = 0;
        }
    }
    return best;
}

int main()
{
    vector<int> v(5);
    for(int i = 0 ; i < 5 ; i++)
    {
        cin >> v[i];
    }

    cout << kadane(v) << endl;
}
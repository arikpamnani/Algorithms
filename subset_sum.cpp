#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > subsets;
int arr[1007];
int dp[1007][1007];

void get_subsets(int i, int sum, vector<int>& p) {
    if(i==0 && sum==0) {
        subsets.push_back(p);
        return;
    }
    if(i==0 && dp[i][sum] && sum!=0) {
        p.push_back(arr[i]);
        subsets.push_back(p);
        return;
    }
    if(dp[i-1][sum]) {
        vector<int> q=p;
        get_subsets(i-1, sum, q);
    }
    if(sum>=arr[i] && dp[i-1][sum-arr[i]]) {
        p.push_back(arr[i]);
        get_subsets(i-1, sum-arr[i], p);
    }
}

int subset_sum(int n, int sum) {
    for(int i=0; i<n; i++) {
        dp[i][0]=1;
    }
    for(int j=1; j<=sum; j++) {
        dp[0][j]=int(arr[0]==j);
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<=sum; j++) {
            if(j>=arr[i]) {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n-1][sum];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int sum;
    scanf("%d", &sum);
    cout<<subset_sum(n, sum)<<"\n";
    vector<int> p;
    get_subsets(n-1, sum, p);
    for(int i=0; i<subsets.size(); i++) {
        for(int j=0; j<subsets[i].size(); j++)
            cout<<subsets[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}


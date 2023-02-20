
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    vector<pair <int,pair<int,int>>> v;
    int n,a,b;
    cout<<"Input Number of Process(s): ";
    cin>>n;
    for(int i=0; i < n; i++)
    {
        cout<<"Input burst time of p"<<i+1<<": ";
        cin>>b;
        cout<<"Input priority: ";
        cin>>a;
        v.push_back(make_pair(a, make_pair(i+1,b)));
    }
    cout<<endl;
    sort(v.begin(),v.end());
    cout<<"Process      Burst time      Priority"<<endl;
     for(int j=0; j<v.size(); j++)
    {
        cout<<"P"<<v[j].second.first<<"             "<<v[j].second.second<<"             "<<v[j].first<<endl;
    }
}

#include<bits/stdc++.h>
#include <cstdio>
#include<vector>
using namespace std;

int main()
{
    freopen("file1.txt","r", stdin);
    vector<pair<int,pair<int,int>>> v;
    int a,b, n;


    cout<<"Enter number of process: ";
    cin>>n;
    cout<<endl;

    for(int i =0; i<n; i++)
    {
        cout<<"Enter arrival time of P"<<i+1<<": ";
        cin>>a;
        cout<<"Enter burst time of P"<<i+1<<": ";
        cin>>b;
        v.push_back(make_pair(a, make_pair(i+1,b)));
    }
    sort(v.begin(),v.end());
    cout<<endl;
    cout<<"Process"<<"       "<<"Arrival Time"<<"      "<<"Burst Time"<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].second.first<<"                 "<<v[i].first<<"                     "<<v[i].second.second<<endl;
    }


    //ghantt chart

    cout<<"Ghantt chart: "<<endl;
    for(int i =0; i<v.size(); i++)
    {
        cout<<"|";
        for(int j=0; j<v[i].second.second; j++)
        {
            cout<<"''";
        }

    }
    cout<<"|";

    cout<<endl;
    for(int i =0; i<v.size(); i++)
    {

        for(int j=0; j<v[i].second.second; j++)
        {
            cout<<" ";
        }
        cout<<"P"<<v[i].second.first;
        for(int j=0; j<v[i].second.second; j++)
        {
            cout<<" ";
        }

    }
    cout<<endl;

    for(int i =0; i<v.size(); i++)
    {
        cout<<"|";
        for(int j=0; j<v[i].second.second; j++)
        {
            cout<<",,";
        }

    }
    cout<<"|";
}

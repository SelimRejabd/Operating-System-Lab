#include<bits/stdc++.h>
#include<vector>

/*
Sample input [save this value in txt file name as "sjf.txt" in the same folder with the code]
5
0 4
0 6
0 3
0 5
0 4

*/

using namespace std;


int main()
{
    freopen("sjf.txt", "r", stdin);
    vector <pair<int, pair <int, int>>> v;
    vector <int> ct;
    vector <int> tat;
    vector <int> wt;
    int a, b, n;
    int ct1 = 0, tat1 = 0, wt1 = 0;
    int noOfProcess;

    double a_wt = 0, a_tat = 0;
    double total_tat = 0, total_wt = 0;

    cout<<"Enter number of precess: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter burst time of P"<<i+1<<": ";
        cin>>a;
        cout<<"Enter arrival time of P"<<i+1<<": ";
        cin>>b;
        v.push_back(make_pair(b, make_pair(i+1, a)));
    }

    sort(v.begin(), v.end());

    cout<<"\n\n";

    for(int i=0; i<v.size(); i++)
    {
        ct1 = ct1 + v[i].first;
        tat1 = ct1 - v[i].second.second;
        wt1 = tat1 - v[i].first;
        wt.push_back(wt1);
        tat.push_back(tat1);
        ct.push_back(ct1);
    }

    for(int k=0; k<tat.size(); k++)
    {
        total_tat += tat[k];
        total_wt += wt[k];
    }
    noOfProcess = v.size();
    a_tat = total_tat/noOfProcess;
    a_wt = total_wt/noOfProcess;
    cout<<"Process"<<"   "<<"Burst time"<<"   "<<"Arrival time"<<"    "<<"TAT"<<"    "<<"Waiting time"<<endl;

    for(int j=0; j<v.size(); j++)
    {
        cout<<"P"<<v[j].second.first
        <<"         "
        <<v[j].first
        <<"              "
        <<v[j].second.second
        <<"              "
        <<tat[j]
        <<"     "<<wt[j]
        <<endl;
    }
    cout<<"\n\n";
    cout<<"Avarage turn around time: "<<a_tat<<endl;
    cout<<"Avarage waiting time: "<<a_wt<<endl;

    //ghantt chart
    cout<<"\n\n";

    cout<<"Ghantt chart: \n\n";
    for(int i =0; i<v.size(); i++)
    {
        cout<<"|";
        for(int j=0; j<v[i].first; j++)
        {
            cout<<"''";
        }

    }
    cout<<"|";

    cout<<endl;
    for(int i =0; i<v.size(); i++)
    {

        for(int j=0; j<v[i].first; j++)
        {
            cout<<" ";
        }
        cout<<"P"<<v[i].second.first;
        for(int j=0; j<v[i].first; j++)
        {
            cout<<" ";
            j++;
        }

    }
    cout<<endl;

    for(int i =0; i<v.size(); i++)
    {
        cout<<"|";
        for(int j=0; j<v[i].first; j++)
        {
            cout<<",,";
        }

    }
    cout<<"|"<<endl;

}

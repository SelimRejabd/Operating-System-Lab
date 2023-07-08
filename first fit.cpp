#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{

    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> partitions(n);
    for(int i=0; i<n; i++)
    {
        cin>>partitions[i];
    }

    int s;
    cin>>s;
    for(int i=0; i<partitions.size(); i++)
    {
        if(partitions[i] >= s)
        {
            cout<<"The process is allocated into "<<partitions[i]<<"Mb memory partitions"<<endl;
            return 0;
        }

    }
    cout<<"No partitions is fit for the process."<<endl;
}

/*
sample input:
8
2 7 12 4 6 32 44 21
10

sample output:
The process is allocated into 32Mb memory partitions.

sample input:
8
2 7 32 12 4 6  44 21
45

sample output:
No partitions is fit for the process.

*/

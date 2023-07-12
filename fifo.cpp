#include <bits/stdc++.h>

using namespace std;

void printState(vector<int> frames)
{
    for (int x: frames)
    {
        cout << " ";
        x == -1 ? cout << "-" : cout << x;
    }
    cout << "\n";
}

int main()
{
    int size;
    cout<<"Enter frame number: ";
    cin >> size;
    vector<int> frames(size, -1);
    int miss = 0, page;

    int index = 0;
    cout<<"Enter pages: ";

    while(cin >> page)
    {
        bool found = false;
        for (int x: frames)
        {
            if (x == page)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << page << " ->\n";
            continue;
        }
        miss++;
        frames[index] = page;
        index = (index + 1) % size;
        cout << page << " ->";
        printState(frames);
    }
    cout << "Total page fault = " << miss;
}

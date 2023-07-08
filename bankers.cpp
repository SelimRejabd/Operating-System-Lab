#include <iostream>
#include <vector>

using namespace std;

const int MAX_PROCESSES = 100;
const int MAX_RESOURCES = 100;

int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max_need[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES];

void init(int num_resources) {
    cout << "Enter the number of available resources: ";
    for (int i = 0; i < num_resources; i++) {
        cin >> available[i];
    }
    cout << "Enter the number of processes: ";
    int num_processes;
    cin >> num_processes;
    cout << "Enter the allocation matrix:" << endl;
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> allocation[i][j];
        }
    }
    cout << "Enter the max need matrix:" << endl;
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> max_need[i][j];
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
    for (int i = 0; i < num_processes; i++) {
        finish[i] = false;
    }
}

bool is_safe(int num_processes, int num_resources) {
    int work[MAX_RESOURCES];
    for (int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }
    vector<int> safe_sequence;
    bool found;
    do {
        found = false;
        for (int i = 0; i < num_processes; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                //cout<<"jjjjjjj: "<<j<<endl;
                if (j == num_resources) {
                    for (j = 0; j < num_resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safe_sequence.push_back(i);
                    found = true;
                }
            }
        }
    } while (found);
    if (safe_sequence.size() == num_processes) {
        cout << "Safe sequence:";
        for (int i = 0; i < num_processes; i++) {
            cout << " " << safe_sequence[i];
        }
        cout << endl;
        return true;
    } else {
        cout << "Unsafe state" << endl;
        return false;
    }
}

int main() {
    int num_resources;
    freopen("banker.txt", "r", stdin);
    cout << "Enter the number of resource types: ";
    cin >> num_resources;
    init(num_resources);
    is_safe(num_resources, MAX_PROCESSES);
    return 0;
}



#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 10;

int n;
int graph[MAX][MAX];
int finalPath[MAX]; 
int finalCost = INT_MAX;

void copyToFinalPath(int currentPath[]) {
    for (int i = 0; i < n; i++)
        finalPath[i] = currentPath[i];
    finalPath[n] = currentPath[0];
}

int firstMin(int i) {
    int min = INT_MAX;
    for (int k = 0; k < n; k++)
        if (graph[i][k] < min && i != k)
            min = graph[i][k];
    return min;
}

int secondMin(int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (i == j)
            continue;
        if (graph[i][j] <= first) {
            second = first;
            first = graph[i][j];
        } else if (graph[i][j] <= second && graph[i][j] != first) {
            second = graph[i][j];
        }
    }
    return second;
}

void TSPRec(int curr_bound, int curr_weight, int level, int currentPath[]) {
    if (level == n) {
        if (graph[currentPath[level - 1]][currentPath[0]] != 0) {
            int curr_cost = curr_weight + graph[currentPath[level - 1]][currentPath[0]];
            if (curr_cost < finalCost) {
                copyToFinalPath(currentPath);
                finalCost = curr_cost;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[currentPath[level - 1]][i] != 0 && find(currentPath, currentPath + level, i) == currentPath + level) {
            int temp = curr_bound;
            curr_weight += graph[currentPath[level - 1]][i];

            if (level == 1)
                curr_bound -= (firstMin(currentPath[level - 1]) + firstMin(i)) / 2;
            else
                curr_bound -= (secondMin(currentPath[level - 1]) + firstMin(i)) / 2;

            if (curr_bound + curr_weight < finalCost) {
                currentPath[level] = i;
                TSPRec(curr_bound, curr_weight, level + 1, currentPath);
            }

            curr_weight -= graph[currentPath[level - 1]][i];
            curr_bound = temp;

            fill(currentPath + level, currentPath + n, -1);
        }
    }
}

bool visited[MAX];

void TSP() {
    int currentPath[MAX];
    int curr_bound = 0;
    fill(currentPath, currentPath + MAX, -1);
    fill(visited, visited + MAX, false);

    for (int i = 0; i < n; i++)
        curr_bound += (firstMin(i) + secondMin(i));

    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    currentPath[0] = 0;
    visited[0] = true;
    TSPRec(curr_bound, 0, 1, currentPath);
}


int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the adjacency matrix representing the graph:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    TSP();

    cout << "Optimal Path: ";
    for (int i = 0; i <= n; i++)
        cout << finalPath[i] << " ";
    cout << endl;

    cout << "Minimum Cost: " << finalCost << endl;

    return 0;
}

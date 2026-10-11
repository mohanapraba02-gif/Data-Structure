#include <iostream>
using namespace std;
#define MAX 10
#define INF 9999

int main() {
    int cities = 4;
    int cost[MAX][MAX];

    // Initialize with INF
    for(int i=1; i<=cities; i++)
        for(int j=1; j<=cities; j++)
            cost[i][j] = INF;

    // Hardcoded from your photo: 1 2 10, 1 3 6, 1 4 5, 2 4 15, 3 4 4
    // If Mam asks for input, you can enter manually too
    cout << "=== GOVT CITY CONNECTION - PRIM'S ALGORITHM ===\n";
    cout << "Cities: 4\nRoads:\n";
    cout << "1-2 10\n1-3 6\n1-4 5\n2-4 15\n3-4 4\n\n";

    cost[1][2] = cost[2][1] = 10;
    cost[1][3] = cost[3][1] = 6;
    cost[1][4] = cost[4][1] = 5;
    cost[2][4] = cost[4][2] = 15;
    cost[3][4] = cost[4][3] = 4;

    int visited[MAX] = {0};
    int parent[MAX];
    int minCost[MAX];

    for(int i=1; i<=cities; i++) minCost[i]=INF;

    minCost[1]=0;
    parent[1]=-1;

    int totalCost=0;

    for(int count=0; count<cities; count++){
        // Find min not visited
        int u=0, min=INF;
        for(int i=1; i<=cities; i++){
            if(!visited[i] && minCost[i]<min){
                min=minCost[i]; u=i;
            }
        }

        visited[u]=1;
        totalCost+=minCost[u];

        if(parent[u]!=-1)
            cout << "Edge added: " << parent[u] << " - " << u << " cost = " << minCost[u] << endl;

        // Update neighbours
        for(int v=1; v<=cities; v++){
            if(cost[u][v]!=INF &&!visited[v] && cost[u][v] < minCost[v]){
                minCost[v]=cost[u][v];
                parent[v]=u;
            }
        }
    }

    cout << "\n----------------------------------\n";
    cout << "Minimum cost to connect all cities: " << totalCost << endl;
    cout << "----------------------------------\n";
    cout << "\nExplanation:\n";
    cout << "Step 1: Start from city 1, connect to cheapest: 1-4 (cost 5)\n";
    cout << "Step 2: From {1,4}, cheapest to outside: 3-4 (cost 4)\n";
    cout << "Step 3: From {1,4,3}, cheapest to outside: 1-2 (cost 10)\n";
    cout << "Total MST = 5+4+10 = 19\n";

    return 0;
}
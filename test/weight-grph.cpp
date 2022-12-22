/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.blogspot.com
 * Problem:   UVA 821 - Page Hopping
 * Technique: Floyd warshall algorithm unweighted directed graph
 *            C++ stl set
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define N 101
#define INF 999999


static int graph[N][N];

int main(){


    int cases = 0;
    int u, v;


    // Scan source node u and its adjacent node v
    // When both u and v zero then exit
    while( scanf("%d%d", &u, &v) && ( u || v )  ){

        // Set is needed to tackle inserting same node twice
        set<int> vec;


        // Since the constraints are simple a 2D matrix will work here
        // Reset all the previously calculated value for new graph
        // Set distances infinite to mark all nodes unreachable from any other node
        // Graph[i][j] holds the distance from node i to node j
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                graph[i][j] = INF;
            }
        }


        // Set the self distances as zero
        for(int i = 0; i < N; ++i){
            graph[i][i] = 0;
        }



        // Minus one as I am mapping node i to node (i-1)
        // Meaning node 1 is represented as node 0 here
        // This is here to handle four 0's in a row for exit
        graph[u-1][v-1] = 1;
        vec.insert(u);
        vec.insert(v);



        // Input a graph if both u and v
        while( scanf("%d%d", &u, &v) && ( u || v ) ){
            // Set the edge weight as 1 since no edge weights will be given
            graph[u-1][v-1] = 1;
            // Insert both nodes into set so that repeating nodes are there only once
            vec.insert(u);
            vec.insert(v);
        }


        // Floyd Warshall algorithm, time complexity: O(N^3)
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    // Check to see if the path can be improved by going through
                    // intermediate node k. Going from i -> .. -> k then k -> .. -> j
                    // Other wise that previously calculated path i -> .. -> j without taking k is shorter
                    if( graph[i][j] > graph[i][k] + graph[k][j] ){
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }



        // For each node just calculate the shortest path to every other node
        // The shortest paths are calculated and stored now on graph matrix
        int sum = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && graph[i][j] != INF){
                    sum = sum + graph[i][j];
                }
            }
        }


        // Just divide the total distance by edge count to get the answer
        int setSize = vec.size();
        printf("Case %d: average length between pages = %.3f clicks\n",  ++cases, (float) sum / (setSize * (setSize-1)));


    }


    return 0;
}
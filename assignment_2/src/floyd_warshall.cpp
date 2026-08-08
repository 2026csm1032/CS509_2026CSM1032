#include<bits/stdc++.h>
#include "floyd_warshall.h"
using namespace std;

bool floydWarshall(vector<vector<long long>>& dist){

    int V=dist.size();

    long long INF=1e18;

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

                if(dist[i][k]==INF || dist[k][j]==INF)continue;

                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<V;i++){
        if(dist[i][i]<0){
            return true;
        }
    }

    return false;
}
#include<bits/stdc++.h>
#include "bellman_ford.h"
using namespace std;

bool bellmanFord(int V,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights,int source,vector<long long>& dist){

    long long INF=1e18;

    dist.assign(V,INF);

    dist[source]=0;

    for(int iter=1;iter<=V-1;iter++){

        bool changed=false;

        for(int u=0;u<V;u++){

            for(int j=row_ptr[u];j<row_ptr[u+1];j++){

                int v=col_idx[j];
                int w=weights[j];

                if(dist[u]==INF)continue;

                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    changed=true;
                }
            }
        }

        if(!changed)break;
        
    }

    for(int u=0;u<V;u++){

        for(int j=row_ptr[u];j<row_ptr[u+1];j++){

            int v=col_idx[j];
            int w=weights[j];

            if(dist[u]==INF)continue;
            
            if(dist[u]+w<dist[v]){
                return true;
            }
        }
    }

    return false;
}
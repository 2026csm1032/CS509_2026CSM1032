#include "prim.h"

pair<long long,vector<pair<pair<int,int>,int>>> primMST(int V,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights){

    vector<int> visited(V,0);

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    pq.push({0,{-1,0}});

    long long totalWeight=0;

    vector<pair<pair<int,int>,int>> mstEdges;

    while(!pq.empty()){

        auto cur=pq.top();
        pq.pop();

        int wt=cur.first;
        int parent=cur.second.first;
        int node=cur.second.second;

        if(visited[node]){
            continue;
        }

        visited[node]=1;

        if(parent!=-1){
            mstEdges.push_back({{parent,node},wt});
            totalWeight+=wt;
        }

        for(int i=row_ptr[node];i<row_ptr[node+1];i++){

            int nxt=col_idx[i];
            int edgeWt=weights[i];

            if(!visited[nxt]){
                pq.push({edgeWt,{node,nxt}});
            }
        }
    }

    return {totalWeight,mstEdges};
}
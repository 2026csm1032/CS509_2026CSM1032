#include "kruskal.h"

class DSU{

    vector<int> parent;
    vector<int> rankv;

public:

    DSU(int n){

        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int x){

        if(parent[x]==x){
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){

        a=find(a);
        b=find(b);

        if(a==b){
            return false;
        }

        if(rankv[a]<rankv[b]){
            swap(a,b);
        }

        parent[b]=a;

        if(rankv[a]==rankv[b]){
            rankv[a]++;
        }

        return true;
    }
};

pair<long long,vector<pair<pair<int,int>,int>>> kruskalMST(int V,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights){

    vector<pair<pair<int,int>,int>> edges;

    for(int u=0;u<V;u++){

        for(int i=row_ptr[u];i<row_ptr[u+1];i++){

            int v=col_idx[i];
            int wt=weights[i];

            if(u<v){
                edges.push_back({{u,v},wt});
            }
        }
    }

    sort(edges.begin(),edges.end(),[](auto& a,auto& b){
        return a.second<b.second;
    });

    DSU dsu(V);

    long long totalWeight=0;

    vector<pair<pair<int,int>,int>> mstEdges;

    for(auto edge:edges){

        int u=edge.first.first;
        int v=edge.first.second;
        int wt=edge.second;

        if(dsu.unite(u,v)){

            mstEdges.push_back(edge);

            totalWeight+=wt;

            if(mstEdges.size()==V-1){
                break;
            }
        }
    }

    return {totalWeight,mstEdges};
}
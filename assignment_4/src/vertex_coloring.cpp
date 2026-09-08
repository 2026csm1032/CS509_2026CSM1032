#include "vertex_coloring.h"

pair<vector<int>,int> vertexColoring(int V,vector<int>& row_ptr,vector<int>& col_idx){

    vector<pair<int,int>> degreeVertex;

    for(int i=0;i<V;i++){

        int degree=row_ptr[i+1]-row_ptr[i];

        degreeVertex.push_back({-degree,i});
    }

    sort(degreeVertex.begin(),degreeVertex.end());

    vector<int> color(V,-1);

    int maxColor=0;

    for(int i=0;i<V;i++){

        int u=degreeVertex[i].second;

        int degree=row_ptr[u+1]-row_ptr[u];

        vector<int> used(degree+2,0);

        for(int j=row_ptr[u];j<row_ptr[u+1];j++){

            int v=col_idx[j];

            if(color[v]!=-1 && color[v]<used.size()){

                used[color[v]]=1;
            }
        }

        int c=0;

        while(c<used.size() && used[c]){

            c++;
        }

        color[u]=c;

        maxColor=max(maxColor,c);
    }

    return {color,maxColor+1};
}
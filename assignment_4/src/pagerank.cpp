#include "pagerank.h"

PageRankResult pageRank(int V,vector<int>& row_ptr,vector<int>& col_idx,double damping,double tolerance,int maxIterations){

    vector<double> rank(V,1.0/V);

    vector<int> outdegree(V);

    for(int i=0;i<V;i++){

        outdegree[i]=row_ptr[i+1]-row_ptr[i];
    }

    vector<vector<int>> incoming(V);

    for(int u=0;u<V;u++){

        for(int j=row_ptr[u];j<row_ptr[u+1];j++){

            int v=col_idx[j];

            incoming[v].push_back(u);
        }
    }

    bool converged=false;

    int iteration=0;

    while(iteration<maxIterations){

        vector<double> newRank(V,(1.0-damping)/V);

        double danglingContribution=0.0;

        for(int u=0;u<V;u++){

            if(outdegree[u]==0){

                danglingContribution+=rank[u];
            }
        }

        danglingContribution=damping*danglingContribution/V;

        for(int v=0;v<V;v++){

            newRank[v]+=danglingContribution;

            for(int u:incoming[v]){

                newRank[v]+=damping*(rank[u]/outdegree[u]);
            }
        }

        double change=0.0;

        for(int i=0;i<V;i++){

            change+=fabs(newRank[i]-rank[i]);
        }

        rank=newRank;

        iteration++;

        if(change<tolerance){

            converged=true;
            break;
        }
    }

    PageRankResult result;

    result.rank=rank;
    result.iterations=iteration;
    result.converged=converged;

    return result;
}
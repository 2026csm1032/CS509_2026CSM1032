#ifndef PAGERANK_H
#define PAGERANK_H

#include<bits/stdc++.h>
using namespace std;

struct PageRankResult{

    vector<double> rank;
    int iterations;
    bool converged;
};

PageRankResult pageRank(int V,vector<int>& row_ptr,vector<int>& col_idx,double damping,double tolerance,int maxIterations);

#endif
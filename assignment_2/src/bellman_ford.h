#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include<bits/stdc++.h>
using namespace std;

bool bellmanFord(int V,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights,int source,vector<long long>& dist);

#endif
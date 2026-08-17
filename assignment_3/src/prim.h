#ifndef PRIM_H
#define PRIM_H

#include<bits/stdc++.h>
using namespace std;

pair<long long,vector<pair<pair<int,int>,int>>> primMST(int V,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights);

#endif
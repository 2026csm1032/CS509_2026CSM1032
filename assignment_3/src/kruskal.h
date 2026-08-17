#ifndef KRUSKAL_H
#define KRUSKAL_H

#include<bits/stdc++.h>
using namespace std;

pair<long long,vector<pair<pair<int,int>,int>>> kruskalMST(int V,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights);

#endif
#ifndef CSR_H
#define CSR_H

#include<bits/stdc++.h>
using namespace std;

void convertToCSR( vector<vector<int>>& adj, vector<int>& row_ptr, vector<int>& col_idx);

void convertToCSR(vector<vector<pair<int,int>>>& adj,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights);


#endif
//
//  Knapsack.cpp
//  Algorithm Programming
//
//  Created by XinquanZhou on 6/21/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#include "Knapsack.h"
#include <algorithm>

using namespace std;

int Knapsack(vector<int> & value, vector<int> & size, int capacity){
    if (value.empty()) {
        return 0;
    }
    vector<int> dp(capacity+1,0);
    size_t len = value.size();
    for (int i = 0 ; i < len; ++i) {
        for (int j = capacity ; j > 0 ; ++j) {
            if (i == 0 && j >= size[i]) {
                dp[j] = value[i];
                continue;
            }
            if (j >= size[i]) {
                dp[j] = max(dp[j], dp[j-size[i]] + value[i]);
            }
            
        }
    }
    return dp[capacity];
}



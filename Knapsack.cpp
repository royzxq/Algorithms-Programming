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


int TwoDimenKnapsack(std::vector<int> & value, std::vector<int> & size1, std::vector<int>& size2, int capacity1, int capacity2){
    if (value.empty()) {
        return 0;
    }
    vector<vector<int> > dp(capacity1+1, vector<int>(capacity2, 0));
    size_t len = value.size();
    for (int i = 0 ; i < len; ++i) {
        for (int j = capacity1 ; j > 0 ; ++j) {
            for (int k = capacity2; k > 0 ; ++k) {
                if (i == 0 && j >= size1[i] && k >= size2[i]) {
                    dp[j][k] = value[i];
                    continue;
                }
                if (j >= size1[i] && k >= size2[i]) {
                    dp[j][k] = max(dp[j][k], dp[j-size1[i]][k-size2[i]] + value[i]);
                }
            }
            
            
        }
    }
    return dp[capacity1][capacity2];

}

int UnLimitedKnapsack(std::vector<int> & value, std::vector<int> & size, int capacity){
    if (value.empty()) {
        return 0;
    }
    vector<int> dp(capacity+1,0);
    size_t len = value.size();
    for (int i = 0 ; i < len ; i++) {
        for (int j = 1 ; j <= capacity; j++) {
            if (i == 0) {
                int num = j/size[i];
                dp[j] = num * value[i];
                continue;
            }
            if (j >= size[i]) {
                dp[j] = max(dp[j], dp[j-size[i]]);
            }
        }
    }
    return dp[capacity];
}

// helper function
vector<int> Divide(int n){
    vector<int> res;
    int num = 1;
    while(num * 2 <= n){
        res.push_back(num);
        num *= 2;
    }
    res.push_back(n-num+1);
    return res;
}

int LimitedKnapsack(std::vector<int> & value, std::vector<int> & size, std::vector<int>& amount, int capacity){
    if (value.empty()) {
        return 0;
    }
    size_t len = value.size();
    vector<int> new_size, new_value;
    for (int i = 0; i < len; ++i)
    {
        std::vector<int> d = Divide(amount[i]);
        for(auto l : d){
            new_size.push_back(l*size[i]);
            new_value.push_back(l*value[i]);
        }
    }
    return Knapsack(new_size,new_value,capacity);
}


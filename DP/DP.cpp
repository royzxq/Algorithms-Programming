//
//  DP.cpp
//  Algorithm programming
//
//  Created by XinquanZhou on 6/23/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#include "DP.h"
#include <algorithm>

using namespace std;

int Robber_I(std::vector<int> & house){
    size_t len = house.size();
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        return house[0];
    }
    if (len == 2) {
        return max(house[0],house[1]);
    }

    // dp[i] is the maximum ending at ith house

    vector<int> dp(len,0);
    dp[0] = house[0];
    dp[1] = house[1];
    
    // the state transfer fucntion
    for (int i = 2; i < len; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + house[i]);
    }
    
    return dp[len-1];
}

int Robber_II(std::vector<int> & house){
    size_t len = house.size();
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        return house[0];
    }
    if (len == 2) {
        return max(house[0],house[1]);
    }
    
    // forward - backward dp, discard the first and last one respectively
    vector<int> dp1(len,0), dp2(len,0);
    dp1[0] = house[0];
    dp1[1] = max(house[0],house[1]);
    for (int i = 2 ; i < len-1; i++) {
        dp1[i] = max(dp1[i-1], dp1[i-2] + house[i]);
    }
    dp2[len-1] = house[len-1];
    dp2[len-2] = house[len-2];
    
    for (int i = len - 3; i > 0 ; i--) {
        dp2[i] = max(dp2[i+1],dp2[i+2] + house[i]);
    }
    return max(dp1[len-2], dp2[1]);
}



int MaximalRectangle(std::vector<std::vector<bool>> & matrix){
    size_t rows = matrix.size(), cols = matrix[0].size();
    if (rows == 0 || cols == 0) {
        return 0;
    }
#ifdef DP
    // 4D dp
    // 2 points determine a rect, with a 4d array, tranvser all the combo of any 2 points
    vector<vector<vector<vector<bool>>>> dp(rows, vector<vector<vector<bool>>>(cols, \
       vector<vector<bool>>(rows, vector<bool> (cols,false) )));
    int final_max = 0, left_top_x, left_top_y, right_bottom_x, right_bottom_y;
    for (int i = 0; i < rows; ++i)
    {
        for(int j = 0 ; j < cols; j++){
            
            for(int m = i; m < rows; m++){
                
                for(int n = j; n < cols; n++){
                    
                    if (m == i && n == j && matrix[i][j] == 1)
                    {
                        dp[i][j][m][n] = true;
                    }
                    else if (matrix[i][j] == 0 || matrix[m][n] == 0){
                        dp[i][j][m][n] = false;
                    }
                    else if(m == i){
                        dp[i][j][m][n] = dp[i][j][m][n-1];
                    }
                    else if(n == j){
                        dp[i][j][m][n] = dp[i][j][m-1][n];
                    }
                    else{
                        dp[i][j][m][n] = dp[i][j][m-1][n] && dp[i][j][m][n-1];
                    }
                    
                    if (dp[i][j][m][n] && final_max < (m-i + 1) * (n-j + 1))
                    {
                        final_max = (m-i + 1) * (n-j + 1);
                        left_top_x = i;
                        left_top_y = j ;
                        right_bottom_x = m;
                        right_bottom_y = n;
                    }
                }
            }
        }
    }
    return final_max;
#else
    vector<int> left(cols,0), right(cols,0), height(cols,0);
    int final_max = 0;
    for(int i=0; i<rows; i++) {
        int cur_left=0, cur_right=cols;
        for(int j=0; j<cols; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++;
            else height[j]=0;
        }
        for(int j=0; j<cols; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=cols-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=cols; cur_right=j;}
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<cols; j++)
            final_max = max(final_max,(right[j]-left[j])*height[j]);
    }
    return final_max;
#endif
}


int MaximalSquare(std::vector<std::vector<bool>> & matrix){
    size_t rows = matrix.size(), cols = matrix[0].size();
    if (rows == 0 || cols == 0) {
        return 0;
    }
#ifdef DP
    vector<vector<vector<bool>>> dp(rows, vector<vector<bool>>(cols, \
       vector<bool>(min(rows,cols),false)));
    int final_max = 0, left_top_x, left_top_y, diaganal_length;
    
    for(int m = 0 ; m < min(rows,cols); m++){
        
        for (int i = 0; i + m < rows; ++i)
        {
            for (int j = 0; j + m  < cols; ++j)
            {
                if (m == 0 && matrix[i][j] == 1)
                {
                    dp[i][j][m] = true;
                }
                else if (matrix[i][j] == 0 || matrix[i+m][j+m] == 0){
                    dp[i][j][m] = false;
                }
                
                else{
                    dp[i][j][m] = dp[i][j][m-1] && dp[i+m-1][j+m][m-1] && dp[i+m][j+m-1][m-1];
                }
                
                if (dp[i][j][m] && final_max < m * m)
                {
                    final_max = m*m;
                    left_top_x = i;
                    left_top_y = j ;
                    diaganal_length = m;
                }
            }
        }
    }
    return final_max;
#else
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int final_max = 0 ;
    for(int i = 0 ; i < rows; ++i){
        for(int j = 0 ; j < cols; ++j){
            if(i == 0 || j == 0) {
                dp[i][j] = matrix[i][j] - '0';
                final_max = max(dp[i][j],m);
                
            }
            else{
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                    dp[i][j] ++;
                    final_max = max(dp[i][j],final_max);
                }
            }
        }
    }
    return final_max * final_max;
#endif
}

int BestTimetoBuyandSellStock_I(vector<int> & prices){
    int len = prices.size();
    if (len == 0 ) {
        return 0;
    }
    // actually unnessary
    vector<int> dp(len, 0);
    int front_low = prices[0];
    int max_profit = 0;
    for (int i = 1; i < len; ++i) {
        if (prices[i] < front_low) {
            front_low = prices[i];
        }
        dp[i] = prices[i] - front_low;
        max_profit = max(max_profit,dp[i]);
    }
    return max_profit;
}

int BestTimetoBuyandSellStock_II(std::vector<int> & prices){
    size_t len = prices.size();
    if (len <= 1) {
        return 0;
    }
    
    vector<int> left(len,0), right(len,0);
    int front_low = prices[0];
    int left_profit = 0;
    for (int i = 1 ; i < len; ++i) {
        if (prices[i] < front_low) {
            front_low = prices[i];
        }
        left_profit = max(left_profit, prices[i]-front_low);
        left[i] = left_profit;
    }
    
    int back_max = prices[len-1];
    int right_profit = 0, final_profit = 0;
    
    for (int i = len - 2; i >=0 ; --i) {
        if (prices[i] > back_max) {
            back_max = prices[i];
        }
        right_profit = max(right_profit, back_max - prices[i]);
        right[i] = right_profit;
        final_profit = max(final_profit, right[i] + (i > 0 ? left[i-1]: 0));
    }
    return final_profit;
}

int maxProfit_all(vector<int> &prices) {
    int n = prices.size();
    int sum = 0;
    for(int i = 1;i < n;i++){
        if(prices[i] > prices[i-1]){
            sum += prices[i] - prices[i-1];
        }
    }
    return sum;
}

int BestTimetoBuyandSellStock_III(std::vector<int> & prices, int k){
    size_t len = prices.size();
    if (k >= len/2) {
        return maxProfit_all(prices);
    }
    vector<vector<int>> dp(k+1, vector<int> (len, 0));
    for (int i = 1 ; i <= k ; ++i) {
        int cur_max = 0 ;
        for (int j = i+1; j < len; ++j) {
            int instantProfit = prices[j] - prices[j-1];
            cur_max = max(cur_max + instantProfit, dp[i-1][j]);
            dp[i][j] = max(dp[i][j-1], cur_max);
        }
    }
    return dp[k][len-1];
}


//
//  main.cpp
//  Algorithm Programming
//
//  Created by XinquanZhou on 6/21/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main(){
    int numTests;
    cin >> numTests;
    while(numTests--){
        int N,V;
        cin >> N >> V;
        std::vector<int> nums, size, value;
        for (int i = 0; i < N; ++i)
        {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        for (int i = 0; i < N; ++i)
        {
            int t;
            cin >> t;
            size.push_back(t);
        }
        for (int i = 0; i < N; ++i)
        {
            int t;
            cin >> t;
            value.push_back(t);
        }
        
        // dp[i][j] is the maximum val using first i items with less than j size
        std::vector<std::vector<int> > dp (N, std::vector<int> (V+1, 0));
        
        std::vector<int> amount(N,0);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 1; j <= V; ++j)
            {
                if (i == 0)
                {
                    int num = j/size[i];
                    num = min(nums[i],num);
                    dp[i][j] = num * value[i];
                    amount[i] = num;
                    continue;
                }
                
                // dp[i][j] = max(dp[i-1][j-k*size[i]]+value[i]) 0<=k<=nums[i];
                for(int k = 0; k <= nums[i]; k++){
                    if (k*size[i] > j)
                    {
                        break;
                    }
                    if ( dp[i-1][j-k*size[i]]+k*value[i] > dp[i][j])
                    {
                        dp[i][j] = dp[i-1][j-k*size[i]]+k*value[i];
                        amount[i] = k;
                    }
                }
            }
        }
        
        
        cout << dp[N-1][V] << endl;
        for (int i = 0; i < N; ++i)
        {
            cout << amount[i] << " ";
        }
        cout << endl;
    }
}
//
//  Knapsack.h
//  Algorithm Programming
//
//  Created by XinquanZhou on 6/21/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#ifndef __Algorithm_Programming__Knapsack__
#define __Algorithm_Programming__Knapsack__

#include <stdio.h>
#include <vector>

// 0-1 knapsack solution
int Knapsack(std::vector<int> & value, std::vector<int> & size, int capacity);

// there are limited amount of each item in knapsack
int LimitedKnapsack(std::vector<int> & value, std::vector<int> & size, std::vector<int>& amount, int capacity);

// there are unlimited amount of each item in knapsack
int UnLimitedKnapsack(std::vector<int> & value, std::vector<int> & size, int capacity);

#endif /* defined(__Algorithm_Programming__Knapsack__) */

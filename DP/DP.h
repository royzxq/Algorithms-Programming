//
//  DP.h
//  Algorithm programming
//
//  Created by XinquanZhou on 6/23/15.
//  Copyright (c) 2015 Xinquan Zhou. All rights reserved.
//

#ifndef __Algorithm_programming__DP__
#define __Algorithm_programming__DP__

#include <stdio.h>
#include <vector>
#define DP

//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

int Robber_I(std::vector<int> & house);


//After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

int Robber_II(std::vector<int> & house);


//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area and indices of its corners from left to right and from top to down.

int MaximalRectangle(std::vector<std::vector<bool>> & matrix);

int MaximalSquare(std::vector<std::vector<bool>> & matrix);



// Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

int BestTimetoBuyandSellStock_I(std::vector<int> & prices);

//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
int BestTimetoBuyandSellStock_II(std::vector<int> & prices);

//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete at most k transactions.
int BestTimetoBuyandSellStock_III(std::vector<int> & prices, int k);

#endif /* defined(__Algorithm_programming__DP__) */

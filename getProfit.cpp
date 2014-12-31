// Problem Statement

// Implement a class StockCalc, which contains a method getProfit.  This method
// takes an int[] representing the stock price for a given stock on a sequence of
// days, and returns, as an int, the maximum profit that can be reaped by buying
// on one of those days and selling on a later day.

// Here is the method signature:
// public int getProfit(int[] prices);

// prices is an int[].  Each Integer must be greater than 0 and less than 1000.
// There must be at least 1 element in the int[] and at most 100 elements.

// Note:
// -If no profit can be made, return 0.

// Examples:
// -prices={3,5,10,20,80,70,40,1}, returns 77
// -prices={80,70,40,3,2,1}, returns 0

// Definition

// Class:  StockCalc
// Method: getProfit
// Parameters: int[]
// Returns:  int
// Method signature: int getProfit(int[] param0)
// (be sure your method is public)

#include <vector>

int getProfit(std::vector<int> prices) {
  int max = 0;
  int curr;
  for(int i = 0; i < prices.size(); i++) {
    for(int j = i + 1; j < prices.size(); j++) {
      curr = prices[j] - prices[i];
      if(curr > max) {
        max = curr;
      }
    }
  }
  return max;
}

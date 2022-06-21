//
//  main.cpp
//  leetcodeTestingPostYr1
//
//  Created by Vincent Zhu on 6/16/22.
//

#include <iostream>
#include <vector>
using namespace std;

//int maxProfit(vector<int>& prices) {
//    int profit = 0;
//    for (int i = 0; i < prices.size(); i++) {
//        for (int j = i + 1; j < prices.size(); j++) {
//            if ((prices.at(j) - prices.at(i)) > profit) {
//                profit = (prices.at(j) - prices.at(i));
//            }
//        }
//    }
//    return profit;
//}

//int maxProfit(vector<int>& prices) {
//    int buyPrice = 0;
//    int sellPrice = 0;
//    int profit = 0;
//    for (int i = prices.size() - 1; i > 0; i--) {
//        sellPrice = prices.at(i);
//        for (int j = 0; j < i; j++) {
//            buyPrice = prices.at(j);
//            if ((sellPrice - buyPrice) > profit) {
//                profit = sellPrice - buyPrice;
//            }
//        }
//    }
//    return profit;
//}

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int min = INT_MAX;
    for (int i = 0; i < prices.size(); i++) {
        if (prices.at(i) < min) {
            min = prices.at(i);
        }
        else if (prices.at(i) - min > profit) {
            profit = prices.at(i) - min;
        }
    }
    return profit;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v) << endl;
    
    return 0;
}

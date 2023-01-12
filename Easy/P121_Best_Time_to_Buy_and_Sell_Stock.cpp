#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int l = 0;
    int r = 0;
    int maxProfit = 0;
    while (r < prices.size()) {
        if (prices.at(r) < prices.at(l)) {
            l = r;
        }
        maxProfit = max(maxProfit, prices.at(r) - prices.at(l));
        r++;
    }
    return maxProfit;
}

int maxProfit2(vector<int>& prices) {
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

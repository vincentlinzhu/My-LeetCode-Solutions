#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
// Problem:
    // prices list of size n, longs
    // profits list of size n, longs
    // find triplet of any 3 days, (i, j, k) with prices[i] < prices[j] < prices[k], where profit[i]+profit[j]+profit[k] is maximized i < j < k
    // EX: 5 days, prices = {3, 4, 2, 1, 8}, profits = {1, 7, 3, 6 2}. answer is days 0, 1, 4

// Less Clean Method:
vector<int> solve2(vector<int> p, vector<int> p1) {
   vector<int> res;
   // Step 1: find any valid triplet
   vector<pair<int, int> > minLeft (p.size(), pair<int, int>(INT_MAX, 0));
   for (int i = 1; i < p.size(); i++) {
       if (p[i - 1] < minLeft[i - 1].first) {
           minLeft[i].first = p[i - 1];
           minLeft[i].second = i - 1;
       } else {
           minLeft[i] = minLeft[i - 1];
       }
   }
   vector<pair<int, int> > maxRight (p.size(), pair<int, int>(0, p.size() - 1));
   for (int i = p.size() - 2; i >= 0; i--) {
       if (p[i + 1] > maxRight[i + 1].first) {
           maxRight[i].first = p[i + 1];
           maxRight[i].second = i + 1;
       } else {
           maxRight[i] = maxRight[i + 1];
       }
   }
   vector<pair<int, int> > triplet (3, pair<int, int>(0, 0));
   int count = 0;
   for (int i = 1; i < p.size() - 1; i++) {
       if ((minLeft[i].first < p[i]) && (p[i] < maxRight[i].first)) {
           triplet[0].first = minLeft[i].second; // index
           triplet[0].second = p1[minLeft[i].second]; // profits[index]

           triplet[1].first = i;
           triplet[1].second = p1[i];

           triplet[2].first = maxRight[i].second;
           triplet[2].second = p1[maxRight[i].second];
           break;
       } else {
           count++;
       }
   }
   if (count == p.size() - 2) { // no valid triplet exists
       return res;
   }
   
   // Step 2: find the max profit triplet
   for (int i = 0; i < p1.size(); i++) {
       if (i == triplet[0].first || i == triplet[1].first || i == triplet[2].first) {
           continue;
       }
       sort(triplet.begin(), triplet.end(), [](const pair<int, int> & a, const pair<int, int> & b){return a.second < b.second;});
       if (p1[i] > triplet[0].second) {
           // Check Valid
           if (i < triplet[1].first && i < triplet[2].first) {
               if (p[i] < p[triplet[1].first] && p[i] < p[triplet[2].first]) {
                   triplet[0].first = i;
                   triplet[0].second = p1[i];
                   continue;
               }
           } else if (i > triplet[1].first && i > triplet[2].first) {
               if (p[i] > p[triplet[1].first] && p[i] > p[triplet[2].first]) {
                   triplet[0].first = i;
                   triplet[0].second = p1[i];
                   continue;
               }
           } else {
               if ((i > triplet[1].first && i < triplet[2].first) || (i < triplet[1].first && i > triplet[2].first)) {
                   if (p[i] > p[triplet[1].first] && p[i] < p[triplet[2].first] || p[i] < p[triplet[1].first] && p[i] > p[triplet[2].first]) {
                       triplet[0].first = i;
                       triplet[0].second = p1[i];
                   }
                   continue;
               }
           }
       } else if (p1[i] > triplet[1].second) {
           // Check Valid
           if (i < triplet[0].first && i < triplet[2].first) {
               if (p[i] < p[triplet[0].first] && p[i] < p[triplet[2].first]) {
                   triplet[1].first = i;
                   triplet[1].second = p1[i];
                   continue;
               }
           } else if (i > triplet[0].first && i > triplet[2].first) {
               if (p[i] > p[triplet[0].first] && p[i] > p[triplet[2].first]) {
                   triplet[1].first = i;
                   triplet[1].second = p1[i];
                   continue;
               }
           } else {
               if ((i > triplet[0].first && i < triplet[2].first) || (i < triplet[0].first && i > triplet[2].first)) {
                   if (p[i] > p[triplet[0].first] && p[i] < p[triplet[2].first] || p[i] < p[triplet[0].first] && p[i] > p[triplet[2].first]) {
                       triplet[1].first = i;
                       triplet[1].second = p1[i];
                       continue;
                   }
               }
           }
       } else if (p1[i] > triplet[2].second) {
           // Check Valid
           if (i < triplet[0].first && i < triplet[1].first) {
               if (p[i] < p[triplet[0].first] && p[i] < p[triplet[1].first]) {
                   triplet[2].first = i;
                   triplet[2].second = p1[i];
                   continue;
               }
           } else if (i > triplet[0].first && i > triplet[1].first) {
               if (p[i] > p[triplet[0].first] && p[i] > p[triplet[1].first]) {
                   triplet[2].first = i;
                   triplet[2].second = p1[i];
                   continue;
               }
           } else {
               if ((i > triplet[0].first && i < triplet[1].first) || (i < triplet[0].first && i > triplet[1].first)) {
                   if (p[i] > p[triplet[0].first] && p[i] < p[triplet[1].first] || p[i] < p[triplet[0].first] && p[i] > p[triplet[1].first]) {
                       triplet[2].first = i;
                       triplet[2].second = p1[i];
                       continue;
                   }
               }
           }
       }
   }

   sort(triplet.begin(), triplet.end());
   for (auto x : triplet) {
       res.push_back(x.first);
   }

   return res; //triplet {i, j, k};
}

// Cleaner Method:
bool validTriplet(int curr, int idx, vector<pair<int, int> >& triplet, vector<int> p, vector<int> p1) {
    int o1 = 1;
    int o2 = 2;
    if (idx == 0) {
        o1 = 1;
        o2 = 2;
    }
    if (idx == 1) {
        o1 = 0;
        o2 = 2;
    }
    if (idx == 2) {
        o1 = 0;
        o2 = 1;
    }
    if (curr < triplet[o1].first && curr < triplet[o2].first) {
        if (p[curr] < p[triplet[o1].first] && p[curr] < p[triplet[o2].first]) {
            triplet[idx].first = curr;
            triplet[idx].second = p1[curr];
            return true;
        }
    } else if (curr > triplet[o1].first && curr > triplet[o2].first) {
        if (p[curr] > p[triplet[o1].first] && p[curr] > p[triplet[o2].first]) {
            triplet[idx].first = curr;
            triplet[idx].second = p1[curr];
            return true;
        }
    } else {
        if ((curr > triplet[o1].first && curr < triplet[o2].first) || (curr < triplet[o1].first && curr > triplet[o2].first)) {
            if (p[curr] > p[triplet[o1].first] && p[curr] < p[triplet[o2].first] || p[curr] < p[triplet[o1].first] && p[curr] > p[triplet[o2].first]) {
                triplet[idx].first = curr;
                triplet[idx].second = p1[curr];
                return true;
            }
        }
    }
    return false;
}
vector<int> solve(vector<int> p, vector<int> p1) {
    vector<int> res;
    // Step 1: find any valid triplet
    vector<pair<int, int> > minLeft (p.size(), pair<int, int>(INT_MAX, 0));
    for (int i = 1; i < p.size(); i++) {
        if (p[i - 1] < minLeft[i - 1].first) {
            minLeft[i].first = p[i - 1];
            minLeft[i].second = i - 1;
        } else {
            minLeft[i] = minLeft[i - 1];
        }
    }
    vector<pair<int, int> > maxRight (p.size(), pair<int, int>(0, p.size() - 1));
    for (int i = p.size() - 2; i >= 0; i--) {
        if (p[i + 1] > maxRight[i + 1].first) {
            maxRight[i].first = p[i + 1];
            maxRight[i].second = i + 1;
        } else {
            maxRight[i] = maxRight[i + 1];
        }
    }
    vector<pair<int, int> > triplet (3, pair<int, int>(0, 0));
    int count = 0;
    for (int i = 1; i < p.size() - 1; i++) {
        if ((minLeft[i].first < p[i]) && (p[i] < maxRight[i].first)) {
            triplet[0].first = minLeft[i].second; // index
            triplet[0].second = p1[minLeft[i].second]; // profits[index]

            triplet[1].first = i;
            triplet[1].second = p1[i];

            triplet[2].first = maxRight[i].second;
            triplet[2].second = p1[maxRight[i].second];
            break;
        } else {
            count++;
        }
    }
    if (count == p.size() - 2) { // no valid triplet exists
        return res;
    }
    
    // Step 2: find the max profit triplet
    for (int i = 0; i < p1.size(); i++) {
        if (i == triplet[0].first || i == triplet[1].first || i == triplet[2].first) {
            continue;
        }
        sort(triplet.begin(), triplet.end(), [](const pair<int, int> & a, const pair<int, int> & b){return a.second < b.second;});
        if (p1[i] > triplet[0].second) {
            if (validTriplet(i, 0, triplet, p, p1)) continue;
        } else if (p1[i] > triplet[1].second) {
            if (validTriplet(i, 1, triplet, p, p1)) continue;
        } else if (p1[i] > triplet[2].second) {
            if (validTriplet(i, 2, triplet, p, p1)) continue;
        }
    }

    sort(triplet.begin(), triplet.end());
    for (auto x : triplet) {
        res.push_back(x.first);
    }

    return res; //triplet {i, j, k};
}

int main () {
   vector<int> prices {3, 4, 2, 1, 8};
   vector<int> profits {1, 7, 3, 6, 2};
   vector<int> res = solve(prices, profits);
   cout << "[";
   cout << res[0] << ",";
   cout << res[1] << ",";
   cout << res[2];
   cout << "]" << endl;
   return 0;
}

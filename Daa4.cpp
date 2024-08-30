#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of shops that can be visited
int maxShops(vector<int>& S, vector<int>& E, int K) {
    // Combine start and end times with the index of shops
    vector<pair<int, int>> shops;
    for (int i = 0; i < S.size(); i++) {
        shops.push_back({E[i], S[i]});
    }
    
    // Sort shops by their ending times
    sort(shops.begin(), shops.end());
    
    // Vector to track the end time of the last shop visited by each person
    vector<int> persons(K, 0);
    
    int count = 0;
    
    for (auto& shop : shops) {
        int start = shop.second;
        int end = shop.first;
        
        // Try to assign this shop to one of the persons
        for (int i = 0; i < K; i++) {
            if (persons[i] <= start) {  // If the person can visit this shop
                persons[i] = end;  // Assign the shop's end time to this person
                count++;
                break;  // Move to the next shop
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum number of shops visited: " << maxShops(S1, E1, K1) << endl;  // Output: 4

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum number of shops visited: " << maxShops(S2, E2, K2) << endl;  // Output: 3

    return 0;
}

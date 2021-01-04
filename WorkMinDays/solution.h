/*
    Time complexity: O(n* log(n))
    Space complexity: O(n)

    Where 'n' is the number of works
*/

int minDaysWork(vector<int> &D1, vector<int> &D2) {
    int ans = 0;
    // Vector to store the pair of D1(i) and D2(i)
    vector<pair<int, int> > combined(D1.size());

    for (int i = 0; i < D1.size(); i++) {
        combined[i] = make_pair(D1[i], D2[i]);
    }
    sort(combined.begin(), combined.end());  // Sort the array
    for (int i = 0; i < D1.size(); i++) {
        if (combined[i].second >= ans) {
            ans = combined[i].second;
        } else {
            ans = combined[i].first;
        }
    }

    return ans;
}
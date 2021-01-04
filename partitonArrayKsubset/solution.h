/*
	Time Complexity: O(k^{N-k} k!)
	Space Complexity: O(N)
				  
	where N is the length of array ARR, and k is as given.
 */

bool splitIntoKUtil(vector<int> &arr, vector<int> &sumOfSubsets, vector<bool> &isElementConsidered, int subset, int K, int N, int currentIndex, int maxLimit) {
    if (sumOfSubsets[currentIndex] == subset) {
        if (currentIndex == K - 2) {
            return 1;
        }

        return splitIntoKUtil(arr, sumOfSubsets, isElementConsidered, subset, K, N, currentIndex + 1, N - 1);
    }

    for (int i = maxLimit; i >= 0; i--) {
        if (isElementConsidered[i]) {
            continue;
        }
        int temp = sumOfSubsets[currentIndex] + arr[i];

        if (temp <= subset) {
            isElementConsidered[i] = 1;
            sumOfSubsets[currentIndex] += arr[i];
            bool next = splitIntoKUtil(arr, sumOfSubsets, isElementConsidered, subset, K, N, currentIndex, i - 1);
            isElementConsidered[i] = 0;
            sumOfSubsets[currentIndex] -= arr[i];
            if (next) {
                return true;
            }
        }
    }
    return 0;
}

bool splitArray(vector<int> &arr, int K) {
    int N = arr.size();
    if (K == 1) {
        return true;
    }

    if (N < K) {
        return false;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    if (sum % K != 0) {
        return false;
    }
    int subset = sum / K;

    vector<int> sumOfSubsets(K);
    vector<bool> isElementConsidered(N);

    for (int i = 0; i < K; i++) {
        sumOfSubsets[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        isElementConsidered[i] = false;
    }

    sumOfSubsets[0] = arr[N - 1];
    isElementConsidered[N - 1] = true;

    return splitIntoKUtil(arr, sumOfSubsets, isElementConsidered, subset, K, N, 0, N - 1);
}

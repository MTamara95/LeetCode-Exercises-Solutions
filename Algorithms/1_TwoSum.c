// task: https://leetcode.com/problems/two-sum
// time complexity: O(n^2), space complexity: O(1)

int* twoSum(int *a, int n, int k) {

	int *res = (int*)malloc(2 * sizeof(int));
	int i = 0, j = 0, ind = 0;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] + a[j] == k) {
				res[0] = i;
				res[1] = j;
				ind = 1; // indicate that we have a result
				break;
			}
		}
		if (ind == 1) { // we reach here because we broke the previous loop
			break;
		}
	}

	return res;
}

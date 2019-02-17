// task: https://leetcode.com/problems/median-of-two-sorted-arrays
// (time) complexity: O(nums1Size+nums2Size)

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	int l = 0, r = 0, i = 0;
	int numsSize = nums1Size + nums2Size;
	int *nums = (int*)malloc(numsSize * sizeof(int));

	while(l < nums1Size && r < nums2Size) {
		if (nums1[l] < nums2[r]) {
			nums[i++] = nums1[l++];
		}
		else {
			nums[i++] = nums2[r++];
		}
	}
	
	if (r < nums2Size) {
		while (r < nums2Size) {
			nums[i++] = nums2[r++];
		}
	}
	else if (l < nums1Size) {
		while (l < nums1Size) {
			nums[i++] = nums1[l++];
		}
	}

	if (numsSize % 2 == 1) {
		return nums[numsSize / 2];
	}
	return 1.0*(nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2;

}
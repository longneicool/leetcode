/*
 * @lc app=leetcode id=26 lang=golang
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	if len(nums) == 0 || len(nums) == 1 {
		return len(nums)
	}

	for i, j := 0, 0; j < len(nums); j++ {
		if nums[i] == nums[j] {
			continue
		}

		i++
		nums[i] = nums[j]
	}

	nums = nums[:i+1]
	return i + 1
}

// @lc code=end


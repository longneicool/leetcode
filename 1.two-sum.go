/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
// Solution 1 先考虑暴力解法
// func twoSum(nums []int, target int) []int {
// 	for i := 0; i < len(nums); i++ {
// 		for j := i + 1; j < len(nums); j++ {
// 			if nums[i]+nums[j] == target {
// 				return []int{i, j}
// 			}
// 		}
// 	}

// Solution2 Use hash to change the O(n) to O(1)
// func twoSum(nums []int, target int) []int {
// 	hashMap := make(map[int]int, n)
// 	for i, v := range nums {
// 		hashMap[v] = i
// 	}

// 	for i, v := range nums {
// 		index, ok := hashMap[target-v]
// 		if ok && i != index {
// 			return []int{i, index}
// 		}
// 	}

// 	return nil
// }

// Sloution3 Single loop
// func twoSum(nums []int, target int) []int {
// 	m := make(map[]int, len(nums))
// 	for i, v := range nums {
// 		wanted := target - v
// 		if j, ok := m[wanted]; ok {
// 			return []int{i, j}
// 		}

// 		m[v] = i
// 	}
// return nil
// }

// 	return nil
// }

// @lc code=end


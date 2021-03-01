/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 */

// @lc code=start
// package leetcode

package leetcode

import "sort"

// Solution1: two sum. 但是没找到好的办法去重
// func twoSum(nums []int, target int) [][]int {
// 	m := make(map[int]int, len(nums))
// 	for i, v := range nums {
// 		m[v] = i
// 	}

// 	results := make([][]int, 0, len(nums))
// 	for i, v := range nums {
// 		// i < j 避免两个数重复计算，比如[-1,0,1], 如果不判断的话就会返回[-1,1][1,-1]
// 		if j, ok := m[target-v]; ok && i < j {
// 			results = append(results, []int{nums[i], nums[j]})
// 		}
// 	}

// 	return results
// }

// func threeSum(nums []int) [][]int {
// 	sort.Slice(nums, func(i, j int) bool {
// 		return nums[i] < nums[j]
// 	})
// 	results := make([][]int, 0, len(nums))
// 	for i, v := range nums {
// 		if i > 0 && nums[i] == nums[i-1] {
// 			continue
// 		}
// 		r := twoSum(nums[i:], 0-v)
// 		for _, s := range r {
// 			results = append(results, append([]int{nums[i]}, s...))
// 		}
// 	}

// 	return results
// }

/* Solution2:
1. 首先进行排序，算法复杂度为O(nlogn)
2. 固定一个数字k，选择i，j从k的左端和右端往中间收敛，如果
	1）nums[k] > 0 break; 因为最小的都大于0了，后面肯定没有了
	2）sum  =nums[k] + nums[i] + nums[j] < 0,则i往前走去找大的值。有种水往低处流的感觉
	3）sum > 0, 则j往后走，去找小的值。
	4）如果i或者j与他们前面已经找过的值相同，则bypass。因为已经找过了，避免重复
	5）k继续往右走。如果k值与之前相同，则bypass。
*/

func threeSum(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	// 排序
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	results := make([][]int, 0)
	for k := 0; k < len(nums); k++ {
		// nums[k] >0 break
		if nums[k] > 0 {
			break
		}

		// 跳过相同的k值
		if k > 0 && nums[k] == nums[k-1] {
			continue
		}

		for i, j := k+1, len(nums)-1; i < j; {
			s := nums[k] + nums[i] + nums[j]
			// 跳过相同的i，j值
			if nums[i] == nums[i-1] {
				i++
				continue
			}

			if j != len(nums)-1 && nums[j] == nums[j+1] {
				j--
				continue
			}

			if s < 0 {
				i++
			} else if s == 0 {
				results = append(results, []int{nums[k], nums[i], nums[j]})
				i++
				j--
			} else {
				j--
			}
		}
	}

	return results
}

// @lc code=end

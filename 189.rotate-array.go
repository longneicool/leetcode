/*
 * @lc app=leetcode id=189 lang=golang
 *
 * [189] Rotate Array
 */

// @lc code=start
package leetcode

/*
Solution1: 见https://blog.csdn.net/qq_28584889/article/details/83655019
func rotate(nums []int, k int) {
	length := len(nums)
	if length == 0 || length == 1 || k == 0 {
		return
	}

	k = k % length

	count := 0
//  最大会循环K*n次
	for i := 0; i < k; i++ {
// 从i+k开始，则i+k会保存i的值，需要把i+k的值缓存起来
		j := i + k
		prev := nums[i]
		for j%length != i {
// 将nums[j]赋值前一个，同时保存j的值为prev，循环下一次
			prev, nums[j%length] = nums[j%length], prev
			j = j + k
// 当总次数等于数组长度时，说明都已经遍历完了，可以break
			count++
			if count == length {
				break
			}
		}
// 此时j已经重新循环到起始点，
		if j%length == i {
			nums[i] = prev
			count++
			if count == length {
				break
			}
		}
	}
}
*/

/*
Solution2:
1. 先翻转整个数组
2. 再翻转前k的元素
3. 再翻转剩余的元素
*/
func reverse(nums []int) {
	for i := 0; i < len(nums)/2; i++ {
		nums[i], nums[len(nums)-i-1] = nums[len(nums)-i-1], nums[i]
	}
}
func rotate(nums []int, k int) {
	// 切记要考虑k>n的情况。否则会出现panic
	k = k % len(nums)
	reverse(nums)
	reverse(nums[:k])
	reverse(nums[k:])
}

// @lc code=end

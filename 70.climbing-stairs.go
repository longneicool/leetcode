/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */

// @lc code=start

//在解题前要考虑
// 1. 暴力破解
// 2. 考虑最基本的情况，比如从1， 2， 3考虑。考虑数学的归纳法

// Solution1 斐波拉切数列的典型用法：缓存所有的结果，避免使用递归
func climbStairs(n int) int {
	s := []int{1, 2}
	for i := 2; i < n; i++ {
		s = append(s, s[i-1]+s[i-2])
	}

	return s[n-1]
}

// Solution 2因为只需要最近3个，所以不需要数组来缓存所有的步数
// func climbStairs(n int) int {
// 	f1, f2 := 1, 2
// 	var f3 int
// 	for i := 2; i < n; i++ {
// 		f3 = f1 + f2
// 		f1, f2 = f2, f3
// 	}

// 	return f3
// }

// @lc code=end


mod solutions;
use solutions::Solution;

fn main() {
    let nums = vec![3,2,4];
    let target = 6;
    let result = Solution::two_sum(nums, target);
    println!("{:?}", result);
}
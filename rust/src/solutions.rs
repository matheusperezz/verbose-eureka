use std::collections::HashMap;

pub(crate) struct Solution;

impl Solution {
    /* Challenge 1 - Two Sum, with two results*/
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut output: Vec<i32> = Vec::new();
        for (index, number) in nums.iter().enumerate() {
            for (idx, num) in nums.iter().enumerate().skip(index){
                if number + num == target && index != idx {
                    output.push(index as i32);
                    output.push(idx as i32);
                    break;
                }
            }
        }
        output
    }
    pub fn two_sum_performance(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for (index, &num) in nums.iter().enumerate() {
            if let Some(&i) = map.get(&(target - num)) {
                return vec![i as i32, index as i32];
            }
            map.insert(num, index as i32);
        }
        vec![]
    }
}
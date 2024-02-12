use std::collections::HashMap;

pub(crate) struct Solution;
pub(crate) struct Solution14;

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

    /* Challenge 9 - Palindrome number */
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false
        }

        let sx = x.to_string();
        let mut left = 0;
        let mut right = sx.len() - 1;
        while left != right {
            if sx.chars().nth(left) != sx.chars().nth(right) {
                return false;
            }
            left += 1;
            if right == 0 {
                return true;
            }
            right -= 1;
        }
        true
    }
    pub fn is_palindrome_performance(x: i32) -> bool {
        if x < 0 || (x % 10 == 0 && x != 0) {
            return false;
        }

        let mut num = x;
        let mut reversed = 0;

        while num > reversed {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }

        num == reversed || num == reversed / 10
    }
}

impl Solution14 {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut short = strs.clone().into_iter().min_by_key(|s| s.len()).unwrap_or("".to_string());
        for item in strs {
            while !item.starts_with(&short) {
                short.pop();
            }
        }
        short
    }
}

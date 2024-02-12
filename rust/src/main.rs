mod solutions;
use solutions::Solution14;

fn main() {
    let strs  = vec!["flower".to_string(),"flow".to_string(),"flight".to_string()];
    let result = Solution14::longest_common_prefix(strs);
    println!("{:?}", result);
}
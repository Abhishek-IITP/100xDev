// fn main(){
//     let file_content_result = fs::read_to_string("hello.txt");

//     match file_content_result{
//         Ok(contents)=> println!("File contents: {}", contents),
//         Err(error)=> println!("Error reading file: {}", error),
//     }
// }

// fn main(){
//     // let file_content = fs::read_to_string("hello.txt").unwrap();
//     let file_content = fs::read_to_string("hello.txt").unwrap_or(String::from("Default content if file not found"));

//     println!("File contents: {}", file_content);
// }


// fn main(){
//     println!("{}", find_first_a(String::from("Abhihsek")));
//     println!("{}", find_first_a(String::from("Mohit")));
//     println!("{}", find_first_a(String::from("superman")));
// }

// fn find_first_a(s: String)-> i32{
//     for (index,char) in s.chars().enumerate(){
//         if charr == 'a' || char == 'A'{
//             return index as i32;
//         }
//     }
//     return -1;
// }
// fn find_first_a(s: String)-> Option<i32>{
//     for (index,char) in s.chars().enumerate(){
//         if char == 'a' || char == 'A'{
//             return Some(index as i32);
//         }
//     }
//     return None;
// }
// fn main(){
//     let value = find_first_a(String::from("bhihasek"));

//     match value{
//         Some(index)=> println!("Found 'a' at index: {}", index),
//         None=> println!("'a' not found in the string"),
//     }

// }

// fn find_first_a(s: String)-> Option<i32>{
//     for(idx,char) in s.chars().enumerate(){
//         if char == 'a' || char == 'A'{
//             return Some(idx as i32);
//         }
//     }
//     return None;
// }


fn main(){
let name = String::from("Abhishek");
print!("My name is {}", name);
}

// fn main() {

//     let mut longests;
//     let str1= String::from("Hello");
//     {
//         let str2 = String::from("Abhishek");
//         longests = longest_str(&str1, &str2);
//         println!("{}",longests);
//     }

//      println!("{}",longests);

//      println!("{}",str1);
//      println!("{}",str2);
// }
// fn longest_str<'a> (first: &'a String, second: &'a String)-> &'a String{

//     if first.len() > second.len() {
//         return first;
//     } else {
//         return  second;
//     }
// }

// #[derive(Debug)]
// struct User{
//     first_name : &String,
//     last_name : &String
// }

// fn main(){

//     let first_name = String::from("Abhishek");
//     let last_name = String::from("Mohanty");

//     let mut u;

//      u= User{
//         first_name : &first_name,
//         last_name: &last_name
//      };

//      println!("{:?}",u)
// }

/*THe about code not has the issue of lifetime , i will that below using scopes */

// #[derive(Debug)]
// struct User {
//     first_name: &String,
//     last_name: &String,
// }

// fn main() {
//     let mut u;
//     let first_name = String::from("Abhishek");

// here we  can see that last name only have the scope till the {}, that why it is showing us to add lifetimes
//     {
//         let last_name = String::from("Mohanty");

//         u = User {
//             first_name: &first_name,
//             last_name: &last_name,
//         };
//     }
//     println!("{:?}", u)
// }

//proper fixed code

#[derive(Debug)]
struct User<'a> {
    first_name: &'a String,
    last_name: &'a String,
}

fn main() {
    let mut u;
    let first_name = String::from("Abhishek");
    {
        let last_name = String::from("Mohanty");

        u = User {
            first_name: &first_name,
            last_name: &last_name,
        };
        println!("{:?}", u)
    }
}

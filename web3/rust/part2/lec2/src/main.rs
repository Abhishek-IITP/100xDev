cargo new my_project_name// fn main() {
//     let s: String= String::from("Abhishek");
//     println!("{}", is_longer_than(&s,10));
//     println!("{}", s);
// }

// fn is_longer_than(s: &String, num: usize)-> bool{

//     if s.len()> num {
//         return true;
//     }else {
//         return false;
//     }

// }

use std::string;

struct  Address{
    city: String,
    pincode: String,
    country: String
}

struct  User{
    name : String,
    age: u32,
    addresses: Vec<Address>
}

fn main(){
    let user1 = User{
        name : String :: from("Abhishek"),
        age: 18,
        addresses: vec![Address{city:String::from("Jamshedpur"), pincode: String::from("831004"), country: String::from("India")}]
    };
    let user2 = User{
        name: String ::from("Mohit"),
        age:17,
        addresses: vec![Address{city: String::from("Patna"), pincode: String::from("310080"),country: String::from("India")}]
    };

    print!("{}", is_allowed_to_vote(user2));
}

fn is_allowed_to_vote(u: User)-> bool{
    if u.age>=18{
        return  true;
    }
    else {
        return  false;
    }
}
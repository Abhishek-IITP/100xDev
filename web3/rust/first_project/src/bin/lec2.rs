struct User{
     name: String,
     age: u32
}

fn main() {
    let user1 = User{
     name: String::from("Abhishek"),
     age: 21
    };
    let user2 = User{
     name: String::from("Abhijeet"),
     age: 12
    };

    println!("{} can vote? {}", user1.name, is_allowed_to_vote(&user1));
    println!("{} can vote? {}", user1.name, is_allowed_to_vote(&user2));
}

fn is_allowed_to_vote(u: &User)->bool{
     if u.age >= 18{
          return true;
     }else{
          return  false;
     }
}


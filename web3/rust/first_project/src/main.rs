// fn main() {
    // println!("Hello, world!");
    // println!("Hello, world!");
    // print!("Hello, world!");
    // print!("Hello, world!");

    // let x: i32 = 1;
    // let y: u32 = 100000;
    // println!("{},{}",x,y);

    // let is_male = false;
    // let is_above_18 = true;

    // if is_male {
    //     println!("You are a male");
    //     if is_above_18 {
    //         println!("and you are adult")
    //     }
    // } else {
    //     println!("You are a female");
    //     if is_above_18 {
    //         println!("and you are adult")
    //     }
    // }

    // let mut greeting = String::from("Hello world");
    // greeting.push_str(&String :: from(" Abhishek"));

    // print!("{}", greeting);

    // let mut vec=vec![1,2,3,4,5];
    // vec.push(10);
    // vec.push(20);
    // println!("{:?}", vec);
    
//     let ans = do_sum(5, 7);
//     print!("{}",ans)



// }


// fn do_sum(a: i32, b: i32) -> i32 {
//     return a + b;
// }

// pub fn main(){
//     let mut ans =0;
//     for i  in 1..100{
//         ans +=i;
//     }
//     print!("{}",ans);
// }

// fn main() {   
//     let str = String::from("Harkirat");
//     let len = get_length(str);

//     println!("{}", len);
//     println!("{}", str);
// }

// fn get_length(str: &String) -> usize {
//     str.len()
// }

// fn main(){
//     let str = String::from("Abhishek");
//     let len = get_length(&str);
//     println!("{}",len);
//     println!("{}",&str);
// }

// fn get_length(str: &String)->usize{
//     str.len()
// }


// fn main(){
//     let arr: [i32; 5] = [1,3,5,2,5];

    // for i in arr {
    //     println!("{}",i);
    // }
    // for i in arr.iter().rev() {
    //     println!("{}",i);
    // }
//     for (i,val) in arr.iter().enumerate() {
//         println!("{} ---> {}",i,val);
//     }
//     println!("{}", arr.len());
// }

// fn main() {
//     for i in (0..10).step_by(2) {
//         println!("{}", i);
//     }
// }


// fn main(){
//     let mut vec = vec![1,2,3,4,5];
//     vec.push(10);
//     vec.push(20);
//     println!("{:?}",&vec);
//     println!("{}", vec.len());       // elements count
//     println!("{}", vec.capacity()); // allocated memory
    
//     match vec.get(0) {
//         Some(val) => println!("{}", val),
//     None => println!("No value"),
// }

// println!("Normal print");
// for val in &vec {
//     println!("{}", val);
// }
// println!("Mutable print");

// for val in &mut vec {
//     *val += 1;
// }
// println!("OwnerShip move");

// for val in &vec {
//     println!("{}", val);
// }
// println!("{:?}",vec);
// }


fn main(){
    let mut str = String::from("Abhishek");
    str.push_str(&String::from(" Mohanty"));

    println!("{}",str);
}

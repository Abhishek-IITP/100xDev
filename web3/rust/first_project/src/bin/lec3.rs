use std::fs;

fn main() {
    let greeting_file_result = fs::read_to_string("a.txt");

    match greeting_file_result {
        Ok(file_contents) => {
            println!("{}", file_contents);
        }
        Err(_err) => {
            println!("Error while reading the file");
        }
    }
}
use std::fs::File;
use std::io::Read;
use std::io::{self, BufRead};
use std::fs;

fn main() -> io::Result<()> {
    let mut file = File::open("./input.txt").expect("Unable to open file");
    let mut contents = String::new();
    file.read_to_string(&mut contents).expect("Unable to read file");
    let groups: Vec<&str> = contents.split("\n\r\n").collect();
    
    for group in groups {
        let numbers: Vec<&str> = group.split("\n").collect();
        println!("new group");
        for number in numbers {
            println!("{}", number);
        }
    }

    /*
    let file = File::open("./input.txt")?;
    let reader = io::BufReader::new(file);
    for line in reader.lines() {
        match line {
            Ok(line) => println!("{}", line),
            Err(err) => eprintln!("Error reading line: {}", err),
        }
    }
    */
    Ok(())
}

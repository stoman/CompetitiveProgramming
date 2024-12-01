use std::io::BufRead;
use std::io::Error;

fn main() -> Result<(), Error> {
    // Read input from stdin into two lists of integers.
    let stdin = std::io::stdin();
    let mut lines = stdin.lock().lines();
    let mut first_list: Vec<i64> = Vec::new();
    let mut second_list: Vec<i64> = Vec::new();
    while let Some(line) = lines.next() {
        let line = line?;
        let ints: Vec<i64> = line.split("   ").map(|n| n.parse().expect("an i64 parseable number")).collect();
        first_list.push(ints[0]);
        second_list.push(ints[1]);
    }

    // Sort the lists as we want to compare the items in order.
    first_list.sort();
    second_list.sort();

    // Iterate through list and compute the differences.
    let mut diff = 0;
    for i in 0..first_list.len() {
        diff += (first_list[i] - second_list[i]).abs();
    }

    println!("{}", diff);
    Ok(())
}
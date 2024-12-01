use std::collections::HashMap;
use std::io::BufRead;
use std::io::Error;

fn main() -> Result<(), Error> {
    // Read input from stdin into two lists of integers.
    let stdin = std::io::stdin();
    let mut lines = stdin.lock().lines();
    let mut first_list: Vec<u64> = Vec::new();
    let mut second_list: Vec<u64> = Vec::new();
    while let Some(line) = lines.next() {
        let line = line?;
        let ints: Vec<u64> = line.split("   ").map(|n| n.parse().expect("an u64 parseable number")).collect();
        first_list.push(ints[0]);
        second_list.push(ints[1]);
    }

    // Count frequencies in the second list.
    let mut frequencies: HashMap<u64, u64> = HashMap::new();
    for i in second_list {
        let count = frequencies.entry(i).or_insert(0);
        *count += 1;
    }

    // Iterate through list and compute similarity score.
    let mut score = 0;
    for i in first_list {
        score += i * frequencies.get(&i).unwrap_or(&0);
    }

    println!("{}", score);
    Ok(())
}
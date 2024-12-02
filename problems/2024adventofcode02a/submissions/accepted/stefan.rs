use std::io::BufRead;
use std::io::Error;

fn main() -> Result<(), Error> {
    let mut safe_reports = 0;
    for line in std::io::stdin().lock().lines() {
        let line = line?;
        let mut last = -1;
        let mut last_diff = -1;
        let mut safe = true;
        for i in line.split_whitespace().map(|n| n.parse().expect("an i32 parseable number")) {
            let diff: i32 = last - i;
            if last_diff != -1 && last_diff * diff < 0 {
                safe = false;
            }
            if last != -1 {
                if diff == 0 || diff.abs() > 3 {
                    safe = false;
                }
                last_diff = diff;
            }
            last = i;
        }
        if safe {
            safe_reports += 1;
        }
    }
    println!("{}", safe_reports);
    Ok(())
}
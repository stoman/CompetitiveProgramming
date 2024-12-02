use std::io::BufRead;
use std::io::Error;

fn main() -> Result<(), Error> {
    let mut safe_reports = 0;
    for line in std::io::stdin().lock().lines() {
        if is_report_really_safe(line?.split_whitespace().map(|n| n.parse().expect("an i32 parseable number")).collect()) {
            safe_reports += 1;
        }
    }
    println!("{}", safe_reports);
    Ok(())
}

fn is_report_really_safe(report: Vec<i32>) -> bool {
    // Not skipping a level is implicitly allowed as well as a safe report can just skip the first or last level to still be safe.
    for i in 0..report.len() {
        if is_report_safe(&report, i) {
            return true;
        }
    }
    return false;
}

fn is_report_safe(report: &Vec<i32>, skip: usize) -> bool {
    let mut last = -1;
    let mut last_diff = -9999;
    let mut safe = true;
    for i in 0..report.len() {
        if i == skip {
            continue;
        }
        let diff: i32 = last - report[i];
        if last_diff != -9999 && last_diff * diff < 0 {
            safe = false;
        }
        if last != -1 {
            if diff == 0 || diff.abs() > 3 {
                safe = false;
            }
            last_diff = diff;
        }
        last = report[i];
    }
    return safe;
}
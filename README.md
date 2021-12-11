# About

This repository contains some submissions for competitive programming problems I solved. Contests include:

 * [Advent of Code](https://adventofcode.com), including
   * [Advent of Code 2020](https://adventofcode.com/2020) in Kotlin ![](https://img.shields.io/badge/stars%20⭐-50-yellow?2020)
   * [Advent of Code 2021](https://adventofcode.com/2021) in Kotlin ![](https://img.shields.io/badge/stars%20⭐-22-yellow?2021)
 * [CodeChef](https://www.codechef.com), including
   * [December Challenge 2015](https://www.codechef.com/DEC15)
   * [December Cook-Off 2015](https://www.codechef.com/COOK65)
   * [July Lunchtime 2016](https://www.codechef.com/LTIME38)
 * [Codeforces](https://codeforces.com), including
   * [Round #350](https://codeforces.com/contest/670)
   * [Round #357](https://codeforces.com/contest/681)
   * [Helvetic Coding Contest 2016](http://codeforces.com/contest/690)
 * [Facebook Hacker Cup](https://www.facebook.com/codingcompetitions/hacker-cup), including
   * [2016 Qualification Round](https://www.facebook.com/codingcompetitions/hacker-cup/2016/qualification-round) 
   * [2016 Round 1](https://www.facebook.com/codingcompetitions/hacker-cup/2016/round-1)  
   * [2017 Qualification Round](https://www.facebook.com/codingcompetitions/hacker-cup/2017/qualification-round) 
   * [2017 Round 1](https://www.facebook.com/codingcompetitions/hacker-cup/2017/round-1)  
 * [Google Code Jam](https://codingcompetitions.withgoogle.com/codejam), including
   * [2016 Qualification Round](https://codingcompetitions.withgoogle.com/codejam/round/0000000000201bee)
   * [2016 Round 1C](https://codingcompetitions.withgoogle.com/codejam/round/0000000000201bef)
   * [2016 Round 2](https://codingcompetitions.withgoogle.com/codejam/round/0000000000201c91)
   * [2017 Qualification Round](https://codingcompetitions.withgoogle.com/codejam/round/00000000002017f7)
   * [2017 Round 1B](https://codingcompetitions.withgoogle.com/codejam/round/000000000020187f)
 * [HackerRank](https://www.hackerrank.com), including
   * [10 Days of Statistics](https://www.hackerrank.com/domains/tutorials/10-days-of-statistics)
   * [101 Hack 32](https://www.hackerrank.com/contests/101hack32)
   * [101 Hack 39](https://www.hackerrank.com/contests/101hack39)
   * [30 Days of Code](https://www.hackerrank.com/contests/30-days-of-code)
   * [Cracking the Coding Interview](https://blog.hackerrank.com/introducing-cracking-the-coding-interview-tutorial-new-study-on-interview-practice/)
   * [HourRank 4](https://www.hackerrank.com/contests/hourrank-4)
   * [HourRank 18](https://www.hackerrank.com/contests/hourrank-18)
   * [Python Domain](https://www.hackerrank.com/domains/python)
   * [Week of Code 20](https://www.hackerrank.com/contests/w20)
   * [World CodeSprint 5](https://www.hackerrank.com/contests/world-codesprint-5)
   * [World CodeSprint May 2016](https://www.hackerrank.com/contests/may-world-codesprint)
 * [Northwestern Europe Regional Contest (NWERC)](https://www.nwerc.eu), including
   * [NWERC 2015](http://2015.nwerc.eu)

Contest not uploaded to this repository include:

* All [ICPC](https://icpc.global) contests I participated in with my team without having access to an internet
  connection.
* [Google Hash Code](https://hashcode.withgoogle.com/) which is uploaded in dedicated repositories.
* Contests I worked on as an organizer of [Google Hash Code](https://hashcode.withgoogle.com/).
* Contests that are still running.

Do not use the submissions if you want to solve the problems yourself, but feel free to have a look if you really
want to see other submissions. Depending on how you use this repository it may not be optimal for learning. The main
purpose of this repository is to collect the problems for myself, I published it since I see no important reasons
against it.

# Usage

All problems use the [Kattis problem format](http://www.problemarchive.org/wiki/index.php/Problem_Format) to allow
the use of the [Kattis problemtools](https://github.com/Kattis/problemtools). Most problems just contain sample data
and my submissions, other data as the problem text or secret test data are only available for selected problems. All
problems contain source links and keywords. Some solutions contain explanations describing the idea to solve the
problem, others just use the code.

To find problems for a specific topic or contest search for keywords like this:

```
grep 'NWERC' problems/*/problem.yaml
grep 'dynamic programming' problems/*/problem.yaml
```

I also tagged the problems with a difficulty rating. This is just a subjective feeling. Search for the difficulty rating
like this: 

```
grep 'medium' problems/*/problem.yaml
```

Execute `make all` or `make DIRECTORY` in the `problems` subdirectory to test problem data.

# Build

`checktestdata` is executed on each problem after pushing to this directory. Results of the builds are available at
[GitHub Actions](https://github.com/stoman/CompetitiveProgramming/actions).

# Installation

Make sure you install all requirements of the [Kattis problemtools](https://github.com/Kattis/problemtools).

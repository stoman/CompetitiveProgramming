# About

This repository contains some submissions for competitive programming problems I solved, but not all of them. I only post solutions to training problems or problems from past contests.

All problems use the [Kattis problem format](http://www.problemarchive.org/wiki/index.php/Problem_Format) to allow the use of the [Kattis problemtools](https://github.com/Kattis/problemtools). Most problems just contain sample data and my submissions, other data as the problem text or secret test data are only available for selected problems. All problems contain source links and keywords. Some solutions contain explanations describing the idea to solve the problem, others just use the algorithm.

Do not use the submissions if you want to solve the problems yourself, but feel free to have a look if you really want to see other submissions. Depending on how you use this repository it may not be optimal for learning. The main purpose of this repository is to collect the problems for myself, I published it since I see no important reasons against it.

# Build

`checktestdata` is executed on each problem after pushing to this directory. Results of the builds may be found at [Travis](https://travis-ci.org/stoman/competitive-programming).

# Installation

This repository contains the [Kattis problemtools](https://github.com/Kattis/problemtools) as a submodule. To use them install the following packages:

```
apt-get install make automake g++ libboost-dev libboost-regex-dev libgmp-dev python-plastex python-yaml
```

Afterwards, execute `make` in the problemtools subdirectory to install the problemtools.

# Usage

To find problems for a specific topic you may search for keywords like this:
```
grep 'dynamic programming' problems/*/problem.yaml
```

Also, the problems are tagged with a difficulty rating. This is just a subjective feeling. You can also search for it like this: 
```
grep 'medium' problems/*/problem.yaml
```

Execute `make all` or `make DIRECTORY` in the `problems` subdirectory to test problem data.

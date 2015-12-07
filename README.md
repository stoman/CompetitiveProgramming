# About

This repository contains some submissions for competitive programming problems I solved. All problems use the [Kattis problem format](http://www.problemarchive.org/wiki/index.php/Problem_Format) to allow the use of the [Kattis problemtools](https://github.com/Kattis/problemtools). Most problems just contain sample data and my submissions, other data as the problem text or secret test data are only availabl efor selected problems.

Do not use the submissions if you want to solve the problems yourself, but feel free to have a look if you want to see other submissions. Some solutions contain explanations describing the idea to solve the problem, others just use the algorithm.

# Build [![Build Status](https://travis-ci.org/stoman/competitive-programming.svg)](https://travis-ci.org/stoman/competitive-programming)

`checktestdata` is executed on each problem after pushing to this directory. Results of the builds may be found at [Travis](https://travis-ci.org/stoman/competitive-programming).

# Installation

This repository contains the [Kattis problemtools](https://github.com/Kattis/problemtools) as a submodule. To use them install the following packages:

```
apt-get install make automake g++ libboost-dev libboost-regex-dev libgmp-dev python-plastex python-yaml
```

Afterwards, execute `make` in the problemtools subdirectory to install the problemtools.

# Usage

Execute `make all` or `make DIRECTORY` in the `problems` subdirectory to test problem data.

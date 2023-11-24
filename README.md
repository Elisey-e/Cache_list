# HWC - Cache_list

This project is the first task on course "Uses and applications of C++ language" by [K.I.Vladimirov](https://github.com/tilir). The task was to implement one of suggested cache replacement algorithms. I chose LFU cache and Perfect implementation.

## How to install

```bash
git clone git@github.com:Elisey-e/Cache_list.git
cd Cache_list
```

## Requirements

The following applications have to be installed:

1) CMake of version 3.15 (or higher)

2) C++ compilator standart C++20 (or higher)

## How to build

### 0) Make sure you are in the subdirectory of root directory of the project

### 1) Build cache

```bash
cmake ..
make
```

## How to run tests

If you want to run some end to end tests, go to [./tests](./tests/) directory.

Let **N** be the number of tests you want to run, then command such sequence:

```bash
./some_running_test < file_to_test.dat
```

runs some file from [unit_tests](./tests/src/unit_tests/) unit_test directory and compares calculated answer with appropriate in [unit_tests_results](./tests/src/unit_tests_results/)'s file.

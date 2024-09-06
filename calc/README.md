# Arithmetic Calculator
### Step 1: The calculator
Build: `cmake [-D CMAKE_CXX_COMPILER=clang++] .`<br>
Run: `bin/calc <expression> [ > bin/<name_to_save>.ll ]`
### Step 2: LLVM IR to executable
Compile LLVM IR: `./compiler-ll.sh <name_to_save>`<br>
Run the result: `bin/<name_to_save>.x`
##### Example: Sum of variables X and Y
```sh
$ cmake -D CMAKE_CXX_COMPILER=clang++ .
$ bin/calc "with x, y: x + y" > bin/sum.ll
$ ./compiler-ll.sh sum
$ bin/sum.x
Enter a value for x: 2
Enter a value for y: 7
The result is: 9
$ 
```
Voila!
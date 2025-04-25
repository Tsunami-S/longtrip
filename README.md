# The subject of finding the longest path

## The development environment
* OS: Linux x86_64(Arch linux)
* Compiler: g++
* language: C++

## Usage
1. **Build the program**:  
   Use the `make` command to compile the program.
   
   ```bash
   make
   ```

2. **Run the program**:
  After building the program, run it and enter one-way train information into the standard input (STDIN).
  Each line should contain the start station ID, end station ID, and the distance, separated by commas.

Example input:

```bash
./longtrip
(example: int,int,float)
1, 2, 8.54
2, 3, 3.11
3, 1, 2.19
3, 4, 4
4, 1, 1.4
```

  The program will continue to accept inputs until you send an EOF (End Of File) signal .
  After receiving EOF, the program will compute and display the longest path.

3. **Output**:
  The program will print the IDs of the stations along the longest path, one ID per line.
  The output will be displayed as follows:

Example output:

```bash
1
2
3
4
1
```

## Notes
* The program does not allow a station to appear more than once in the path.
* The input format must follow this structure:
  * Station IDs (start and end) are 32-bit signed integers.
  * The distance is a floating-point number represented within the range of the float type.
* If the input is invalid (e.g., incorrect format), the program will print an error message and skip the invalid line.
* If 'std::regex' does not compile due to compiler or library support issues with C++17, please open `utils.cpp` and replace the current function with the commented-out alternatives.
* This issue may occur in certain environments where 'std::regex' is not fully supported or enabled by default.

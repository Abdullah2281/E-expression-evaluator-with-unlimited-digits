# E-expression Evaluator with Unlimited Digits

This project is an implementation of Unlimited Int and Unlimited Rational from scratch. Here's how you can run the checker code based on your operating system:

## Author : Abdullah

## Instructions for Linux/macOS:

1. **Extract Checker Code**: 
    - Extract the checker code and place the following files in the starter code folder: `drivercode.cpp`, `Makefile`, and the `test_cases` folder.

2. **Compilation**:
    - Open your terminal and navigate to the starter code folder.
    - Run the command:
      ```bash
      make
      ```

3. **Run Checker**:
    - Once the compilation is successful, execute the checker using:
      ```bash
      ./A4Checker
      ```

## Instructions for Windows:

- **Compilation**:
    - Compile the `drivercode.cpp` file along with all other `.cpp` files, excluding `testInt` and `testRat` from the starter code.
    - This will generate an executable `.exe` file.

- **Run Checker**:
    - Execute the resulting `.exe` file.

## About the Checker:

The provided checker is straightforward, focusing on:
- Ensuring the parse tree is constructed correctly.
- Verifying the accuracy of the evaluated value at every node.

Additionally, `testInt` and `testRat` have been created specifically to validate that the unlimited rational and unlimited int outputs are correct.
You can also make your own testcases for more robust checking

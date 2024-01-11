# Interpreter_V3
## A Scheme to C++ interpreter.

**This project was built in 3 major iterations:**

### Iteration 1: 
    For this iteration, the goal was to design and 
    construct a lexical analyzer for the language 
    scheme. This included recognizing lexemes 
    for identifiers, numeric literals and 
    all symbols listed in the grammar PDF within 
    this repository. After the input file is read 
    in, the lexical analyzer outputs a listing file, 
    a token file and a debugging file. The listing 
    file contains the lines of the input file with 
    line numbers and errors. The token file
    contains a list of the tokens identified in
    the file and their corresponding lexemes.


### Iteration 2: 
    In this iteration, I wrote a recursive decent 
    parser in order to perform syntactical analysis 
    on the scheme input code. The output from this 
    step is a list of all grammar rules used 
    throughout the analysis of the file and if 
    each line code is deemed valid according to 
    said grammar. An error counter will be 
    incremented and displayed at the end of the 
    resulting file.


### Iteration 3: 
    For this final iteration of the interpreter, 
    I wrote the code generator classes that take 
    in the scheme input code and translate each line 
    into valid C++ code. That C++ code is then compiled 
    and executed for the user to observe in the console 
    via a script file called "run1".

---

Future versions of this project will read in scheme code 
and output valid code in multiple languages, not just C++. 
This first complete interpreter version was built for 
CS460 at SSU with professor Watts.

---
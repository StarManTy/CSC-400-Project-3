

- This workspace is set up to work in Visual Studio Code assuming you have Dev C++ installed to the default directory.
    - It uses the gcc compiler that comes with Dev C++ at ("C:/Program Files/CodeBlocks/MinGW/bin/gcc.exe")
    - if needed change this directory in `c_cpp_properties.json`

- To compile the code, you can use `compile.bat` in the root directory. Or, in VSCode, you can press ctrl+shift+b to "build"
- To compile and run the unit tests, you can use 'runtests.bat' or press ctrl+shift+p to bring up the command pallette in VSCode and select the "run tests" command.s



I set this up with CuTest. I have found this small library invaluable with C programs to test individual functions. You can find CuTest's readme in docs/CuTest-Readme.txt
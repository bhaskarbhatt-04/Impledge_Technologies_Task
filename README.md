# Overview
This C++ program is designed to read a list of words from a file, insert them into a trie data structure and comparing function, and then identify the longest and second-longest compound words from the list.

Task.cpp: Contains the main program logic.

Input_01.txt: Sample input file (you can replace it with your own file).

Input_02.txt: Sample input file (you can replace it with your own file).

Output_File_1.png: Sample output window of console from Input_01.txt.

Output_File_2.png: Sample output window of console from Input_02.txt.

C++ Compiler: Ensure that you have a C++ compiler installed on your system.

# How to Run
Step 1: Open a terminal or command prompt.

Step 2: Navigate to the directory containing the source code.

Step 3: Compile the program using a C++ compiler. For example, using:

g++ Task.cpp -o Task

Run the compiled executable

# Approach used

This C++ program uses a trie to store words efficiently. It sorts words by length, focusing on longer words first. The program checks if each word is a compound of smaller words in the trie. It outputs the longest and second-longest compounds, along with processing time.

Key Steps:

1. Trie Implementation: Efficient storage and retrieval of words.

2. Sorting by Length: Prioritize longer words for compound checks.

3. Compound Word Check: Iterative search for compound words.

4. Output: Display longest compounds and processing time.

# Note:

Trie handles prefix-based searches efficiently.
Sorting by length optimizes compound word discovery.

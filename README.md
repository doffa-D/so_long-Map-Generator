# so_long Map-Generator

Treasure Map Generator
This program generates a treasure map with random obstacles and coins. The generated map is saved in a file named map.ber.

# Usage

1) Open a terminal and navigate to the directory where the program is located.

2) Compile the program using a C compiler such as `gcc: gcc Map-Generator.c -o Map-Generator`

3) Run the program: `./Map-Generator`

4) Enter the number of rows for the treasure map when prompted. The number should be between 3 and 40, inclusive.

5) Enter the number of columns for the treasure map when prompted. The number should be between 3 and 40, inclusive.

6) Optionally, enter the number of coins for the treasure map when prompted. If you do not want to specify the number of coins, you can enter 0 and the 
program will generate a random number of coins.

7) The program will generate a treasure map with random obstacles and coins, and save it in a file named map.ber in the same directory.

# Note: 
If you enter a number greater than 40 or less than 3 for the number of rows or columns, the program will not work properly. However, this does not apply to the number of coins, which can be 0 or any positive integer.


# Usage Example

```
$ ./Map-Generator
Enter the number of rows: 20
Enter the number of columns: 30
Enter the number of coins: 0
The file was created successfully. Check the file named {map.ber}.
```

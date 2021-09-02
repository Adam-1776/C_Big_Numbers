Introduction:
	Intal is an ASCII string that is used to store a number. Each character of the
string stores one digit of the number in big-endian order. The advantage of Intal is that
it can store an arbitrarily long number. The disadvantage of using Intal is that the 
computer doesn't actually 'know' that the Intal represents a number -- it simply sees it as
any other string. For this reason, all arithmetic operations have to be defined from scratch.
Each character of the string (i.e. each digit of the number) has to be manipulated manually
and individually for each arithmetic operation. This is in stark contrast to an integer data type,
where the entire number (i.e all the digits) are stored in a single variable and can easily be
operated on using the default arithmetic operators. The only real advantage of Intal is the ability
to manipulate arbitrarily long numbers (in contrast to integer datatypes, which have a fixed range).

Approach:
	My program is very minimalistic. (The entire implementation is only 87 lines of code!)
My approach has very little overhead; I have not made use of any structs, global variables,
or macros. I also took care to avoid memory leaks.
As for the actual algorithms used, I took inspiration from online resources as well as open-source
big-number libraries. My approach towards addition, subtraction, and mulitplication are fairly 
conventional and mimic paper-and-pen methods.
	However, I divised my own method for performing the modulo operation. My intal_mod()
function takes the divisor, and repeatedly doubles it as many times as possible before
it exceeds the divident. Let's call this number 'y'. Using the expression y+(divisor^n) it 
keeps on incrementing 'n' as many times as it can before the value of the expression exceeds the
divident. The value of this expression is assigned to 'y'. This cycle is repeated as many times as
necessary until the difference between 'y' and the divisor is less than 10000. After that, it 
simply keeps on adding the divisor to 'y' until it exceeds the divident. Finally, the remainder is
found by subtracting this value from the divident. Basically, this is an efficient bruteforcing method.
	My approach to the other functions are fairly conventional and utilize well-known algorithms.
In the coin-row problem, I use a space-efficient dynamic-programming approach which utilizes a fixed
size table capable of storing three intals.

Future possibilities:
	While working on this project, I took a look at some open-source bignumber libraries for 
C/C++. The libraries I saw utilized a typedef struct to store each intal. This allows some meta-data
about each intal to be stored easily. In particular, a boolean variable can be included in each intal
to specify whether it represents a positive or negative number. This would eliminate the limitation of
only being able to handle positive numbers. While I didn't look into it in detail, I also noticed that
the common bignumber libraries offer the ability to handle arbitrarily long floating point numbers.
The bignumber libraries I've seen include robust functionality that far exceeds what I have
developed. I cannot think of any additional features that could be divised that is not already included
in the open-source bignumber libraries I've seen.







after reading the prompt for the assignment, I decided that the easiest way to input and output the data would be
to use the input data from a text file, and then output that data onto another text file matching the format shown

example:
    XVI || 14
    
    XXX || 30
    
    IIVV || 12
    
    and so on.

To utilize this solution, I used a main file to interact with the inputs from the command line, and give
instructions if the incorrect arguments are used as inputs, or if there were errors detected in the program.
The program will still output a solution if there was an error detected. with notes pointing out the error.

I made a class that would keep track of the Roman Numerals along with their conversions. utilising queues to keep my
conversions in order, and a map to have the conversions saved.

The class function "fileExists" would validate a file's existence, and the function "setUp" would prepare my Roman
Numeral Queue. Then the function "adapt" would sum up the number into a queue. after every number a function called
"finish" would put the numbers and original Roman Numerals into the file to be outputted to.

unfortunately I was unable to finish the assignment before the 4 hours were up. But the code is nearly functionality.

# get_next_line
42 school project

get next line is a function allowing to read a line ending with a newline character ('\n') from a file descriptor (fd).<br />
This was originally a 42 school project.<br />

### Mandatory part

* Write a function that returns a line read from a file descriptor.
•What we call a “line” is a succession of characters that end with ’\n’ (ascii code0x0a) or withEnd Of File(EOF).

•Your function must be prototyped as follow :intget_next_line(const intfd,char**line);•The first parameter is the file descriptor that will be used to read.•The second parameter is the address of a pointer to a character that will be usedto save the line read from the file descriptor.•The return value can be1,0or-1depending on whether a line has been read,when the reading has been completed, or if an error has happened respectively.

•Your functionget_next_linemust return its result without’\n’.•Calling your functionget_next_linein a loop will then allow you to read the textavailable on a file descriptor one line at a time until the end of the text, no matterthe size of either the text or one of its lines.

•We consider thatget_next_linehas an undefined behavior if, between two calls,the same file descriptor designs two distinct files although the reading from the firstfile was not completed.•We consider also that a call tolseek(2)will never take place between two calls ofthe functionget_next_lineon the same file descriptor.•Finally we consider thatget_next_linehas an undefined behavior when readingfrom a binary file. 

Bonus part

The projectget_next_lineis straight forward and leaves very little room for bonuses,but I am sure that you have a lot of imagination. If you ace perfectly the mandatorypart, then by all means complete this bonus part to go furher. I repeat, no bonus will betaken into consideration if the mandatory part isn’t perfect.

•To succeedget_next_linewith a single static variable.•To be able to manage multiple file descriptor with yourget_next_line. For ex-ample, if the file descriptors 3, 4 and 5 are accessible for reading, then you can callget_next_lineonce on 3, once on 4, once again on 3 then once on 5 etc. withoutlosing the reading thread on each of the descriptors.

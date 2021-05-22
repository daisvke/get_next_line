# get_next_line
42 school project

get_next_line is a function allowing to read a line ending with a newline character ('\n') from a file descriptor (fd).<br />
This was originally a 42 school project.<br />

### Mandatory part

* The function returns a line read from a file descriptor.
* What we call a “line” is a succession of characters that ends with '\n' (ascii code 0x0a) or with End Of File (EOF).
* The function is prototyped as follows : 
  ```
  int  get_next_line(int fd, char** line);
  ```
* The first parameter is the file descriptor that will be used to read.
* The second parameter is the address of a pointer to a character that will be used to save the line read from the file descriptor.
* The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.
* The function returns its result without '\n'.
* Calling get_next_line in a loop will then allow us to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.
* get_next_line has an undefined behavior if, between two calls, the same file descriptor refers to two distinct files although the reading from the first file was not completed.
* Finally get_next_line has an undefined behavior when reading from a binary file. 

### Bonus part

• The function is able to manage multiple file descriptors. For instance, if the file descriptors 3, 4 and 5 are accessible for reading, then we can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc., without losing the reading thread on each of the descriptors.

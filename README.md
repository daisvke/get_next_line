# get_next_line

get_next_line is a function allowing to read a line ending with a newline character ('\n') from a file descriptor (fd).<br />
This was originally a 42 school project.<br />
<br />

## Mandatory part

### Description

* The function returns a line read from a file descriptor.
* What we call a “line” is a succession of characters that ends with '\n' (ascii code 0x0a) or with End Of File (EOF).
* The function is declared as follows : 
  ```
  int  get_next_line(int fd, char** line);
  ```
* The first parameter is the file descriptor that will be used to read.
* The second parameter is the address of a pointer to a character that will be used to save the line read from the file descriptor
* Calling get_next_line in a loop will allow us to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

### Return value

* The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.
* The function returns its resulting line without '\n'.

### Errors

* get_next_line has an undefined behavior if, between two calls, the same file descriptor refers to two distinct files although the reading from the first file was not completed.
* get_next_line has an undefined behavior when reading from a binary file. 

## Bonus part

* Although it passes all the gnl testers from Github, this part got a K.O. from the "moulinette".
* The function is able to manage multiple file descriptors. For instance, if the file descriptors 3, 4 and 5 are accessible for reading, then we can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc., without losing the reading thread on each of the descriptors.

## Validation

This work has been validated by the following tests:
* [42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)
* [42cursus_gnl_tests](https://github.com/mrjvs/42cursus_gnl_tests)
* [Test-42 test_gnl](https://github.com/PandaCoustik/Test-42/tree/master/test_gnl)
* [gnlTester](https://github.com/Tripouille/gnlTester) (This test may falsely return "TIMEOUT" when testing with BUFFER_SIZE=1 with big_line_no_nl and big_line_with_nl if it is done on a Linux system.)
* [norminette v.3](https://github.com/alexandregv/norminette-action)

<p align="center">
  <img src="/screenshots/all.png" width="100%" />
</p>


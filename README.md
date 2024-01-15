<html>
<body>
<h1>C - SIMPLE SHELL PROJECT</h1>
<img src="https://i.pinimg.com/736x/93/1a/da/931ada2f410834f0bcd8d70f9f8c1fdb.jpg" title="Simple Shell holberton" /></a>
<hr>

<h2>DESCRIPTION</h2>
<p>The "shell" is a command-line interface (CLI) that serves as an interpreter for interacting with the operating system's services. It provides a text-based interface, allowing users to input commands and receive output. The term "shell" can also refer to a scripting environment that facilitates task automation through shell scripts.

This project is a simulation of the Simple Shell.
</p>

<h2>REQUIREMENTS</h2>

  - Allowed editors: vi, vim, emacs
  - All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.
  - All your files should end with a new line
  - A README.md file, at the root of the folder of the project is mandatory
  - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
  - Your shell should not have any memory leaks
  - No more than 5 functions per file
  - All your header files should be include guarded
  - Use system calls only when you need to (why?)


<h2>COMPILATION 💻:</h2>
<pre>
    <p>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh</p>
</pre>

<h2>OUTPUT</h2>

- <p>Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
</p>

<p>Example of error with sh:</p>
<pre>
<p>$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$</p>
</pre>

<p>Same error with your program hsh:</p>
<pre>
<p>$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$</p>
</pre>

<h2>TESTING</h2>
<p>Your shell should work like this in interactive mode:</p>
<pre>
<p>$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$</p>
</pre>

<p>But also in non-interactive mode:</p>
<pre>
<p>$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$</p>
</pre>

<br>

<p>Brayan Salazar</p>
<a href="https://www.linkedin.com/in/brayan-salazar-perdomo-07a4321b1/">
  <img src="https://static-00.iconduck.com/assets.00/linkedin-icon-2048x2048-ya5g47j2.png" width="50">
</a>

<a href="https://github.com/BrayanSalazar14">
 <img src="https://1000logos.net/wp-content/uploads/2021/05/GitHub-logo.png" width="100">
</a>

------------

<p>Maria Alejandra Gonzales</p>
<a href="https://www.linkedin.com/feed/">
  <img src="https://static-00.iconduck.com/assets.00/linkedin-icon-2048x2048-ya5g47j2.png" width="50">
</a>

<a href="https://github.com/marialegl">
 <img src="https://1000logos.net/wp-content/uploads/2021/05/GitHub-logo.png" width="100">
</center>

<footer><img src="https://img.freepik.com/vector-premium/fondo-textura-elegante-blanco_23-2148434267.jpg?size=626&ext=jpg&ga=GA1.1.1222169770.1701648000&semt=ais" width="1000", height ="200"></footer>

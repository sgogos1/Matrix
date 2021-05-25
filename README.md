<h1>Matrix Library</h1>
<h2>Summary</h2>
<h4>Description</h4>
<p>This library was created as an in-house and high-performance solution to management, transposition, and multiplication of two-dimensional matrices using an interface made for easy integration. By default it is built on the C++11 library.</p>
<h4>Dependencies</h4>
<p>The list below details the software that is required in order to integrate this library into your development or execution work. These dependencies are: </p>
<ul>
    <li>C++11 Standard Library</li>
</ul>
<h4>Current Features</h4>
<p>The features currently instantiated in the Matrix library are: </p>
<ul>
    <li><strong>Matrix Manipulation & Storage</strong> - Storage and manipulation of a matrix, its elements.</li>
    <li><strong>Matrix Transposition</strong> - Transposing of a Matrix object.</li>
    <li><strong>Matrix Multiplication</strong> - Multiplication of two Matrix objects (assuming compatible dimensions - # of columns of the first matrice match the # of rows of the second matrice).</li>
</ul>
<h4>License</h4>
<p>The Unlicense</p>

<h2>Using the Matrix Library</h2>
<p>In order to use the Matrix library in your environment as is or after changes you've made, follow the steps below.</p>
<ol>
    <li>Find the location of the file "gogos-stavros.h" (By default its path is: include/gogos-stavros.h). </li>
    <li>Copy the file to a directory in your include path for third party libraries or add the current file path to your environment's include path.</li>
    <li>Add the following text into your header (.h) or source file (.cpp): <strong>include "gogos-stavros.h"</strong></li>
</ol>         

<h2>Developing the Matrix Library</h2>
<p>To further develop this library and add more capability, follow the steps above to locate the library.</p>
<p>Once located, open the file in your preferred development environment and make the changes you seek!</p>
<p>Once you've made your changes, it's encouraged your write a test in order to ensure you've properly built your features. Upon writing the test, build via the command: </p>
<ul>
    <li><strong>g++ test.cpp -o matrix-test -std=c++11</strong></li>
    <li style="margin-left: 3%;">To install g++ please reference this for <a href="https://www.instructables.com/How-to-Install-MinGW-GCCG-Compiler-in-Windows-XP78/">Windows</a> and <a href="https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux">Linux</a>.</li>
</ul>    

<h2>Testing the Matrix Library</h2>
<p>To test the current state of the Matrix library, follow the following steps below:</p>
<ol>
    <li>
        Access the directory for the Matrix library by:
        <ul>
            <li>Contacting the author (see information below)</li>
            <li>Pulling the repository from <a href="https://github.com/sgogos1/Matrix" target="_blank" rel="norefferer noopener">Github</a> (git clone https://github.com/sgogos1/Matrix.git)</li>
        </ul>
    </li>
    <li>Build the test file by running the following command via g++: <strong>g++ test.cpp -o matrix-test -std=c++11</strong> in the command prompt (from the root of the directory)</li>
    <ul><li>To install g++ please reference <a href="https://www.instructables.com/How-to-Install-MinGW-GCCG-Compiler-in-Windows-XP78/">Windows</a> and <a href="https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux">Linux</a>.</li></ul>
    <li>To run the tests for instantiation, multiplication, and transposition of via the Matrix library, run the command: <strong>./matrix-test</strong> (on Powershell or Bash) or <strong>matrix-test.exe</strong> (on Command Prompt)</li>
</ol>

<h2>Point of Contact</h2>
<p>Author: Stavros Gogos</p>
<p>Email: sgogos1@gmail.com</p>
<p>Github: <a href="https://github.com/sgogos1">https://github.com/sgogos1</a></p>

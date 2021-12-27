# Netpbm C Graphing Library
## :chart_with_upwards_trend: Purpose
The idea of this project is to make a `plot` function in C that will take the
user's input (either a functions or collection of points) and generate a graph
similar to how easy it is with python or MATLAB.

The file format used to make the graph is the netpbm format. This format is
supported by many pdf readers.  This file format is good for quick graphical
debugging due to its uncompressed nature, however this also leads to larger
file sizes. [Here](https://en.wikipedia.org/wiki/Netpbm) is the wikipedia 
page for the netpbm file format, I found it quite helpful.

## Supported Features
Currently there is a 

## :floppy_disk: Installation
NOTE: This installation will produce a binary in the system under the name 
`millipedes_grapher`.  This binary will accept flags that are arguments to the
function `plot` in the source code.  This function can be imported to other C
libraries by copying the code, including it in the new program and calling
`plot` with the correct parameters.

To install, clone the repository, change directories into the clone, and run
the following command:
```
	sudo make install
```

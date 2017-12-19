# Experiment log for August 30, 2017
## Bitfields
There is a functionality for C/C++ which allows to use *bitfields*. Bitfields are representations for integral types (`int`, `char`, `long`...) that are masked at compile time.

But there is a big problem with it, since we are [unable to allocate a bitfield array](https://stackoverflow.com/questions/41918433/is-it-possible-to-use-array-of-bit-fields). This occurs because bitfields apply a mask to it's integral type. Also, as pointer arithmetic works with a minimum size of a byte, to execute a *memory reshaping* for arbitrary sized integers only increases the number of clock cycles required to work with those variables.

As is a practical thing on FPGAs since we *represent values as a set of wires*, to use those types will only invalidate the experiments performed by introducing [memory misalignment](https://en.wikipedia.org/wiki/Data_structure_alignment).

Because of this, we'll only use primitive types that allow comparison without memory alignment problems.

## Index implementation - Memory
In order to ease memory transferal and to "encourage" caching, the index will be implemented on a single array without any reshaping involved. 

## What's the problem with this implementation?
As you can see, it's tweaked for direct memory address. This is probably not what I actually want, because I do need a way to access memory, but to generate some obscure code is not what I want. Still, it helped me to devise the caveats of this approach.

Given this situation, the next implementation will be organised as follows:
* A wapper implementation
* An improved copy of current lib compilant with some standard
* Probably some macros
# My First App

This repository contains my "first" app. It was a program for my TI-83+ graphing calculator that would essentially do my trigonometry homework for me.

I've preserved it here as a historical curiosity.

## Contents

- `TRIANGLE.8xp`: The original TI-BASIC source file I wrote on my calculator
- `Triangle.txt`: The text equivalent of `TRIANGLE.8xp`
- `main.c`: My translation of `Triangle.txt` to make it run on a computer
- `tibasic.h`: a bunch of macros and functions to mimic TI-BASIC from C
- `metamacros.h`: some support macros to make some TI-BASIC functions simpler
- `README.md`: see README.md

## Compiling

```
% git clone git@github.com:davedelong/triangle.git
% cd triangle
% gcc main.c -o triangle
% ./triangle
```

## Acknowledgements

"metamacros.h" comes from https://github.com/jspahrsummers/libextobjc
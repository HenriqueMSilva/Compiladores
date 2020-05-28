#!/bin/sh

lex jucompiler.l
yacc -y -d -t -v --debug jucompiler.y
clang-3.9 -o jucompiler *.c

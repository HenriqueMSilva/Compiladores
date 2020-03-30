#!/bin/sh

lex jucompiler.l
yacc -y -d -t -v --debug jucompiler.y
cc -o jucompiler *.c

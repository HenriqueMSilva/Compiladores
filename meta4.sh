#!/bin/sh

lex jucompiler.l
yacc -y -d -t -v --debug jucompiler.y
clang-3.9 -o jucompiler *.c

./jucompiler < testes/experimento.java > testes/experimento.ll
lli-3.9 testes/experimento.ll 1 2 3 4 5

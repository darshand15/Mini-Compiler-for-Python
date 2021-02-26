yacc -d -t --verbose test1_y.y
lex test1_l.l
g++ -std=c++11 lex.yy.c y.tab.c test1.cpp -ll -ly -w
./a.out < ../Test/py_test2.py 
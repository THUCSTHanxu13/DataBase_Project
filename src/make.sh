bison -d yacc.y 
flex lex.l
g++ -c yacc.tab.c -g  -std=c++11
g++ -c lex.yy.c -g  -std=c++11
g++ *.o -o main -O3 -march=native -g -std=c++11
rm *.o
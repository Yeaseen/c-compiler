echo "<--------1------->"
bison -d -y -v parser.y
echo "<--------2------->"
g++ -std=c++11 -w -c -o y.o y.tab.c
echo "<--------3------->"
flex scanner.l
echo "<--------4------->"
g++ -std=c++11 -fpermissive -w -c -o l.o lex.yy.c
echo "<--------5------->"
g++ -std=c++11 -o a.out y.o l.o -lfl -ly
echo "<--------6------->"
./a.out input.txt

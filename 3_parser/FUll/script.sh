echo "<--------1------->"
bison -d -y -v parser.y
echo "<--------2------->"
g++ -w -c -o y.o y.tab.c
echo "<--------3------->"
flex scanner.l
echo "<--------4------->"
g++ -fpermissive -w -c -o l.o lex.yy.c
echo "<--------5------->"
g++ -o a.out y.o l.o -lfl -ly
echo "<--------6------->"
./a.out input.c

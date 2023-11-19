 
#! /bin/sh 
a=0 
b=1 
echo $a 
echo $b 
for((i=0; i<10; i++)) 
do 
c=‘expr $a + $b‘ 
echo $c 
a=$b 
b=$c 
done 
 
//OUTPUT 
 
0 
1 
1 
2 
3 
5 
8 
13 
21 
34 
55 
89
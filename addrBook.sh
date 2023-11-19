# 
# Welcome to GDB Online.
# GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
# C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
# Code, Compile, Run and Debug online from anywhere in world.
# 
# 
echo "Hello World";


touch emprecord.txt

while true;
do
echo "1 View all record"
echo "2 Insert a record"
echo "3 delete a record"
echo "4 Modify a record"
echo "5 search a record"
echo "6 Exit"

echo "Enter your choice"
read choice
 
case $choice in
 
  1) 
    cat emprecord.txt
    ;;
  2) 
    echo -e "enter empid,ename,mbo,city"
    read empid ename mbo city
    echo -e "\n $empid\t$ename\t$mbo\t$city">>emprecord.txt
    ;;
    
  3) 
    echo "which record you want to delete"
    read dr
    sed -i "/$dr/d" emprecord.txt
    ;;
   
  4) 
    echo -e "enter record to modify"
    read rec
    echo -e "enter new record"
    read nrec
    sed -i "s/$rec/$nrec/" emprecord.txt
    ;;
   
   5)
    echo -e "Enter search keyword"
    read keyword
    grep -i "$keyword" emprecord.txt
    ;;
   
  6)
    echo "Exited"
    exit
    ;;
esac
done

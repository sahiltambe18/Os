
touch emprecord.txt

while true;
do
echo "1 View all record"
echo "2 Insert a record"
echo "3 delete a record"
echo "4 Modify a record"
echo "5 Exit"

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
    echo "Exited"
    exit
    ;;
esac
done

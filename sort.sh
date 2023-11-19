echo "Sorting Array" 
echo "Enter the length of Array: " 
read len 
arr=() 
echo "Enter the elements in Array:" 
for ((i=0;i<len;i++)) 
do 
read arr[i] 
done 
echo -e "The Array is: ${arr[@]}" 
for((i=0;i<len;i++)) 
do 
for((j=0;j<len;j++)) 
do 
if [[ ${arr[j]} > ${arr[j+1]} ]] 
then 
temp=${arr[j]} 
arr[j]=${arr[j+1]} 
arr[j+1]=$temp 
fi 
done 
done 
echo -e "The Sorted Array: ${arr[@]}"



Sorting Array
Enter the length of Array: 
5
Enter the elements in Array:
6
8
7
9
4
The Array is: 6 8 7 9 4
The Sorted Array:  4 6 7 8 9
!/bin/sh 
echo "Enter the String" 
read String 
echo $String 
 
len=${#String} 
 
echo $len 
 
for((i=$len; i>0;i--)) 
do 
char=‘echo $String | cut -c $i‘ 
String2=$String2$char 
done 
 
if [ $String = $String2 ] 
then 
echo "palindrome" 
else 
echo -e "\n not palindrome" 
fi 
 
//OUTPUT 
 
sahil@sahil-VirtualBox:~$ bash Palindrome.sh 
Enter the String 
naman 
naman 
5 
palindrome 
sahil@sahil-VirtualBox:~$ bash Palindrome.sh 
Enter the String 
sahil 
sahil 
7 
 
not palindrome
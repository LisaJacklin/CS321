echo "Read file line by line Method1"
cat abcd.txt | while read line; do
  echo $line
done

echo ""
echo "Read file line by line Method2"
while IFS= read -r line
do
  echo "$line"
done < "abcd.txt"

echo ""
echo "Read file using awk"
awk '{print}' abcd.txt #Read the entire file
awk '{print $1,$4}' abcd.txt #Read column 1 and 4 of each line
awk '{print NR,$0}' abcd.txt #print each row with line number (added by NR)
awk 'NR==3, NR==6 {print NR,$0}' abcd.txt 
#More about awk: https://www.geeksforgeeks.org/awk-command-unixlinux-examples/

echo ""
echo "replace with sed"
sed 's/Linux/Unix/' abcd.txt

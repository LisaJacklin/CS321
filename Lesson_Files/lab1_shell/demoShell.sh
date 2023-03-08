#!/bin/bash
# set x,y and z to an integer data type
x=10 #Automatically figure out the datatype (dynamic typing)
declare -i y=30 #Or you can explicitly specify the type
echo "x = $x" #This is how you print it

str="abcd" #Store a string variable
echo "str = $str" #print it

#reading data from the user
read -p 'Enter a : ' a
read -p 'Enter b : ' b
  
add=$((a + b))
echo Addition of a and b are $add

sub=$((a - b))
echo Subtraction of a and b are $sub
  
mul=$((a * b))
echo Multiplication of a and b are $mul
  
div=$((a / b))
echo division of a and b are $div
  
mod=$((a % b))
echo Modulus of a and b are $mod
  
((++a))
echo Increment operator when applied on "a" results into a = $a
  
((--b))
echo Decrement operator when applied on "b" results into b = $b



#Relational Operators
#reading data from the user
read -p 'Enter a : ' a
read -p 'Enter b : ' b

if(( $a==$b ))
then
    echo a is equal to b.
else
    echo a is not equal to b.
fi

if(( $a!=$b ))
then
    echo a is not equal to b.
else
    echo a is equal to b.
fi

if(( $a<$b ))
then
    echo a is less than b.
else
    echo a is not less than b.
fi

if(( $a<=$b ))
then
    echo a is less than or equal to b.
else
    echo a is not less than or equal to b.
fi

if(( $a>$b ))
then
    echo a is greater than b.
else
    echo a is not greater than b.
fi

if(( $a>=$b ))
then
    echo a is greater than or equal to b.
else
    echo a is not greater than or equal to b.
fi



#Logical Operators
#reading data from the user
read -p 'Enter a : ' a
read -p 'Enter b : ' b

if(($a == "true" & $b == "true" ))
then
    echo Both are true.
else
    echo Both are not true.
fi

if(($a == "true" || $b == "true" ))
then
    echo Atleast one of them is true.
else
    echo None of them is true.
fi

if(( ! $a == "true"  ))
then
    echo "a" was initially false.
else
     echo "a" was initially true.
fi

#Loop
c=1
while [ $c -le 5 ] #Another way of writing -le
do
  echo "Welcone $c times"
  (( c++ ))
done

#Array
NAME[0]="Alice"
NAME[1]="Bob"
NAME[2]="Charles"
NAME[3]="Daisy"
NAME[4]="Eric"
echo "${NAME[1]}"

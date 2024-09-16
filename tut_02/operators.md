## OPERATORS
### Arithmetic
---
> Returns the resulting value based on which arithmetic operator is used
```
+  (a + b): adding two numerical values
-  (a - b): minus two numerical values
*  (a * b): times two numerical values
/  (a / b): divides two numerical values
%  (a % b): divides two numerical values, returns remainder
```

### Logical
---
> Returns either 1 (TRUE) or 0 (FALSE) by evaluating a and b
```
||  (a OR b):  evaluates if either are true, the statement is true, otherwise false
&&  (a AND b): evaluates only if both are true, the statement is true, otherwise false
!   (NOT a):   evaluates negates the boolean, changing false to true, and vice versa
```

### Comparison
---
> Returns either 1 (TRUE) or 0 (FALSE) by comparing a and b
```
>   (a > b):  checks if a is strictly greater than b
>=  (a >= b): checks if a is greater or equal to b
<   (a < b):  checks if a is strictly less than b
<=  (a <= b): checks if a is less or equal to b
!=  (a != b): checks if both are not matching in numerical values
==  (a == b): checks if both are matching in numerical values
```

### Other
---
> These operators are just arithmetic operators simplified with storing the returning
value in a <br>
(Allowing us to write less, especially for frequent code like incrementing by 1)
```
Example:
    a = a + 1; (Standard Way)
    a += 1;    (Simplified)
    a++;       (Simplified Further)
```
```
Increment and Decrement
++  (a++): when we add 1 to a
--  (a--): when we subtract 1 from a

Simplified arithmetic
+=  (a += b): adds two numerical values, storing result in a
-=  (a -= b): subtracts two numerical values, storing result in a
*=  (a *= b): multiply two numerical values, storing result in a
/=  (a /= b): divides two numerical values, storing result in a
```

### Bitwise
---
> These operators aren't covered in this course, AVOID using them
(COMP1521 will teach these)
```
^: XOR (Does not perform exponent calculations)
>>: Bitshift Right
<<: Bitshift Left 
&: Bitwise AND (Not the same as Logical AND)
|: Bitwise OR (Not the same as Logical OR)
```
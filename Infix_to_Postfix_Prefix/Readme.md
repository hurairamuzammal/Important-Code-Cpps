# Introduction
The code to convert all types of polish notations.  
This is code for "Infix to prefix and Infix to Prefix" and there evaluation. 
This Code uses Stack for conversion and Evaluation of the answer.

# How Code Works
1. First Menu Provides Basic interface to the user . The user choose for any of the available option.
2. If user choose for evaultion it takes input in string which is passed to both infix to Prefix and Infix to Prefix converesion function.  
### Infix to Postfix function

3. In Infix to Postfix function I made temp and outputstream string and  by one by one traversing every character in string I checked for input valdition by checking it whether it is an operator or operand (Number 0 to 9). For this I made my own isOperator Function. 
4. if it is operand append it in the string, else it is operator so check its precedence by comparing for this for this I made function named as checkPrecedence that will return me and interger value based on which i made assumption to push the new character on to stack.
5. If any "(" simply push in stack and if ")" is occured pop until "(" in the stack in found . if there is no "(" then it is error simply return.
6. This Process will repeat until the outer for loop that will execute to the length of input will break. At this stage stack may contain some of the operators So simply add them to the string and pop them until stack is empty.

So the result of this function will be a string that will be converted in Postfix.
### Rule for converting Infix to Postfix:
While converting infix to postfix if the precedence of top element is >= to new element then pop the element and append in out output stream but if the precedence is lower than simply push the new operand on to the top of the stack.


# Conclusing Statement
In this way Conversion Code works.

## Thank You

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(string dat) : data(dat), next(nullptr) {}
};

class Stack // created stack for operations
{
    Node *top;

public:
    Stack() : top(nullptr) {}
    ~Stack()
    {
        clear();
    }

    void push(string ch)
    {
        Node *newNode = new Node(ch);
        newNode->next = top;
        top = newNode;
    }

    string pop()
    {
        if (!isEmpty())
        {
            string temp = top->data;
            Node *tempNode = top;
            top = top->next;
            delete tempNode;
            return temp;
        }
        return " ";
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    string getTop()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        return " ";
    }

    // return an integer value on which furthre calculation is performed
    int checkPrecedence(string c)
    {
        if (c == "*" || c == "/" || c == "%")
            return 2;
        else if (c == "+" || c == "-")
            return 1;
        else
            return 0;
    }

    // using stack and pushing and poping operator on the base of there precedence conversion is perfomed
    string infixtoPostfix(string input)
    {
        string outputStream;
        string temp;
        int length = input.length();
        for (int i = 0; i < length; i++)
        {
            temp = input[i];
            if (!isOperator(temp) && !(temp >= "0" && temp <= "9") && temp != " " && temp != "(" && temp != ")")
            {
                // Error case: invalid input character
                cout << "Invalid input character: " << temp << ". Returning ";
                return " ";
            }
            if (temp >= "0" && temp <= "9")
            {
                outputStream += temp;
            }

            else if (isOperator(temp) && (temp != "(" || temp != ")"))
            {

                if (checkPrecedence(getTop()) >= checkPrecedence(temp))
                {
                    while (!isEmpty() && checkPrecedence(getTop()) >= checkPrecedence(temp) && getTop() != "(")
                    {
                        outputStream += ' ';
                        outputStream += getTop();
                        pop();
                    }
                }

                push(temp);
            }
            else if (temp == " ")
            {
                outputStream += temp;
            }
            else if (temp == "(")
            {
                push(temp);
            }
            else if (temp == ")")
            {
                while (!isEmpty() && getTop() != "(")
                {
                    outputStream += ' ';
                    outputStream += getTop();
                    pop();
                }
                if (!isEmpty() && getTop() == "(")
                    pop();
            }
        }
        // Pop any remaining operators from the stack
        while (!isEmpty())
        {
            outputStream += ' ';
            outputStream += getTop();
            pop();
        }
        return outputStream;
    }
    // using stack and pushing and poping operator on the base of there precedence conversion is perfomed
   string infixtoPrefix(string input)
   {
       string reverseinfix;
       string outputString;
       string temp;

       // Reverse the input string
       for (int i = input.length() - 1; i >= 0; i--)
       {
           reverseinfix += input[i];
       }

       for (int i = 0; i < reverseinfix.length(); i++)
       {
           temp = reverseinfix[i];
           if (!isOperator(temp) && !(temp >= "0" && temp <= "9") && temp != " " && temp != "(" && temp != ")")
           {
               // Error case: invalid input character
               cout << "Invalid input character: " << temp << ". Returning ";
               return " ";
           }

           if (temp >= "0" && temp <= "9")
           {
               outputString += temp;
           }
           else if (temp == " ")
           {
               outputString += temp;
           }
           else if (temp == ")")
           {
               push(temp);
           }
           else if (temp == "(")
           {
               while (!isEmpty() && getTop() != ")")
               {
                   outputString += " ";
                   outputString += getTop();
                   pop();
               }
               if (!isEmpty() && getTop() == ")")
                   pop();
           }
           else if (isOperator(temp))
           {
               if (checkPrecedence(getTop()) > checkPrecedence(temp))
               {
                   while (!isEmpty() && checkPrecedence(getTop()) > checkPrecedence(temp) && getTop() != "(")
                   {
                       outputString += " ";
                       outputString += getTop();
                       pop();
                   }
               }
               push(temp);
           }
       }

       while (!isEmpty())
       {
           outputString += " ";
           outputString += getTop();
           pop();
       }

       string result;
       for (int i = outputString.length() - 1; i >= 0; i--)
       {
           result += outputString[i];
       }

       return result;
   }

    bool isOperator(string ch)
    {
        return (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "%");
    }

//this function will perform operation on the base of operator and return result
    int performOperation(char op, int operand1, int operand2)
    {
        int result;
        if (op == '+')
        {
            result = operand1 + operand2;
        }
        else if (op == '-')
        {
            result = operand1 - operand2;
        }
        else if (op == '/')
        {
            if (operand2 == 0)
            {
                cout << "Operand 2 is Zero" << endl;
            }
            result = operand1 / operand2;
        }
        else if (op == '*')
        {
            result = operand1 * operand2;
        }
        else if (op == '%')
        {
            result = operand1 % operand2;
        }
        return result;
    }
    
/*this function will evaluate the postfix expression by using stack
some working it will perform is 
1. if it is operand then inner loop will concatinate it and push in stack
2. pop operand and push result*/

    string evaluatePostexpression(string ch)
    {
        int length = ch.length();
        char op;
        int operand2, operand1, operationResult;
        string temp, temp2;
        // loop that will traverse entire string one by one
        for (int i = 0; i < length; i++)
        {
            temp2 = ch[i]; // each char is assigned to empty string
            if (!isOperator(temp2) && ch[i] != ' ')
            {
                temp = "";
                while ((i < length) && (!isOperator(temp2)) && (ch[i] != ' '))
                {
                    temp += ch[i];
                    i++;
                }
                cout << "Number pushed in Stack is " << temp << endl;
                push(temp);
            }
            else if (isOperator(temp2))
            {
                operand2 = stoi(pop());
                operand1 = stoi(pop());
                cout << " -----------------------------------------------" << endl;
                cout << "Operand 1 is: " << operand1 << " Operand 2 is " << operand2 << endl;
                op = ch[i];
                cout << "Operation to be perfomed is " << op << endl;
                operationResult = performOperation(op, operand1, operand2);
                cout << "Result of operation " << operationResult << endl;
                string ResultinStack;
                ResultinStack = to_string(operationResult);
                push(to_string(operationResult));
            }
        }

        string finalResult = pop();
        return finalResult;
    }
// this function will evaluate the prefix expression by using stack
    string evaluatePreexpression(string ch)
    {
        string temp;
        cout << "String to be evaluated is " << ch << endl;
        char op;
        for (int i = ch.length() - 1; i >= 0; i--)  // this loop will help to evaluate  by index 
        {
            temp = string(1, ch[i]);

            // if it is operand then inner loop will concatinate it and push in stack 
            if (!isOperator(temp) && temp != " " && temp != "(" && temp != ")")
            {
                string operand = "";
                while (i >= 0 && !isOperator(temp) && temp != " " && temp != "(" && temp != ")")
                {
                    operand = temp + operand;
                    i--;
                    if (i >= 0)
                        temp = string(1, ch[i]);
                }

                push(operand);
            }
            // pop operand and push result
            else if (isOperator(temp))
            {
                op = temp[0];

                int operand1 = stoi(pop());
                int operand2 = stoi(pop());
                cout << "--------------------------------------------------------" << endl;
                cout << "Operand 1 : " << operand1 << endl;
                cout << "Operand 2 : " << operand2 << endl;
                cout << "Operation to be performed is : " << op << endl;

                int resultI = performOperation(op, operand1, operand2);
                cout << "Result of the operation is " << resultI << endl;
                cout << "--------------------------------------------------------" << endl;
                push(to_string(resultI));
            }
        }

        string finalResult = pop();
        return finalResult;
    }
};

int main()
{
    string input, Postfix, Prefix;
    string choice;
    Stack stack1;
    // loop till choice is 4
    do
    {
        cout << "Infix to postfix converter"
             << endl;

        cout << "1. For Conversion" << endl;
        cout << "2. Evaluate Postfix Expresion" << endl;
        cout << "3. Evaluate Prefix Expression" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();
        if (choice == "1")
        {

            cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the infix expression: ";
            getline(cin, input);
            Postfix = stack1.infixtoPostfix(input);
            cout << "Postfix notation is: " << Postfix << endl;
            Prefix = stack1.infixtoPrefix(input);
            cout << "Prefix notation is: " << Prefix << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else if (choice == "2")
        {
            if (!Prefix.empty())
            {
                string answer = stack1.evaluatePostexpression(Postfix);

                cout << "Final Result of Postfix Evaluation is " << answer << endl
                     << endl;
            }
            else
                cout << "Postfix String Empty!";
        }
        else if (choice == "3")
        {
            if (!Postfix.empty())
            {
                string answer = stack1.evaluatePreexpression(Prefix);

                cout << "Final Result of Prefix Evaluation is " << answer << endl
                     << endl;
            }
            else
                cout << "Prefix String Empty!";
        }
        else if (choice == "4")
        {
            return 0;
        }
        else
            cout << "Error Wrong input" << endl;

    } while (choice != "4");

    return 0;
}

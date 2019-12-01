/*
Name: Gregory Litman-Navarro
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program: Tester file for components of complex calculator.
Last updated:
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Complex.h"
#include "DoublyLinkedList.h"
#include "StackDoublyLinkedList.h"
using namespace std;

Complex parseComplexNumber(string expression);
int getPrecedence(char op);
bool isComplexComponent(char ch);
int getNumberLength(int startIndex, string expression);
bool isOperator(char ch);
bool isException(int start, string expression);
void doAlgebra(StackDoublyLinkedList<Complex>* numStack, StackDoublyLinkedList<char>* opStack);
string evaluate(string complexExpression);

/**
 *
 * @return 0 for successful exit
 */
int main() {
    // START MAIN
//    // open input file 'expression.txt'
//    fstream complexExpressions;
//    complexExpressions.open("expression.txt");
//    // open file 'result.txt' to write calculator output to
//    ofstream output;
//    output.open("result.txt");
//    string currentExpression;
//
//    while(getline(complexExpressions, currentExpression))
//    {
//        output << evaluate(currentExpression) << endl;
//    }
//    complexExpressions.close();
    // END MAIN

    //FIXME START TESTER


    //FIXME END TESTER

    return 0;
}

/**
 *
 * @param ch
 * @return
 */
bool isOperator(char ch) {
    bool isOp = false;
    switch (ch) {
        case '/':
        case '*':
        case '+':
        case '-':
            isOp = true;
            break;
        default:
            isOp = false;
    }
    return isOp;
}

/**
 *
 * @param start
 * @param expression
 * @return
 */
bool isException(int start, string expression) {
    bool exception = false;

    if (start == 0 && expression[start] == '-')
        exception == true;
    else if (start > 0)
    {
        if (expression.substr(start-1, 2) == ")-") //FIXME this is wrong
            exception = true;
        else if (expression.substr(start-1, 2) == "(-")
            exception = true;
        else if (expression.substr(start-1, 2) == "/-")
            exception = true;
        else if (expression.substr(start-1, 2) == "*-")
            exception = true;
    }
    return exception;
}

/**
 *
 * @param expression
 * @return
 */
Complex parseComplexNumber(string expression) {
    //get length of exp
    int length = expression.length();
    int index = 0;
    int real = 0; // the real part of value
    int imag = 0; // the imaginary part of value

    bool inDigit = false;
    bool isNegative = false;
    string digit = "";

    //while still more characters to process, continue iterating through string
    while (index < length) {
        if (isdigit(expression[index]))
        {
            inDigit = true;
            digit += expression[index];
        }
        else if (expression[index] == 'i')
        {
            if (inDigit == true && !isNegative)
                imag += stoi(digit);
            else if (inDigit == true && isNegative)
                imag -= stoi(digit);
            else if (inDigit == false && !isNegative)
                imag += 1;
            else if (inDigit == false && isNegative)
                imag -= 1;
            digit = "";
            inDigit = false;
            isNegative = false;
        }
        else if (expression[index] == '+')
        {
            if (inDigit == true)
            {
                if (inDigit == true && !isNegative)
                    real += stoi(digit);
                else if (inDigit == true && isNegative)
                    real -= stoi(digit);
                digit = "";
                inDigit = false;
            }
            isNegative = false;
        }
        else if (expression[index] == '-')
        {
            if (inDigit == true) {
                if (!isNegative)
                    real += stoi(digit);
                else
                    real -= stoi(digit);
                digit = "";
                inDigit = false;
            }
            isNegative = true;
        }
        index++;
    }
    return Complex(real, imag, 1);
}


/**
 *
 * @param op
 * @return
 */
int getPrecedence(char op) {
    int value = 0;
    if (op == '%')
        value = 3;
    else if (op == '+' || op == '-')
        value = 2;
    else if (op == '*' || op == '/')
        value = 1;
    return value;
}

/**
 *
 * @param ch
 * @return
 */
bool isComplexComponent(char ch) {
    bool component = false;

    if (isdigit(ch) || ch == '+' || ch == '-' || ch == 'i')
        component = true;

    return component;
}

/**
 *
 * @param startIndex
 * @param expression
 * @return
 */
int getNumberLength(int startIndex, string expression) {
    int counter = 0;

    while (isComplexComponent(expression[startIndex+counter])) {
        counter++;
    }

    return counter;
}

/**
 * THIS METHOD DOES NOT CHECK FOR VALID CONDITIONS BEWARE.
 * @param numStack
 * @param opStack
 * @return
 */
void doAlgebra(StackDoublyLinkedList<Complex>* numStack, StackDoublyLinkedList<char>* opStack) {
    // grab to oprands and an operator
    Complex operandOne = numStack->getTop();
    numStack->popBack();
    Complex operandTwo = numStack->getTop();
    numStack->popBack();
    Complex solution(1, 1, 1);
    // push their yield back onto the operand stack
    switch (opStack->getTop())
    {
        case '*':
            solution = operandOne * operandTwo;
            break;
        case '/':
            solution = operandTwo / operandOne; // keep eye out for fixme error
            break;
        case '+':
            solution = operandOne + operandTwo;
            break;
        case '-':
            solution = operandTwo - operandOne;
            break;
    }
    opStack->popBack();
    numStack->addBack(solution);
}


/**
 *
 */
string evaluate(string complexExpression) {
    bool validExpression = true; // todo in case we have a problem, we can simply return an error string
    string output = "";
    int index = 0;
    int expressionLength = complexExpression.length(); //fixme keeps?

    StackDoublyLinkedList<Complex> numberStack;
    StackDoublyLinkedList<char> operatorStack;

    while (index < expressionLength) {
        // beginning of term: digit, ')-', or index == 0 and '-'
        if (isdigit(complexExpression[index]) || isException(index, complexExpression))
        {
            // getTermLength
            int termLength = getNumberLength(index, complexExpression);
            // get operand
            Complex newOperand = parseComplexNumber(complexExpression.substr(index, termLength));
            // push operand onto operand stack
            numberStack.addBack(newOperand);
            // update index
            index += termLength; //todo/fixme is correct? maybe -1
        }
        else if (complexExpression[index] == '(')
        {
            // push onto opstack
            operatorStack.addBack(complexExpression[index]);
            index++;
        }
        else if (complexExpression[index] == '%')
        {
            // remove operand from stack
            Complex conjugate = numberStack.getTop();
            // find its conjugate
            conjugate.im = conjugate.im * -1;
            // return conjugate to the stack
            numberStack.popBack();
            numberStack.addBack(conjugate);
            index++;
        }
        else if (isOperator(complexExpression[index]))
        {
            // push onto operator stack
            operatorStack.addBack(complexExpression[index]);
            index++;
        }
        else if (complexExpression[index] == ')')
        {
            // while top of op stack isnt '(' /
            while(operatorStack.getTop() != '(' && operatorStack.getSize() > 0 && numberStack.getSize() >= 2)
            {
                // do algebra // TODO maybe check if valid conditions or error here
                doAlgebra(&numberStack, &operatorStack);
            }

            if (operatorStack.getTop() == '(')
                operatorStack.popBack();
            else //an error has occured
                validExpression = false;

            index++;
        }
        else if (complexExpression[index] == '=') // TODO maybe adjust to take spaces as well
        {
            index++;
        }

    } // end while loop

    // while operators are still on stack, continue to evaluate
    while (operatorStack.getSize() > 0 && numberStack.getSize() >= 2)
    {
        doAlgebra(&numberStack, &operatorStack);
    }

    output = numberStack.getTop().toString();
    return output;
} // end evaluate function

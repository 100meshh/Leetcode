class Solution {
    void evaluate(stack<char>& optr,stack<char>& operand){
        char op=optr.top(); //get the operator at the top
        optr.pop(); //remove the operator from the stack
        bool ans;


        if(op=='|'){
            ans=false; //for or initial value shuold be false
            while(operand.top()!='(') {
                ans|=(operand.top()=='t');
                operand.pop();
            }
            operand.pop(); //pop the '('
        }


        else if(op=='&'){
            ans=true; //for & initial value shuold be true
            while(operand.top()!='(') {
                ans&=(operand.top()=='t');
                operand.pop();
            }
            operand.pop(); //pop the '('
        }


        else if(op=='!'){
            ans=(operand.top()=='t');
           ans=!ans; //negate the value
           operand.pop(); //pop the value
            operand.pop(); //pop the '('
        }

        
        if(ans) operand.push('t'); //push true result back to operand stack
        else operand.push('f'); //push false result to operand stack
    }
public:
    bool parseBoolExpr(string expression) {

        stack<char>optr,operand;
        int index=0;
        while(expression[index])
        {
            if(expression[index]=='!'||expression[index]=='&'||expression[index]=='|'){
                optr.push(expression[index]);  //push operators
            }
            else if(expression[index]=='t'||expression[index]=='f'){
                operand.push(expression[index]);  //push operands
            }
            else if(expression[index]=='(') {
                operand.push(expression[index]);   //push opening paranthesis
            }
            else if(expression[index]==')') {
                evaluate(optr,operand);   //evalute when closing paranthesis is
            }
            index++;
        }
        return operand.top()=='t'; //final result check
        
    }
};
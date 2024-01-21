#include "exp.h"
#include <string>
#include "error.h"
#include "strlib.h"
using namespace std;



/*
 * Implementation notes: Expression
 * The expression class itself implements only those methods that
 * are not designated as pure virtual.
*/
Expression::Expression(){
    /* Empty */
}

Expression::~Expression(){
    /* Empty */
}

int Expression::getConstantValue(){
    error("getConstantValue: Illegal expression type");
    return 0;
}

std::string Expression::getIdentifierName(){
    error("getIdentifierName: Illegal expression type");
    return "";
}

std::string Expression::getOperator(){
    error("getOperator: Illegal expression type");
    return "";
}

Expression *Expression::getLHS(){
    error("getLHS: Illegal expression type");
    return NULL;
}

Expression *Expression::getRHS(){
    error("getRHS: Illegal expression type");
    return NULL;
}

/*
 * Implementation notes: ConstantExp
 * The ConstantExp subclass represents an integer constant. The eval
 * method simply returns that value.
*/
ConstantExp::ConstantExp(int value){
    this->value = value;
}

int ConstantExp::eval(EvaluationContext &context){
    return value;
}

string ConstantExp::toString(){
    return integerToString(value);
}

ExpressionType ConstantExp::getType(){
    return CONSTANT;
}

int ConstantExp::getConstantValue(){
    return value;
}

/*
 * Implemnetation notes: IdentifierExp
 * The IdentifierExp subclass represents a variable name. The
 * implementation of eval looks up that name in the evalutaion coontext.
*/
IdentifierExp::IdentifierExp(string name){
    this->name = name;
}

int IdentifierExp::eval(EvaluationContext &context){
    if(!context.isDefined(name)) error(name + " is undefined");
    return context.getValue(name);
}

string IdentifierExp::toString(){
    return name;
}

ExpressionType IdentifierExp::getType(){
    return IDENTIFIER;
}

string IdentifierExp::getIdentifierName(){
    return name;
}

/*
 * Implementation notes: CompoundExp
 * The implementation of eval for CompoundExp evaluates the left and right
 * subexpressions recursively and then applies the operator. Assignment is
 * treated as a special case because it dose not evalute the left operand.
 */
CompoundExp::CompoundExp(string op, Expression *lhs, Expression *rhs){
    this->op = op;
    this->lhs = lhs;
    this->rhs = rhs;
}

CompoundExp::~CompoundExp(){
    delete lhs;
    delete rhs;
}

CompoundExp::eval(EvaluationContext &context){
    int right = rhs->eval(context);
    if (op == "="){
        context.setValue(lhs->getIdentifierName(),right);
        return right;
    }
    int left = lhs->eval(context);
    if(op == "+") return left + right;
    if(op == "-") return left - right;
    if(op == "*") return left * right;
    if(op == "/"){
        if(right == 0) error("Division by 0");
        return left / right;
    }
    error("Illegal operator in exptression");
    return 0;
}

string CompoundExp::toString(){
    return '(' + lhs->toString() + ' ' + op + ' ' + rhs->toString() + ')';
}

ExpressionType CompoundExp::getType(){
    return COMPOUND;
}

string CompoundExp::getOp(){
    return op;
}

Expression *CompoundExp::getLHS(){
    return lhs;
}

Expression *CompoundExp::getRHS(){
    return rhs;
}

/*
 * Implementation notes: EvaluationContext
 * The methods in the EvaluationContext class simply call the appropriate
 * method on the map used to represent the symbol table.
 */
void EvaluationContext::setValue(string var, int value){
    symbolTable.put(var, value);
}

int EvaluationContext::getValue(string var){
    return symbolTable.get(var);
}

bool EvaluationContext::isDefined(string var){
    return symbolTable.containsKey(var);
}
























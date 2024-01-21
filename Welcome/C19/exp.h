#ifndef EXP_H
#define EXP_H
#include <string>
#include <string>
#include "map.h"
#include "tokenscanner.h"

/* Forward reference */
class EvaluationContext;

enum ExpressionType{ CONSTANT, IDENTIFIER, COMPOUND };

/*
 * Class: Expression
 * This class is used to representa node in an expression tree.
 * Expression itself is an abstract class, which means that there are
 * never any objects whose primary type is Expression. All objects are
 * instead created using one of the three concrete subclasses:
 * 1. ConstantExp   -- an integer constant
 * 2. IdentifierExp -- a string representing an identifier
 * 3. CompoundExp   -- two expressions combined by an operator
*/
class Expression
{
public:
    /*
     * Constructor: Expression
     * Specifies the constructor for the base Expression class. Each subclass
     * constructor will define its own constructor.
    */
    Expression();

    /*
     * Constructor: ~Expression
     * Destruction, deallocates.
    */
    virtual ~Expression();

    /*
     * Method: eval
     * Usage: int value = exp->eval(context);
     */
    virtual int eval(EvaluationContext & context) = 0;

    /*
     * Method: toString
     * Usage: string str = exp->toString();
     */
    virtual std::string toString() = 0;

    /*
     * Method: type
     * Usage: string str = exp->getType();
     */
    virtual ExpressionType getType() = 0;

    /*
    *Getter methods for convenience
    *The following methods get the fields of the appropriate subclass. Calling
    *these methods on an object of the wrong subclass generates an error.
    */
    virtual int getConstantValue();
    virtual std::string getIdentifierName();
    virtual std::string getOperator();
    virtual Expression *getLHS();
    virtual Expression *getRHS();

};

/*
 * Subclass:ConstantExp
 * This subclass represents an integer constant.
*/
class ConstantExp : public Expression{
public:
    /*
     * Constructor: ConstantExp
     * Usage: Expression *exp = new ConstantExp(value);
     * The constructor creates a new integer constant expression.
     */
    ConstantExp(int value);

    /* Prototypes for the virtual methods overriden by thsi class */
    virtual int eval(EvaluationContext &context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual int getConstantValue();
private:
    int value;
};

class IdentifierExp : public Expression{
public:
    IdentifierExp(std::string name);

    /* Prototypes for the virtual methods overriden by thsi class */
    virtual int eval(EvaluationContext &context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual std::string getIdentifierName();
private:
    std::string name;
};

/*
 * Subclass: CompoundExp
 * Thsi subclass represents a compound expression consisting of
 * two subexpressions joined  by an operator.
*/
class CompoundExp : public Expression{
public:
    /*
     * Constructor: CompoundExp
     * Usage: Expression *exp = new CompoundExp(op, lhs, rhs);
     * The constructor initializes a new compoud expression composed of
     * the operator (op) and the left and right subexpresson(lhs and rhs).
     */
    CompoundExp(std::string op, Expression *lhs, Expression *rhs);

    /* Prototypes for the virtual methods overridden by this class */

    virtual ~CompoundExp();
    virtual int eval(EvaluationContext &context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual std::string getOp();
    virtual Expression *getLHS();
    virtual Expression *getRHS();

private:
    std::string op;
    Expression *lhs, *rhs;
};

/*
 * Class: EvaluationContext
 * This class encapsulates the information that the evaluator needs
 * to know in order to evaluate an expression.
 */
class EvaluationContext{
public:
    /*
     * Method: setValue
     * Usage: context.setValue(avr, value);
     */
    void setValue(std::string var, int value);

    /*
     * Method: getValue
     * Usage: int value = context.getValue(var);
     * Returns the value associated with the specified variable.
    */
    int getValue(std::string var);

    /*
     * Method: isDefined
     * Usage: if(ontext.isDefined(var));
     *
    */
    bool isDefined(std::string var);
private:
    Map<std::string, int> symbolTable;
};




#endif // EXP_H

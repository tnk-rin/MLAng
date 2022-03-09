#include "./interpreter.h"

void Interpreter::visit(struct Nodes* node) {

}

Integer Interpreter::visitIntTree(struct Nodes* node) {
	if (node == NULL)
		return NULL;

	switch (node->mode) {
		case 0:
			return visitNum(node);

		case 1:
			return visitBinInt(node);

		case 2:
			return visitIntTree(node->right);

	}
	return NULL;
}

Integer Interpreter::visitNum(struct Nodes* node) {
	double val = atof(node->token.value.c_str());
	return Integer(val);
}

Integer Interpreter::visitBinInt(struct Nodes* node) {
	std::string opType = node->opToken.value;
	Integer result = Integer(0);
	Integer left = visitIntTree(node->left);
	Integer right = visitIntTree(node->right);
	if (opType == TOKEN_PLUS) {
		result = left.add(right);
	} else if (opType == TOKEN_MINUS) {
		result = left.sub(right);
	} else if (opType == TOKEN_MUL) {
		result = left.mul(right);
	} else if (opType == TOKEN_DIV) {
		result = left.div(right);
	} else if (opType == TOKEN_EXP) {
		result = left.pow(right);
	}
	return result;
}

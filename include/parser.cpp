#include "./parser.h"

Parser::Parser(std::vector<Token> pTokens) {
	tokens = pTokens;
	token_index = -1;
	advance();
}

struct Nodes* Parser::parse() {
	struct Nodes* result = expression();
	return result;
}

Token Parser::advance() {
	++token_index;
	if(token_index < tokens.size())
		current_token = tokens[token_index];
	return current_token;
}

struct Nodes* Parser::factor() {
	Token tok = current_token;
	if(tok.type == TOKEN_PLUS || tok.type == TOKEN_MINUS) {
		advance();
		struct Nodes* _FACTOR = factor();
		struct Nodes* toReturn = new Nodes();
		toReturn->mode = 2;
		toReturn->node = _FACTOR;
		toReturn->token = tok;
		return toReturn;
	} else if(tok.type == TOKEN_INT) {
		advance();
		struct Nodes* toReturn = new Nodes();
		toReturn->mode = 0;
		toReturn->token = tok;
		return toReturn;
	} else if(tok.type == TOKEN_LPAREN) {
		advance();
		struct Nodes* _EXPR = expression();
		if (current_token.type == TOKEN_RPAREN) {
			advance();
			return _EXPR;
		} else {
			InvalidSyntax error = InvalidSyntax("Missing ')'");
			struct Nodes* errorNode = new Nodes();
			errorNode->mode = -2;
			errorNode->token = current_token;
			errorNode->error = &error;
			return errorNode;
		}

	}
	return NULL;
}

struct Nodes* Parser::term() {
	return binaryOp(0, { TOKEN_MUL, TOKEN_DIV });
}

struct Nodes* Parser::expression() {
	return binaryOp(1, { TOKEN_PLUS, TOKEN_MINUS });
}

struct Nodes* Parser::binaryOp(uint8_t mode, std::vector<std::string> operators) {
	struct Nodes* left;
	left = (mode == 1) ? term() : factor();

	while (std::find(operators.begin(), operators.end(), current_token.value) != operators.end()) {
		Token op_token = current_token;
		advance();
		struct Nodes* right;
		right = (mode == 1) ? term() : factor();
		struct Nodes* newLeft = new Nodes();
		newLeft->left = left;
		newLeft->right = right;
		newLeft->opToken = op_token;
		newLeft->mode = 1;
		left = newLeft;
	}
	return left;
}

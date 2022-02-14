#include "./parser.h"

Parser::Parser(std::vector<Token> pTokens) {
	tokens = pTokens;
	token_index = -1;
	advance();
}

Token Parser::advance() {
	token_index += 1;
	if(token_index < tokens.size())
		current_token = tokens[token_index];
	return current_token;
}

Node Parser::factor() {
	Token tok = current_token;	
	if (tok.type == TOKEN_INT) {
		advance();
		return Node(tok);
	}
	return Node(Token("NULL", "NULL"));
}

Node Parser::term() {
	return binaryOp(0, { TOKEN_MUL, TOKEN_DIV });
}

Node Parser::expression() {
	return binaryOp(1, { TOKEN_PLUS, TOKEN_MINUS });
}

Node Parser::binaryOp(uint8_t mode, std::vector<std::string> operators) {
	Node left = mode ? term() : factor();
	uint8_t inOps = 0;
	
	for(std::string s : operators)
		s == current_token.type ? ++inOps : inOps;
	
	while (inOps > 0) {
		inOps = 0;
		Token op_token = current_token;
		Node right = mode ? term() : factor();
		left = Node(left, op_token, right);
		for(std::string s : operators)
			s == current_token.type ? ++inOps : inOps;
	}

}



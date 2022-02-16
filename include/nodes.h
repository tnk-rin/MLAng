#pragma once
#include <string>
#include "./token.h"

struct Nodes {
	int mode;
	Token token, opToken;
	struct Nodes* left;
	struct Nodes* right;
	
	Nodes() {
		mode = 0;
		left = NULL;
		right = NULL;
	}
};

class Node {
	public:
		Node(Token pToken) {
			token = pToken;
			mode = 0;
		}

		Node(Node* pLeft, Token opTok, Node* pRight) {
			left = pLeft;
			right = pRight;
			opToken = opTok;
			mode = 1;
		}

		Node(Token opTok, Node* pNode) {
			opToken = opTok;
			node = pNode;
			mode = 2;
		}

		std::string str () {
			std::string s;
			switch(mode) {
				case 0:
					s = token.str();
					break;

				case 1:
					s = left->str() + " : " + opToken.str() + " : " + right->str();
					break;

				case 2:
					s = "how";
					break;
			}
			return s;
		}
		
		// 0 = NumberNode, 1 = BinaryOp, 2 = UnaryOp
		uint8_t mode;
		Token token, opToken;
		Node *left, *right, *node;

};

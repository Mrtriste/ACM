#include <iostream>  
#include <fstream>  
#include <string>  
using namespace std；

struct TreeNode
{
	struct TreeNode* left；
	struct TreeNode* right；
	char  elem；
}；

//the subtree's inorder is start at *inorder,postorder starts at *postorder, both length is length
void BinaryTreeFromOrderings(char* inorder, char* postorder, int length)
{
	if (length == 0)
		return NULL;

	cout << *(postorder + length - 1) << endl;
	int rootIndex = 0;
	for (; rootIndex < length; rootIndex++)//a variation of the loop
		if (inorder[rootIndex] == *(postorder + length - 1))
			break;

	BinaryTreeFromOrderings(inorder, postorder, rootIndex);
	BinaryTreeFromOrderings(inorder + rootIndex + 1, postorder + rootIndex, length - (rootIndex + 1));

}

int main(int argc, char** argv)
{
	char* af = "AEFDHZMG";
	char* in = "ADEFGHMZ";
	BinaryTreeFromOrderings(in, af, 8);
	printf("\n");
	return 0;
}


//////////////////////////////////////////////////需要建立二叉树
TreeNode* BinaryTreeFromOrderings(char* inorder, char* postorder, int length)
{
	if (length == 0)
		return NULL;
	TreeNode* node = new TreeNode;//Noice that [new] should be written out.
	node->elem = *(postorder + length - 1);
	std::cout << node->elem << std::endl;
	int rootIndex = 0;
	for (; rootIndex < length; rootIndex++)//a variation of the loop
		if (inorder[rootIndex] == *(postorder + length - 1))
			break;

	node->left = BinaryTreeFromOrderings(inorder, postorder, rootIndex);
	node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, postorder + rootIndex, length - (rootIndex + 1));

	return node;
}

int main(int argc, char** argv)
{
	char* af = "AEFDHZMG";
	char* in = "ADEFGHMZ";
	TreeNode*root = BinaryTreeFromOrderings(in, af, 8);
	printf("");
	return 0;
}
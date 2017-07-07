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

//the subtree's inorder is start at *inorder,preorder starts at *preorder, both length is length
void BinaryTreeFromOrderings(char* inorder, char* preorder, int length)
{
	if (length == 0)
		return；
	char c = *preorder；  
	int rootIndex = 0；
	for (； rootIndex < length； rootIndex++)
		if (inorder[rootIndex] == *preorder)
			break;
	
	BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex)；//Left
	BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1))；//Right
	cout<<c;
	return;
}

int main(int argc, char* argv[])
{
	printf("Question: 已知前序、中序遍历，求后序遍历\n\n")；

	char* pr = "GDAFEMHZ"；//前序
	char* in = "ADEFGHMZ"；//中序


	cout << "前序是：" << pr << endl；
	cout << "中序是：" << in << endl；
	cout << "后序是："；

	BinaryTreeFromOrderings(in, pr, 8)；
	printf("\n\n")；
	return 0；
}


///////////////////////////////////////需要建立二叉树
TreeNode* BinaryTreeFromOrderings(char* inorder, char* preorder, int length)
{
	if (length == 0)
		return NULL；
	
	TreeNode* node = new TreeNode；//Noice that [new] should be written out.  
	node->elem = *preorder；
	int rootIndex = 0；
	for (； rootIndex < length； rootIndex++)//a variation of the loop  
		if (inorder[rootIndex] == *preorder)
			break；
	
	node->left = BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex)；
	node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1))；
	cout << node->elem <<endl；
	return node；
}

int main(int argc, char** argv){
	char* pr = "GDAFEMHZ"；
	char* in = "ADEFGHMZ"； 
	TreeNode*root = BinaryTreeFromOrderings(in, pr, 8)；
	printf("\n")； return 0；
}

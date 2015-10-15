#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};
Node *root;

void InsertNode(Node **aNode, int data){
	if (!(*aNode)){		// ������ ����� �������
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else{
		if (data < (*aNode)->value) InsertNode(&(*aNode)->left,data);
		else InsertNode(&(*aNode)->right, data);
	}
	return;}

void PrintNode(Node *aNode){
	if (aNode){
		PrintNode(aNode->left);
		cout<<aNode->value<<" ";
		PrintNode(aNode->right);
	}
	return;
}

void Del(Node **r, Node **q)// �������� ������� ��� ��������� �������
{	Node *s;
	if (!(*r)->right)
	{
		(*q)->value = (*r)->value;
		*q = *r;
		s = *r; *r = (*r)->left; delete s;
	}
	else  Del(&((*r)->right), q);
}

void Delete(Node **p, int data)
// ��������� ������� k �� �������� ������
// *p � �������� �� ����� ������
{
	Node *q;

	if (!p) cout<<"������� �� ������� ������ �� ��������!"<<endl;	// ����� �� ��������
	else
		if (data<(*p)->value) Delete(&((*p)->left), data);		// ����� ������ �� �������� � �����
		else
			if (data>(*p)->value) Delete(&((*p)->right), data); // ����� ������ �� �������� � �����
			else					// ����� ��������; ���������
			{	q = *p;
				if (!q->right) { *p = q->left; delete q; }		//���� � ����� � ����� ���� �������
				else
					if (!q->left) { *p = q->right; delete q; } //���� � ����� � ����� ������ �������
					else  Del(&(q->left), &q);					//���� � ����� � ������ �������
			}
	return;}

int main()
{

    InsertNode(&root,5);
    InsertNode(&root,7);
    InsertNode(&root,3);

    PrintNode(root);

    Delete(&root,3);
    cout<<endl;
    PrintNode(root);
    return 0;
}

#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};
Node *root;

void InsertNode(Node **aNode, int data){
	if (!(*aNode)){		// додаємо новий елемент
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

void Del(Node **r, Node **q)// допоміжна функція для видалення вершини
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
// видалення вершини k із бінарного дерева
// *p – вказівник на корінь дерева
{
	Node *q;

	if (!p) cout<<"Вершина із заданим ключем не знайдена!"<<endl;	// вузол не знайдено
	else
		if (data<(*p)->value) Delete(&((*p)->left), data);		// вузол менший за значення в корені
		else
			if (data>(*p)->value) Delete(&((*p)->right), data); // вузол більший за значення в корені
			else					// вузол знайдено; видаляємо
			{	q = *p;
				if (!q->right) { *p = q->left; delete q; }		//якщо у вузла є тільки лівий нащадок
				else
					if (!q->left) { *p = q->right; delete q; } //якщо у вузла є тільки правий нащадок
					else  Del(&(q->left), &q);					//якщо у вузла є обидва нащадки
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

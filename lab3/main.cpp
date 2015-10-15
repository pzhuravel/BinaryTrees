#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};
Node *root;

void InsertNode(Node **aNode, int data){
	if (!(*aNode)){		// äîäàºìî íîâèé åëåìåíò
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

void Del(Node **r, Node **q)// äîïîì³æíà ôóíêö³ÿ äëÿ âèäàëåííÿ âåðøèíè
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
// âèäàëåííÿ âåðøèíè k ³ç á³íàðíîãî äåðåâà
// *p – âêàç³âíèê íà êîð³íü äåðåâà
{
	Node *q;

	if (!p) cout<<"Âåðøèíà ³ç çàäàíèì êëþ÷åì íå çíàéäåíà!"<<endl;	// âóçîë íå çíàéäåíî
	else
		if (data<(*p)->value) Delete(&((*p)->left), data);		// âóçîë ìåíøèé çà çíà÷åííÿ â êîðåí³
		else
			if (data>(*p)->value) Delete(&((*p)->right), data); // âóçîë á³ëüøèé çà çíà÷åííÿ â êîðåí³
			else					// âóçîë çíàéäåíî; âèäàëÿºìî
			{	q = *p;
				if (!q->right) { *p = q->left; delete q; }		//ÿêùî ó âóçëà º ò³ëüêè ë³âèé íàùàäîê
				else
					if (!q->left) { *p = q->right; delete q; } //ÿêùî ó âóçëà º ò³ëüêè ïðàâèé íàùàäîê
					else  Del(&(q->left), &q);					//ÿêùî ó âóçëà º îáèäâà íàùàäêè
			}
	return;}

int SumTree(Node *aNode){
    if (aNode)
        return SumTree(aNode->left)+aNode->value+SumTree(aNode->right);
}

int MaxTree(Node *aNode){
    if (!(aNode->right)) return aNode->value;
    else MaxTree(aNode->right);
}

void PrintLeaf(Node *aNode){
    if (aNode){
    PrintLeaf(aNode->left);
    if ((!(aNode->left))&&(!(aNode->right)))
    {
     cout<<aNode->value<<endl;
     return;
    }
    PrintLeaf(aNode->right);
}
return;
}
int main()
{
    //This is version edited in GitHub
    InsertNode(&root,5);
    InsertNode(&root,7);
    InsertNode(&root,3);

    PrintNode(root);

 //   Delete(&root,3);
    cout<<endl;
    PrintNode(root);
    cout<<endl<<"Tree sum is "<<SumTree(root)<<endl;
    cout<<endl<<"Maximum of tree is "<<MaxTree(root)<<endl;
    PrintLeaf(root);
    return 0;
}

#pragma once
#include"Tree.h"

template<class T>
class RBT:public Tree<T>
{
	void dealWithCases(Node<T>*, Node<T>*, Node<T>*, Node<T>*);
	void INORDER(Node<T>*);
	void POSTORDER(Node<T>*);
	void PREORDER(Node<T>*);

	void INORDER2(Node<T>*);
	void POSTORDER2(Node<T>*);
	void PREORDER2(Node<T>*);

	bool SEARCH(Node<T>*, T);
	void DELETEDUPLICATES(Node<T>*);

	void DESTROYTREE(Node<T>*);

public:
	void insertValue(T);
	void inorder();
	void postorder();
	void preorder();


	void inorder2();
	void postorder2();
	void preorder2();
	bool search(T);

	void deleteDuplicates();
	void destroyCompleteTree();
	void  displayingParent(T);

	~RBT();
};





template<class T>
void RBT<T>::dealWithCases(Node<T>*c, Node<T>* p, Node<T>* g, Node<T>* pofg)
{
	if (c->colour == 'r'&& p->colour == 'r')
	{
		if (c==p->left)
		{
			if (p == g->left)
			{				
				//please note that g->right in this case is u(uncle)node
				if (g->right == nullptr || g->right->colour == 'b')
				{
					
					//n is added as left child of left parent of Grand parent
					g->left = p->right;
					p->right = g;
					p->colour = 'b';
					g->colour = 'r';
					if (Tree<T>::root == g && g == pofg)
					{
						
						Tree<T>::root = p;
					}
					if (pofg->left==g)
					{
						pofg->left = p;
					}
                    if(pofg->right==g)
                    {
                        pofg->right=p;
                    }
				}
				else
				{
					p->colour = 'b';
					g->right->colour = 'b';
					if (g != Tree<T>::root)
						g->colour = 'r';
				}
			}
			else if(p == g->right) 
			{
				if (g->left == nullptr || g->left->colour == 'b')
				{
					//n is added as left child of right parent  to Grand parent
					p->left = c->right;
					c->right = p;
					g->right = c;

					g->right = c->left;
					c->left = g;
					c->colour = 'b';
					g->colour = 'r';

					if (Tree<T>::root == g && g == pofg)
						Tree<T>::root = c;
					if (pofg->left==g)
					{
						pofg->left = c;
					}
					if(pofg->right==g)
					{
						pofg->right = c;
					}

				}
				else//g->left->colour=='r'
				{
					p->colour = 'b';
					g->left->colour = 'b';
					if (g != Tree<T>::root)
						g->colour = 'r';
				}
			}
		}
		else if(c==p->right)
		{
			
			if (p == g->left)
			{
				
				if (g->right == nullptr || g->right->colour == 'b')
				{
					//n is added as right of left parent to Grand
					p->right = c->left;
					c->left = p;
					g->left = c;

					g->left = c->right;
					c->right = g;
					c->colour = 'b';
					g->colour = 'r';
					if (Tree<T>::root == g && g == pofg)
						Tree<T>::root = c;
					if (pofg->right ==g)
					{
						pofg->right = c;
					}
					if (pofg->left == g)
					{
						pofg->left = c;
					}
				}
				else
				{
					p->colour = 'b';
					g->right->colour = 'b';
					if (g != Tree<T>::root)
						g->colour = 'r';
				}
			}
			else if(p==g->right)
			{
				if (g->left == nullptr || g->left->colour == 'b')
				{
					//n is added right of right parent to Grand

					g->right = p->left;
					p->left = g;
					p->colour = 'b';
					g->colour = 'r';

					if (Tree<T>::root == g && g == pofg)
						Tree<T>::root = p;
					if (pofg->right ==g)
					{
						pofg->right = p;
					}
					if (pofg->left == g)
					{
						pofg->left = p;
					}
				}
				else//g->left->colour=='r'
				{
					p->colour = 'b';
					g->left->colour = 'b';
					if (g != Tree<T>::root)
						g->colour = 'r';
				}
			}
		}
	}
}



template<class T>
void RBT<T>::insertValue(T value)
{
	Node<T>* n = new Node<T>;
	n->data = value;
	n->colour = 'r';
	n->count = 1;
	n->left = nullptr;
	n->right = nullptr;
	if (Tree<T>::root == nullptr)
	{
		Tree<T>::root = n;
		n->colour = 'b';
	}
	else
	{
		Node<T>* t = Tree<T>::root;
		Node<T>* PofG=t;
		Node<T>* G=t;
		Node<T>* P = t;
		Node<T>* C = t;
		myStack<Node<T>*> obst;
		while (1)
		{
			obst.push(t);
			if(value<t->data)
			{
				if (t->left == nullptr)
				{
					t->left = n;
					if (PofG == G && G == P && P == C)
					{
						C = P->left;
					}
					else if (PofG == G && G == P && P != C)
					{
						P = C;
						C = P->left;
					}
					else if (PofG == G && G != P && P != C)
					{
						G = P;
						P = C;
						C = P->left;
					}
					else
					{

						PofG = G;
						G = P;
						P = C;
						C = P->left;
					}
					dealWithCases(C, P, G, PofG);
					break;
				}
				else
				{
					if (PofG==G&&G == P && P == C)
					{
						C = P->left;
					}
					else if(PofG == G&&G == P && P != C)
					{
						P=C;
						C = P->left;
					}
					else if(PofG == G&&G != P && P != C)
					{
						G = P;
						P = C;
						C = P->left;
					}
					else
					{

						PofG = G;
						G = P;
						P = C;
						C = P->left;
					}

					t = t->left;
				}
			}
			else
			{
				if (t->data == value)
				{
					t->count++;
					delete n;
					n = nullptr;
					break;
				}
				if (t->right == nullptr)
				{
					t->right = n;

					if (PofG == G && G == P && P == C)
					{
						C = P->right;
					}
					else if (PofG == G && G == P && P != C)
					{
						P = C;
						C = P->right;
					}
					else if (PofG == G && G != P && P != C)
					{
						G = P;
						P = C;
						C = P->right;
					}
					else
					{

						PofG = G;
						G = P;
						P = C;
						C = P->right;
					}
					dealWithCases(C, P, G, PofG);
					break;
				}
				else
				{
					if (PofG == G && G == P && P == C)
					{
						C = P->right;
					}
					else if (PofG == G && G == P && P != C)
					{
						P = C;
						C = P->right;
					}
					else if (PofG == G && G != P && P != C)
					{
						G = P;
						P = C;
						C = P->right;
					}
					else
					{

						PofG = G;
						G = P;
						P = C;
						C = P->right;
					}
					t = t->right;
				}
			}

		}
		Node<T>* pofg = nullptr;
		Node<T>* g = nullptr;
		Node<T>* p = nullptr;
		Node<T>* c = nullptr;
		if (obst.empty() != true)
		{
			c = obst.pop();
		}
		if (obst.empty() != true)
		{
			p = obst.pop();
		}
		if (obst.empty() != true)
		{
			g = obst.pop();
		}
		if (obst.empty() != true)
		{
			pofg = obst.pop();
		}
		if (c != nullptr && p != nullptr && g != nullptr && pofg != nullptr)
		{
			while (1)
			{
				dealWithCases(c, p, g, pofg);
				if (g == pofg &&obst.empty() == true)
					break;
				c = p;
				p = g;
				g = pofg;
				if (obst.empty() != true)
					pofg = obst.pop();
			}
		}
	}
}

template<class T>
void RBT<T>::inorder()
{
	cout << ">>>>INORDER<<<<<\n";
	cout << "\t\t";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		INORDER(Tree<T>::root);
		cout << endl;
	}
}



template<class T>
void RBT<T>::INORDER(Node<T>* r)//LNR
{
	if (r != nullptr)
	{
		INORDER(r->left);
		for (int i = 0; i < r->count; i++)
		{
			cout <<r->data << "," << r->colour;
			if (r == Tree<T>::root)
			{
				cout << " (root)";
			}
			cout <<"\t";
		}
		INORDER(r->right);
	}
}



template<class T>
void RBT<T>::postorder()
{
	cout << ">>>>POSTORDER<<<<<\n";
	cout << "\t\t";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		POSTORDER(Tree<T>::root);
		cout << endl;
	}
}



template<class T>
void RBT<T>::POSTORDER(Node<T>* r)//LRN
{
	if (r != nullptr)
	{
		POSTORDER(r->left);
		POSTORDER(r->right);
		for (int i = 0; i < r->count; i++)
		{
			cout <<r->data << "," << r->colour;
			if (r == Tree<T>::root)
			{
				cout << " (root)";
			}
			cout <<"\t";
		}
	}
}



template<class T>
void RBT<T>::preorder()
{
	cout << ">>>>PREORDER<<<<<\n";
	cout << "\t\t";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		PREORDER(Tree<T>::root);
		cout << endl;
	}
}
template<class T>
void RBT<T>::PREORDER(Node<T>* r)
{
	if (r != nullptr)
	{
		for (int i = 0; i < r->count; i++)
		{
			cout <<r->data << "," << r->colour;
			if (r == Tree<T>::root)
			{
				cout << " (root)";
			}
			cout <<"\t";
		}
		PREORDER(r->left);
		PREORDER(r->right);
	}
}


template<class T>
void RBT<T>::inorder2()
{
	cout << ">>>>INORDER2<<<<<\n";
	cout << "\t\t";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		INORDER2(Tree<T>::root);
		cout << endl;
	}
}


template<class T>
void RBT<T>::INORDER2(Node<T>* r)//RNL
{
	if (r != nullptr)
	{
		INORDER2(r->right);
		for (int i = 0; i < r->count; i++)
		{
			cout <<r->data << "," << r->colour;
			if (r == Tree<T>::root)
			{
				cout << " (root)";
			}
			cout <<"\t";
		}
		INORDER2(r->left);
	}
}



template<class T>
void RBT<T>::postorder2()
{
	cout << ">>>>POSTORDER2<<<<<\n";
	cout << "\t\t";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		POSTORDER2(Tree<T>::root);
		cout << endl;
	}
}

template<class T>
void RBT<T>::POSTORDER2(Node<T>* r)//RLN
{
	if (r != nullptr)
	{
		POSTORDER2(r->right);
		POSTORDER2(r->left);
		for (int i = 0; i < r->count; i++)
		{
			cout <<r->data << "," << r->colour;
			if (r == Tree<T>::root)
			{
				cout << " (root)";
			}
			cout <<"\t";
		}
	}
}



template<class T>
void RBT<T>::preorder2()
{
	cout << ">>>>PREORDER2<<<<<\n";
	cout << "\t\t";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		PREORDER2(Tree<T>::root);
		cout << endl;
	}
}
template<class T>
void RBT<T>::PREORDER2(Node<T>* r)
{
	if (r != nullptr)
	{
		for (int i = 0; i < r->count; i++)
		{
			cout <<r->data << "," << r->colour;
			if (r == Tree<T>::root)
			{
				cout << " (root)";
			}
			cout <<"\t";
		}
		PREORDER2(r->right);
		PREORDER2(r->left);
	}
}



template<class T>
bool RBT<T>::search(T val)
{
	if (Tree<T>::root != nullptr)
		return SEARCH(Tree<T>::root, val);
	else
		return false;
}

template<class T>
bool RBT<T>::SEARCH(Node<T>* p, T val)
{
	if (val < p->data)
	{
		if (p->left== nullptr)
		{
			return false;
		}
		SEARCH(p->left, val);
	}
	else
	{
		if (val == p->data)
		{
			return true;
		}
		if (p->right == nullptr)
		{
			return false;
		}
		SEARCH(p->right, val);
	}
}

template<class T>
void RBT<T>::DELETEDUPLICATES(Node<T>*r)
{
	if (r != nullptr)
	{
		if (r->count > 1)
		{
			r->count = 1;
		}
		DELETEDUPLICATES(r->left);
		DELETEDUPLICATES(r->right);
	}
}
template<class T>
void RBT<T>::deleteDuplicates()
{
	if (Tree<T>::root != nullptr)
	{
		DELETEDUPLICATES(Tree<T>::root);
	}
	else
	{
		cout << "RBT ALREADY EMPTY\n";
	}
}

template<class T>
void RBT<T>::destroyCompleteTree()
{
	if (Tree<T>::root != nullptr)
		DESTROYTREE(Tree<T>::root);
	else  
		cout << "RBT ALREADY EMPTY\n";
}

template<class T>
void RBT<T>::DESTROYTREE(Node<T>* r)
{
	if (r != nullptr)
	{
		//LRN
		DESTROYTREE(r->left);
		DESTROYTREE(r->right);
		if (r == Tree<T>::root)
		{
			delete Tree<T>::root;
			Tree<T>::root = nullptr;
		}
		else
		{
			delete r;
			r = nullptr;
		}
	}
}

template<class T>
void  RBT<T>::displayingParent(T nodeval)
{
	cout << ":: Displaying Parent\n";
	if (Tree<T>::root == nullptr)
	{
		cout << "RBT EMPTY\n";
	}
	else
	{
		if (Tree<T>::root->data == nodeval)
		{
			cout << "Given value is of root node which can't have any parent node\n";
		}
		else
		{
			Node<T>* childPointer = Tree<T>::root;
			Node<T>* parentPointer = Tree<T>::root;
			while (1)
			{
				if (nodeval < childPointer->data)
				{
					if (childPointer->left == nullptr)
					{
						cout << "No node exists with given value in RBT\n";
						break;
					}
					else
					{
						parentPointer = childPointer;
						childPointer = childPointer->left;
					}
				}
				else
				{
					if (childPointer->right == nullptr)
					{
						cout << "No node exists with given value in RBT\n";
						break;
					}
					else
					{
						parentPointer = childPointer;
						childPointer = childPointer->right;
					}

				}
				if (childPointer->data == nodeval)
				{
					cout << parentPointer->data << "," << parentPointer->colour << endl;
					break;
				}
			}
		}
	}
}

template<class T>
RBT<T>::~RBT()
{
	destroyCompleteTree();
}
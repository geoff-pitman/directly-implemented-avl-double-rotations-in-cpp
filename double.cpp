/*
The full AVL implementation can be found through Mark Weiss' web site 
[http://users.cs.fiu.edu/~weiss/]  from 'Data Structures and Algorithm Analysis' 4e.   

The only examples the book provides are single rotations.  
Below are the directly implemented double rotations.
*/
    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
	void doubleLeftRigt( AvlNode * & k3 )
	{
		AvlNode *k1, *k2;
		
		//assign child nodes
		k1 = k3->left;
		k2 = k1->right;
		//rotate left
		k1->right = k2->left;
		k3->left = k2->right;
		//rotate right
		k2->left = k1;
		k2->right = k3;
		//update heights
		k1->height = max( height(k1->left), height(k1->right) ) + 1;
		k3->height = max( height(k3->left), height(k3->right) ) + 1;
		k2->height = max( k1->height, k3->height ) + 1;
		//set root
		k3 = k2;
	}
	
	 /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
	void doubleRightLeft( AvlNode * & k1 )
	{
		AvlNode *k2, *k3;
		
		// assign child nodes
		k3 = k1->right;
		k2 = k3->left;
		// rotate right
		k1->right = k3->left;
		k2->right = k1->left;
		// rotate left
		k2->right = k3;
		k2->left = k1;
		// update heights
		k2->height = max( height(k2->left), height(k2->right) ) + 1;
		k3->height = max( height(k3->left), height(k3->right) ) + 1;
		k1->height = max( k2->height, k3->height ) + 1;
		// set root
		k1 = k2;
	}

**Merging two trees**

```
//TODO: function to merge two trees and returns a new tree.
Node* mergeTree(Node* tree1, Node* tree2){
	if(tree2 == NULL) return tree1;

	mergeTree(tree1, tree2->m_left);
	tree1 = add(tree1, tree2->m_data);
	mergeTree(tree1, tree2->m_right);
	return tree1;
	
}

```

we also need an add function :

```
Node* add(Node* root, int data){
	if(root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->m_data = data;
		root->m_right = root->m_left = NULL;
		return root;
	}
	if(data < root->m_data){
		root->m_left = add(root->m_left, data);
	}else{
		root->m_right = add(root->m_right, data);
	}
}

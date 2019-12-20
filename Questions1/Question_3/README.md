**INTENDED FUNCTION**

```
int biggestData(Node* tree){ 
  Node* iter = tree;
  while(iter->m_right != NULL) iter = iter->m_right;
  return iter->m_data;
}

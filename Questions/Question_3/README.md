**INTENDED FUNCTION**

```
int biggestData(Node* tree){ 
  Node* iter = tree;</br>
  while(iter->m_right != NULL) iter = iter->m_right;</br>
  return iter->m_data;</br>
}

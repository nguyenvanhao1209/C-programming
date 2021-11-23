#include <stdio.h>
#define MAX 20
typedef struct phoneaddress_t {
  char name[20];
  char tel[11];
  char email[25];
}phoneaddress;
typedef struct Node{
  phoneaddress Key;
  struct Node* left;
  struct Node* right;
}NodeType;
typedef struct Node* TreeType;
TreeType Search(char* email,TreeType Root){
  if (Root == NULL) return NULL;
  if (strcmp((Root->Key).email, email) == 0) return Root;
  else if (strcmp((Root->Key).email, email) < 0)
    return Search(email,Root->right);
  else {
    return Search(email,Root->left);
  }
}
void InsertNode(phoneaddress x,TreeType *Root ){
  if (*Root == NULL){
    *Root=(NodeType*)malloc(sizeof(NodeType));
    (*Root)->Key = x;
    (*Root)->left = NULL;
    (*Root)->right = NULL;
  }
  else if (strcmp(((*Root)->Key).email, x.email) > 0)
    InsertNode(x, (*Root)->left);
  else if (strcmp(((*Root)->Key).email, x.email) > 0) 
    InsertNode(x,(*Root)->right); 
}
void printTree(TreeType Root){
  if(Root != NULL){
    printTree(Root->left);
    printf("%-20s\t%-20s\t%-20s\n",Root->Key.email,Root->Key.name,Root->Key.tel);
    printTree(Root->right);
  }
}
int main(){
  FILE *fp;
  phoneaddress phonearr[MAX];
  TreeType root;
  int i,n, irc;
  int n=10;
  if((fp = fopen("phonebook.dat","rb")) == NULL){
    printf("Can not open %s.\n", "phonebook.dat");
  }
  irc = fread(phonearr, sizeof(phoneaddress), n, fp);
  fclose(fp);
  for (i=0; i<n; i++)
     InsertNode(phonearr[i],root);
  printTree(root);
  char s[25];
  fflush(stdin);
  gets(s);
  TreeType p = Search(s,root);
  printf("%-20s\t%-20s\t%-20s\n",p->Key.email,p->Key.name,p->Key.tel);
}

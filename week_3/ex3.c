#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct infomation{
	char id[10];
	char name[30];
	int grade;
};
typedef struct infomation infomation;
struct student_t{
	infomation info;
	struct student_t *next;
};
typedef struct student_t student;
student *createSt(infomation x){
	student *temp;
	temp = (student *)malloc(sizeof(student));
	temp->next = NULL;
	temp->info = x;
	return temp;
}
void printlist(student *root){
	student *p = root;
	while(p != NULL){
		printf("%-10s\t%-20s\t%d\n",p->info.id,p->info.name,p->info.grade);
		p = p->next;
	}
}
student *add_student(student *root,student *to_add){
	student *curr_std, *prev_std = NULL;
	if(root == NULL) return to_add;
	if(to_add->info.grade > root->info.grade){
		to_add->next = root;
		return to_add;
	}
	curr_std = root;
	while(curr_std != NULL  &&  to_add->info.grade < curr_std->info.grade){
		prev_std = curr_std;
		curr_std = curr_std->next;
	}
	prev_std->next = to_add;
	to_add->next = curr_std;
	return root;
}
student *find_student(student *root, char *id){
	student *to_search = root;
	while(to_search != NULL){
		if(strcmp(to_search->info.id,id)==0){
			return to_search;
		}
		to_search = to_search->next;
	}
	return NULL;
}
student *remove_student(student *root, char *id){
	student *cur = root;
	student *prev;
	if(strcmp(cur->info.id,id)==0){
			root = root->next;
			free(cur);
			return root;
	}
	while(cur != NULL  &&  strcmp(cur->info.id,id)!=0){
		prev = cur;
		cur = cur->next;
	}
	if(cur != NULL){
		prev->next = cur->next;
		free(cur);
	}
	return root;
}
student *change_grade(student *root, char *id, int new_grade){
	student* std = find_student(root, id);
	student* temp;
	strcpy(temp->info.id,std->info.id);
	strcpy(temp->info.name,std->info.name);
	temp->info.grade = new_grade;
	root = remove_student(root, id);
	return add_student(root, temp);
}

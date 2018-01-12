//category : implementation
#include <stdio.h>
char exp[27 + 27 + 27];
char stk[27+27+27];
int top;
int main(){
	int i;
	scanf("%s",exp);
	for (i = 0; exp[i] != '\0'; i++){
		if (exp[i] >= 'A'&&exp[i] <= 'Z'){
			printf("%c",exp[i]);
		}
		else if (exp[i] == ')'){
			while (top != 0 && stk[top - 1] != '(') printf("%c", stk[--top]);
			if (stk[top - 1] == '(') top--;
		}
		else {
			if (top != 0){
				if (exp[i] == '+' || exp[i] == '-' ||
					((exp[i] == '/' || exp[i] == '*') && (stk[top - 1] == '/' || stk[top - 1] == '*')))
					while (top != 0 && stk[top - 1] != '('){
						if ((exp[i] == '/' || exp[i] == '*') && (stk[top - 1] == '+' || stk[top - 1] == '-'))
							break;
						printf("%c",stk[--top]);
					}
			}
			stk[top++] = exp[i];
		}
	}
	while (top != 0) printf("%c", stk[--top]);
	return 0;
}

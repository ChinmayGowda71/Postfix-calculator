#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
	int* stack = malloc(4096); //creates a stack for outputting
	int conditional = 1;
	int n =0;
while(conditional==1){
	char *buffer = NULL;
	int x = 0;
	size_t buffersize = 0;
	size_t character;
	char *ptr = NULL;
	character = getline(&buffer,&buffersize,stdin); //line that pulls the input
	if (character == -1){ //there are no characters left 
		char b4='[';
        for(int i=0; i<n; i+=1) { 
                printf("%c %d", b4, stack[i]); 
                b4=','; 
        }
	puts(" ]");
        free(stack);
        return 0;
	}
        char *arr[character];
        char *splitchar;
        while( (splitchar = strsep(&buffer, " ")) != NULL){ //splices the long string into individual characters
		arr[x] = splitchar;
                x++;
        }

	for (int f = 0; f < x; f++){
		if (arr[f][strlen(arr[f]) - 1] == '\n'){ //creates an initial array of everyhting 
               		arr[f][strlen(arr[f]) - 1] = '\0';
        	}
		int val = strtol(arr[f],&ptr,10);
		if(arr[f] == ptr){		// when either the symbols or letters exist
			if (strcmp(arr[f],"") == 0){  // continue when theres a space 
	                        continue;
               		 }
                	else if (strcmp(arr[f], "+") == 0){ //compares to see if current iteration is the symbol to perform the operation
				if (n >=2){
                     		stack[n-2] = stack[n-2]+stack[n-1]; // takes the last two elements and does the math with it
                        	n--;
				}
				else {
					
					char b4='[';
				        for(int i=0; i<n; i+=1) { 
			                printf("%c %d", b4, stack[i]); 
             				   b4=','; 
      				  }
					puts(" ]");
				        free(stack);
				        return 0;
				}
               		 }
                	else if (strcmp(arr[f], "-") == 0){
				if (n >=2) {
                	        stack[n-2] = stack[n-2] - stack[n-1];
                	        n--;
				}
				else {
					
                                        char b4='[';
				        for(int i=0; i<n; i+=1) { 
			                printf("%c %d", b4, stack[i]); 
			                b4=','; 
			        }
					puts(" ]");
				        free(stack);
				        return 0;
                                }

               		 } 
                	else if (strcmp(arr[f], "*") == 0){
				if (n >= 2){
                	        stack[n-2] = stack[n-2] * stack[n-1];
                	        n--;
				}
				else {
					
                                        char b4='[';
     					   for(int i=0; i<n; i+=1) { 
    				            printf("%c %d", b4, stack[i]); 
    				            b4=','; 
    				    }
					puts(" ]");
				        free(stack);
				        return 0;
                                }

                	}
                	else if (strcmp(arr[f], "%") == 0){
                	        if (n >= 2){ 
				stack [n-2] = stack[n-2] % stack[n-1];
                	        n--;
				}
				else {
					
                                        char b4='[';
       					 for(int i=0; i<n; i+=1) { 
              				  printf("%c %d", b4, stack[i]); 
               					 b4=','; 
       					 }
					puts(" ]");
						        free(stack);
				        return 0;
                                }

                	}
			else {
	
				char b4='[';
			        for(int i=0; i<n; i+=1) { 
		                printf("%c %d", b4, stack[i]); 
        		        b4=','; 
      			  }
				puts(" ]");
			        free(stack); // freeing the stack so that other calculations can be done without overwriting 
			        return 0;
			}
		}
		else{
			stack[n] = strtol(arr[f],&ptr,10);
			n++;
			if (n % 4096 == 0){
				stack = realloc(stack, n*2); //reallocates more memory in case space runs out
			}
		}
	}

}

	
}

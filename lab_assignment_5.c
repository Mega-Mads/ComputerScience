#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;
// Returns the num of nodes withinme linkedList.
int length(node* head) { // used to calculate the length linked list
    int len = 0; // length counter
    while (head != NULL) { // Traverse the list till end
        len++; // Increment length for each and every node
        head = head->next; // Move to the next node
    }
    return len;  // Retur total length
}
// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) { // used to convert linked list into string
    int len = length(head); // this will get the length of the list
    char* str = (char*)malloc(len + 1); // Allocate memory then (+1 for null terminator)
    char* temp = str; // Temporary pointer 
    while (head != NULL) { // Traverselist
        *temp++ = head->letter; // Copy character to the string~!!
        head = head->next;  // next node moved
    }
    *temp = '\0'; // Null-terminate
    return str; // Return string
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) { // this Function will be used to insert a character at the end of linked list
    node* newNode = (node*)malloc(sizeof(node)); // Allocate memory for the new node
    newNode->letter = c; // Ssetting character for the new node
    newNode->next = NULL;  // New node will be the last making the next one NULL

    if (*pHead == NULL) { // if statment stating if the list is empty,
        *pHead = newNode; // the new node becomes the head
    } else { // ELSE find the last node
        node* temp = *pHead;
        while (temp->next != NULL) {  //  end of the list
            temp = temp->next;
        }
        temp->next = newNode; // Insert new node at the end
    }
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead) { // THIS WILL free memory
    node* current = *pHead; // starting head of the list
    node* next;

    while (current != NULL) { // Traverse 
        next = current->next; 
        free(current); // Freeing  current node
        current = next; // Moves next node
    }

    *pHead = NULL; // After being deleted the  head then becomes NULL
}

int main(void) { // Main function 
    int i, strLen, numInputs;
    node* head = NULL; // saying head of the list as NULL
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r"); // Open the txt file

    fscanf(inFile, " %d\n", &numInputs); // Read the  inputs

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen); // eACH input WILL BE Red the string length
        for (i = 0; i < strLen; i++) {  // Read EVERYHTING
            fscanf(inFile, " %c", &c);
            insertChar(&head, c); // Inserting character into the list
        }

        str = toCString(head); // Convert the list into string
        printf("String is : %s\n", str); // Print the string

        free(str); // Free 
        deleteList(&head); // Delete 

        if (head != NULL) { // deletion was successful?
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile); // Close the input file
    return 0; // Return from main
}

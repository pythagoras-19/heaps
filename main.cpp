/*Insert 10 values into a min-heap from a file.  Display the data, level by level.
Then delete 5 items. After each delete, display the heap, level by level. */
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node // for tree
{
    int key;
   // node* next; //maybe not
    int height; // we can calculate balance with this
    node* left;
    node* right;
    node* current;
    node* next;
   
    //node* front;
    //node* rear;
};
//QUEUES
bool isEmpty(node *&front)    // checking if our queue is empty
{
    if(!front)                // if queue has no elements
    {
        return true;        // queue is empty
    }
    else return false;      // else queue is NOT empty
}
void dequeue(node* &front, node* &rear) // remove from front
{
    //std::cout << "dequeue()\n";
    //FILE* fp;
    //const char fileName[100] = "output.txt";
    //fp = fopen(fileName, "w");
    node* temp; // used to hold the item we want to delete
    //this is where we need to focus
    if(front)  // if there is an item there that we can dequeue
    {
        //fprintf(fp, "%d", front->value);
        temp = front;         // temp = front value so we can dequeue temp
        front = front->next;  // make our new front the element after front
        delete temp;          // dequeue
        if(!front)            // empty list, can't dequeue
        {
            rear = NULL;
        }
    }
}
//pass by alias to affect front and rear directly
void enqueue(node* &front, node* &rear, node* myNode) // put it at the end
{
    //std::cout << "enqueue()\n";
    node* nn = new node;
    //std::cout << "1" << myNode->key << std::endl;
    nn = myNode;      // new node value gets our passed value
    nn->next = NULL;        // end value
    //differentiate between an empty queue and not empty queue
    if(!front) // checking if empty
    {
        //std::cout << "In !front(), nn->value: " << nn->value << std::endl;
        rear = front = nn; // first assignment so both the rear and front get nn as their value
        //assign rear and front with the Node nn
    }
    else //not an empty list, insert another node
    {
        //std::cout << "In else(), nn->value: " << nn->value << std::endl;
        rear->next = nn; // the old rear's next member points to our new node
        rear = nn;       // nn becomes the new rear in our list (enqueue happens at the rear)
    }
}
/*
void traverse(Node* front, Node* rear)
{
    std::cout << "In traverse() " << std::endl;
    Node* currentNode;
    for(currentNode = front; currentNode; currentNode = currentNode->next)
    {
        std::cout << currentNode->value << std::endl;
    }
}
*/
/*
//printing level by level
void printLevel(int array[], int heapSize)
{
    node* root = new node;
    root->key = array[0];
    if (root == NULL)
    {
        return;
    }
    FILE* fp;
    const char fileName[100] = "output.txt";
    fp = fopen(fileName, "w");
    //else create a queue
    node* front = NULL;
    node* rear = NULL;
    node* current = root;
    int nodesOnCurrentLevel = 0;
    int nodesInNextLevel = 0;
    enqueue(front, rear, root); // inserted root node in queue
   // Node* current = front;
    current = front;
    nodesOnCurrentLevel ++; // nodesOnCurrentLevel = 1
    while(nodesOnCurrentLevel != 0)
    //while (!(isEmpty(front))) //while there is at least one discovered node
    {
        current = front;
        //dequeue and display
        //dequeue(front, rear); //removing from front
        //int bal = getBalance(current);
        //std::cout << current->key << "- (height: " << current->height << ", bal: " << bal << ")" << " ";
        //fprintf(fp, "%d - ", current->key);
        //fprintf(fp, "(height: %d, balance: %d) ", current->height, bal);
        //nodesOnCurrentLevel--;
        //std::cout << current->key << " ";
        //dequeue(front,rear);
        //nodesOnCurrentLevel--;
       // std::cout << "current->left->key: " << current->left->key << std::endl;
        if(current->left != NULL)// curr needs to be updated
        {
            enqueue(front, rear, current->left);
            nodesInNextLevel++;
        }
        if (current->right != NULL)
        {
            enqueue(front, rear, current->right);
            nodesInNextLevel++;
        }
        //std::cout << current->value << " ";
        //fprintf(fp, "%s", "\n");
        dequeue(front, rear); //removing from front
        nodesOnCurrentLevel--;
        //std::cout << std::endl;
       
        if(nodesOnCurrentLevel == 0)
        {
            nodesOnCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
            std::cout << std::endl;
            fprintf(fp, "%s", "\n");
        }
       
    }
}
*/
void printLevel(int array[], int heapSize)
{
    std::cout << "\nPrint Level:";
    FILE* fp;
    const char fileName[100] = "output.txt";
    fp = fopen(fileName, "w");
    int elementsOnCurrentLevel = 0;
    int elementsInNextLevel = 0;
    int k = 0;
    int printFactor = pow(2,k);
    int i = 0;
    while (i < heapSize)
    {
        printFactor = pow(2,k);
        /*
        if (printFactor == 1)
        {
            std::cout << array[i];
            k++;
            std::cout << std::endl;
        }
        */
        //else
       // {
            while(i < printFactor-1 && i < heapSize)
            {
                std:: cout << array[i] << " ";
                i++;
            }
            k++;
            std::cout << std::endl;
      //  }
        //std::cout << std::endl;
    }
}
/*
void swap(int* num1, int* num2)
{
    std::cout<< "in swap()\n";
    int* temp = num1;
    std::cout << num1 << " " << num2 << std::endl;
    num1 = num2;
    num2 = temp;
}
*/
void siftDown(int index, int heapSize, int array[]) // always delete a[0], never anything else
{
    //compares left child and right child
    //once found do a substitution
    //continue process...
    int min = index;
    int leftChild = (2*index) + 1;
    int rightChild = (2*index) + 2;
 
    if (leftChild <= heapSize)
    {
        if(leftChild == heapSize) // dont have a right child
        {
            min = leftChild;
        }
        else
        {
            if (array[leftChild] < array[rightChild])
            {
                min = leftChild;
            }
            else
            {
                min = rightChild;
            }
        }
    }
    if(array[index] > array[min])
    {
        //std::cout<< "in swap()\n";
        int temp = array[index];
        //heapSize--;
        //std::cout << num1 << " " << num2 << std::endl;
        array[index] = array[min];
        array[min] = temp;
        siftDown(min, heapSize, array);
        //printLevel(array,heapSize);
    }
    //printLevel(array, heapSize);
 
}
void siftUp(int index, int array[])
{
    //climb up until hit 0 or at top
    if (index != 0)
    {
        int parentIndex = (index - 1) / 2;
        //if(array[index] < array[parentIndex]) // might be >
        if(array[parentIndex] > array[index])
        {
            //std::cout<< "in swap()\n";
            int temp = array[index];
            //std::cout << num1 << " " << num2 << std::endl;
            array[index] = array[parentIndex];
            array[parentIndex] = temp;
            //std::cout << "after swap(): \narray[parentIndex]: " << array[parentIndex] << ", array[index]: " << array[index] << std::endl;
            siftUp(parentIndex, array);
        }
    }
}
 
int main()
{
    int array[10];
    //initialize all the elements to a large number so we know if this element has a value inserted into it or not.
    int heapSize = sizeof(array)/sizeof(int);
    for(int i=0; i < heapSize; i++)
    {
        array[i] = 9999;
    }
    int parentIndex = 999;
    int j = 0;
    FILE *fp;
    char line[255]; // line of chars
    //int line[20];
    //int number[20];
    char deleteWord[] = "delete";
    const char fileName[100] = "input.txt";
    fp = fopen(fileName, "r");
    //node* root = NULL;
    int i = 0;
    while(fscanf(fp, "%s", line) != EOF)
    {
        //std::cout << "line is now: " << line << std::endl;
        /*
        if(strcmp(line, deleteWord) == 0) //read "delete"
        {
            fscanf(fp, "%s", line); // read one more to get value of node we want to delete
            std::cout << "line is now: " << line << std::endl;
            for(j=0; j < heapSize; j++)
            {
                if (atoi(line) == array[j])
                {
                     parentIndex = (j-1) / 2;
                     break;
                }
            }
           
            if (parentIndex >= 0)
            {
                siftDown(0, j, heapSize, array); // always delete a[0], never anything else
            }
            else
            {
                std::cout << "ERROR\n";
            }
           // deleteNode(root, line);
        }
        */
       if(strcmp(line,deleteWord) == 0)
       {
           //std::cout << "called siftDown()\n";
           array[0] = array[heapSize-1];
           heapSize--;
           siftDown(0, heapSize, array );
           printLevel(array,heapSize);
       }
       else
       {
            array[i] = atoi(line);
            //std::cout << "inserting " << line << std::endl;
            siftUp(i, array);
            i++;
            //call sift-up to keep min-heap property
        }
       
 
    }
    //printLevel(array, heapSize);
    return 0;
}
 
//////////////////////////
/*
void printLevel(int array[], int heapSize)
    FILE* fp;
    const char fileName[100] = "output.txt";
    fp = fopen(fileName, "w");
    int elementsOnCurrentLevel = 0;
    int elementsInNextLevel = 0;
    int k = 0;
    int printFactor = pow(2,k);
    int i = 0;
    while (i < heapSize)
    {
        printFactor = pow(2,k);
        if (printFactor == 1)
        {
            std::cout << array[i];
            k++;
            i++;
            std::cout << std::endl;
        }
        else
        {
            while(i < printFactor-1 && i < heapSize)
            {
                std:: cout << array[i] << " ";
                i++;
            }
            k++;
            std::cout << std::endl;
        }
        //std::cout << std::endl;
    }
   */

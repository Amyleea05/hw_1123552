# hw_1123552
Author: Amylea
Submission date: 2024.11.28

IMPORTANT NOTE!
I used the cin or input commands in all the codes. Therefore, in order to get the output, you need to manually provide all the inputs. You can use examples on the documents or the example inputs and outputs below (that different from documents). 

QUESTION 1: Write a program to calculate the diameter of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root. Programm required to	1. Build the binary tree using level-order input. Use -1 to represent null nodes. 2.	Implement a function to calculate the diameter of the binary tree efficiently using recursion.
EXAMPLE input and output: 
Enter the number of nodes: 9 
Enter the level-order traversal (use -1 for null nodes): 
1 2 3 4 5 6 7 -1 -1
Diameter of the binary tree is: 5

QUESTION 2: Write a program to manage a task priority queue using a max heap. Each task has a name and a priority level. Program should allow: 1.	Add a Task: Add a task with a given priority. 2.	Get the Highest Priority Task: Remove and return the task with the highest priority. 3.	Display the Remaining Tasks: Print the remaining tasks in descending order of priority.
EXAMPLE input and output: 
Enter the number of operations: 5
Enter operation: ADD TaskA 30
Enter operation: ADD TaskB 25
Enter operation: ADD TaskC 40
TaskC
Enter operation: ADD TaskD 10
Enter operation: GET
TaskA
Remaining tasks: (TaskB, 25) (TaskD, 10)


QUESTION 3: Given K sorted arrays of integers. Write a Python program to merge these arrays into a single sorted array using a Min Priority Queue. Program should: 1.	Insert the first element of each array into a Min Priority Queue along with the array index and element index. 2.	Extract the smallest element from the queue, add it to the result array, and insert the next element from the same array into the queue. 3.	Continue this process until all elements from all arrays are merged.
EXAMPLE input and output:
4
10 20 30
5 15 25
1 12 22 32
3 13 23 33
Expected Output:
Merged Array: [1, 3, 5, 10, 12, 13, 15, 20, 22, 23, 25, 30, 32, 33]

QUESTION 4: Given N tasks, each with a profit and a deadline. Write a Python program to schedule the tasks such that the maximum profit is achieved, using a Max Priority Queue. Each task must be completed within its deadline (1-based index), and only one task can be scheduled at a time.
EXAMPLE input and output:
5
50 3
30 2
70 3
60 1
40 2

Maximum Profit: 120
Scheduled Tasks: [70, 50]


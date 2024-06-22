# Queue and Stack

Information about my data set: This dataset is about languages from the World Atlas of Language
Structure.

- row_number: a unique integer that corresponds to the row. The row_number starts at 1
with the last value being 2678.
- wals_code: a unique string that is typically 3 letters. It is a way to identify the individual
languages. This was the way it was organized by default. With codes starting with a at the
top and codes starting with z at the bottom.
- name: a string that identifies the name of the language.
- genus: a string that identifies the genus, a group of phylogenetically related languages
inside a linguistic family, that the language belongs to.
- family: a string that identifies the family, a group of languages related through descent
from a common ancestral language, that the language belongs to.
- macroarea: a string that identifies the macro-area that the language comes from.
- The macroarea contained 21 empty rows. But it was alright as there was still 2657
viable data to use.
- latitude: a double that identifies the latitude of the location.
- longitude: a double that identifies the longitude of the location.

### Stack Class
What is the Big-Oh complexity of the methods?
- Everything is O(1)/constant except for the search method which is O(N)/linear. The search
and printStack method is linear because it depends on size of the stack, N = number of nodes in
the stack, thus in the worst-case scenario we will have to search through every node or go
through each node and them print it out.

### Queue Class
Your Queue should be able to push Objects onto its back, pop Objects off its front, and determine
if an Object is in the Queue. What is the complexity of each method?
- Same as with the Stack class everything is O(1)/constant except for the search and
printQueue method which is O(N)/linear. The search method is linear because it depends on
size of the Queue thus in the worst-case scenario we will have to search through every node.
The printQueue method also follows a similar logic with it going through each node in the
Queue in order to print it out.

### Main function
What is the order of the objects before and after adding them to the Queue and Stack? When
and why did it change?
- Queue uses FIFO à First in First out and Stack uses LIFO à Last in First out. Thus, when
adding the objects to Queue the first object added is at the top and the last object added is
at the bottom of the Queue. But after the objects were “popped” of the Queue and added
into the Stack the order was reversed/changed. The first object added was at the bottom of
the stack and the last object ended up at the front. This change was caused by the way in
which Queue and Stack organizes and manipulates the data.

### Design
Using the Node class, will the links point from the front to the back of the Queue or from the
back to the front? Which way will make the push and pop methods more efficient?
- The links will point from the back of the Queue to the front as a Queue uses FIFO, first in
first out. This will make the “push” and “pop” methods more efficient.
How will you make sure there are no memory leaks?
- I made sure that there are no memory leaks by creating a destructor class which is
automatically called at the end of the stack/queue object’s lifetime. By doing this we will be
deleting the remaining nodes from the stack or queue. Then there is a print statement
outside of the while loop that prints “No memory leaks” so that I know that the destructor
was called.
How will you print the objects in the main function? Should you overload an operator?
- I printed the Queue objects in the main function by calling my printQueue method. Then for
searching for a specific value in the Queue I created an overloaded operator as the == in the
search method works for integers but won't work with Language objects.

### Test 
- To demonstrate that my Queue class works correctly I created three Queue objects: one of
integers, one of strings, and one of Language. Then I used my enQueue method to insert 4
values each into the Queues and then used the deQueue method to remove a value. Then I
used the printQueue method to print the three Queues which showed that the 4 values of
each Queue were properly inserted with the first value being removed. Finally, I tested my
search function by first searching for the dequeued value which returned false and then
searching for a value that I knew was in the Queue which returned true.

Cite:
I used this article on queue linked-list implication to figure out enqueue and dequeue.
https://www.geeksforgeeks.org/queue-linked-list-implementation/

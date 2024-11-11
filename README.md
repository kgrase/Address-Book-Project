# Address Book Linked List Project

## 1. What did you find most challenging with this program?

While the program compiled and ran without implementing the `ostream` operator for `extPersonType`, it only printed partial information (e.g., just the person's name). The challenge was enhancing the output of the `LinkedList`'s `print` function to display complete details of `extPersonType`.

## 2. What problems did you encounter and how did you solve them?

Initially, the `LinkedList`'s `print` function only printed partial information for `extPersonType`. I solved this by implementing the `ostream` operator to display all relevant member variables in a formatted way. Additionally, I ensured that data reading and writing from and to files were properly handled.

## 3. What did you learn from writing this program?

I learned how to implement a linked list-based solution and understood how it differs from a vector-based solution, especially in terms of dynamic memory management, node traversal, and efficient insertion or deletion operations.

---

## How to Compile

To compile all `.cpp` files in the project, use the following command:

```bash
g++ $(find . -name "*.cpp") -o main

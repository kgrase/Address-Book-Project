# Address Book Linked List Project

## 1. What did you find most challenging with this program?

Managing pointer logic while ensuring correct list order was challenging. Specifically, handling the deletion of nodes without causing memory corruption or leaks required careful pointer management.

## 2. What problems did you encounter and how did you solve them?

- **Pointer Issues**: Deleting nodes sometimes caused list corruption.  
  **Solution**: I ensured proper updates of the `first` and `last` pointers, especially for edge cases.

- **Memory Leaks**: Some nodes weren’t freed correctly.  
  **Solution**: I ensured every `new` operation was paired with `delete` and used smart pointers for better memory management.

- **Insert Function**: It didn’t always insert in order.  
  **Solution**: I refined the insertion logic to maintain the list’s order.

## 3. What did you learn from writing this program?

I gained a deeper understanding of dynamic memory management and pointer manipulation. I also learned the importance of testing edge cases and handling them properly to avoid errors in list operations.

---

## How to Compile

To compile all `.cpp` files in your project, run the following command:

```bash
g++ $(find . -name "*.cpp") -o main


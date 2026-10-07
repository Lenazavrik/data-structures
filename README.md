# Data Structures in C++

A collection of nine standalone C++ coursework programs exploring linked lists, stacks, queues, deques and binary trees.

Each source file has its own `main()` function. The original implementations, comments and console prompts are preserved, including the different versions of the list and tree exercises. Comments and prompts are in English and Latvian.

## Examples

| Structure | Source | Focus |
| --- | --- | --- |
| Stack | [stack.cpp](stack/stack.cpp) | Adding and removing elements at the top; displaying, counting and clearing elements |
| Queue | [queue.cpp](queue/queue.cpp) | Adding elements at the end and removing them from the front |
| Deque | [deque.cpp](deque/deque.cpp) | Adding and removing elements at both ends using doubly linked nodes |
| Singly linked list — basic version | [singly_linked_list_basic.cpp](linked-list/singly_linked_list_basic.cpp) | An early exercise in creating and linking nodes |
| Singly linked list | [singly_linked_list.cpp](linked-list/singly_linked_list.cpp) | Insertion, deletion, display and element counting |
| Singly linked list with input validation | [singly_linked_list_with_input_validation.cpp](linked-list/singly_linked_list_with_input_validation.cpp) | List operations with numeric input validation and a console menu |
| Binary tree — sketch | [binary_tree_sketch.cpp](tree/binary_tree_sketch.cpp) | An early node creation and traversal sketch |
| Binary search tree — draft | [binary_search_tree_draft.cpp](tree/binary_search_tree_draft.cpp) | An early version of the tree exercise |
| Binary search tree | [binary_search_tree.cpp](tree/binary_search_tree.cpp) | Insertion, search, deletion, traversal and element counting |

The early versions are kept alongside the later coursework versions to preserve the original exercises. Some are incomplete; this collection is retained as coursework rather than maintained as a reusable data structure library.

## Build and run an example

You need a C++ compiler, such as GCC (`g++`) or Clang (`clang++`).

From the repository root, compile and run the linked list example with input validation:

```bash
mkdir -p build
g++ -std=c++17 linked-list/singly_linked_list_with_input_validation.cpp -o build/linked_list
./build/linked_list
```

On Windows, use `build/linked_list.exe` as the output path and run that executable.

The program presents a numbered menu. For a short demonstration:

1. Choose **1** and enter a value to create the head node.
2. Press Enter when prompted, then choose **3** and enter another value to append a node.
3. Choose **10** to display the list.
4. Choose **13** to exit.

Compile one file at a time, since each program has a separate entry point. The command above was checked for this example; the preserved early versions are not all complete build targets.

## Repository layout

| Path | Contents |
| --- | --- |
| [linked-list/](linked-list/) | Three versions of the singly linked list exercise |
| [stack/](stack/) | Stack example |
| [queue/](queue/) | Queue example |
| [deque/](deque/) | Double-ended queue example |
| [tree/](tree/) | Three versions of the tree exercise |
| [.gitignore](.gitignore) | Ignore rules for local metadata and build output |

## Original file names

Only the paths and file names were changed. Source contents remain identical to the originals.

| Original name | Current path |
| --- | --- |
| `steks.cpp` | `stack/stack.cpp` |
| `rinda.cpp` | `queue/queue.cpp` |
| `deks.cpp` | `deque/deque.cpp` |
| `linearaisSaraksts.cpp` | `linked-list/singly_linked_list_basic.cpp` |
| `linearaisNodosanai.cpp` | `linked-list/singly_linked_list.cpp` |
| `linearaisNew.cpp` | `linked-list/singly_linked_list_with_input_validation.cpp` |
| `binars.cpp` | `tree/binary_tree_sketch.cpp` |
| `koks.cpp` | `tree/binary_search_tree_draft.cpp` |
| `koksNodosanai.cpp` | `tree/binary_search_tree.cpp` |

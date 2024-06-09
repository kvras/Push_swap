# Push Swap Project - 42 School

## Project Overview

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The goal is to sort the stack with the minimum possible number of operations. The algorithm used in this project is highly efficient and involves dynamic programming, which makes the source code quite large compared to other stack sorting algorithms.

## Instructions

The project uses two stacks, `a` and `b`, and the following operations:

- `sa` : swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
- `sb` : swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
- `ss` : `sa` and `sb` at the same time.
- `pa` : take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
- `pb` : take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
- `ra` : shift up all elements of stack `a` by 1. The first element becomes the last one.
- `rb` : shift up all elements of stack `b` by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : shift down all elements of stack `a` by 1. The last element becomes the first one.
- `rrb` : shift down all elements of stack `b` by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.


## Building and Running

git clone [link]
cd [Directorty]
make


## Algorithm and Efficiency

The algorithm used in this project is a highly efficient sorting algorithm specifically designed for this type of stack sorting problem. It uses dynamic programming to optimize the sorting process, which results in a larger source code compared to other stack sorting algorithms. However, the increased code complexity leads to a more efficient sorting process, making it a worthwhile trade-off.

## Author

Mohamed Amine IGUIJI

## License

This project is licensed under the [MIT License](LICENSE).

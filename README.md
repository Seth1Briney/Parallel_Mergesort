An in-place non-recursive parallelizable mergesort implementation written in C++ using std::vector data structures.

Parallelism is not implemented, but in theory it can be achieved by throwing some pragma omp parallel for directives in before the loops.

Putting this in front of certain loops should make the program parallel, since the loops are written pseudo-recursively, all sections of each iteration can be done simultaneously.

#pragma omp parallel for

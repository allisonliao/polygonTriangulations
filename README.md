## Polygon triangulations counting program

C++ code recursively collects diagonals, passing $n$ (number of edges) and the offset value for recursion.

Also implements method to count triangulations recursively with only the condition that each unique triangule multiplies the overall triangulation count and a triangle has one triangulation. (This method does not actually 'count' the triangulations, but successfully produces the Catalan number.)

Using C++ `clock()` function to time the execution of each triangulation-list generation.

To compile and create executable:
```
g++ -std=c++11 countTriangulations.cpp
```

To run:
```
./a.out
```

Rough measurement of time taken (rounded to 2 decimals):

| $n$ sided polygon | Time Taken |
| ----------- | ----------- |
| $3$ (triangle)  | $0$ m $ 0.00$ s |
| $4$ (square)    | $0$ m $ 0.00$ s |
| $5$ (pentagon)  | $0$ m $ 0.00$ s |
| $6$ (hexagon)   | $0$ m $ 0.00$ s |
| $7$             | $0$ m $ 0.00$ s |
| $8$             | $0$ m $ 0.00$ s |
| $9$             | $0$ m $ 0.00$ s |
| $10$            | $0$ m $ 0.02$ s |
| $11$            | $0$ m $ 0.05$ s |
| $12$            | $0$ m $ 0.12$ s |
| $13$            | $0$ m $ 0.44$ s |
| $14$            | $0$ m $ 1.55$ s |
| $15$            | $0$ m $ 5.52$ s |
| $16$            | $0$ m $ 19.85$ s |
| $17$            | $1$ m $ 11.22$ s |
| $18$            | $4$ m $ 22.67$ s |
| $19$            | $15$ m $ 58.54$ s |
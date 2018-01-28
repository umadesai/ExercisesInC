/* Notes on Experiments with Optimization
*
* Looking at the assembly language output after adding the "int x = 5" line of code, you can
* see a corresponding line of code "movl $5, -4(%rbp)"" that moves the value 5 between registers.
* Once you turn on optimization using the flag -02, the corresponding line of code in the assembly
* language output is no longer as apparent, with no clear value 5, because there are other actions
* happening like logic operations.
*
* After modifying the printf statement to print x, compiling it with and without optimization
* again showed a difference in operations. There were noticably fewer xorl commands and, similarly
* to the previous optimization, there was a new xorl operation involved.
*
* Adding "int y = x + 1" made a clear distinction between the assembly language with and without optimization.
* The optimized assembly code skips the addl operation for x + 1 by starting with a register value of 6
* instead of 5. The optimized code takes significantly less steps and is 7 lines shorter.
*
* Overall, each of these experiments with optimization show a clear theme around optimization shortening
* the assembly language output by using more efficient processes and combining tasks. This is exemplified
* by the way that optimization in the last experiment was able to save a step by setting a value incremented
* by 1 to a register rather than doing an addition operation on the original x.
*/

#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%d\n",y);
    return 0;
}

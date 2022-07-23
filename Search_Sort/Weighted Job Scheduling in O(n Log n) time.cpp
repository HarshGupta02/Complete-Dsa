


1,2,50
3,5,20
6,19,100
2,100,200


/*

//  total sum = 370

l = 0 , h = 370 , m = 185

l = 186 , h = 370 , m = 278

l = 186 , h = 277 , m = 231

l = 187 , h = 



let's think greedy

1 .sort on basis of max profit

{2,100,200} {6,19,100} {1,2,50} {3,5,20}

{2,100,200} {6,19,100} {20,30,100} {31,40,100} {41,50,100}
// so to gain max profit , we lost such a big interval which could give better profits.


2 . try to do more jobs which could increase profit

=> sort on the basis of finish time

{1,2,50} {3,5,20} {6,19,100} {2,100,200}

not works here max profit = 170 (not the maximum).


3. recursive approach as we choose jobs as a subsequence of the jobs array and each job can
either be selected or not selected (0/1).

    {1,2,50} {3,5,20} {6,19,100} {2,100,200}

    time = O(2 ^ N)

4 . dp approach as we can see overlapping subproblems.

5 . binary search on profit . if we can have x as profit then can we have x + 1 as profit 
or not.

*/





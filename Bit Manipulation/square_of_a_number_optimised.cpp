/*
if n is odd so n = 2 * x + 1 so n^2 = 4 * x ^ 2 + 4 * x + 1;
else n = 2 * x , so n ^ 2 = 4 * x ^ 2;
*/

int square(int num){
    if(num == 0) return 0;
    if(num < 0) num = -1 * num;
    int x = num >> 1;
    if(num & 1) return ((square(x) << 2) + (x << 2) + 1);
    else return (square(x) << 2);
}

int calculateSquare(int num)
{
    return square(num);
}
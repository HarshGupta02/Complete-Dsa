/// HERE WE KNOW THAT IF I HAVE TO REACH X FROM ARR[I] I NEED TO JUMP = ABS(ARR[I] - X) DISTANCE
/// AND EACH JUMP CONTRIBUTES K DISTANCES SO I WILL DIRECTLY JUMP = ABS(ARR[I] - X)/K NUMBER OF
// JUMPS AND THEN START SEARCHING FOR MY KEY(x).

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while(i < n){
        if(arr[i] == x) return i;
        i += max(1 , abs(arr[i] - x)/k);
    }
    return -1;
}
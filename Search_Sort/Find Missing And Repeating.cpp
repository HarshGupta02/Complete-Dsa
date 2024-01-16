/// METHOD 1: TIME = O(N) , SPACE = O(1)
// NOT PREFERRED AS MODIFIES THE ARRAY


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *a = new int[2];
        int repeating;
        for(int i = 0; i < n ; i ++){
            if(arr[abs(arr[i]) - 1] < 0 or (arr[abs(arr[i]) - 1] == abs(arr[i]) and i != abs(arr[i]) - 1)){
                repeating = abs(arr[i]); break;
            }
            arr[abs(arr[i]) - 1] *= -1;
        }
        long long int total_sum = 0;
        for(int i = 1; i <= n ; i++) total_sum += i;
        long long int curr_sum = 0 ;
        for(int i = 0 ; i < n ; i ++) curr_sum += abs(arr[i]);
        long long int missing  = total_sum - (curr_sum - repeating);
        a[0] = repeating; a[1] = missing;
        return a;
    }
};


// METHOD 2 : TIME = O(N) , SPACE = O(1); FIND DUPLICATE AND MISSING NUMBER

/*

HERE WE FIRST FOUND OUT THE XOR OF ALL THE GIVEN NUMBERS AND NUMBER FROM 1 TO N INCLUSIVE. SO WE
GET A RESULT AS THE XOR OF MISSING NUMBER AND THE REPEATED NUMBER BECAUSE MISSING NUMBER CANNOT 
FIND A PAIR TO CANCEL WITH AND THE REPEATING NUMBER FOUND 2 DUPLICATES , ONE OF WHICH GOT
CANCELLED AND ONE GOT LEFT.

SO M ^ R = X(XORING ALL ARR[I] AND I).  WHERE M = MISSING NUMBER , R = REPEATING NUMBER

SO NOW WE KNOW THAT ONE BIT HAS TO BE SET IN X BECAUSE IF ALL ARE ZERO THEN M HAS TO EQUAL TO R
BUT NEVER POSSIBLE. SO WE DIVIDE ALL THE ELEMENTS(ARR[I] , I) INTO 2 BASKETS WITH ALL THE ELEMENTS
HAVING UNSET BIT AT A PARTICULAR CHOSEN POSITION AND ANOTHER BASKET HAVING BITS SET AT THAT
PARTICULAR CHOSEN POSITION. DO THE XOR OF ALL THE ELEMENTS IN EACH BUCKET. WE GET TWO NUMBERS
BUT DON'T KNOW WHICH IS MISSING AND WHICH IS REPEATING. SO WE LINEARLY TRAVERSE AND IF WE FIND
EITHER BASKET1 OR BASKET2 THEN IT HAS TO REPEATING AND OTHER BASKET BECOMES MISSING.

*/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *a = new int[2];
        int Xor = 0;
        for(int i = 0; i < n ; i ++){
            Xor ^= (arr[i] ^ (i + 1));
        }
        /// M ^ R = Xor , where M = missing number , R = repeating number
        int temp = Xor , idx = 0;
        while(!(temp & 1)){
            temp >>= 1; idx ++;
        }
        int basket_1 = 0 , basket_2 = 0; // basket_1 has all the idx th bit as 0 and basket_2 has 1.
        for(int i = 0 ; i < n ; i ++){
            int curr = arr[i];
            if((curr >> idx) & 1) basket_2 ^= arr[i];
            else basket_1 ^= arr[i];
            curr = i + 1;
            if((curr >> idx) & 1) basket_2 ^= (i + 1);
            else basket_1 ^= (i + 1);
        }
        // now basket_1 or basket_2 can be missing and repeating or vice versa.
        bool found = false;
        for(int i = 0; i < n ; i ++){
            if(basket_1 == arr[i]){
                found = true;
                break;
            }
        }
        if(found){
            a[0] = basket_1 , a[1] = basket_2;
        }else{
            a[0] = basket_2 , a[1] = basket_1;
        }
        return a;
    }
};

// OR

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xorr = 0;
        for(int i = 0; i < n; i ++) {
            xorr ^= (i + 1);
            xorr ^= arr[i];
        }
        int number = xorr & ~(xorr - 1);
        int b1 = 0, b2 = 0;
        for(int i = 0; i < n; i ++) {
            if((arr[i] & number) != 0) b1 ^= arr[i];
            else b2 ^= arr[i];
            if(((i + 1) & number) != 0) b1 ^= (i + 1);
            else b2 ^= (i + 1);
        }
        for(int i = 0; i < n; i ++) {
            if(arr[i] == b1) return {b1, b2};
        }
        return {b2, b1};
    }
};

// METHOD 3: ALL REPEATING TWICE EXCEPT TWO NUMBERS => JUST SAME AS FIND MISSING AND 
// DUPLICATE NUMBER. IN ABOVE METHOD THE XOR THAT WE DID WITH ARR[I] AND I, IT IS
// ACTUALLY SAME THING AS ALL REPATING TWICE EXCEPT TWO NUMBERS.


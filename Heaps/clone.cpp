ll mod_add(ll a,ll b){
    if(a+b<=MOD)
     return a+b;
    return ((a+b+MOD)%MOD);
}

ll mod_sub(ll a,ll b){
    if(a-b<=MOD)
     return a-b;
    return ((a-b+MOD)%MOD);
}

ll mod_mul(ll a,ll b){
    if(a*b<=MOD)
     return a*b;
    return ((a*b+MOD)%MOD);
}

const ll n=10000000;
bitset<10000000>b; // saves a lot of space
// if a number is less than n just check b[n] if 1 so prime
vector<ll>primes;

void bitset_sieve(){
    b.set(); // set all the bits to 1.
    b[0]=b[1]=0;/// means not prime.
    for(ll i=2;i<n;i++){
        if(b[i]){
            for(ll j=i*i;j<n;j+=i){
                b[j]=0;
            }
        }
    }
    for(ll i=2;i<n;i++)
    {
        if(b[i])
         primes.push_back(i);
    }
}

bool isprime(ll No) // for large values of n to check if it is prime
{
    if(No<=n)
     return b[No]==1?true:false;
    for(ll i=0;primes[i]*(ll)primes[i]<=No;i++){
       if(No%primes[i]==0)
          return false;
    }
    return true;
}
const int MAXN=1000001;
vector<int>euler;

void precompute(){
    euler[0]=0;
    euler[1]=1;
    for(int i=2;i<=MAXN;i++)
     euler[i]=i-1;
    for(int i=2;i<=MAXN;i++){
        for(int j=i+i;j<=MAXN;j+=i){
            euler[j]-=euler[i];
        }
    }
}

int x,y,GCD;
void ExtendedEuclid(int a,int b){
    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    } 
    ExtendedEuclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*y;
    x=cx;
    y=cy;
}

int InverseModulo(int a,int m){
    ExtendedEuclid(a,m);
    return (x+m)%m; // x=b which is the multiplicative modulo 
    // inverse
}

vector<ll>v; // global vector which stores all prime numbers
// upto n as entered by user.
void prime_sieve(int *p,int n){
    for(int i=3;i<n+1;i+=2){
        p[i]=1; // marking one means prime
    }
    for(ll i=3;i<n+1;i+=2){
        if(p[i]==1){
            for(ll j=i*i;j<n+1;j+=i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[0]=p[1]=0;
    for(ll i=0;i<n+1;i++){
        if(p[i]==1)
         v.push_back(i);
    }
}

// gcd properties
// 1. gcd(a,b)=gcd(b,a%b);
// 2. gcd(a,b)=gcd(a,b-a); 
// 3. gcd(a,b)=gcd(a,b+a);
// 4. gcd(a,b)=gcd(a+b,b);
// 5. gcd(a,b)=gcd(a-b,b);
// 6. a%b = a-[a/b]*b;
// 7. gcd(even,odd)= it means that if we multiply power of 2 to even value ,the gcd won't change
// 8. gcd(a,0)=a;
// 9. gcd(lcm(ai,aj),lcm(ai,aj+1),lcm(ai,aj+2)...))= lcm(ai,gcd(aj,aj+1,aj+2));
// 10.gcd(a1,a2,a3.....,an)=gcd(a1,gcd(a2-a1,a3-a2,a4-a3...))
// Goldbach's Conjecture = it states that all even whole number can be represented as sum of 2 prime numbers
// it holds for all numbers <= 4 * 1e18.
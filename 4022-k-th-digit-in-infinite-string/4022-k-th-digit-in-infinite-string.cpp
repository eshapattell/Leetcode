class Solution {
public:
    int kthDigit(long long k) {
        if(k <= 9){
            return k;
        }
        k-=9;
        long long p=1;

        for(int i=2;i <= 15;i++){
            long long blocks= 9*p;
            long long len= blocks *10 * i;

            if(k> len){
                k-=len;
                p*= 10;
                continue;
            }

            long long block = (k-1) /(10*i);
            long long pos =(k-1) %(10 * i);

            long long actual= p+block;

            long long index= pos/i;
            int digit= pos% i;

            long long num;

            if(actual %2 == 0){
                num =10* actual +index;
            }else{
                num= 10* actual +9 - index;
            }
            return to_string(num)[digit]- '0';
        }
        return -1;
    }
};
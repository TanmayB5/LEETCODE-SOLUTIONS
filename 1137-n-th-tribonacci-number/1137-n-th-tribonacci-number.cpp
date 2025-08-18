class Solution {
public:
    int tribonacci(int n) {
        int first = 0 , second = 1;
        int third = 1;
        if(n==0){return first;}
        if(n==1 || n==2){return second;}
        int temp =3;
        int curr = 0;
        while(temp<=n){
            curr = first + second + third;
            first  = second;
            second = third;
            third = curr;
            temp++;
        }
        return curr;
    }
};
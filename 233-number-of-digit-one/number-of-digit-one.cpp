class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        if(n < 10) return 1;
        
        
        int digits = 0;
        int temp = n;
        while(temp > 0) {
            digits++;
            temp /= 10;
        }
        
        
        int power = 1;
        for (int i = 1; i < digits; i++) {
            power *= 10;
        }
        
       
        int msd = n / power;
        int remainder = n % power;
        
        
        int onesForLowerDigits = (digits - 1) * (power / 10);
        
        
        if(msd == 1) {
           
            return onesForLowerDigits + (remainder + 1) + countDigitOne(remainder);
        } else {
            
            return msd * onesForLowerDigits + power + countDigitOne(remainder);
        }
    }


        
    
};
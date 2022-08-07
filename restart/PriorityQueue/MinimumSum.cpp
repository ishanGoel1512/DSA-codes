
    string solve(int arr[], int n) {
  string f="";
        string s="";
        sort(arr,arr+n);
        if(n==1){
            return to_string(arr[0]);
        }
        for(int i=0;i<n;i++){
            if(i%2==0)
              f+=to_string(arr[i]);
            else
              s+=to_string(arr[i]);
        }
       
         string sum="";
         int c=0;
         int i=f.size()-1;
         int j=s.size()-1;
         while(i>=0 and j>=0){
             int x=f[i]-'0';
             int y=s[j]-'0';
             int l=(x+y+c)%10;
             c=(x+y+c)/10;
             sum+=to_string(l);
             i--;
             j--;
         }
         while(i>=0){
             int x=f[i]-'0';
             int l=(x+c)%10;
             c=(x+c)/10;
             sum+=to_string(l);
             i--;
         }
         while(j>=0){
             int y=s[j]-'0';
             int l=(y+c)%10;
             c=(y+c)/10;
             sum+=to_string(l);
             j--;
         }
         if(c!=0){
             sum+=to_string(c);
         }
         
         string final="";
         int h=sum.size()-1;
         while(h>=0 and sum[h]=='0'){
             h--;
         }
         for(;h>=0;h--){
             final+=sum[h];
         }
         
         return final;        
    }
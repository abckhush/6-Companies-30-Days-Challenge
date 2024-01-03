 vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>v(n,0);
       int mis = 0; // Initialize to an invalid value
        int rep = 0; // Initialize to an invalid value

        for(int i=0;i<n;i++){
            v[arr[i]-1]++;
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
                mis=i+1;
            }
            else if(v[i]==2){
                rep=i+1;
            }
        }

        return {rep, mis};
    }

int mod=1e9+7;

class Solution {
public:
    long long modexp(long long x, long long y) 
    { 
        int res = 1;    
        x = x % mod;   
        if (x == 0) return 0;
        while (y > 0) 
        { 
            if (y & 1) 
                res = (res*x) % mod; 
            y = y>>1;
            x = (x*x) % mod; 
        } 
        return res; 
    } 

    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        if(m==1) return nums;

        int n=nums.size();
        vector<pair<int,int>> list(n);
        for(int i=0; i<n; i++) list[i].first=nums[i], list[i].second=i;
        vector<int> raise(n, 0);

        sort(list.begin(), list.end());
        if(n>1)
        {
            int l=1, r=list[n-1].first;
            int req=0;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                int count=0;
                for(int i=0; i<n; i++)
                {
                    int x=list[i].first;
                    int z=floor((log2(mid)-log2(x))/log2(m)+1e-6);
                    if(z<=0) break;
                    count+=z;
                }
                if(count>k) r=mid-1;
                else if(count<k)
                {
                    req=max(req, mid);
                    l=mid+1;
                }
                else
                {
                    req=max(req, mid);
                    break;
                }
            }

            for(int i=0; i<n && k>0; i++)
            {
                int x=list[i].first;
                int z=floor((log2(req)-log2(x))/log2(m)+1e-6);
                if(z<=0) break;
                raise[i]+=z;
                k-=z;
            }
        }



        for(int i=0; i<n; i++)
        {
            list[i].first*=modexp(m, raise[i]);
        }

        sort(list.begin(), list.end());
        
        int a=k/n, b=k%n;
        // vector<pair<int,int>> list(ord.begin(), ord.end());

        for(int i=0; i<b; i++)
        {
            list[i].first=(list[i].first*modexp(m, a+1))%mod;
        }
        for(int i=b; i<n; i++)
        {
            list[i].first=(list[i].first*modexp(m, a))%mod;
        }

        for(auto &el:list) nums[el.second]=el.first;

        return nums;
    }
};
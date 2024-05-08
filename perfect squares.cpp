bool isSquare(int n){
        
        if(n < 0) return false;
        
        long long sr = sqrt(n);
        
        return sr * sr == n;
    }
    
    int numSquares(int n) {
        
        int min = INT_MAX, shortestPath[n + 1];
        stack<int> St;
        
        if(isSquare(n)) return 1;
        
        for(int num = 0; num < n; num++) shortestPath[num] = INT_MAX;
        
        St.push(n);
        
        while(!St.empty()){
            int r = St.top();
            St.pop();
            
            if(r == 0) if(min > shortestPath[r]) min = shortestPath[r];
            
            if(r < 0) continue;
            
            else{
                
                for(int num = 1; num * num <= r; num++){
                    
                    if(shortestPath[r - num * num] > shortestPath[r] + 1)
                    
                        shortestPath[r - num * num] = shortestPath[r] + 1;
                    
                    St.push(r - num * num);
                    
                }   
            }
        }
        
        return min;
            
    }

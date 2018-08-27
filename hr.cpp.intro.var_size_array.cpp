#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    size_t size = 100000;
    vector<vector<int>> VECT;
    
    /*
    The first line contains two space-separated integers denoting the respective values of  (the number of variable-length arrays) and  (the number of queries). 
    */
    int n, q;
    cin >> n >> q;
    
    /*
    Each line  of the  subsequent lines contains a space-separated sequence in the format 
    k a[i]0 a[i]1 … a[i]k-1 describing the -element array located at . 
    */
    int k, data;
    
    //cout << endl << "DEBUG: n=" << n << "; q=" << q;
    
    for (int i=0; i< n; i++){
        cin >> k;
        //cout << endl << "DEBUG: i=" << i << "; k=" << k << endl;
        vector<int> VECT_INNER;
        for (int j=0; j<k; j++){
            cin >> data;
            //cout << "DEBUG: j=" << j << "; data=" << data << endl;
            VECT_INNER.push_back(data);
        }

        /*
        cout << endl << "DEBUG: The INNER array contents are:";
        cout << endl << "DEBUG: VECT_INNER.size()=" << ((int)VECT_INNER.size()) << endl;
        for (int j=0; j<k; j++){
            cout << "  VECT_INNER[" << j << "]=";
            cout << VECT_INNER[j];
        }
        cout << endl;
        */
        
        VECT.push_back(VECT_INNER);
    }

    /*
    DEBUG: comment it out when submitting
    */
    /*
    cout << endl << "DEBUG: The OUTER array contents are:";
    for (int i=0; i<n; i++){
        cout << endl << "DEBUG: VECT[" << i << "].size()=" << VECT[i].size() << endl;
        for (int j=0; j<VECT[i].size(); j++){
            cout << VECT[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    
    /*
    Each of the  subsequent lines contains two space-separated integers describing 
    the respective values of  
    (an index in array ) and  (an index in the array referenced by ) for a query.
    */
    int target_vect, target_vect_index;
    for (int i=0; i<q; i++){
        cin >> target_vect >> target_vect_index;
        cout << VECT[target_vect][target_vect_index] << endl;
    }
    
    return 0;
}


// How do we use custom data structs and still have comparison abilities in sorting/ priority queue

// 1st method
struct special_int {
    int x;
    special_int(int _x) {
        x = _x;
    }
    // Create an operator overload
    bool operator < (const special_int& b) const {
        return x > b.x;
    }
};

// 2nd method - use pairs
auto i = make_pair(0, make_pair(1, 1)); // 0 will be used as the comparison integer



// Juggle priority 

int main () {
    priority_queue<pair<int, string > , vector<pair<int, string>>, greater<pair<int, string>>> juggle;
    juggle.push(make_pair(0, "CHINCHIN"));
    juggle.push(make_pair(0, "TSUNDERE"));
    
    // CHINCHIN will increase by 3 every iteration
    // TSUNDERE will increase by 5 every iteration.
    
    // Whichever has a smaller value will take priority first
    
    for (int i = 0; i < 5; i++) {
        auto out = juggle.top();
        cout << out.first << " " << out.second << endl;
        juggle.pop();
        if (out.second == "CHINCHIN") out.first += 3;
        else out.first += 5;
        
        juggle.push(out); // push it back
    }
}


// Convert int to string 

string itos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}


// Add multiple actions in a while loop while only caring about the last condition

int main () {
    int n, t;
    // This will only care about the second condition in the while loop, that is it will break when n == t
    while (scanf("%d %d", &n, &t), (n == t)) {
        // Perform operations here 
    }
}



// Custom comparator functions 

// Create the comparator function
// This will only compare the first value of the pairs
bool comparePairs (const pair<int, int> &lhs, pair<int, int> &rhs) {
    return lhs.first > rhs.first;
}

// Create the comparator function for sets
class compare {
public:
    bool operator()(const int lhs,const int rhs) const {
        return lhs > rhs; // When this is true, it will trigger the sort/ swap
    }
};

// Note that we cannot compare by the second of map similar to sets
class compare_map {
public:
    bool operator()(const int lhs,const int rhs) const {
        return lhs > rhs;
    }
};

// Compare only second value of PQ
class compare_pq {
public:
    bool operator()(const pair<int, int> lhs,const pair<int, int> rhs) const {
        return lhs.second > rhs.second;
    }
};


int main () {
    // Syntax 
    vector<pair<int, int > > test;
    set<int, compare> test_set;
    map<int, int, compare_map> test_map;
    priority_queue<pair<int, int>, vector<pair<int, int>> , compare_pq> test_pq;

}

// Unique identification and removal in hash table

void remove_key (int key, unordered_map<int, int> * myMap) {
    // If key does not exist, return
    if (myMap->find(key) == myMap->end()) return;
    // Remove the key
    myMap->at(key)--;
    // If key turns to ZERO, completely erase it
    if (myMap->at(key) == 0) {
        myMap->erase(key);
    }
}


int main () {
    unordered_map<int, int> countUnique;
    
    for (int i = 0 ; i < 6; i++) {
        countUnique[testcase[i]]++;
    }
    cout << countUnique.size() << endl; // 4 unique values

    remove_key(3, &countUnique);
    remove_key(3, &countUnique);

    cout << countUnique.size() << endl; // Only 3 unique values left

}

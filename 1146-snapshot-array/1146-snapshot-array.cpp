class SnapshotArray {
public:
    int id;
    vector<vector<pair<int, int>>> arr;
    SnapshotArray(int length) {
        id = 0;
        arr.resize(length);
        for (int i = 0; i < length; ++i) {
            arr[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        if(arr[index].back().first==id){
            arr[index].pop_back();
        }
        arr[index].push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        int st=0,end=arr[index].size()-1,ans;
        while(end>=st){
            int mid=(st+end)/2;
            if(arr[index][mid].first>snap_id){
                if(end==st){
                    break;
                }
                end=mid;
                continue;
            }
            else if(arr[index][mid].first<snap_id){
                ans=arr[index][mid].second;
                st=mid+1;
                continue;
            }
            else if(arr[index][mid].first==snap_id){
                return arr[index][mid].second;
            }
        }
        return ans;
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
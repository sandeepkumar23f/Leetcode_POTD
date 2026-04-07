class Robot {
public:
    int idx=0;
    vector<vector<int>> path;
    bool moved=false;
    Robot(int width, int height) {
        // Bottom Row (L to R) -> East(0)
        for(int x=0; x<width; x++){
            path.push_back({x,0,0});
        }
        // Right Col (bottom to top) -> North(1)
        for(int y=1; y<height; y++){
            path.push_back({width-1,y,1});
        }
        // Top row (right to left) -> West(2)
        for(int x=width-2; x >= 0; x--){
            path.push_back({x,height-1,2});
        }
        // Left column (top to bottom ) -> South(3)
        for(int y=height-2; y>0; y--){
            path.push_back({0,y,3});
        }
        path[0][2]=3; // make it South for handkling corner case when it comes to (0,0) after moving 
    }
    
    void step(int num) {
        moved = true;
        idx = (idx+num) % path.size();
    }
    
    vector<int> getPos() {
        return {path[idx][0],path[idx][1]};
    }
    
    string getDir() {
        if(!moved){
            return "East";
        }
        int d = path[idx][2];
        if(d==0) return "East";
        else if(d==1) return "North";
        else if(d==2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
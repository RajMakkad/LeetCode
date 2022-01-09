class Solution {
    void go(int &x,int &y,int &d){
        if(d == 0) y++; // N
        if(d == 1) x++; // E
        if(d == 2) y--; // S
        if(d == 3) x--; // W
    }

    void turn(int &d,char &direction){
        if(direction == 'R') d = (d + 1)%4;
        else d = (d + 3)%4;
    }
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int d = 0;

        for(auto &i:instructions){
            if(i == 'G') go(x,y,d);
            else turn(d,i);
        }

        bool circle = false;
        if(d) circle = true;
        else if(x == 0 and y == 0) circle = true;

        return circle;
    }
};
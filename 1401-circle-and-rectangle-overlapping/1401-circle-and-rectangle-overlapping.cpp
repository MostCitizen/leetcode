class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closetX = clamp(xCenter, x1, x2);
        int closetY = clamp(yCenter, y1, y2);
        int diffX = closetX - xCenter;
        int diffY = closetY - yCenter;
        return radius * radius >= diffX * diffX + diffY * diffY;
    }
};
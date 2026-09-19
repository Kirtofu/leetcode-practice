class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // 找到在矩形中的到圆心 (xCenter, yCenter) 最近的点 (x, y)
        int x = clamp(xCenter, x1, x2);
        int y = clamp(yCenter, y1, y2);
        // 判断 (x, y) 是否在圆中
        return (x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) <= radius * radius;
    }
};
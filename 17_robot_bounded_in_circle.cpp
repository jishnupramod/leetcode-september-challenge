/*
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

    "G": go straight 1 unit;
    "L": turn 90 degrees to the left;
    "R": turn 90 degress to the right.

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.

Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...

 

Note:

    1 <= instructions.length <= 100
    instructions[i] is in {'G', 'L', 'R'}
*/



class Solution {
public:
    // Making code concise is pending...
    bool isRobotBounded(string instructions) {
        int x = 0, y = 1;
        int posX = 0, posY = 0;
        for (char i : instructions) {
            if (i == 'L') {
                if (x == 0 and y == 1) {
                    x = -1;
                    y = 0;
                }
                else if (x == -1 and y == 0) {
                    x = 0;
                    y = -1;
                }
                else if (x == 0 and y == -1) {
                    x = 1;
                    y = 0;
                }
                else if (x == 1 and y == 0) {
                    x = 0;
                    y = 1;
                }
            } else if (i == 'R') {
                if (x == 0 and y == 1) {
                    x = 1;
                    y = 0;
                }
                else if (x == -1 and y == 0) {
                    x = 0;
                    y = 1;
                }
                else if (x == 0 and y == -1) {
                    x = -1;
                    y = 0;
                }
                else if (x == 1 and y == 0) {
                    x = 0;
                    y = -1;
                }
            } else if (i == 'G') {
                if (x == 0 and y == 1)
                    ++posY;
                else if (x == -1 and y == 0)
                    --posX;
                else if (x == 0 and y == -1)
                    --posY;
                else if (x == 1 and y == 0)
                    ++posX;
            }
        }
        if (posX == 0 and posY == 0)
            return true;
        if (x == 0 and y == 1)
            return false;
        return true;
    }
};

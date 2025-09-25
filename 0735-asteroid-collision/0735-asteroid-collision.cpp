class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int asteroid : asteroids) {

            bool moveRight = asteroid > 0;
            bool moveLeft = asteroid < 0;

            // case #1: add elm to stack if stack is empty
            if (stack.empty()) {
                stack.push_back(asteroid);
            }

            // case #2: if both are heading to the same direction, add asteroid
            else if (stack.back() > 0 && moveRight || stack.back() < 0 && moveLeft) {
                stack.push_back(asteroid);
            }

            // case #3: if one are heading to opposite direction and are the same size, collision!
            else if (stack.back() > 0 && moveLeft && abs(stack.back()) == abs(asteroid)) {
                stack.pop_back();
            }

            // case #4: last elm in stack and asteroid are moving <-a b->
            else if (stack.back() < 0 && asteroid > 0) {
                stack.push_back(asteroid);
            }

            // case #5: last elm in stack are losing with asteroid
            else {
                while (!stack.empty() && abs(stack.back()) < abs(asteroid)) {
                    if ((stack.back() < 0 && asteroid < 0) || (stack.back() > 0 && asteroid > 0)) break;
                    stack.pop_back();
                }

                // if asteroid wins, insert asteroid
                if (stack.empty()) {
                    stack.push_back(asteroid);
                }
                // if last elm are moving with the same direction, add asteroid
                else if ((stack.back() < 0 && asteroid < 0) || (stack.back() > 0 && asteroid > 0)) {
                    stack.push_back(asteroid);
                }
                // if last elm and stack are collided
                else if (stack.back() > 0 && moveLeft && abs(stack.back()) == abs(asteroid)) { 
                    stack.pop_back();
                }
            }
        }

        return stack;
    }
};
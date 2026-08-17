class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survived;

        for (int asteroid : asteroids) {
            bool alive = true;
            while (alive && asteroid < 0 && !survived.empty() && survived.back() > 0) {
                int previous = survived.back();
                if (previous < -asteroid) survived.pop_back();
                else if (previous > -asteroid) alive = false;
                else {
                    survived.pop_back();
                    alive = false;
                }
            }

            if (alive) survived.push_back(asteroid);
        }

        return survived;
    }
};

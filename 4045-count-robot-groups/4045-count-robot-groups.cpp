class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {

        int n = position.size();

        // Initially rightmost robot khud ek group hai
        int groups = 1;

        // IMPORTANT:
        // Current group ki speed = RIGHTMOST robot ki speed
        int curSpeed = speed[n - 1];

        // RIGHT -> LEFT traverse kar rahe hain
        for (int i = n - 2; i >= 0; i--) {

            // Current robot aur right-side group ke beech ka gap
            int gap = position[i + 1] - position[i];

            /*
                MERGE tab hoga agar koi ek condition true ho:

                1. gap <= distance
                   -> Already merging distance ke andar hain

                OR

                2. speed[i] > curSpeed
                   -> Left robot faster hai
                   -> Eventually right group ko catch karega
            */
            if (gap <= distance || speed[i] > curSpeed) {

                // MERGE
                // curSpeed change nahi hogi
                // because merged group's speed
                // RIGHTMOST robot ki speed hoti hai

                continue;
            }

            /*
                Dono conditions false:

                gap > distance
                AND
                speed[i] <= curSpeed

                -> Left robot current group ko catch nahi karega
                -> NEW GROUP
            */
            groups++;

            // New group bana hai.
            // Current robot ab is group ka RIGHTMOST robot hai.
            // Isliye group ki speed = speed[i]
            curSpeed = speed[i];
        }

        return groups;
    }
};
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target){
        Map<Integer,Integer> number = new HashMap<>();
        int idx = 0;
        for (int num : nums) {
            int comp = target-num;
            if (number.containsKey(num)){
                return new int[] { number.get(num), idx};
            }
            number.put(comp,idx);
            idx+=1;
        }
        return new int[0];
    }
}

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(intervals.length == 0) return new int[][] {newInterval};
        List<int[]> list = new ArrayList<>();
        int start = newInterval[0], end = newInterval[1];
        int index = 0;
        for(int i=0;i<intervals.length;i++){
            if(start == -1 && end == -1){
                list.add(intervals[i]);
            } else if(intervals[i][0] <= end && end <= intervals[i][1]){
                start = Math.min(start, intervals[i][0]);
                end = intervals[i][1];
            } else if(end < intervals[i][0]){
                list.add(new int[]{start, end});
                list.add(intervals[i]);
                start = -1;
                end = -1;
            } else if(intervals[i][0] <= start && start <= intervals[i][1]){
                start = intervals[i][0];
            } else if(!(start < intervals[i][0] && intervals[i][1] < end)){
                list.add(intervals[i]);
            }
        }
        if(start != -1 && end != -1){
            list.add(new int[]{start, end});
        }
        int res[][] = new int[list.size()][2];
        for(int i=0;i<list.size();i++){
            res[i] = list.get(i);
        }
        return res;
    }
}
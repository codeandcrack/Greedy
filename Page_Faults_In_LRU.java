
class Solution{
    
    static boolean next;
    
    public static int index_helper(int[] queue, int[] last_used, int page){

        int ret_idx = 0;

        for(int i = 0;i<queue.length;i++){

            if(queue[i] == page){
                next = true;
                return i;
            }else if(queue[i] == -1){
                next = false;
                return i;
            }

            if(last_used[ret_idx] > last_used[i]){
                ret_idx = i;
            }
        }
        return ret_idx;
    }

    static int pageFaults(int N, int C, int[] pages){
        // code here
        int[] queue = new int[C];
        int[] last_used = new int[C];

        Arrays.fill(queue, -1);
        int ptr = 0;

        int total_page_fault = 0;
        int count = 0;

        for(int i : pages){
            next = false;
            ptr = index_helper(queue, last_used, i);

            if (!next) {
                total_page_fault++;

                queue[ptr] = i;
            }

            last_used[ptr] = count;

            count++;
        }
        return total_page_fault;
    }
}


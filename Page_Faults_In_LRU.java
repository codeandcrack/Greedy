Deque<Integer> deque = new ArrayDeque<>();
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (deque.contains(pages[i])) {
                // If page is already in the deque, remove it and add it to the end (most recently used)
                deque.remove(pages[i]);
                deque.addLast(pages[i]);
            } else {
                // Page fault occurs
                count++;
                if (deque.size() == C) {
                    // If deque is full, remove the least recently used page
                    deque.removeFirst();
                }
                // Add the new page to the deque
                deque.addLast(pages[i]);
            }
        }

        return count;
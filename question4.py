#Amylea
#1123552
#2024.11.28
import heapq

# Function to schedule tasks with maximum profit
def schedule_tasks(tasks, N):
    # Sort the tasks by profit in descending order, and then by deadline in ascending order
    tasks.sort(key=lambda x: (-x[0], x[1]))

    # Keep track of the available slots
    # The available slots will be tracked using a max-heap based on task deadlines
    max_profit_heap = []
    total_profit = 0
    scheduled_tasks = []

    # Go through tasks in order of their profit (largest to smallest)
    for profit, deadline in tasks:
        # Find the most recent available slot for this task
        if len(max_profit_heap) < deadline:
            # If there are free slots, we can simply add the task
            heapq.heappush(max_profit_heap, profit)
            total_profit += profit
            scheduled_tasks.append(profit)
        else:
            # If there are no free slots, but this task has a higher profit than the smallest in the heap
            if max_profit_heap and max_profit_heap[0] < profit:
                # Replace the least profitable task with the current task
                total_profit -= heapq.heappop(max_profit_heap)
                heapq.heappush(max_profit_heap, profit)
                total_profit += profit
                # Replace the last task in the scheduled list with the newly scheduled one
                scheduled_tasks[-1] = profit

    return total_profit, scheduled_tasks

# Input
N = int(input())
tasks = [tuple(map(int, input().split())) for _ in range(N)]

# Output the results
max_profit, scheduled_tasks = schedule_tasks(tasks, N)
print(f"Maximum Profit: {max_profit}")
print(f"Scheduled Tasks: {scheduled_tasks}")

#Amylea
#1123552
#2024.11.28
import heapq

def merge_k_sorted_arrays(k, arrays):
    # Initialize the min heap
    min_heap = []
    
    # Step 1: Insert the first element of each array into the min heap
    for i in range(k):
        if arrays[i]:  # if the array is not empty
            heapq.heappush(min_heap, (arrays[i][0], i, 0))  # (value, array index, element index)
    
    merged_array = []
    
    # Step 2: Process the heap and merge the arrays
    while min_heap:
        value, array_index, element_index = heapq.heappop(min_heap)
        merged_array.append(value)
        
        # Step 3: If there is another elem ent in the same array, insert it into the heap
        if element_index + 1 < len(arrays[array_index]):
            next_value = arrays[array_index][element_index + 1]
            heapq.heappush(min_heap, (next_value, array_index, element_index + 1))
    
    return merged_array

# Input: number of arrays and the arrays themselves
k = int(input())  # Number of arrays
arrays = []

for _ in range(k):
    arrays.append(list(map(int, input().split())))

# Output: merged sorted array
result = merge_k_sorted_arrays(k, arrays)
print("Merged Array:", result)

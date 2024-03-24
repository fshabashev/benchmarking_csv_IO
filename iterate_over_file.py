import time

time_before = time.time()

# open the files according to the last column value
file_objects = [open(f"./data_output/output32gb_{i}.csv", "w") for i in range(10)]

cnt = 0
with open("./data/output32gb.csv", "r") as f:
    for i, line in enumerate(f):
        if i == 0:
            columns = line.strip().split(",")
            print(f"Columns: {columns}")
        else:
            data = line.strip().split(",")
            int_column = int(data[-1])
            output_file_ind = int_column % 10
            # write row to the corresponding output file
            file_objects[output_file_ind].write(",".join(data) + "\n")
            cnt += 1
            if cnt % 10_000_000 == 0:
                print(f"Row {cnt}: {data}, time taken since start: {time.time() - time_before} seconds")
print(f"Number of rows: {cnt}")     
# close the files
for file_obj in file_objects:
    file_obj.close()
time_after = time.time()

print(f"Time taken: {time_after - time_before} seconds")
import pandas as pd
import numpy as np
import string
import random

# Function to generate a random string
def random_string(length=10):
    letters = string.ascii_letters
    return ''.join(random.choice(letters) for i in range(length))

# Function to generate random data for the CSV
def generate_random_data(rows=100, cols=5):
    for _ in range(rows):
        row = [random_string(10) for _ in range(cols-1)]  # Generate random strings for cols-1
        row.append(np.random.randint(0, 100))  # Add a random integer in the last column
        yield row

# Column names
columns = ['Column_' + str(i) if i < 4 else 'Integer_Column' for i in range(1, 6)]

# Generate random data
data = generate_random_data(rows=800_000_000)

# write data to a CSV file line by line
with open('./data/output32gb.csv', 'w') as f:
    f.write(','.join(columns) + '\n')  # Write the column names
    cnt = 0
    for row in data:
        f.write(','.join(map(str, row)) + '\n')  # Write the row
        if cnt % 5_000_000 == 0:
            print(f"Row {cnt}: {row}")
        cnt += 1
#!/bin/bash

# Define the list of input parameters
PARAMETERS=(4 8 12 16 24 32 48 64)

# Loop through the list of parameters and call the executable with each one
for param in "${PARAMETERS[@]}"
do
  ./exec "$param"
done
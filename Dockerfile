# Use an official gcc runtime as a parent image
FROM gcc:4.9

# Set the working directory to /app
WORKDIR /binary-search/src

# Copy the current directory contents into the container at /app
COPY . /binary-search

# Install any needed packages specified in requirements.txt
RUN make binary_tree

# Make port 80 available to the world outside this container
EXPOSE 80

# Define environment variable
ENV BINARY_SEARCH World

# Run app.py when the container launches
CMD ["./binary_tree"]

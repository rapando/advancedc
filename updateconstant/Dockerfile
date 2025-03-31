FROM ubuntu:latest

# Install dependencies
RUN apt-get update && apt-get install -y gcc && rm -rf /var/lib/apt/lists/*

# Create a non-root user
RUN useradd -m appuser

# Set working directory
WORKDIR /app

# Copy files and change ownership
COPY main.c .
RUN chown -R appuser:appuser /app

# Switch to non-root user
USER appuser

# Compile the C program
RUN gcc -o main main.c -Wall

# Run the compiled binary
CMD ["./main"]


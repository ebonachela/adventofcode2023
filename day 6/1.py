from sys import stdin

total = 1
times = []
distances = []

for line in stdin:
  if line.startswith("Time:"):
    times = list(map(int, " ".join(line.split(':')[1].split()).split())) # python is fun, but this is disgusting
    continue

  if line.startswith("Distance:"):
    distances = list(map(int, " ".join(line.split(':')[1].split()).split()))
    continue

for p in range(0, len(times)):
  time = times[p]
  record = distances[p]
  ways = 0

  for i in range(1, time):
    velocity = i
    time_to_run = time - i

    current_distance = velocity * time_to_run
    if current_distance > record:
      ways += 1

  total *= ways


print("Total:", total)
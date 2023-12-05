from sys import stdin

action = None
seeds = []

# would be easier to just add everthing inside a 
# big dictionary, but I already wrote all this down
soil_map = []
fertilizer_map = []
water_map = []
light_map = []
temperature_map = []
humidity_map = []
location_map = []

def generate_map(line):
  global action
  global soil_map
  global fertilizer_map
  global water_map
  global light_map
  global temperature_map
  global humidity_map
  global location_map

  numbers = line.split()

  destination = int(numbers[0])
  source = int(numbers[1])
  r = int(numbers[2])

  if action == 'soil_map':
    soil_map.append([source, destination, r])
  elif action == 'fertilizer_map':
    fertilizer_map.append([source, destination, r])
  elif action == 'water_map':
    water_map.append([source, destination, r])
  elif action == 'light_map':
    light_map.append([source, destination, r])
  elif action == 'temperature_map':
    temperature_map.append([source, destination, r])
  elif action == 'humidity_map':
    humidity_map.append([source, destination, r])
  elif action == 'location_map':
    location_map.append([source, destination, r])

def process_map(map, result):
  for value in map:
    source = value[0]
    destination = value[1]
    r = value[2]

    if result >= source and result < source + r:
      result = destination + (result - source)
      break
  
  return result

def get_magic_location(seed):
  result = int(seed)

  # seed -> soil
  result = process_map(soil_map, result)
  
  # soil -> fertilizer
  result = process_map(fertilizer_map, result)

  # fertilizer -> water
  result = process_map(water_map, result)
  
  # water -> light
  result = process_map(light_map, result)

  # light -> temperature
  result = process_map(temperature_map, result)
  
  # temperature -> humidity
  result = process_map(humidity_map, result)

  # humidity -> location
  result = process_map(location_map, result)

  return result

for line in stdin:
  if len(seeds) == 0:
    seeds = line.split(':')[1].strip().split()
  
  if line == '\n':
    action = None
    continue

  if line.startswith("seed-to-soil map:"):
    action = 'soil_map'
    continue

  if line.startswith("soil-to-fertilizer map:"):
    action = 'fertilizer_map'
    continue

  if line.startswith("fertilizer-to-water map:"):
    action = 'water_map'
    continue

  if line.startswith("water-to-light map:"):
    action = 'light_map'
    continue

  if line.startswith("light-to-temperature map:"):
    action = 'temperature_map'
    continue

  if line.startswith("temperature-to-humidity map:"):
    action = 'humidity_map'
    continue

  if line.startswith("humidity-to-location map:"):
    action = 'location_map'
    continue

  if action != None:
    generate_map(line)
    continue

min_location = int(seeds[0])

for seed in seeds:
  min_location = min(get_magic_location(seed), min_location)

print("Min:", min_location)
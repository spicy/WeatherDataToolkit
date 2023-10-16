# WeatherDataToolkit

WeatherDataToolkit is a collection of tools designed to fetch weather data based on geographical coordinates. This toolkit provides both sequential and parallel fetching functionalities to cater to different needs and scenarios.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [WeatherSerialFetcher](#weatherserialfetcher)
  - [WeatherParallelFetcher](#weatherparallelfetcher)
- [Performance](#performance)

## Features

- **WeatherSerialFetcher**: Fetches weather data for locations one at a time.
- **WeatherParallelFetcher**: Fetches weather data for multiple locations concurrently.

## Installation

1. Clone the repository:
git clone https://github.com/spicy/WeatherDataToolkit.git

2. Navigate to the directory:
cd WeatherDataToolkit

3. Compile the programs (assuming a generic compile command; replace with actual instructions):
make all

## Usage

### WeatherSerialFetcher
To use the `WeatherSerialFetcher`:

- g++ -o serial serial.cpp
- ./serial

### WeatherParallelFetcher
To use the `WeatherParallelFetcher`:

- g++ -o parallel parallel.cpp
- ./parallel

## Performance

You can compare the performance of both fetchers using the `time` utility. This will provide insights into how each tool behaves under different loads and conditions.

You can copy and paste the content above directly into your markdown file. Adjust placeholder links and other details as needed.

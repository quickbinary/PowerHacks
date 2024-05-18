# SafiAir

A smart air quality monitoring system using IoT, designed to improve urban air quality, foster inclusivity, and contribute to sustainable and resilient cities. This project aligns with the UN's Sustainable Development Goal 11: Sustainable Cities and Communities.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Particulate matter (PM2.5) is a significant contributor to air pollution, with serious health implications. Our solution leverages a laser PM2.5 sensor and IoT technology to create a real-time air quality monitoring system. This system aims to provide accurate data, raise environmental awareness, and help policymakers implement effective pollution control measures.

## Features

- **Real-time PM2.5 Monitoring**: Continuous monitoring of PM2.5 levels using IoT network.
- **Data Transmission**: Wireless transmission of data to a cloud platform for storage and analysis.
- **User Interface**: Accessible air quality data via a mobile app and web dashboard.
- **Alerts**: Notifications when AIR QUALITY INDEX scores exceed safe thresholds.
- **Community Reporting**: Residents can report sources of pollution through the mobile app.
- **Inclusivity**: Ensures all residents have access to air quality information and the ability to contribute to pollution reporting.

## Components

- Laser PM2.5 sensor
- Arduino R4 WiFi microcontroller board.
- Power supply (solar).

## Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/SafiAir.git
    cd SafiAir
    ```

2. **Set up the hardware**:
    - Wire the circuit.

3. **Install Arduino IDE**:
    - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

4. **Install required libraries**:
    - Open the Arduino IDE and install the required libraries for the Groove laser 2.5 sensor(<Tomoto_HM330X.h>)

5. **Upload the code**:
    - Open the `.ino` file from the repository in the Arduino IDE.
    - Select the correct board and port from the Tools menu.
    - Click on the Upload button to upload the code to your Arduino.

## Usage

1. **Power on the device**: Ensure the system is properly powered.
2. **Connect to Wi-Fi**: The device will connect to the configured Wi-Fi network and start transmitting data.
3. **Monitor air quality**: Access real-time air quality data via the cloud dashboard.
4. **Receive Alerts**: Get notifications when PM2.5 levels exceed safe thresholds.
5. **Report Pollution**: Use the mobile app to report sources of pollution in your area.

## Contributing

We welcome contributions to enhance the functionality and features of this project. To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

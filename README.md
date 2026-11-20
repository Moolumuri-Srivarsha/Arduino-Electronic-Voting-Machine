# Arduino-Based Electronic Voting Machine

## Project Overview
An Arduino-based Electronic Voting Machine developed as part of our Microcontrollers and Embedded Systems Laboratory project.

The system allows users to vote for four candidates using push buttons. It counts votes in real time and displays the results on a 16x2 LCD.

It also identifies the winning candidate, detects election ties and calculates the winning margin.

## Features
- Four candidate voting options
- Real-time vote counting
- 16x2 LCD display
- Automatic winner detection
- Winning margin calculation
- Election tie detection
- Simple button-based operation

## Hardware Components
- Arduino Uno
- 16x2 LCD with I2C module
- Push buttons
- Breadboard
- Jumper wires

## Software and Technologies
- Arduino IDE
- Embedded C++
- Arduino Uno
- I2C Communication

## Working Principle
1. The system starts and displays a welcome message on the LCD.
2. Users press the corresponding buttons to vote for candidates.
3. Arduino counts each vote.
4. The LCD displays the updated vote counts.
5. When the result button is pressed, the system compares all candidate votes.
6. It displays the winner, winning margin or tie result.

## Winning Margin Calculation

The system calculates the difference between the highest and second-highest vote counts.

Example:

| Candidate | Votes |
|---|---:|
| Candidate A | 3 |
| Candidate B | 5 |
| Candidate C | 2 |
| Candidate D | 1 |

Winner: Candidate B

Winning Margin = 5 - 3 = 2 votes.

## Source Code
`Electronic_Voting_Machine.ino`

## Project Type
Academic Laboratory Micro Project

## Learning Outcomes
- Arduino programming
- Microcontroller interfacing
- LCD communication using I2C
- Digital input handling
- Vote counting and comparison logic
- Hardware and software integration

## Contributors
Add your team members' names here.

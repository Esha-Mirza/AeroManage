<div align='center'>
<h1>AeroManage</h1>
</div>
<p align="center">
  <strong>Integrated Flight Operations & Reservation Management in C++</strong>
</p>

<p align="center">
  A comprehensive airline management system designed to streamline flight operations, passenger management, reservations, ticketing, payments, and essential passenger services through a modular object-oriented architecture.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/OOP-Object--Oriented-6A5ACD" alt="OOP">
  <img src="https://img.shields.io/badge/Airline-Management-0F766E" alt="Airline Management">
  <img src="https://img.shields.io/badge/Status-Active-2E7D32" alt="Status">
</p>

---

## Overview

**AeroManage** is a C++-based airline reservation and flight management system that models the core workflows involved in airline operations.

The system brings together flight management, passenger management, reservations, seat allocation, ticketing, payment processing, meal selection, luggage management, loyalty programs, reviews, and administrative operations within a modular object-oriented application.

The project demonstrates how **Object-Oriented Programming (OOP)** principles can be applied to design and implement a multi-module airline management environment.

---

## Core Capabilities

- Flight management and scheduling
- Passenger management
- Flight reservations and booking
- Seat allocation and management
- Ticket management
- Payment processing
- Meal selection
- Carry-on and luggage management
- Passenger loyalty programs
- Review and feedback management
- Administrative operations
- Modular C++ class architecture
- File-based application workflows

---

## System Architecture

```
                     AEROMANAGE
                         |
        +----------------+----------------+
        |                |                |
        v                v                v
   Flight Management  Passenger      Admin
        |            Management         |
        +----------------+----------------+
                         |
                         v
                    Booking System
                         |
            +------------+------------+
            |            |            |
            v            v            v
          Seats      Payment      Tickets
            |            |            |
            +------------+------------+
                         |
            +------------+------------+
            |            |            |
            v            v            v
          Meals       Luggage      Loyalty
                                        |
                                        v
                                     Reviews
```

---

## Airline Reservation Workflow

A typical passenger reservation follows a structured workflow:

```
Passenger
    |
    v
Flight Search
    |
    v
Flight Selection
    |
    v
Seat Selection
    |
    v
Booking Creation
    |
    v
Payment Processing
    |
    v
Ticket Generation
    |
    +------> Meal Selection
    |
    +------> Luggage
    |
    +------> Loyalty Program
    |
    v
Reservation Complete
    |
    v
Review / Feedback
```

---

## Features

### Flight Management

The flight management module handles flight-related information and operations. It provides the foundation for managing flights and connecting them with passengers and reservations.

### Passenger Management

The passenger module manages passenger information and passenger-specific operations. Passengers can be associated with:

- Flights
- Bookings
- Seats
- Tickets
- Payments
- Loyalty information
- Reviews

### Reservation Management

The booking module manages the reservation workflow between passengers and flights.

```
Passenger
    |
    v
Flight
    |
    v
Booking
    |
    v
Seat
    |
    v
Payment
    |
    v
Ticket
```

### Seat Management

The dedicated seat module handles seat-related operations and allocation as part of the reservation workflow.

### Ticket Management

The ticket module manages ticket-related information associated with completed reservations. This provides a dedicated component for connecting travel information with passenger bookings.

### Payment Processing

A dedicated payment module manages payment-related operations within the booking workflow.

```
Booking
   |
   v
Payment
   |
   v
Ticket
```

### Meal Selection

The system includes a dedicated meal-selection module for managing passenger meal preferences and related services.

### Luggage Management

The luggage module provides functionality for managing passenger baggage and carry-on information.

### Loyalty Program

A dedicated loyalty-program module supports passenger loyalty and rewards functionality.

### Review System

The review system allows passenger feedback to be represented independently from the core booking workflow.

### Administrative Operations

The administrative module provides functionality for airline administration and management operations.

---

## Object-Oriented Design

AeroManage is organized around domain-specific C++ classes.

Core components include:

- `Admin`
- `Booking`
- `CarryLuggage`
- `Flight`
- `LoyaltyProgram`
- `MealSelection`
- `Passenger`
- `Payment`
- `ReviewSystem`
- `Seat`
- `Tickets`
- `User`

Each major component is separated into its corresponding header and implementation files.

This architecture promotes:

- Encapsulation
- Modularity
- Separation of concerns
- Maintainability
- Reusability
- Clear domain modelling

---

## Domain Model

```
                         User
                           |
                           v
                       Passenger
                           |
              +------------+------------+
              |                         |
              v                         v
           Booking                   Loyalty
              |
       +------+------+------+
       |      |      |      |
       v      v      v      v
    Flight   Seat  Payment Ticket
       |
       +------> Meal
       |
       +------> Luggage

Passenger
    |
    v
 Review
```

---

## Data Flow

```
                     User Input
                         |
                         v
                  +-------------+
                  |  Passenger  |
                  +------+------+
                         |
                         v
                  +-------------+
                  |   Flight    |
                  +------+------+
                         |
                         v
                  +-------------+
                  |   Booking   |
                  +------+------+
                         |
             +-----------+-----------+
             |           |           |
             v           v           v
           Seat       Payment      Services
             |           |           |
             |           v           |
             |        Ticket          |
             |                       |
             +-----------+-----------+
                         |
                         v
                    Reservation
```

---

## Technology Stack

| Technology | Purpose |
|------------|---------|
| C++ | Core application language |
| Object-Oriented Programming | Domain modelling and architecture |
| C++ Standard Library | Core programming functionality |
| Header / Source Architecture | Modular code organization |
| File Handling | Application data management |

---

## Project Structure

```
Airline-Reservation-Flight-Management-System/
│
├── include/
│   ├── Admin.h
│   ├── Booking.h
│   ├── CarryLuggage.h
│   ├── Flight.h
│   ├── LoyaltyProgram.h
│   ├── MealSelection.h
│   ├── Passenger.h
│   ├── Payment.h
│   ├── ReviewSystem.h
│   ├── Seat.h
│   ├── Staff.h
│   ├── Tickets.h
│   └── User.h
│
├── src/
│   ├── Admin.cpp
│   ├── Booking.cpp
│   ├── CarryLuggage.cpp
│   ├── Flight.cpp
│   ├── LoyaltyProgram.cpp
│   ├── MealSelection.cpp
│   ├── Passenger.cpp
│   ├── Payment.cpp
│   ├── ReviewSystem.cpp
│   ├── Seat.cpp
│   ├── Tickets.cpp
│   └── main.cpp
│
└── README.md
```

---

## Module Breakdown

| Module | Description |
|--------|-------------|
| **Admin** | Handles administrative and airline management functionality. |
| **Booking** | Manages reservation-related operations and connects passengers with flights. |
| **CarryLuggage** | Handles passenger luggage and baggage-related operations. |
| **Flight** | Represents flight information and flight-related functionality. |
| **LoyaltyProgram** | Manages passenger loyalty and rewards functionality. |
| **MealSelection** | Handles passenger meal-selection functionality. |
| **Passenger** | Represents passenger information and passenger-related operations. |
| **Payment** | Handles payment-related functionality associated with bookings. |
| **ReviewSystem** | Manages passenger reviews and feedback. |
| **Seat** | Handles seat-related operations and seat allocation. |
| **Tickets** | Manages ticket-related information and operations. |
| **User** | Provides user-level functionality within the application. |

---

## Installation

### Clone the Repository

```bash
git clone https://github.com/Esha-Mirza/Airline-Reservation-Flight-Management-System.git
cd Airline-Reservation-Flight-Management-System
```

### Compilation

The project follows a standard C++ header/source structure.

Using GCC or MinGW:

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o AeroManage
```

### Running the Application

**Windows:**
```bash
AeroManage.exe
```

**macOS / Linux:**
```bash
./AeroManage
```

The application starts through `src/main.cpp`.

### Development Environment

The project can be developed using any compatible C++ development environment, including:

- Visual Studio
- Visual Studio Code
- CLion
- Code::Blocks
- MinGW
- GCC
- Other C++17-compatible environments

---

## Example Reservation Workflow

```
                     AEROMANAGE
                         |
                         v
                  Passenger Login
                         |
                         v
                  Flight Selection
                         |
                         v
                   Seat Selection
                         |
                         v
                      Booking
                         |
                         v
                      Payment
                         |
                         v
                      Ticket
                         |
             +-----------+-----------+
             |           |           |
             v           v           v
           Meal       Luggage      Loyalty
                         |
                         v
                    Trip Complete
                         |
                         v
                       Review
```

---

## Design Principles

### Modularity

Each major airline operation is represented through its own class and module.

### Encapsulation

Domain-specific data and operations are grouped within dedicated classes.

### Separation of Concerns

Flight management, bookings, payments, tickets, meals, luggage, loyalty, and reviews are maintained as separate components.

### Extensibility

The modular architecture provides a foundation for introducing additional airline functionality without placing all logic inside a single source file.

---

## Use Cases

AeroManage can be used to demonstrate:

- Airline reservation workflows
- Flight management
- Passenger management
- Seat management
- Ticket management
- Payment workflows
- Object-oriented system design
- C++ class architecture
- Modular programming
- Domain modelling
- File handling
- Entity relationships
- Reservation workflows

---

## Learning Outcomes

This project demonstrates practical application of:

- Object-Oriented Programming
- Encapsulation
- Modular architecture
- Header/source separation
- Class design
- Domain modelling
- Entity relationships
- File handling
- Application workflow design
- Software maintainability

---

## Future Enhancements

Potential improvements include:

- Graphical user interface
- Database integration
- Persistent user accounts
- Advanced flight search
- Real-time seat availability
- Automated ticket generation
- Payment gateway integration
- Booking history
- Flight cancellation and rescheduling
- Administrative dashboard
- Staff management
- Passenger notifications
- Email ticket delivery
- Reporting and analytics
- Automated testing
- CMake build configuration
- Comprehensive API layer
- Cloud deployment

---

## Limitations

AeroManage is primarily designed as an educational and software-engineering project demonstrating airline-domain modelling using C++.

It should not be considered a production-ready airline reservation platform.

A production implementation would require additional infrastructure for:

- Secure authentication
- Database transactions
- Concurrent booking management
- Payment security
- Data encryption
- API services
- Audit logging
- Fault tolerance
- Real-time availability
- Production monitoring
- Regulatory compliance

---

## Contributing

Contributions are welcome.

1. Create a feature branch:
   ```bash
   git checkout -b feature/your-feature
   ```

2. Make your changes:
   ```bash
   git add .
   git commit -m "feat: describe your change"
   ```

3. Push your branch:
   ```bash
   git push origin feature/your-feature
   ```

Then open a pull request.

When contributing, please maintain the existing modular architecture and keep new functionality separated into appropriate classes and components.

---

## Author

**Esha Mirza**

- GitHub: [https://github.com/Esha-Mirza](https://github.com/Esha-Mirza)

---

<p align="center">
  <strong>AeroManage</strong><br>
  Engineering structured airline operations with C++.
</p>
